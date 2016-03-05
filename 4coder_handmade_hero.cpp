/* NOTE(casey):

   This is my attempt to make 4coder work close enough to Emacs
   for me to switch!

   NOTE(casey): Microsoft/Windows is poopsauce.

   TODO(casey): Here are our current issues

   - Have buffers normalize slashes to always be forward-slash
     - Cursor setting seems to do no movement first time, and then weird scrolling behavior on
       jump-to-same-line subsequently

   - Switch-to-buffer with no typing, just return, should switch to the most recently
     used buffer that is not currently displayed in a view.
     - Kill-buffer should perform this switch automatically, or it should be easy
       to build a custom kill buffer that does

   - Need a way of highlighting the current line like Emacs does for the benefit
     of people on The Stream(TM)
   - Need a way of changing some things visually so we can indicate the modal state (this has
     to be something very obvious - ideally something like
     1) Change the line highlight color
     2) In modal mode, highlight the whole selected region (mark to cursor) potentially?
   - Macros
   - Some way to recenter the view so that the line containing the cursor becomes the
     center line vertically.
   - NOTE / IMPORTANT / TODO highlighting?  Ability to customize?  Whatever.


   NOTE(allen): Things that were on the issue list that are now fixed

   - Need a way of calling things by name, so infrequently used functions won't need keybindings
   - Need a way of changing some things visually so we can indicate the modal state (this has
     to be something very obvious - ideally something like
     1) Change the cursor color
     2) X
     3) X
     4) Change the header bar color?
   - Need a way to set the theme from the custom config file so I don't have to pick it every
     time.
*/

#include <math.h>
#include <stdio.h>

#define UseHack4Coder 0

#ifndef Assert
#define internal static
#define Assert assert 
#endif

static bool GlobalEditMode;
static char *GlobalCompilationBufferName = "*compilation*";


#if UseHack4Coder
#include <windows.h>
static HWND GlobalModalIndicator;
static HBRUSH GlobalEditModeBrush;
static HBRUSH GlobalNormalModeBrush;
static WNDPROC global_old_4coder_winproc;
#endif

// TODO(casey): If 4coder gets variables at some point, this would go in a variable.
static char BuildDirectory[4096] = "./";
static int ErrorParsingPosition;
static int ErrorParsingLastJumpLine;
static int ErrorParsingLastBufferID;

enum token_type
{
    Token_Unknown,

    Token_OpenParen,    
    Token_CloseParen,    
    Token_Asterisk,
    Token_Minus,
    Token_Plus,
    Token_ForwardSlash,
    Token_Percent,
    Token_Colon,
    Token_Number,

    Token_EndOfStream,
};
struct token
{
    token_type Type;

    size_t TextLength;
    char *Text;
};

struct tokenizer
{
    char *At;
};

inline bool
IsEndOfLine(char C)
{
    bool Result = ((C == '\n') ||
                   (C == '\r'));

    return(Result);
}

inline bool
IsWhitespace(char C)
{
    bool Result = ((C == ' ') ||
                   (C == '\t') ||
                   (C == '\v') ||
                   (C == '\f') ||
                   IsEndOfLine(C));

    return(Result);
}

inline bool
IsAlpha(char C)
{
    bool Result = (((C >= 'a') && (C <= 'z')) ||
                   ((C >= 'A') && (C <= 'Z')));

    return(Result);
}

inline bool
IsNumeric(char C)
{
    bool Result = ((C >= '0') && (C <= '9'));

    return(Result);
}

static void
EatAllWhitespace(tokenizer *Tokenizer)
{
    for(;;)
    {
        if(IsWhitespace(Tokenizer->At[0]))
        {
            ++Tokenizer->At;
        }
        else if((Tokenizer->At[0] == '/') &&
                (Tokenizer->At[1] == '/'))
        {
            Tokenizer->At += 2;
            while(Tokenizer->At[0] && !IsEndOfLine(Tokenizer->At[0]))
            {
                ++Tokenizer->At;
            }
        }
        else if((Tokenizer->At[0] == '/') &&
                (Tokenizer->At[1] == '*'))
        {
            Tokenizer->At += 2;
            while(Tokenizer->At[0] &&
                  !((Tokenizer->At[0] == '*') &&
                    (Tokenizer->At[1] == '/')))
            {
                ++Tokenizer->At;
            }

            if(Tokenizer->At[0] == '*')
            {
                Tokenizer->At += 2;
            }
        }
        else
        {
            break;
        }
    }
}

static token
GetToken(tokenizer *Tokenizer)
{
    EatAllWhitespace(Tokenizer);

    token Token = {};
    Token.TextLength = 1;
    Token.Text = Tokenizer->At;
    char C = Tokenizer->At[0];
    ++Tokenizer->At;
    switch(C)
    {
        case '0': {--Tokenizer->At; Token.Type = Token_EndOfStream;} break;

        case '(': {Token.Type = Token_OpenParen;} break;
        case ')': {Token.Type = Token_CloseParen;} break;
        case '*': {Token.Type = Token_Asterisk;} break;
        case '-': {Token.Type = Token_Minus;} break;
        case '+': {Token.Type = Token_Plus;} break;
        case '/': {Token.Type = Token_ForwardSlash;} break;
        case '%': {Token.Type = Token_Percent;} break;
        case ':': {Token.Type = Token_Colon;} break;

        default:
        {
            if(IsNumeric(C))
            {
                // TODO(casey): Real number
                Token.Type = Token_Number;
                while(IsNumeric(Tokenizer->At[0]) ||
                      (Tokenizer->At[0] == '.') ||
                      (Tokenizer->At[0] == 'f'))
                {
                    ++Tokenizer->At;
                    Token.TextLength = Tokenizer->At - Token.Text;
                }
            }
            else
            {
                Token.Type = Token_Unknown;
            }
        } break;        
    }

    return(Token);
}

static token
PeekToken(tokenizer *Tokenizer)
{
    tokenizer Tokenizer2 = *Tokenizer;
    token Result = GetToken(&Tokenizer2);
    return(Result);
}

inline bool
IsH(String extension)
{
    bool Result = (match(extension, make_lit_string("h")) ||
                   match(extension, make_lit_string("hpp")) ||
                   match(extension, make_lit_string("hin")));

    return(Result);
}

inline bool
IsCPP(String extension)
{
    bool Result = (match(extension, make_lit_string("c")) ||
                   match(extension, make_lit_string("cpp")) ||
                   match(extension, make_lit_string("cin")));

    return(Result);
}

inline bool
IsINL(String extension)
{
    bool Result = (match(extension, make_lit_string("inl")));

    return(Result);
}

inline bool
IsCode(String extension)
{
    bool Result = (IsH(extension) || IsCPP(extension) || IsINL(extension));

    return(Result);
}

HOOK_SIG(casey_start)
{
    exec_command(app, cmdid_open_panel_vsplit);
    app->change_theme(app, literal("Handmade Hero"));
    app->change_font(app, literal("liberation mono"));
}

CUSTOM_COMMAND_SIG(casey_open_in_other)
{
    exec_command(app, cmdid_change_active_panel);
    exec_command(app, cmdid_interactive_open);
}

CUSTOM_COMMAND_SIG(casey_clean_and_save)
{
    exec_command(app, cmdid_clean_all_lines);
    exec_command(app, cmdid_eol_nixify);
    exec_command(app, cmdid_save);
}

CUSTOM_COMMAND_SIG(casey_newline_and_indent)
{
    exec_command(app, cmdid_write_character);
    exec_command(app, cmdid_auto_tab_line_at_cursor);
}

CUSTOM_COMMAND_SIG(casey_open_file_other_window)
{
    exec_command(app, cmdid_change_active_panel);
    exec_command(app, cmdid_interactive_open);
}

CUSTOM_COMMAND_SIG(casey_switch_buffer_other_window)
{
    exec_command(app, cmdid_change_active_panel);
    exec_command(app, cmdid_interactive_switch_buffer);
}

internal void
DeleteAfterCommand(struct Application_Links *app, Command_ID CommandID)
{
    View_Summary view = app->get_active_view(app);

    int pos2 = view.cursor.pos;
    exec_command(app, CommandID);
    app->refresh_view(app, &view);
    int pos1 = view.cursor.pos;

    Range range = make_range(pos1, pos2);

    Buffer_Summary buffer = app->get_buffer(app, view.buffer_id);
    app->buffer_replace_range(app, &buffer, range.min, range.max, 0, 0);
}

CUSTOM_COMMAND_SIG(casey_delete_token_left)
{
    DeleteAfterCommand(app, cmdid_seek_white_or_token_left);
}

CUSTOM_COMMAND_SIG(casey_delete_token_right)
{
    DeleteAfterCommand(app, cmdid_seek_white_or_token_right);
}

CUSTOM_COMMAND_SIG(casey_kill_to_end_of_line)
{
    View_Summary view = app->get_active_view(app);

    int pos2 = view.cursor.pos;
    exec_command(app, cmdid_seek_end_of_line);
    app->refresh_view(app, &view);
    int pos1 = view.cursor.pos;

    Range range = make_range(pos1, pos2);
    if(pos1 == pos2)
    {
        range.max += 1;
    }

    Buffer_Summary buffer = app->get_buffer(app, view.buffer_id);
    app->buffer_replace_range(app, &buffer, range.min, range.max, 0, 0);
}

CUSTOM_COMMAND_SIG(casey_paste_and_tab)
{
    // NOTE(allen): Paste puts the mark at the beginning and the cursor at
    // the end of the pasted chunk, so it is all set for cmdid_auto_tab_range
    exec_command(app, cmdid_paste);
    exec_command(app, cmdid_auto_tab_range);
}

CUSTOM_COMMAND_SIG(casey_seek_beginning_of_line_and_tab)
{
    exec_command(app, cmdid_seek_beginning_of_line);
    exec_command(app, cmdid_auto_tab_line_at_cursor);
}

struct switch_to_result
{
    bool Switched;
    View_Summary view;
    Buffer_Summary buffer;
};

inline switch_to_result
SwitchToOrLoadFile(struct Application_Links *app, String FileName, bool CreateIfNotFound = false)
{
    switch_to_result Result = {};

    View_Summary view = app->get_active_view(app);
    Buffer_Summary buffer = app->get_buffer_by_name(app, FileName.str, FileName.size);

    Result.view = view;
    Result.buffer = buffer;

    if(buffer.exists)
    {
        app->view_set_buffer(app, &view, buffer.buffer_id);
        Result.Switched = true;
    }
    else
    {
        if(app->file_exists(app, FileName.str, FileName.size) || CreateIfNotFound)
        {
            push_parameter(app, par_name, expand_str(FileName));
            // TODO(casey): Do I have to check for existence, or can I pass a parameter
            // to interactive open to tell it to fail if the file isn't there?
            exec_command(app, cmdid_interactive_open);

            Result.buffer = app->get_buffer_by_name(app, FileName.str, FileName.size);            

            Result.Switched = true;
        }
    }

    return(Result);
}

CUSTOM_COMMAND_SIG(casey_load_todo)
{
    String ToDoFileName = make_lit_string("w:/handmade/code/todo.txt");
    SwitchToOrLoadFile(app, ToDoFileName, true);
}

CUSTOM_COMMAND_SIG(casey_load_handmade)
{
    // NOTE(allen|a3.4.4): Here we get the list of files in this directory.
    // Notice that we free_file_list at the end.
    String dir = make_string(app->memory, 0, app->memory_size);
    append(&dir, "w:/handmade/code/");
    File_List list = app->get_file_list(app, dir.str, dir.size);
    int dir_size = dir.size;

    for (int i = 0; i < list.count; ++i)
    {
        File_Info *info = list.infos + i;
        if (!info->folder)
        {
            String extension = file_extension(info->filename);
            if (IsCode(extension))
            {
                // NOTE(allen): There's no way in the 4coder API to use relative
                // paths at the moment, so everything should be full paths.  Which is
                // managable.  Here simply set the dir string size back to where it
                // was originally, so that new appends overwrite old ones.
                dir.size = dir_size;
                append(&dir, info->filename);
                push_parameter(app, par_name, dir.str, dir.size);
                if (!match(info->filename, make_lit_string("handmade.cpp"))){
                    push_parameter(app, par_do_in_background, 1);
                }
                exec_command(app, cmdid_interactive_open);
            }
        }
    }

    app->free_file_list(app, list);
    
    strcpy(BuildDirectory, "w:/handmade/code/");
}

CUSTOM_COMMAND_SIG(casey_build_search)
{
    int keep_going = 1;
    int old_size;
    // TODO(allen): It's fine to get memory this way for now, eventually
    // we should properly suballocating from app->memory.
    String dir = make_string(app->memory, 0, app->memory_size);
    dir.size = app->directory_get_hot(app, dir.str, dir.memory_size);
    
    while (keep_going)
    {
        old_size = dir.size;
        append(&dir, "build.bat");
        
        if (app->file_exists(app, dir.str, dir.size))
        {
            dir.size = old_size;
            memcpy(BuildDirectory, dir.str, dir.size);
            BuildDirectory[dir.size] = 0;
            
            return;
        }

        dir.size = old_size;

        if (app->directory_cd(app, dir.str, &dir.size, dir.memory_size, literal("..")) == 0)
        {
            keep_going = 0;
        }
    }

    // TODO(casey): How do I print out that it found or didn't find something?
}

CUSTOM_COMMAND_SIG(casey_find_corresponding_file)
{
    View_Summary view = app->get_active_view(app);
    Buffer_Summary buffer = app->get_buffer(app, view.buffer_id);

    String extension = file_extension(make_string(buffer.file_name, buffer.file_name_len));
    if (extension.str)
    {       
        char *HExtensions[] =
        {
            "hpp",
            "hin",
            "h",
        };

        char *CExtensions[] =
        {
            "c",
            "cin",
            "cpp",
        };

        int ExtensionCount = 0;
        char **Extensions = 0;
        if(IsH(extension))
        {
            ExtensionCount = ArrayCount(CExtensions);
            Extensions = CExtensions;
        }
        else if(IsCPP(extension) || IsINL(extension))
        {
            ExtensionCount = ArrayCount(HExtensions);
            Extensions = HExtensions;
        }

        int MaxExtensionLength = 3;
        int Space = (int)(buffer.file_name_len + MaxExtensionLength);
        String FileNameStem = make_string(buffer.file_name, (int)(extension.str - buffer.file_name), 0);
        String TestFileName = make_string(app->push_memory(app, Space), 0, Space);   
        for(int ExtensionIndex = 0;
            ExtensionCount;
            ++ExtensionIndex)
        {
            TestFileName.size = 0;
            append(&TestFileName, FileNameStem);
            append(&TestFileName, Extensions[ExtensionIndex]);

            if(SwitchToOrLoadFile(app, TestFileName, ((ExtensionIndex + 1) == ExtensionCount)).Switched)
            {
                break;
            }
        }
    }
}

CUSTOM_COMMAND_SIG(casey_save_and_make_without_asking)
{
    exec_command(app, cmdid_change_active_panel);

    Buffer_Summary buffer = {};

    for(buffer = app->get_buffer_first(app);
        buffer.exists;
        app->get_buffer_next(app, &buffer))
    {
        push_parameter(app, par_name, buffer.file_name, buffer.file_name_len);
        push_parameter(app, par_buffer_id, buffer.buffer_id);
        exec_command(app, cmdid_save);
    }

    String dir = make_string(app->memory, 0, app->memory_size);
    append(&dir, BuildDirectory);

    push_parameter(app, par_flags, CLI_OverlapWithConflict);
    push_parameter(app, par_name, GlobalCompilationBufferName, (int)strlen(GlobalCompilationBufferName));
    push_parameter(app, par_cli_path, dir.str, dir.size);

    if(append(&dir, "build"))
    {
        push_parameter(app, par_cli_command, dir.str, dir.size);
        exec_command(app, cmdid_command_line);
        ErrorParsingPosition = 0;
        ErrorParsingLastJumpLine = 0;
        ErrorParsingLastBufferID = 0;

        exec_command(app, cmdid_change_active_panel);
    }
    else{
        app->clear_parameters(app);
    }
}

CUSTOM_COMMAND_SIG(casey_goto_previous_error)
{
    // TODO(casey): Implement
//    Buffer_Summary Buffer = app->get_buffer_by_name(app, GlobalCompilationBufferName, (int)strlen(GlobalCompilationBufferName));
}

CUSTOM_COMMAND_SIG(casey_goto_next_error)
{
    Buffer_Summary Buffer = app->get_buffer_by_name(app, GlobalCompilationBufferName, (int)strlen(GlobalCompilationBufferName));

    int Size = Buffer.size - ErrorParsingPosition;
    if(Size > 0)
    {
        char *ParsingRegion = (char *)malloc(Size + 1);
        app->buffer_read_range(app, &Buffer, ErrorParsingPosition, Buffer.size, ParsingRegion);
        ParsingRegion[Size] = 0;

        tokenizer Tokenizer = {ParsingRegion};
        for(;;)
        {
            token Token = GetToken(&Tokenizer);
            if(Token.Type == Token_OpenParen)
            {
                token LineToken = GetToken(&Tokenizer);
                if(LineToken.Type == Token_Number)
                {
                    token CloseToken = GetToken(&Tokenizer);
                    if(CloseToken.Type == Token_CloseParen)
                    {
                        token ColonToken = GetToken(&Tokenizer);
                        if(ColonToken.Type == Token_Colon)
                        {
                            // NOTE(casey): We maybe found an error!
                            int line_number = atoi(LineToken.Text);

                            char *Seek = Token.Text;
                            while(Seek != ParsingRegion)
                            {
                                if(IsEndOfLine(*Seek))
                                {
                                    while(IsWhitespace(*Seek))
                                    {
                                        ++Seek;
                                    }
                                    break;
                                }

                                --Seek;
                            }

                            String FileName = make_string(Seek, (int)(Token.Text - Seek));
                            switch_to_result Switch = SwitchToOrLoadFile(app, FileName, false);
                            if(Switch.Switched)
                            {
                                app->view_set_cursor(app, &Switch.view, seek_line_char(line_number, 0), 1);
                            }

                            if((line_number != ErrorParsingLastJumpLine) ||
                               (Switch.buffer.buffer_id != ErrorParsingLastBufferID))
                            {
                                ErrorParsingLastJumpLine = line_number;
                                ErrorParsingLastBufferID = Switch.buffer.buffer_id;
                                ErrorParsingPosition += (int)(ColonToken.Text - ParsingRegion);

                                View_Summary compilation_view =
                                    get_first_view_with_buffer(app, Buffer.buffer_id);
                                if(compilation_view.exists)
                                {
                                    app->view_set_cursor(app, &compilation_view, seek_pos(ErrorParsingPosition), 1);
                                }

                                break;
                            }
                        }
                    }
                }
            }
            else if(Token.Type == Token_EndOfStream)
            {
                break;
            }
        }

        free(ParsingRegion);
    }
}

CUSTOM_COMMAND_SIG(casey_imenu)
{
    // TODO(casey): Implement!
}

//
// TODO(casey): Everything below this line probably isn't possible yet
//

CUSTOM_COMMAND_SIG(casey_call_keyboard_macro)
{
    // TODO(casey): Implement!
}

CUSTOM_COMMAND_SIG(casey_begin_keyboard_macro_recording)
{
    // TODO(casey): Implement!
}

CUSTOM_COMMAND_SIG(casey_end_keyboard_macro_recording)
{
    // TODO(casey): Implement!
}

CUSTOM_COMMAND_SIG(casey_fill_paragraph)
{
    // TODO(casey): Implement!
}

enum calc_node_type
{
    CalcNode_UnaryMinus,

    CalcNode_Add,
    CalcNode_Subtract,
    CalcNode_Multiply,
    CalcNode_Divide,
    CalcNode_Mod,

    CalcNode_Constant,
};
struct calc_node
{
    calc_node_type Type;
    double Value;
    calc_node *Left;
    calc_node *Right;
};

internal double
ExecCalcNode(calc_node *Node)
{
    double Result = 0.0f;

    if(Node)
    {
        switch(Node->Type)
        {
            case CalcNode_UnaryMinus: {Result = -ExecCalcNode(Node->Left);} break;
            case CalcNode_Add: {Result = ExecCalcNode(Node->Left) + ExecCalcNode(Node->Right);} break;
            case CalcNode_Subtract: {Result = ExecCalcNode(Node->Left) - ExecCalcNode(Node->Right);} break;
            case CalcNode_Multiply: {Result = ExecCalcNode(Node->Left) * ExecCalcNode(Node->Right);} break;
            case CalcNode_Divide: {/*TODO(casey): Guard 0*/Result = ExecCalcNode(Node->Left) / ExecCalcNode(Node->Right);} break;
            case CalcNode_Mod: {/*TODO(casey): Guard 0*/Result = fmod(ExecCalcNode(Node->Left), ExecCalcNode(Node->Right));} break;
            case CalcNode_Constant: {Result = Node->Value;} break;
            default: {Assert(!"AHHHHH!");}
        }
    }

    return(Result);
}

internal void
FreeCalcNode(calc_node *Node)
{
    if(Node)
    {
        FreeCalcNode(Node->Left);
        FreeCalcNode(Node->Right);
        free(Node);
    }
}

internal calc_node *
AddNode(calc_node_type Type, calc_node *Left = 0, calc_node *Right = 0)
{
    calc_node *Node = (calc_node *)malloc(sizeof(calc_node));
    Node->Type = Type;
    Node->Value = 0;
    Node->Left = Left;
    Node->Right = Right;    
    return(Node);
}

internal calc_node *
ParseNumber(tokenizer *Tokenizer)
{
    calc_node *Result = AddNode(CalcNode_Constant);

    token Token = GetToken(Tokenizer);
    Result->Value = atof(Token.Text);

    return(Result);
}

internal calc_node *
ParseConstant(tokenizer *Tokenizer)
{
    calc_node *Result = 0;

    token Token = PeekToken(Tokenizer);
    if(Token.Type == Token_Minus)
    {
        Token = GetToken(Tokenizer);
        Result = AddNode(CalcNode_UnaryMinus);
        Result->Left = ParseNumber(Tokenizer);
    }
    else
    {
        Result = ParseNumber(Tokenizer);
    }

    return(Result);
}

internal calc_node *
ParseMultiplyExpression(tokenizer *Tokenizer)
{
    calc_node *Result = 0;

    token Token = PeekToken(Tokenizer);
    if((Token.Type == Token_Minus) ||
       (Token.Type == Token_Number))
    {
        Result = ParseConstant(Tokenizer);
        token Token = PeekToken(Tokenizer);
        if(Token.Type == Token_ForwardSlash)
        {
            GetToken(Tokenizer);
            Result = AddNode(CalcNode_Divide, Result, ParseNumber(Tokenizer));
        }
        else if(Token.Type == Token_Asterisk)
        {
            GetToken(Tokenizer);
            Result = AddNode(CalcNode_Multiply, Result, ParseNumber(Tokenizer));
        }
    }

    return(Result);
}

internal calc_node *
ParseAddExpression(tokenizer *Tokenizer)
{
    calc_node *Result = 0;

    token Token = PeekToken(Tokenizer);
    if((Token.Type == Token_Minus) ||
       (Token.Type == Token_Number))
    {
        Result = ParseMultiplyExpression(Tokenizer);
        token Token = PeekToken(Tokenizer);
        if(Token.Type == Token_Plus)
        {
            GetToken(Tokenizer);
            Result = AddNode(CalcNode_Add, Result, ParseMultiplyExpression(Tokenizer));
        }
        else if(Token.Type == Token_Minus)
        {
            GetToken(Tokenizer);
            Result = AddNode(CalcNode_Subtract, Result, ParseMultiplyExpression(Tokenizer));
        }
    }

    return(Result);
}

internal calc_node *
ParseCalc(tokenizer *Tokenizer)
{
    calc_node *Node = ParseAddExpression(Tokenizer);

    return(Node);
}

CUSTOM_COMMAND_SIG(casey_quick_calc)
{
    View_Summary view = app->get_active_view(app);

    Range range = get_range(&view);

    size_t Size = range.max - range.min;
    if (Size == 0) return;
    
    char *Stuff = (char *)malloc(Size + 1);
    Stuff[Size] = 0;
    
    Buffer_Summary buffer = app->get_buffer(app, view.buffer_id);
    app->buffer_read_range(app, &buffer, range.min, range.max, Stuff);

    tokenizer Tokenizer = {Stuff};
    calc_node *CalcTree = ParseCalc(&Tokenizer);
    double ComputedValue = ExecCalcNode(CalcTree);
    FreeCalcNode(CalcTree);

    char ResultBuffer[256];
    int ResultSize = sprintf(ResultBuffer, "%f", ComputedValue);

    app->buffer_replace_range(app, &buffer, range.min, range.max, ResultBuffer, ResultSize);

    free(Stuff);
}

CUSTOM_COMMAND_SIG(modal_toggle)
{
    Theme_Color normal_colors[] = {
        {Stag_Cursor, 0x40FF40},
        {Stag_At_Cursor, 0x161616},
        {Stag_Mark, 0x808080},
        {Stag_Margin, 0x262626},
        {Stag_Margin_Hover, 0x333333},
        {Stag_Margin_Active, 0x404040},
        {Stag_Bar, 0xCACACA}
    };

    Theme_Color edit_colors[] = {
        {Stag_Cursor, 0xFF0000},
        {Stag_At_Cursor, 0x00FFFF},
        {Stag_Mark, 0xFF6F1A},
        {Stag_Margin, 0x33170B},
        {Stag_Margin_Hover, 0x49200F},
        {Stag_Margin_Active, 0x934420},
        {Stag_Bar, 0x934420}
    };

    GlobalEditMode = !GlobalEditMode;

    if (GlobalEditMode){
        app->set_theme_colors(app, edit_colors, ArrayCount(edit_colors));
    }
    else{
        app->set_theme_colors(app, normal_colors, ArrayCount(normal_colors));
    }

#if UseHack4Coder
    RECT Rect;
    GetClientRect(GlobalModalIndicator, &Rect);
    InvalidateRect(GlobalModalIndicator, &Rect, FALSE);
#endif

}

CUSTOM_COMMAND_SIG(casey_arbitrary_command){
    Query_Bar bar;
    char space[1024];
    bar.prompt = make_lit_string("Command: ");
    bar.string = make_fixed_width_string(space);

    if (!query_user_string(app, &bar)) return;
    app->end_query_bar(app, &bar, 0);

    if (match(bar.string, make_lit_string("build search"))){
        exec_command(app, casey_build_search);
    }
    else if (match(bar.string, make_lit_string("open hmh"))){
        exec_command(app, casey_load_handmade);
    }
    else if (match(bar.string, make_lit_string("open menu"))){
        exec_command(app, cmdid_open_menu);
    }
    else{
        // TODO(allen): feedback message
    }
}

#define DEFINE_FULL_BIMODAL_KEY(binding_name,edit_code,normal_code) \
CUSTOM_COMMAND_SIG(binding_name) \
{ \
    if(GlobalEditMode) \
    { \
        edit_code;            \
    } \
    else \
    { \
        normal_code; \
    } \
}

#define DEFINE_BIMODAL_KEY(binding_name,edit_code,normal_code) DEFINE_FULL_BIMODAL_KEY(binding_name,exec_command(app,edit_code),exec_command(app,normal_code))
#define DEFINE_MODAL_KEY(binding_name,edit_code) DEFINE_BIMODAL_KEY(binding_name,edit_code,cmdid_write_character)

//    cmdid_paste_next ?
//    cmdid_timeline_scrub ?
//    cmdid_history_backward,
//    cmdid_history_forward,
//    cmdid_toggle_line_wrap,
//    cmdid_close_minor_view,

DEFINE_MODAL_KEY(modal_space, cmdid_set_mark);
DEFINE_MODAL_KEY(modal_back_slash, casey_clean_and_save);
DEFINE_MODAL_KEY(modal_single_quote, casey_call_keyboard_macro);
DEFINE_MODAL_KEY(modal_comma, casey_goto_previous_error);
DEFINE_MODAL_KEY(modal_period, casey_fill_paragraph);
DEFINE_MODAL_KEY(modal_forward_slash, cmdid_change_active_panel);
DEFINE_MODAL_KEY(modal_semicolon, cmdid_cursor_mark_swap); // TODO(casey): Maybe cmdid_history_backward?
DEFINE_MODAL_KEY(modal_open_bracket, casey_begin_keyboard_macro_recording);
DEFINE_MODAL_KEY(modal_close_bracket, casey_end_keyboard_macro_recording);
DEFINE_MODAL_KEY(modal_a, cmdid_write_character); // TODO(casey): Available
DEFINE_MODAL_KEY(modal_b, cmdid_interactive_switch_buffer);
DEFINE_MODAL_KEY(modal_c, casey_find_corresponding_file);
DEFINE_MODAL_KEY(modal_d, cmdid_write_character); // TODO(casey): Available
DEFINE_MODAL_KEY(modal_e, cmdid_write_character); // TODO(casey): Available
DEFINE_MODAL_KEY(modal_f, casey_paste_and_tab);
DEFINE_MODAL_KEY(modal_g, goto_line);
DEFINE_MODAL_KEY(modal_h, cmdid_auto_tab_range);
DEFINE_MODAL_KEY(modal_i, cmdid_redo);
DEFINE_MODAL_KEY(modal_j, casey_imenu);
DEFINE_MODAL_KEY(modal_k, casey_kill_to_end_of_line);
DEFINE_MODAL_KEY(modal_l, replace_in_range);
DEFINE_MODAL_KEY(modal_m, casey_save_and_make_without_asking);
DEFINE_MODAL_KEY(modal_n, casey_goto_next_error);
DEFINE_MODAL_KEY(modal_o, query_replace);
DEFINE_MODAL_KEY(modal_p, casey_quick_calc);
DEFINE_MODAL_KEY(modal_q, cmdid_copy);
DEFINE_MODAL_KEY(modal_r, reverse_search); // NOTE(allen): I've modified my default search so you can use it now.
DEFINE_MODAL_KEY(modal_s, search);
DEFINE_MODAL_KEY(modal_t, casey_load_todo);
DEFINE_MODAL_KEY(modal_u, cmdid_undo);
DEFINE_MODAL_KEY(modal_v, casey_switch_buffer_other_window);
DEFINE_MODAL_KEY(modal_w, cmdid_cut);
DEFINE_MODAL_KEY(modal_x, casey_open_file_other_window);
DEFINE_MODAL_KEY(modal_y, cmdid_auto_tab_line_at_cursor);
DEFINE_MODAL_KEY(modal_z, cmdid_interactive_open);

DEFINE_MODAL_KEY(modal_1, casey_build_search); // TODO(casey): Shouldn't need to bind a key for this?
DEFINE_MODAL_KEY(modal_2, casey_load_handmade); // TODO(casey): Shouldn't need to bind a key for this?
DEFINE_MODAL_KEY(modal_3, casey_arbitrary_command); // NOTE(allen): I set this for testing stuff modal_1 and modal_2 don't need to be set anymore
DEFINE_MODAL_KEY(modal_4, cmdid_write_character); // TODO(casey): Available
DEFINE_MODAL_KEY(modal_5, cmdid_write_character); // TODO(casey): Available
DEFINE_MODAL_KEY(modal_6, cmdid_write_character); // TODO(casey): Available
DEFINE_MODAL_KEY(modal_7, cmdid_write_character); // TODO(casey): Available
DEFINE_MODAL_KEY(modal_8, cmdid_write_character); // TODO(casey): Available
DEFINE_MODAL_KEY(modal_9, cmdid_write_character); // TODO(casey): Available
DEFINE_MODAL_KEY(modal_0, cmdid_kill_buffer);
DEFINE_MODAL_KEY(modal_minus, cmdid_write_character); // TODO(casey): Available
DEFINE_MODAL_KEY(modal_equals, cmdid_write_character); // TODO(casey): Available

DEFINE_BIMODAL_KEY(modal_backspace, casey_delete_token_left, cmdid_backspace);
DEFINE_BIMODAL_KEY(modal_up, cmdid_move_up, cmdid_move_up);
DEFINE_BIMODAL_KEY(modal_down, cmdid_move_down, cmdid_move_down);
DEFINE_BIMODAL_KEY(modal_left, cmdid_seek_white_or_token_left, cmdid_move_left); 
DEFINE_BIMODAL_KEY(modal_right, cmdid_seek_white_or_token_right, cmdid_move_right);
DEFINE_BIMODAL_KEY(modal_delete, casey_delete_token_right, cmdid_delete);
DEFINE_BIMODAL_KEY(modal_home, cmdid_seek_beginning_of_line, casey_seek_beginning_of_line_and_tab);
DEFINE_BIMODAL_KEY(modal_end, cmdid_seek_end_of_line, cmdid_seek_end_of_line);
DEFINE_BIMODAL_KEY(modal_page_up, cmdid_page_up, cmdid_seek_whitespace_up);
DEFINE_BIMODAL_KEY(modal_page_down, cmdid_page_down, cmdid_seek_whitespace_down);
//DEFINE_BIMODAL_KEY(modal_escape, cmdid_write_character, cmdid_write_character); // TODO(casey): Available
DEFINE_BIMODAL_KEY(modal_tab, cmdid_word_complete, cmdid_word_complete);

HOOK_SIG(casey_file_settings)
{
    // NOTE(allen|a4): As of alpha 4 hooks can have parameters which are
    // received through functions like this app->get_parameter_buffer.
    // This is different from the past where this hook got a buffer
    // from app->get_active_buffer.
    Buffer_Summary buffer = app->get_parameter_buffer(app, 0);

    int treat_as_code = 0;

    if (buffer.file_name && buffer.size < (16 << 20))
    {
        String ext = file_extension(make_string(buffer.file_name, buffer.file_name_len));
        treat_as_code = IsCode(ext);
    }

    push_parameter(app, par_lex_as_cpp_file, treat_as_code);
    push_parameter(app, par_wrap_lines, !treat_as_code);
    push_parameter(app, par_key_mapid, (treat_as_code)?((int)my_code_map):((int)mapid_file));
    exec_command(app, cmdid_set_settings);
}

// NOTE(allen): This was a bit of fun so I'll leave it in,
// incase anyone would like to hack 4coder again.
#if UseHack4Coder
internal void
hack_place_modal_indicator(void)
{
    static RECT LastParentRect;

    HWND ParentWindow = GetParent(GlobalModalIndicator);
    RECT ParentRect;
    GetClientRect(ParentWindow, &ParentRect);        

    if((LastParentRect.bottom != ParentRect.bottom) ||
       (LastParentRect.right != ParentRect.right))
    {
        SetWindowPos(GlobalModalIndicator, 0,
                     (ParentRect.left+ParentRect.right)/2 - 10,
                     ParentRect.top,
                     10,
                     ParentRect.bottom - ParentRect.top,
                     SWP_NOOWNERZORDER|SWP_NOACTIVATE);
    }

    LastParentRect = ParentRect;
}

internal LRESULT CALLBACK
main_window_intercept(HWND Window,
                      UINT Message,
                      WPARAM WParam,
                      LPARAM LParam)
{
    LRESULT Result = CallWindowProc(global_old_4coder_winproc, Window, Message, WParam, LParam);

    if(Message == WM_SIZE)
    {
        hack_place_modal_indicator();
    }

    return(Result);
}

internal LRESULT CALLBACK
modal_indicator_window_callback(HWND Window,
                                UINT Message,
                                WPARAM WParam,
                                LPARAM LParam)
{       
    LRESULT Result = 0;

    switch(Message)
    {        
        case WM_PAINT:
        {
            PAINTSTRUCT Paint;
            HDC DeviceContext = BeginPaint(Window, &Paint);
            FillRect(DeviceContext, &Paint.rcPaint, GlobalEditMode ? GlobalEditModeBrush : GlobalNormalModeBrush);
            EndPaint(Window, &Paint);
        } break;

        default:
        {
            Result = DefWindowProcA(Window, Message, WParam, LParam);
        } break;
    }

    return(Result);
}

internal void
hack_4coder(void)
{
    HWND Window = FindWindow("4coder-win32-wndclass", "4coder-window");    
    ShowWindow(Window, SW_MAXIMIZE);

    WNDCLASSA WindowClass = {};

    HINSTANCE Instance = GetModuleHandle(0);

    WindowClass.style = CS_HREDRAW|CS_VREDRAW;
    WindowClass.lpfnWndProc = modal_indicator_window_callback;
    WindowClass.hInstance = Instance;
    WindowClass.hCursor = LoadCursor(0, IDC_ARROW);
    WindowClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    WindowClass.lpszClassName = "4coderhackmodaldisplay";

    if(RegisterClassA(&WindowClass))
    {
        GlobalModalIndicator =
            CreateWindowEx(
                0,
                WindowClass.lpszClassName,
                0,
                WS_VISIBLE|WS_CHILD,
                0, 0, 10, 10,
                Window,
                0,
                Instance,
                0);
        GlobalEditModeBrush = CreateSolidBrush(RGB(100, 20, 20));
        GlobalNormalModeBrush = CreateSolidBrush(RGB(20, 100, 20));

        hack_place_modal_indicator();
    }

    global_old_4coder_winproc = (WNDPROC)SetWindowLongPtr(Window, GWLP_WNDPROC, (LONG_PTR)main_window_intercept);
}
#endif

void
casey_get_bindings(Bind_Helper *context)
{
    set_hook(context, hook_start, casey_start);
    set_hook(context, hook_open_file, casey_file_settings);
    
    set_scroll_rule(context, smooth_scroll_rule);

#if UseHack4Coder
    hack_4coder();
#endif

    begin_map(context, mapid_global);
    {
        bind(context, 'z', MDFR_NONE, cmdid_interactive_open);
        bind(context, 'x', MDFR_NONE, casey_open_in_other);
        bind(context, 't', MDFR_NONE, casey_load_todo);
        bind(context, '/', MDFR_NONE, cmdid_change_active_panel);
        bind(context, 'b', MDFR_NONE, cmdid_interactive_switch_buffer);
        bind(context, '3', MDFR_NONE, casey_arbitrary_command);
        bind(context, key_page_up, MDFR_NONE, search);
        bind(context, key_page_down, MDFR_NONE, reverse_search);

        // NOTE(allen): These don't necessarily need to be here anymore.
        // They are now bound to long form commands in casey_arbitrary_command.
        bind(context, '2', MDFR_NONE, casey_load_handmade);
        bind(context, '4', MDFR_NONE, cmdid_open_color_tweaker);

        // NOTE(allen): I added this here myself, I believe this is what you want.
        bind(context, 'm', MDFR_NONE, casey_save_and_make_without_asking);
    }        
    end_map(context);

    begin_map(context, mapid_file);

    bind_vanilla_keys(context, cmdid_write_character);

    bind(context, key_insert, MDFR_NONE, modal_toggle);
    bind(context, '`', MDFR_NONE, modal_toggle);
    bind(context, '\n', MDFR_NONE, casey_newline_and_indent);

    bind(context, 't', MDFR_CTRL, cmdid_timeline_scrub);

    // NOTE(casey): Modal keys come here.
    bind(context, ' ', MDFR_NONE, modal_space);
    bind(context, ' ', MDFR_SHIFT, modal_space);
    bind(context, '\\', MDFR_NONE, modal_back_slash);
    bind(context, '\'', MDFR_NONE, modal_single_quote);
    bind(context, ',', MDFR_NONE, modal_comma);
    bind(context, '.', MDFR_NONE, modal_period);
    bind(context, '/', MDFR_NONE, modal_forward_slash);
    bind(context, ';', MDFR_NONE, modal_semicolon);
    bind(context, '[', MDFR_NONE, modal_open_bracket);
    bind(context, ']', MDFR_NONE, modal_close_bracket);
    bind(context, 'a', MDFR_NONE, modal_a);
    bind(context, 'b', MDFR_NONE, modal_b);
    bind(context, 'c', MDFR_NONE, modal_c);
    bind(context, 'd', MDFR_NONE, modal_d);
    bind(context, 'e', MDFR_NONE, modal_e);
    bind(context, 'f', MDFR_NONE, modal_f);
    bind(context, 'g', MDFR_NONE, modal_g);
    bind(context, 'h', MDFR_NONE, modal_h);
    bind(context, 'i', MDFR_NONE, modal_i);
    bind(context, 'j', MDFR_NONE, modal_j);
    bind(context, 'k', MDFR_NONE, modal_k);
    bind(context, 'l', MDFR_NONE, modal_l);
    bind(context, 'm', MDFR_NONE, modal_m);
    bind(context, 'n', MDFR_NONE, modal_n);
    bind(context, 'o', MDFR_NONE, modal_o);
    bind(context, 'p', MDFR_NONE, modal_p);
    bind(context, 'q', MDFR_NONE, modal_q);
    bind(context, 'r', MDFR_NONE, modal_r);
    bind(context, 's', MDFR_NONE, modal_s);
    bind(context, 't', MDFR_NONE, modal_t);
    bind(context, 'u', MDFR_NONE, modal_u);
    bind(context, 'v', MDFR_NONE, modal_v);
    bind(context, 'w', MDFR_NONE, modal_w);
    bind(context, 'x', MDFR_NONE, modal_x);
    bind(context, 'y', MDFR_NONE, modal_y);
    bind(context, 'z', MDFR_NONE, modal_z);

    bind(context, '1', MDFR_NONE, modal_1);
    bind(context, '2', MDFR_NONE, modal_2);
    bind(context, '3', MDFR_NONE, modal_3);
    bind(context, '4', MDFR_NONE, modal_4);
    bind(context, '5', MDFR_NONE, modal_5);
    bind(context, '6', MDFR_NONE, modal_6);
    bind(context, '7', MDFR_NONE, modal_7);
    bind(context, '8', MDFR_NONE, modal_8);
    bind(context, '9', MDFR_NONE, modal_9);
    bind(context, '0', MDFR_NONE, modal_0);
    bind(context, '-', MDFR_NONE, modal_minus);
    bind(context, '=', MDFR_NONE, modal_equals);

    bind(context, key_back, MDFR_NONE, modal_backspace);
    bind(context, key_up, MDFR_NONE, modal_up);
    bind(context, key_down, MDFR_NONE, modal_down);
    bind(context, key_left, MDFR_NONE, modal_left);
    bind(context, key_right, MDFR_NONE, modal_right);
    bind(context, key_del, MDFR_NONE, modal_delete);
    bind(context, key_home, MDFR_NONE, modal_home);
    bind(context, key_end, MDFR_NONE, modal_end);
    bind(context, key_page_up, MDFR_NONE, modal_page_up);
    bind(context, key_page_down, MDFR_NONE, modal_page_down);
    bind(context, '\t', MDFR_NONE, modal_tab);
//    bind(context, key_esc, MDFR_NONE, modal_escape);

    end_map(context);
}
