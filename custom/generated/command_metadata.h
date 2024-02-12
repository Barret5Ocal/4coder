#if !defined(META_PASS)
#define command_id(c) (fcoder_metacmd_ID_##c)
#define command_metadata(c) (&fcoder_metacmd_table[command_id(c)])
#define command_metadata_by_id(id) (&fcoder_metacmd_table[id])
#define command_one_past_last_id 271
#if defined(CUSTOM_COMMAND_SIG)
#define PROC_LINKS(x,y) x
#else
#define PROC_LINKS(x,y) y
#endif
#if defined(CUSTOM_COMMAND_SIG)
CUSTOM_COMMAND_SIG(allow_mouse);
CUSTOM_COMMAND_SIG(auto_indent_line_at_cursor);
CUSTOM_COMMAND_SIG(auto_indent_range);
CUSTOM_COMMAND_SIG(auto_indent_whole_file);
CUSTOM_COMMAND_SIG(b50_rg);
CUSTOM_COMMAND_SIG(backspace_alpha_numeric_boundary);
CUSTOM_COMMAND_SIG(backspace_char);
CUSTOM_COMMAND_SIG(basic_change_active_panel);
CUSTOM_COMMAND_SIG(begin_clipboard_collection_mode);
CUSTOM_COMMAND_SIG(build_in_build_panel);
CUSTOM_COMMAND_SIG(build_search);
CUSTOM_COMMAND_SIG(center_view);
CUSTOM_COMMAND_SIG(change_active_panel);
CUSTOM_COMMAND_SIG(change_active_panel_backwards);
CUSTOM_COMMAND_SIG(change_to_build_panel);
CUSTOM_COMMAND_SIG(clean_all_lines);
CUSTOM_COMMAND_SIG(clean_trailing_whitespace);
CUSTOM_COMMAND_SIG(clear_all_themes);
CUSTOM_COMMAND_SIG(clear_clipboard);
CUSTOM_COMMAND_SIG(click_set_cursor);
CUSTOM_COMMAND_SIG(click_set_cursor_and_mark);
CUSTOM_COMMAND_SIG(click_set_cursor_if_lbutton);
CUSTOM_COMMAND_SIG(click_set_mark);
CUSTOM_COMMAND_SIG(clipboard_record_clip);
CUSTOM_COMMAND_SIG(close_all_code);
CUSTOM_COMMAND_SIG(close_build_panel);
CUSTOM_COMMAND_SIG(close_panel);
CUSTOM_COMMAND_SIG(command_documentation);
CUSTOM_COMMAND_SIG(command_lister);
CUSTOM_COMMAND_SIG(comment_line);
CUSTOM_COMMAND_SIG(comment_line_toggle);
CUSTOM_COMMAND_SIG(copy);
CUSTOM_COMMAND_SIG(cursor_mark_swap);
CUSTOM_COMMAND_SIG(custom_api_documentation);
CUSTOM_COMMAND_SIG(cut);
CUSTOM_COMMAND_SIG(decrease_face_size);
CUSTOM_COMMAND_SIG(default_file_externally_modified);
CUSTOM_COMMAND_SIG(default_startup);
CUSTOM_COMMAND_SIG(default_try_exit);
CUSTOM_COMMAND_SIG(default_view_input_handler);
CUSTOM_COMMAND_SIG(delete_alpha_numeric_boundary);
CUSTOM_COMMAND_SIG(delete_char);
CUSTOM_COMMAND_SIG(delete_current_scope);
CUSTOM_COMMAND_SIG(delete_file_query);
CUSTOM_COMMAND_SIG(delete_line);
CUSTOM_COMMAND_SIG(delete_range);
CUSTOM_COMMAND_SIG(display_key_codes);
CUSTOM_COMMAND_SIG(display_text_input);
CUSTOM_COMMAND_SIG(double_backspace);
CUSTOM_COMMAND_SIG(duplicate_line);
CUSTOM_COMMAND_SIG(execute_any_cli);
CUSTOM_COMMAND_SIG(execute_previous_cli);
CUSTOM_COMMAND_SIG(exit_4coder);
CUSTOM_COMMAND_SIG(go_to_user_directory);
CUSTOM_COMMAND_SIG(goto_beginning_of_file);
CUSTOM_COMMAND_SIG(goto_end_of_file);
CUSTOM_COMMAND_SIG(goto_first_jump);
CUSTOM_COMMAND_SIG(goto_first_jump_same_panel_sticky);
CUSTOM_COMMAND_SIG(goto_jump_at_cursor);
CUSTOM_COMMAND_SIG(goto_jump_at_cursor_same_panel);
CUSTOM_COMMAND_SIG(goto_line);
CUSTOM_COMMAND_SIG(goto_next_jump);
CUSTOM_COMMAND_SIG(goto_next_jump_no_skips);
CUSTOM_COMMAND_SIG(goto_prev_jump);
CUSTOM_COMMAND_SIG(goto_prev_jump_no_skips);
CUSTOM_COMMAND_SIG(hide_filebar);
CUSTOM_COMMAND_SIG(hide_scrollbar);
CUSTOM_COMMAND_SIG(hit_sfx);
CUSTOM_COMMAND_SIG(hms_demo_tutorial);
CUSTOM_COMMAND_SIG(if0_off);
CUSTOM_COMMAND_SIG(if_read_only_goto_position);
CUSTOM_COMMAND_SIG(if_read_only_goto_position_same_panel);
CUSTOM_COMMAND_SIG(increase_face_size);
CUSTOM_COMMAND_SIG(interactive_kill_buffer);
CUSTOM_COMMAND_SIG(interactive_new);
CUSTOM_COMMAND_SIG(interactive_open);
CUSTOM_COMMAND_SIG(interactive_open_or_new);
CUSTOM_COMMAND_SIG(interactive_switch_buffer);
CUSTOM_COMMAND_SIG(jump_to_definition);
CUSTOM_COMMAND_SIG(jump_to_definition_at_cursor);
CUSTOM_COMMAND_SIG(jump_to_last_point);
CUSTOM_COMMAND_SIG(keyboard_macro_finish_recording);
CUSTOM_COMMAND_SIG(keyboard_macro_replay);
CUSTOM_COMMAND_SIG(keyboard_macro_start_recording);
CUSTOM_COMMAND_SIG(kill_buffer);
CUSTOM_COMMAND_SIG(kill_tutorial);
CUSTOM_COMMAND_SIG(left_adjust_view);
CUSTOM_COMMAND_SIG(list_all_functions_all_buffers);
CUSTOM_COMMAND_SIG(list_all_functions_all_buffers_lister);
CUSTOM_COMMAND_SIG(list_all_functions_current_buffer);
CUSTOM_COMMAND_SIG(list_all_functions_current_buffer_lister);
CUSTOM_COMMAND_SIG(list_all_locations);
CUSTOM_COMMAND_SIG(list_all_locations_case_insensitive);
CUSTOM_COMMAND_SIG(list_all_locations_of_identifier);
CUSTOM_COMMAND_SIG(list_all_locations_of_identifier_case_insensitive);
CUSTOM_COMMAND_SIG(list_all_locations_of_selection);
CUSTOM_COMMAND_SIG(list_all_locations_of_selection_case_insensitive);
CUSTOM_COMMAND_SIG(list_all_locations_of_type_definition);
CUSTOM_COMMAND_SIG(list_all_locations_of_type_definition_of_identifier);
CUSTOM_COMMAND_SIG(list_all_substring_locations);
CUSTOM_COMMAND_SIG(list_all_substring_locations_case_insensitive);
CUSTOM_COMMAND_SIG(load_project);
CUSTOM_COMMAND_SIG(load_theme_current_buffer);
CUSTOM_COMMAND_SIG(load_themes_default_folder);
CUSTOM_COMMAND_SIG(load_themes_hot_directory);
CUSTOM_COMMAND_SIG(make_directory_query);
CUSTOM_COMMAND_SIG(miblo_decrement_basic);
CUSTOM_COMMAND_SIG(miblo_decrement_time_stamp);
CUSTOM_COMMAND_SIG(miblo_decrement_time_stamp_minute);
CUSTOM_COMMAND_SIG(miblo_increment_basic);
CUSTOM_COMMAND_SIG(miblo_increment_time_stamp);
CUSTOM_COMMAND_SIG(miblo_increment_time_stamp_minute);
CUSTOM_COMMAND_SIG(mouse_wheel_change_face_size);
CUSTOM_COMMAND_SIG(mouse_wheel_scroll);
CUSTOM_COMMAND_SIG(move_down);
CUSTOM_COMMAND_SIG(move_down_10);
CUSTOM_COMMAND_SIG(move_down_5);
CUSTOM_COMMAND_SIG(move_down_textual);
CUSTOM_COMMAND_SIG(move_down_to_blank_line);
CUSTOM_COMMAND_SIG(move_down_to_blank_line_end);
CUSTOM_COMMAND_SIG(move_down_to_blank_line_skip_whitespace);
CUSTOM_COMMAND_SIG(move_left);
CUSTOM_COMMAND_SIG(move_left_alpha_numeric_boundary);
CUSTOM_COMMAND_SIG(move_left_alpha_numeric_or_camel_boundary);
CUSTOM_COMMAND_SIG(move_left_token_boundary);
CUSTOM_COMMAND_SIG(move_left_whitespace_boundary);
CUSTOM_COMMAND_SIG(move_left_whitespace_or_token_boundary);
CUSTOM_COMMAND_SIG(move_line_down);
CUSTOM_COMMAND_SIG(move_line_up);
CUSTOM_COMMAND_SIG(move_right);
CUSTOM_COMMAND_SIG(move_right_alpha_numeric_boundary);
CUSTOM_COMMAND_SIG(move_right_alpha_numeric_or_camel_boundary);
CUSTOM_COMMAND_SIG(move_right_token_boundary);
CUSTOM_COMMAND_SIG(move_right_whitespace_boundary);
CUSTOM_COMMAND_SIG(move_right_whitespace_or_token_boundary);
CUSTOM_COMMAND_SIG(move_up);
CUSTOM_COMMAND_SIG(move_up_10);
CUSTOM_COMMAND_SIG(move_up_5);
CUSTOM_COMMAND_SIG(move_up_to_blank_line);
CUSTOM_COMMAND_SIG(move_up_to_blank_line_end);
CUSTOM_COMMAND_SIG(move_up_to_blank_line_skip_whitespace);
CUSTOM_COMMAND_SIG(multi_paste);
CUSTOM_COMMAND_SIG(multi_paste_interactive);
CUSTOM_COMMAND_SIG(multi_paste_interactive_quick);
CUSTOM_COMMAND_SIG(music_start);
CUSTOM_COMMAND_SIG(music_stop);
CUSTOM_COMMAND_SIG(open_all_code);
CUSTOM_COMMAND_SIG(open_all_code_recursive);
CUSTOM_COMMAND_SIG(open_file_in_quotes);
CUSTOM_COMMAND_SIG(open_in_other);
CUSTOM_COMMAND_SIG(open_long_braces);
CUSTOM_COMMAND_SIG(open_long_braces_break);
CUSTOM_COMMAND_SIG(open_long_braces_semicolon);
CUSTOM_COMMAND_SIG(open_matching_file_cpp);
CUSTOM_COMMAND_SIG(open_panel_hsplit);
CUSTOM_COMMAND_SIG(open_panel_vsplit);
CUSTOM_COMMAND_SIG(page_down);
CUSTOM_COMMAND_SIG(page_up);
CUSTOM_COMMAND_SIG(paste);
CUSTOM_COMMAND_SIG(paste_and_indent);
CUSTOM_COMMAND_SIG(paste_next);
CUSTOM_COMMAND_SIG(paste_next_and_indent);
CUSTOM_COMMAND_SIG(place_in_scope);
CUSTOM_COMMAND_SIG(play_with_a_counter);
CUSTOM_COMMAND_SIG(profile_clear);
CUSTOM_COMMAND_SIG(profile_disable);
CUSTOM_COMMAND_SIG(profile_enable);
CUSTOM_COMMAND_SIG(profile_inspect);
CUSTOM_COMMAND_SIG(project_command_F1);
CUSTOM_COMMAND_SIG(project_command_F10);
CUSTOM_COMMAND_SIG(project_command_F11);
CUSTOM_COMMAND_SIG(project_command_F12);
CUSTOM_COMMAND_SIG(project_command_F13);
CUSTOM_COMMAND_SIG(project_command_F14);
CUSTOM_COMMAND_SIG(project_command_F15);
CUSTOM_COMMAND_SIG(project_command_F16);
CUSTOM_COMMAND_SIG(project_command_F2);
CUSTOM_COMMAND_SIG(project_command_F3);
CUSTOM_COMMAND_SIG(project_command_F4);
CUSTOM_COMMAND_SIG(project_command_F5);
CUSTOM_COMMAND_SIG(project_command_F6);
CUSTOM_COMMAND_SIG(project_command_F7);
CUSTOM_COMMAND_SIG(project_command_F8);
CUSTOM_COMMAND_SIG(project_command_F9);
CUSTOM_COMMAND_SIG(project_command_lister);
CUSTOM_COMMAND_SIG(project_fkey_command);
CUSTOM_COMMAND_SIG(project_go_to_root_directory);
CUSTOM_COMMAND_SIG(project_reprint);
CUSTOM_COMMAND_SIG(query_replace);
CUSTOM_COMMAND_SIG(query_replace_identifier);
CUSTOM_COMMAND_SIG(query_replace_selection);
CUSTOM_COMMAND_SIG(quick_swap_buffer);
CUSTOM_COMMAND_SIG(redo);
CUSTOM_COMMAND_SIG(redo_all_buffers);
CUSTOM_COMMAND_SIG(rename_file_query);
CUSTOM_COMMAND_SIG(reopen);
CUSTOM_COMMAND_SIG(replace_in_all_buffers);
CUSTOM_COMMAND_SIG(replace_in_buffer);
CUSTOM_COMMAND_SIG(replace_in_range);
CUSTOM_COMMAND_SIG(reverse_search);
CUSTOM_COMMAND_SIG(reverse_search_identifier);
CUSTOM_COMMAND_SIG(save);
CUSTOM_COMMAND_SIG(save_all_dirty_buffers);
CUSTOM_COMMAND_SIG(save_to_query);
CUSTOM_COMMAND_SIG(search);
CUSTOM_COMMAND_SIG(search_identifier);
CUSTOM_COMMAND_SIG(seek_beginning_of_line);
CUSTOM_COMMAND_SIG(seek_beginning_of_textual_line);
CUSTOM_COMMAND_SIG(seek_end_of_line);
CUSTOM_COMMAND_SIG(seek_end_of_textual_line);
CUSTOM_COMMAND_SIG(select_all);
CUSTOM_COMMAND_SIG(select_next_scope_absolute);
CUSTOM_COMMAND_SIG(select_next_scope_after_current);
CUSTOM_COMMAND_SIG(select_prev_scope_absolute);
CUSTOM_COMMAND_SIG(select_prev_top_most_scope);
CUSTOM_COMMAND_SIG(select_surrounding_scope);
CUSTOM_COMMAND_SIG(select_surrounding_scope_maximal);
CUSTOM_COMMAND_SIG(set_eol_mode_from_contents);
CUSTOM_COMMAND_SIG(set_eol_mode_to_binary);
CUSTOM_COMMAND_SIG(set_eol_mode_to_crlf);
CUSTOM_COMMAND_SIG(set_eol_mode_to_lf);
CUSTOM_COMMAND_SIG(set_face_size);
CUSTOM_COMMAND_SIG(set_face_size_this_buffer);
CUSTOM_COMMAND_SIG(set_mark);
CUSTOM_COMMAND_SIG(set_mode_to_notepad_like);
CUSTOM_COMMAND_SIG(set_mode_to_original);
CUSTOM_COMMAND_SIG(setup_build_bat);
CUSTOM_COMMAND_SIG(setup_build_bat_and_sh);
CUSTOM_COMMAND_SIG(setup_build_sh);
CUSTOM_COMMAND_SIG(setup_new_project);
CUSTOM_COMMAND_SIG(show_filebar);
CUSTOM_COMMAND_SIG(show_scrollbar);
CUSTOM_COMMAND_SIG(show_the_log_graph);
CUSTOM_COMMAND_SIG(snipe_backward_whitespace_or_token_boundary);
CUSTOM_COMMAND_SIG(snipe_forward_whitespace_or_token_boundary);
CUSTOM_COMMAND_SIG(snippet_lister);
CUSTOM_COMMAND_SIG(string_repeat);
CUSTOM_COMMAND_SIG(suppress_mouse);
CUSTOM_COMMAND_SIG(swap_panels);
CUSTOM_COMMAND_SIG(theme_lister);
CUSTOM_COMMAND_SIG(to_lowercase);
CUSTOM_COMMAND_SIG(to_uppercase);
CUSTOM_COMMAND_SIG(toggle_filebar);
CUSTOM_COMMAND_SIG(toggle_fps_meter);
CUSTOM_COMMAND_SIG(toggle_fullscreen);
CUSTOM_COMMAND_SIG(toggle_highlight_enclosing_scopes);
CUSTOM_COMMAND_SIG(toggle_highlight_line_at_cursor);
CUSTOM_COMMAND_SIG(toggle_line_numbers);
CUSTOM_COMMAND_SIG(toggle_line_wrap);
CUSTOM_COMMAND_SIG(toggle_mouse);
CUSTOM_COMMAND_SIG(toggle_paren_matching_helper);
CUSTOM_COMMAND_SIG(toggle_show_whitespace);
CUSTOM_COMMAND_SIG(toggle_virtual_whitespace);
CUSTOM_COMMAND_SIG(tutorial_maximize);
CUSTOM_COMMAND_SIG(tutorial_minimize);
CUSTOM_COMMAND_SIG(uncomment_line);
CUSTOM_COMMAND_SIG(undo);
CUSTOM_COMMAND_SIG(undo_all_buffers);
CUSTOM_COMMAND_SIG(view_buffer_other_panel);
CUSTOM_COMMAND_SIG(view_jump_list_with_lister);
CUSTOM_COMMAND_SIG(word_complete);
CUSTOM_COMMAND_SIG(word_complete_drop_down);
CUSTOM_COMMAND_SIG(write_block);
CUSTOM_COMMAND_SIG(write_hack);
CUSTOM_COMMAND_SIG(write_note);
CUSTOM_COMMAND_SIG(write_space);
CUSTOM_COMMAND_SIG(write_text_and_auto_indent);
CUSTOM_COMMAND_SIG(write_text_input);
CUSTOM_COMMAND_SIG(write_todo);
CUSTOM_COMMAND_SIG(write_underscore);
CUSTOM_COMMAND_SIG(write_zero_struct);
#endif
struct Command_Metadata{
PROC_LINKS(Custom_Command_Function, void) *proc;
b32 is_ui;
char *name;
i32 name_len;
char *description;
i32 description_len;
char *source_name;
i32 source_name_len;
i32 line_number;
};
static Command_Metadata fcoder_metacmd_table[271] = {
{ PROC_LINKS(allow_mouse, 0), false, "allow_mouse", 11, "Shows the mouse and causes all mouse input to be processed normally.", 68, "G:\\projects\\4ed\\code\\custom\\4coder_default_framework.cpp", 56, 481 },
{ PROC_LINKS(auto_indent_line_at_cursor, 0), false, "auto_indent_line_at_cursor", 26, "Auto-indents the line on which the cursor sits.", 47, "G:\\projects\\4ed\\code\\custom\\4coder_auto_indent.cpp", 50, 420 },
{ PROC_LINKS(auto_indent_range, 0), false, "auto_indent_range", 17, "Auto-indents the range between the cursor and the mark.", 55, "G:\\projects\\4ed\\code\\custom\\4coder_auto_indent.cpp", 50, 430 },
{ PROC_LINKS(auto_indent_whole_file, 0), false, "auto_indent_whole_file", 22, "Audo-indents the entire current buffer.", 39, "G:\\projects\\4ed\\code\\custom\\4coder_auto_indent.cpp", 50, 411 },
{ PROC_LINKS(b50_rg, 0), false, "b50_rg", 6, "Atempt to make rip grep work", 28, "G:\\projects\\4ed\\code\\custom\\4coder_search.cpp", 45, 694 },
{ PROC_LINKS(backspace_alpha_numeric_boundary, 0), false, "backspace_alpha_numeric_boundary", 32, "Delete characters between the cursor position and the first alphanumeric boundary to the left.", 94, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 154 },
{ PROC_LINKS(backspace_char, 0), false, "backspace_char", 14, "Deletes the character to the left of the cursor.", 48, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 96 },
{ PROC_LINKS(basic_change_active_panel, 0), false, "basic_change_active_panel", 25, "Change the currently active panel, moving to the panel with the next highest view_id.  Will not skipe the build panel if it is open.", 132, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 680 },
{ PROC_LINKS(begin_clipboard_collection_mode, 0), true, "begin_clipboard_collection_mode", 31, "Allows the user to copy multiple strings from other applications before switching to 4coder and pasting them all.", 113, "G:\\projects\\4ed\\code\\custom\\4coder_clipboard.cpp", 48, 71 },
{ PROC_LINKS(build_in_build_panel, 0), false, "build_in_build_panel", 20, "Looks for a build.bat, build.sh, or makefile in the current and parent directories.  Runs the first that it finds and prints the output to *compilation*.  Puts the *compilation* buffer in a panel at the footer of the current view.", 230, "G:\\projects\\4ed\\code\\custom\\4coder_build_commands.cpp", 53, 160 },
{ PROC_LINKS(build_search, 0), false, "build_search", 12, "Looks for a build.bat, build.sh, or makefile in the current and parent directories.  Runs the first that it finds and prints the output to *compilation*.", 153, "G:\\projects\\4ed\\code\\custom\\4coder_build_commands.cpp", 53, 123 },
{ PROC_LINKS(center_view, 0), false, "center_view", 11, "Centers the view vertically on the line on which the cursor sits.", 65, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 197 },
{ PROC_LINKS(change_active_panel, 0), false, "change_active_panel", 19, "Change the currently active panel, moving to the panel with the next highest view_id.", 85, "G:\\projects\\4ed\\code\\custom\\4coder_default_framework.cpp", 56, 356 },
{ PROC_LINKS(change_active_panel_backwards, 0), false, "change_active_panel_backwards", 29, "Change the currently active panel, moving to the panel with the next lowest view_id.", 84, "G:\\projects\\4ed\\code\\custom\\4coder_default_framework.cpp", 56, 362 },
{ PROC_LINKS(change_to_build_panel, 0), false, "change_to_build_panel", 21, "If the special build panel is open, makes the build panel the active panel.", 75, "G:\\projects\\4ed\\code\\custom\\4coder_build_commands.cpp", 53, 181 },
{ PROC_LINKS(clean_all_lines, 0), false, "clean_all_lines", 15, "Removes trailing whitespace from all lines and removes all blank lines in the current buffer.", 93, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 660 },
{ PROC_LINKS(clean_trailing_whitespace, 0), false, "clean_trailing_whitespace", 25, "Removes trailing whitespace from all lines in the current buffer.", 65, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 669 },
{ PROC_LINKS(clear_all_themes, 0), false, "clear_all_themes", 16, "Clear the theme list", 20, "G:\\projects\\4ed\\code\\custom\\4coder_default_framework.cpp", 56, 565 },
{ PROC_LINKS(clear_clipboard, 0), false, "clear_clipboard", 15, "Clears the history of the clipboard", 35, "G:\\projects\\4ed\\code\\custom\\4coder_clipboard.cpp", 48, 221 },
{ PROC_LINKS(click_set_cursor, 0), false, "click_set_cursor", 16, "Sets the cursor position to the mouse position.", 47, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 235 },
{ PROC_LINKS(click_set_cursor_and_mark, 0), false, "click_set_cursor_and_mark", 25, "Sets the cursor position and mark to the mouse position.", 56, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 225 },
{ PROC_LINKS(click_set_cursor_if_lbutton, 0), false, "click_set_cursor_if_lbutton", 27, "If the mouse left button is pressed, sets the cursor position to the mouse position.", 84, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 245 },
{ PROC_LINKS(click_set_mark, 0), false, "click_set_mark", 14, "Sets the mark position to the mouse position.", 45, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 258 },
{ PROC_LINKS(clipboard_record_clip, 0), false, "clipboard_record_clip", 21, "In response to a new clipboard contents events, saves the new clip onto the clipboard history", 93, "G:\\projects\\4ed\\code\\custom\\4coder_clipboard.cpp", 48, 7 },
{ PROC_LINKS(close_all_code, 0), false, "close_all_code", 14, "Closes any buffer with a filename ending with an extension configured to be recognized as a code file type.", 107, "G:\\projects\\4ed\\code\\custom\\4coder_project_commands.cpp", 55, 885 },
{ PROC_LINKS(close_build_panel, 0), false, "close_build_panel", 17, "If the special build panel is open, closes it.", 46, "G:\\projects\\4ed\\code\\custom\\4coder_build_commands.cpp", 53, 175 },
{ PROC_LINKS(close_panel, 0), false, "close_panel", 11, "Closes the currently active panel if it is not the only panel open.", 67, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 688 },
{ PROC_LINKS(command_documentation, 0), true, "command_documentation", 21, "Prompts the user to select a command then loads a doc buffer for that item", 74, "G:\\projects\\4ed\\code\\custom\\4coder_docs.cpp", 43, 190 },
{ PROC_LINKS(command_lister, 0), true, "command_lister", 14, "Opens an interactive list of all registered commands.", 53, "G:\\projects\\4ed\\code\\custom\\4coder_lists.cpp", 44, 761 },
{ PROC_LINKS(comment_line, 0), false, "comment_line", 12, "Insert '//' at the beginning of the line after leading whitespace.", 66, "G:\\projects\\4ed\\code\\custom\\4coder_combined_write_commands.cpp", 62, 125 },
{ PROC_LINKS(comment_line_toggle, 0), false, "comment_line_toggle", 19, "Turns uncommented lines into commented lines and vice versa for comments starting with '//'.", 92, "G:\\projects\\4ed\\code\\custom\\4coder_combined_write_commands.cpp", 62, 149 },
{ PROC_LINKS(copy, 0), false, "copy", 4, "Copy the text in the range from the cursor to the mark onto the clipboard.", 74, "G:\\projects\\4ed\\code\\custom\\4coder_clipboard.cpp", 48, 110 },
{ PROC_LINKS(cursor_mark_swap, 0), false, "cursor_mark_swap", 16, "Swaps the position of the cursor and the mark.", 46, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 124 },
{ PROC_LINKS(custom_api_documentation, 0), true, "custom_api_documentation", 24, "Prompts the user to select a Custom API item then loads a doc buffer for that item", 82, "G:\\projects\\4ed\\code\\custom\\4coder_docs.cpp", 43, 175 },
{ PROC_LINKS(cut, 0), false, "cut", 3, "Cut the text in the range from the cursor to the mark onto the clipboard.", 73, "G:\\projects\\4ed\\code\\custom\\4coder_clipboard.cpp", 48, 119 },
{ PROC_LINKS(decrease_face_size, 0), false, "decrease_face_size", 18, "Decrease the size of the face used by the current buffer.", 57, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 771 },
{ PROC_LINKS(default_file_externally_modified, 0), false, "default_file_externally_modified", 32, "Notes the external modification of attached files by printing a message.", 72, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 2079 },
{ PROC_LINKS(default_startup, 0), false, "default_startup", 15, "Default command for responding to a startup event", 49, "G:\\projects\\4ed\\code\\custom\\4coder_default_hooks.cpp", 52, 53 },
{ PROC_LINKS(default_try_exit, 0), false, "default_try_exit", 16, "Default command for responding to a try-exit event", 50, "G:\\projects\\4ed\\code\\custom\\4coder_default_hooks.cpp", 52, 91 },
{ PROC_LINKS(default_view_input_handler, 0), false, "default_view_input_handler", 26, "Input consumption loop for default view behavior", 48, "G:\\projects\\4ed\\code\\custom\\4coder_default_hooks.cpp", 52, 135 },
{ PROC_LINKS(delete_alpha_numeric_boundary, 0), false, "delete_alpha_numeric_boundary", 29, "Delete characters between the cursor position and the first alphanumeric boundary to the right.", 95, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 162 },
{ PROC_LINKS(delete_char, 0), false, "delete_char", 11, "Deletes the character to the right of the cursor.", 49, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 79 },
{ PROC_LINKS(delete_current_scope, 0), false, "delete_current_scope", 20, "Deletes the braces surrounding the currently selected scope.  Leaves the contents within the scope.", 99, "G:\\projects\\4ed\\code\\custom\\4coder_scope_commands.cpp", 53, 112 },
{ PROC_LINKS(delete_file_query, 0), false, "delete_file_query", 17, "Deletes the file of the current buffer if 4coder has the appropriate access rights. Will ask the user for confirmation first.", 125, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 1397 },
{ PROC_LINKS(delete_line, 0), false, "delete_line", 11, "Delete the line the on which the cursor sits.", 45, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 1569 },
{ PROC_LINKS(delete_range, 0), false, "delete_range", 12, "Deletes the text in the range between the cursor and the mark.", 62, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 134 },
{ PROC_LINKS(display_key_codes, 0), false, "display_key_codes", 17, "Example of input handling loop", 30, "G:\\projects\\4ed\\code\\custom\\4coder_examples.cpp", 47, 90 },
{ PROC_LINKS(display_text_input, 0), false, "display_text_input", 18, "Example of to_writable and leave_current_input_unhandled", 56, "G:\\projects\\4ed\\code\\custom\\4coder_examples.cpp", 47, 137 },
{ PROC_LINKS(double_backspace, 0), false, "double_backspace", 16, "Example of history group helpers", 32, "G:\\projects\\4ed\\code\\custom\\4coder_examples.cpp", 47, 10 },
{ PROC_LINKS(duplicate_line, 0), false, "duplicate_line", 14, "Create a copy of the line on which the cursor sits.", 51, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 1555 },
{ PROC_LINKS(execute_any_cli, 0), false, "execute_any_cli", 15, "Queries for an output buffer name and system command, runs the system command as a CLI and prints the output to the specified buffer.", 133, "G:\\projects\\4ed\\code\\custom\\4coder_cli_command.cpp", 50, 22 },
{ PROC_LINKS(execute_previous_cli, 0), false, "execute_previous_cli", 20, "If the command execute_any_cli has already been used, this will execute a CLI reusing the most recent buffer name and command.", 126, "G:\\projects\\4ed\\code\\custom\\4coder_cli_command.cpp", 50, 7 },
{ PROC_LINKS(exit_4coder, 0), false, "exit_4coder", 11, "Attempts to close 4coder.", 25, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 860 },
{ PROC_LINKS(go_to_user_directory, 0), false, "go_to_user_directory", 20, "Go to the 4coder user directory", 31, "G:\\projects\\4ed\\code\\custom\\4coder_config.cpp", 45, 1655 },
{ PROC_LINKS(goto_beginning_of_file, 0), false, "goto_beginning_of_file", 22, "Sets the cursor to the beginning of the file.", 45, "G:\\projects\\4ed\\code\\custom\\4coder_helper.cpp", 45, 2258 },
{ PROC_LINKS(goto_end_of_file, 0), false, "goto_end_of_file", 16, "Sets the cursor to the end of the file.", 39, "G:\\projects\\4ed\\code\\custom\\4coder_helper.cpp", 45, 2266 },
{ PROC_LINKS(goto_first_jump, 0), false, "goto_first_jump", 15, "If a buffer containing jump locations has been locked in, goes to the first jump in the buffer.", 95, "G:\\projects\\4ed\\code\\custom\\4coder_jump_sticky.cpp", 50, 525 },
{ PROC_LINKS(goto_first_jump_same_panel_sticky, 0), false, "goto_first_jump_same_panel_sticky", 33, "If a buffer containing jump locations has been locked in, goes to the first jump in the buffer and views the buffer in the panel where the jump list was.", 153, "G:\\projects\\4ed\\code\\custom\\4coder_jump_sticky.cpp", 50, 542 },
{ PROC_LINKS(goto_jump_at_cursor, 0), false, "goto_jump_at_cursor", 19, "If the cursor is found to be on a jump location, parses the jump location and brings up the file and position in another view and changes the active panel to the view containing the jump.", 187, "G:\\projects\\4ed\\code\\custom\\4coder_jump_sticky.cpp", 50, 348 },
{ PROC_LINKS(goto_jump_at_cursor_same_panel, 0), false, "goto_jump_at_cursor_same_panel", 30, "If the cursor is found to be on a jump location, parses the jump location and brings up the file and position in this view, losing the compilation output or jump list.", 167, "G:\\projects\\4ed\\code\\custom\\4coder_jump_sticky.cpp", 50, 375 },
{ PROC_LINKS(goto_line, 0), false, "goto_line", 9, "Queries the user for a number, and jumps the cursor to the corresponding line.", 78, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 868 },
{ PROC_LINKS(goto_next_jump, 0), false, "goto_next_jump", 14, "If a buffer containing jump locations has been locked in, goes to the next jump in the buffer, skipping sub jump locations.", 123, "G:\\projects\\4ed\\code\\custom\\4coder_jump_sticky.cpp", 50, 464 },
{ PROC_LINKS(goto_next_jump_no_skips, 0), false, "goto_next_jump_no_skips", 23, "If a buffer containing jump locations has been locked in, goes to the next jump in the buffer, and does not skip sub jump locations.", 132, "G:\\projects\\4ed\\code\\custom\\4coder_jump_sticky.cpp", 50, 494 },
{ PROC_LINKS(goto_prev_jump, 0), false, "goto_prev_jump", 14, "If a buffer containing jump locations has been locked in, goes to the previous jump in the buffer, skipping sub jump locations.", 127, "G:\\projects\\4ed\\code\\custom\\4coder_jump_sticky.cpp", 50, 481 },
{ PROC_LINKS(goto_prev_jump_no_skips, 0), false, "goto_prev_jump_no_skips", 23, "If a buffer containing jump locations has been locked in, goes to the previous jump in the buffer, and does not skip sub jump locations.", 136, "G:\\projects\\4ed\\code\\custom\\4coder_jump_sticky.cpp", 50, 511 },
{ PROC_LINKS(hide_filebar, 0), false, "hide_filebar", 12, "Sets the current view to hide it's filebar.", 43, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 718 },
{ PROC_LINKS(hide_scrollbar, 0), false, "hide_scrollbar", 14, "Sets the current view to hide it's scrollbar.", 45, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 704 },
{ PROC_LINKS(hit_sfx, 0), false, "hit_sfx", 7, "Play the hit sound effect", 25, "G:\\projects\\4ed\\code\\custom\\4coder_examples.cpp", 47, 240 },
{ PROC_LINKS(hms_demo_tutorial, 0), false, "hms_demo_tutorial", 17, "Tutorial for built in 4coder bindings and features.", 51, "G:\\projects\\4ed\\code\\custom\\4coder_tutorial.cpp", 47, 869 },
{ PROC_LINKS(if0_off, 0), false, "if0_off", 7, "Surround the range between the cursor and mark with an '#if 0' and an '#endif'", 78, "G:\\projects\\4ed\\code\\custom\\4coder_combined_write_commands.cpp", 62, 70 },
{ PROC_LINKS(if_read_only_goto_position, 0), false, "if_read_only_goto_position", 26, "If the buffer in the active view is writable, inserts a character, otherwise performs goto_jump_at_cursor.", 106, "G:\\projects\\4ed\\code\\custom\\4coder_jump_sticky.cpp", 50, 564 },
{ PROC_LINKS(if_read_only_goto_position_same_panel, 0), false, "if_read_only_goto_position_same_panel", 37, "If the buffer in the active view is writable, inserts a character, otherwise performs goto_jump_at_cursor_same_panel.", 117, "G:\\projects\\4ed\\code\\custom\\4coder_jump_sticky.cpp", 50, 581 },
{ PROC_LINKS(increase_face_size, 0), false, "increase_face_size", 18, "Increase the size of the face used by the current buffer.", 57, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 760 },
{ PROC_LINKS(interactive_kill_buffer, 0), true, "interactive_kill_buffer", 23, "Interactively kill an open buffer.", 34, "G:\\projects\\4ed\\code\\custom\\4coder_lists.cpp", 44, 521 },
{ PROC_LINKS(interactive_new, 0), true, "interactive_new", 15, "Interactively creates a new file.", 33, "G:\\projects\\4ed\\code\\custom\\4coder_lists.cpp", 44, 661 },
{ PROC_LINKS(interactive_open, 0), true, "interactive_open", 16, "Interactively opens a file.", 27, "G:\\projects\\4ed\\code\\custom\\4coder_lists.cpp", 44, 715 },
{ PROC_LINKS(interactive_open_or_new, 0), true, "interactive_open_or_new", 23, "Interactively open a file out of the file system.", 49, "G:\\projects\\4ed\\code\\custom\\4coder_lists.cpp", 44, 612 },
{ PROC_LINKS(interactive_switch_buffer, 0), true, "interactive_switch_buffer", 25, "Interactively switch to an open buffer.", 39, "G:\\projects\\4ed\\code\\custom\\4coder_lists.cpp", 44, 511 },
{ PROC_LINKS(jump_to_definition, 0), true, "jump_to_definition", 18, "List all definitions in the code index and jump to one chosen by the user.", 74, "G:\\projects\\4ed\\code\\custom\\4coder_code_index_listers.cpp", 57, 12 },
{ PROC_LINKS(jump_to_definition_at_cursor, 0), true, "jump_to_definition_at_cursor", 28, "Jump to the first definition in the code index matching an identifier at the cursor", 83, "G:\\projects\\4ed\\code\\custom\\4coder_code_index_listers.cpp", 57, 68 },
{ PROC_LINKS(jump_to_last_point, 0), false, "jump_to_last_point", 18, "Read from the top of the point stack and jump there; if already there pop the top and go to the next option", 107, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 1350 },
{ PROC_LINKS(keyboard_macro_finish_recording, 0), false, "keyboard_macro_finish_recording", 31, "Stop macro recording, do nothing if macro recording is not already started", 74, "G:\\projects\\4ed\\code\\custom\\4coder_keyboard_macro.cpp", 53, 54 },
{ PROC_LINKS(keyboard_macro_replay, 0), false, "keyboard_macro_replay", 21, "Replay the most recently recorded keyboard macro", 48, "G:\\projects\\4ed\\code\\custom\\4coder_keyboard_macro.cpp", 53, 77 },
{ PROC_LINKS(keyboard_macro_start_recording, 0), false, "keyboard_macro_start_recording", 30, "Start macro recording, do nothing if macro recording is already started", 71, "G:\\projects\\4ed\\code\\custom\\4coder_keyboard_macro.cpp", 53, 41 },
{ PROC_LINKS(kill_buffer, 0), false, "kill_buffer", 11, "Kills the current buffer.", 25, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 1740 },
{ PROC_LINKS(kill_tutorial, 0), false, "kill_tutorial", 13, "If there is an active tutorial, kill it.", 40, "G:\\projects\\4ed\\code\\custom\\4coder_tutorial.cpp", 47, 9 },
{ PROC_LINKS(left_adjust_view, 0), false, "left_adjust_view", 16, "Sets the left size of the view near the x position of the cursor.", 65, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 212 },
{ PROC_LINKS(list_all_functions_all_buffers, 0), false, "list_all_functions_all_buffers", 30, "Creates a jump list of lines from all buffers that appear to define or declare functions.", 89, "G:\\projects\\4ed\\code\\custom\\4coder_function_list.cpp", 52, 296 },
{ PROC_LINKS(list_all_functions_all_buffers_lister, 0), true, "list_all_functions_all_buffers_lister", 37, "Creates a lister of locations that look like function definitions and declarations all buffers.", 95, "G:\\projects\\4ed\\code\\custom\\4coder_function_list.cpp", 52, 302 },
{ PROC_LINKS(list_all_functions_current_buffer, 0), false, "list_all_functions_current_buffer", 33, "Creates a jump list of lines of the current buffer that appear to define or declare functions.", 94, "G:\\projects\\4ed\\code\\custom\\4coder_function_list.cpp", 52, 268 },
{ PROC_LINKS(list_all_functions_current_buffer_lister, 0), true, "list_all_functions_current_buffer_lister", 40, "Creates a lister of locations that look like function definitions and declarations in the buffer.", 97, "G:\\projects\\4ed\\code\\custom\\4coder_function_list.cpp", 52, 278 },
{ PROC_LINKS(list_all_locations, 0), false, "list_all_locations", 18, "Queries the user for a string and lists all exact case-sensitive matches found in all open buffers.", 99, "G:\\projects\\4ed\\code\\custom\\4coder_search.cpp", 45, 168 },
{ PROC_LINKS(list_all_locations_case_insensitive, 0), false, "list_all_locations_case_insensitive", 35, "Queries the user for a string and lists all exact case-insensitive matches found in all open buffers.", 101, "G:\\projects\\4ed\\code\\custom\\4coder_search.cpp", 45, 180 },
{ PROC_LINKS(list_all_locations_of_identifier, 0), false, "list_all_locations_of_identifier", 32, "Reads a token or word under the cursor and lists all exact case-sensitive mathces in all open buffers.", 102, "G:\\projects\\4ed\\code\\custom\\4coder_search.cpp", 45, 192 },
{ PROC_LINKS(list_all_locations_of_identifier_case_insensitive, 0), false, "list_all_locations_of_identifier_case_insensitive", 49, "Reads a token or word under the cursor and lists all exact case-insensitive mathces in all open buffers.", 104, "G:\\projects\\4ed\\code\\custom\\4coder_search.cpp", 45, 198 },
{ PROC_LINKS(list_all_locations_of_selection, 0), false, "list_all_locations_of_selection", 31, "Reads the string in the selected range and lists all exact case-sensitive mathces in all open buffers.", 102, "G:\\projects\\4ed\\code\\custom\\4coder_search.cpp", 45, 204 },
{ PROC_LINKS(list_all_locations_of_selection_case_insensitive, 0), false, "list_all_locations_of_selection_case_insensitive", 48, "Reads the string in the selected range and lists all exact case-insensitive mathces in all open buffers.", 104, "G:\\projects\\4ed\\code\\custom\\4coder_search.cpp", 45, 210 },
{ PROC_LINKS(list_all_locations_of_type_definition, 0), false, "list_all_locations_of_type_definition", 37, "Queries user for string, lists all locations of strings that appear to define a type whose name matches the input string.", 121, "G:\\projects\\4ed\\code\\custom\\4coder_search.cpp", 45, 216 },
{ PROC_LINKS(list_all_locations_of_type_definition_of_identifier, 0), false, "list_all_locations_of_type_definition_of_identifier", 51, "Reads a token or word under the cursor and lists all locations of strings that appear to define a type whose name matches it.", 125, "G:\\projects\\4ed\\code\\custom\\4coder_search.cpp", 45, 224 },
{ PROC_LINKS(list_all_substring_locations, 0), false, "list_all_substring_locations", 28, "Queries the user for a string and lists all case-sensitive substring matches found in all open buffers.", 103, "G:\\projects\\4ed\\code\\custom\\4coder_search.cpp", 45, 174 },
{ PROC_LINKS(list_all_substring_locations_case_insensitive, 0), false, "list_all_substring_locations_case_insensitive", 45, "Queries the user for a string and lists all case-insensitive substring matches found in all open buffers.", 105, "G:\\projects\\4ed\\code\\custom\\4coder_search.cpp", 45, 186 },
{ PROC_LINKS(load_project, 0), false, "load_project", 12, "Looks for a project.4coder file in the current directory and tries to load it.  Looks in parent directories until a project file is found or there are no more parents.", 167, "G:\\projects\\4ed\\code\\custom\\4coder_project_commands.cpp", 55, 912 },
{ PROC_LINKS(load_theme_current_buffer, 0), false, "load_theme_current_buffer", 25, "Parse the current buffer as a theme file and add the theme to the theme list. If the buffer has a .4coder postfix in it's name, it is removed when the name is saved.", 165, "G:\\projects\\4ed\\code\\custom\\4coder_config.cpp", 45, 1611 },
{ PROC_LINKS(load_themes_default_folder, 0), false, "load_themes_default_folder", 26, "Loads all the theme files in the default theme folder.", 54, "G:\\projects\\4ed\\code\\custom\\4coder_default_framework.cpp", 56, 535 },
{ PROC_LINKS(load_themes_hot_directory, 0), false, "load_themes_hot_directory", 25, "Loads all the theme files in the current hot directory.", 55, "G:\\projects\\4ed\\code\\custom\\4coder_default_framework.cpp", 56, 554 },
{ PROC_LINKS(make_directory_query, 0), false, "make_directory_query", 20, "Queries the user for a name and creates a new directory with the given name.", 76, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 1509 },
{ PROC_LINKS(miblo_decrement_basic, 0), false, "miblo_decrement_basic", 21, "Decrement an integer under the cursor by one.", 45, "G:\\projects\\4ed\\code\\custom\\4coder_miblo_numbers.cpp", 52, 44 },
{ PROC_LINKS(miblo_decrement_time_stamp, 0), false, "miblo_decrement_time_stamp", 26, "Decrement a time stamp under the cursor by one second. (format [m]m:ss or h:mm:ss", 81, "G:\\projects\\4ed\\code\\custom\\4coder_miblo_numbers.cpp", 52, 237 },
{ PROC_LINKS(miblo_decrement_time_stamp_minute, 0), false, "miblo_decrement_time_stamp_minute", 33, "Decrement a time stamp under the cursor by one minute. (format [m]m:ss or h:mm:ss", 81, "G:\\projects\\4ed\\code\\custom\\4coder_miblo_numbers.cpp", 52, 249 },
{ PROC_LINKS(miblo_increment_basic, 0), false, "miblo_increment_basic", 21, "Increment an integer under the cursor by one.", 45, "G:\\projects\\4ed\\code\\custom\\4coder_miblo_numbers.cpp", 52, 29 },
{ PROC_LINKS(miblo_increment_time_stamp, 0), false, "miblo_increment_time_stamp", 26, "Increment a time stamp under the cursor by one second. (format [m]m:ss or h:mm:ss", 81, "G:\\projects\\4ed\\code\\custom\\4coder_miblo_numbers.cpp", 52, 231 },
{ PROC_LINKS(miblo_increment_time_stamp_minute, 0), false, "miblo_increment_time_stamp_minute", 33, "Increment a time stamp under the cursor by one minute. (format [m]m:ss or h:mm:ss", 81, "G:\\projects\\4ed\\code\\custom\\4coder_miblo_numbers.cpp", 52, 243 },
{ PROC_LINKS(mouse_wheel_change_face_size, 0), false, "mouse_wheel_change_face_size", 28, "Reads the state of the mouse wheel and uses it to either increase or decrease the face size.", 92, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 813 },
{ PROC_LINKS(mouse_wheel_scroll, 0), false, "mouse_wheel_scroll", 18, "Reads the scroll wheel value from the mouse state and scrolls accordingly.", 74, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 268 },
{ PROC_LINKS(move_down, 0), false, "move_down", 9, "Moves the cursor down one line.", 31, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 342 },
{ PROC_LINKS(move_down_10, 0), false, "move_down_10", 12, "Moves the cursor down ten lines.", 32, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 354 },
{ PROC_LINKS(move_down_5, 0), false, "move_down_5", 11, "Moves the cursor down ten lines.", 32, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 366 },
{ PROC_LINKS(move_down_textual, 0), false, "move_down_textual", 17, "Moves down to the next line of actual text, regardless of line wrapping.", 72, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 372 },
{ PROC_LINKS(move_down_to_blank_line, 0), false, "move_down_to_blank_line", 23, "Seeks the cursor down to the next blank line.", 45, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 425 },
{ PROC_LINKS(move_down_to_blank_line_end, 0), false, "move_down_to_blank_line_end", 27, "Seeks the cursor down to the next blank line and places it at the end of the line.", 82, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 449 },
{ PROC_LINKS(move_down_to_blank_line_skip_whitespace, 0), false, "move_down_to_blank_line_skip_whitespace", 39, "Seeks the cursor down to the next blank line and places it at the end of the line.", 82, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 437 },
{ PROC_LINKS(move_left, 0), false, "move_left", 9, "Moves the cursor one character to the left.", 43, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 455 },
{ PROC_LINKS(move_left_alpha_numeric_boundary, 0), false, "move_left_alpha_numeric_boundary", 32, "Seek left for boundary between alphanumeric characters and non-alphanumeric characters.", 87, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 532 },
{ PROC_LINKS(move_left_alpha_numeric_or_camel_boundary, 0), false, "move_left_alpha_numeric_or_camel_boundary", 41, "Seek left for boundary between alphanumeric characters or camel case word and non-alphanumeric characters.", 106, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 546 },
{ PROC_LINKS(move_left_token_boundary, 0), false, "move_left_token_boundary", 24, "Seek left for the next beginning of a token.", 44, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 504 },
{ PROC_LINKS(move_left_whitespace_boundary, 0), false, "move_left_whitespace_boundary", 29, "Seek left for the next boundary between whitespace and non-whitespace.", 70, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 489 },
{ PROC_LINKS(move_left_whitespace_or_token_boundary, 0), false, "move_left_whitespace_or_token_boundary", 38, "Seek left for the next end of a token or boundary between whitespace and non-whitespace.", 88, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 518 },
{ PROC_LINKS(move_line_down, 0), false, "move_line_down", 14, "Swaps the line under the cursor with the line below it, and moves the cursor down with it.", 90, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 1549 },
{ PROC_LINKS(move_line_up, 0), false, "move_line_up", 12, "Swaps the line under the cursor with the line above it, and moves the cursor up with it.", 88, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 1543 },
{ PROC_LINKS(move_right, 0), false, "move_right", 10, "Moves the cursor one character to the right.", 44, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 463 },
{ PROC_LINKS(move_right_alpha_numeric_boundary, 0), false, "move_right_alpha_numeric_boundary", 33, "Seek right for boundary between alphanumeric characters and non-alphanumeric characters.", 88, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 525 },
{ PROC_LINKS(move_right_alpha_numeric_or_camel_boundary, 0), false, "move_right_alpha_numeric_or_camel_boundary", 42, "Seek right for boundary between alphanumeric characters or camel case word and non-alphanumeric characters.", 107, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 539 },
{ PROC_LINKS(move_right_token_boundary, 0), false, "move_right_token_boundary", 25, "Seek right for the next end of a token.", 39, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 497 },
{ PROC_LINKS(move_right_whitespace_boundary, 0), false, "move_right_whitespace_boundary", 30, "Seek right for the next boundary between whitespace and non-whitespace.", 71, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 481 },
{ PROC_LINKS(move_right_whitespace_or_token_boundary, 0), false, "move_right_whitespace_or_token_boundary", 39, "Seek right for the next end of a token or boundary between whitespace and non-whitespace.", 89, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 511 },
{ PROC_LINKS(move_up, 0), false, "move_up", 7, "Moves the cursor up one line.", 29, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 336 },
{ PROC_LINKS(move_up_10, 0), false, "move_up_10", 10, "Moves the cursor up ten lines.", 30, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 348 },
{ PROC_LINKS(move_up_5, 0), false, "move_up_5", 9, "Moves the cursor up ten lines.", 30, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 360 },
{ PROC_LINKS(move_up_to_blank_line, 0), false, "move_up_to_blank_line", 21, "Seeks the cursor up to the next blank line.", 43, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 419 },
{ PROC_LINKS(move_up_to_blank_line_end, 0), false, "move_up_to_blank_line_end", 25, "Seeks the cursor up to the next blank line and places it at the end of the line.", 80, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 443 },
{ PROC_LINKS(move_up_to_blank_line_skip_whitespace, 0), false, "move_up_to_blank_line_skip_whitespace", 37, "Seeks the cursor up to the next blank line and places it at the end of the line.", 80, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 431 },
{ PROC_LINKS(multi_paste, 0), false, "multi_paste", 11, "Paste multiple entries from the clipboard at once", 49, "G:\\projects\\4ed\\code\\custom\\4coder_clipboard.cpp", 48, 229 },
{ PROC_LINKS(multi_paste_interactive, 0), false, "multi_paste_interactive", 23, "Paste multiple lines from the clipboard history, controlled with arrow keys", 75, "G:\\projects\\4ed\\code\\custom\\4coder_clipboard.cpp", 48, 371 },
{ PROC_LINKS(multi_paste_interactive_quick, 0), false, "multi_paste_interactive_quick", 29, "Paste multiple lines from the clipboard history, controlled by inputing the number of lines to paste", 100, "G:\\projects\\4ed\\code\\custom\\4coder_clipboard.cpp", 48, 380 },
{ PROC_LINKS(music_start, 0), false, "music_start", 11, "Starts the music.", 17, "G:\\projects\\4ed\\code\\custom\\4coder_examples.cpp", 47, 213 },
{ PROC_LINKS(music_stop, 0), false, "music_stop", 10, "Stops the music.", 16, "G:\\projects\\4ed\\code\\custom\\4coder_examples.cpp", 47, 234 },
{ PROC_LINKS(open_all_code, 0), false, "open_all_code", 13, "Open all code in the current directory. File types are determined by extensions. An extension is considered code based on the extensions specified in 4coder.config.", 164, "G:\\projects\\4ed\\code\\custom\\4coder_project_commands.cpp", 55, 894 },
{ PROC_LINKS(open_all_code_recursive, 0), false, "open_all_code_recursive", 23, "Works as open_all_code but also runs in all subdirectories.", 59, "G:\\projects\\4ed\\code\\custom\\4coder_project_commands.cpp", 55, 903 },
{ PROC_LINKS(open_file_in_quotes, 0), false, "open_file_in_quotes", 19, "Reads a filename from surrounding '\"' characters and attempts to open the corresponding file.", 94, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 1590 },
{ PROC_LINKS(open_in_other, 0), false, "open_in_other", 13, "Interactively opens a file in the other panel.", 46, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 2073 },
{ PROC_LINKS(open_long_braces, 0), false, "open_long_braces", 16, "At the cursor, insert a '{' and '}' separated by a blank line.", 62, "G:\\projects\\4ed\\code\\custom\\4coder_combined_write_commands.cpp", 62, 46 },
{ PROC_LINKS(open_long_braces_break, 0), false, "open_long_braces_break", 22, "At the cursor, insert a '{' and '}break;' separated by a blank line.", 68, "G:\\projects\\4ed\\code\\custom\\4coder_combined_write_commands.cpp", 62, 62 },
{ PROC_LINKS(open_long_braces_semicolon, 0), false, "open_long_braces_semicolon", 26, "At the cursor, insert a '{' and '};' separated by a blank line.", 63, "G:\\projects\\4ed\\code\\custom\\4coder_combined_write_commands.cpp", 62, 54 },
{ PROC_LINKS(open_matching_file_cpp, 0), false, "open_matching_file_cpp", 22, "If the current file is a *.cpp or *.h, attempts to open the corresponding *.h or *.cpp file in the other view.", 110, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 1673 },
{ PROC_LINKS(open_panel_hsplit, 0), false, "open_panel_hsplit", 17, "Create a new panel by horizontally splitting the active panel.", 62, "G:\\projects\\4ed\\code\\custom\\4coder_default_framework.cpp", 56, 382 },
{ PROC_LINKS(open_panel_vsplit, 0), false, "open_panel_vsplit", 17, "Create a new panel by vertically splitting the active panel.", 60, "G:\\projects\\4ed\\code\\custom\\4coder_default_framework.cpp", 56, 372 },
{ PROC_LINKS(page_down, 0), false, "page_down", 9, "Scrolls the view down one view height and moves the cursor down one view height.", 80, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 390 },
{ PROC_LINKS(page_up, 0), false, "page_up", 7, "Scrolls the view up one view height and moves the cursor up one view height.", 76, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 382 },
{ PROC_LINKS(paste, 0), false, "paste", 5, "At the cursor, insert the text at the top of the clipboard.", 59, "G:\\projects\\4ed\\code\\custom\\4coder_clipboard.cpp", 48, 130 },
{ PROC_LINKS(paste_and_indent, 0), false, "paste_and_indent", 16, "Paste from the top of clipboard and run auto-indent on the newly pasted text.", 77, "G:\\projects\\4ed\\code\\custom\\4coder_clipboard.cpp", 48, 207 },
{ PROC_LINKS(paste_next, 0), false, "paste_next", 10, "If the previous command was paste or paste_next, replaces the paste range with the next text down on the clipboard, otherwise operates as the paste command.", 156, "G:\\projects\\4ed\\code\\custom\\4coder_clipboard.cpp", 48, 164 },
{ PROC_LINKS(paste_next_and_indent, 0), false, "paste_next_and_indent", 21, "Paste the next item on the clipboard and run auto-indent on the newly pasted text.", 82, "G:\\projects\\4ed\\code\\custom\\4coder_clipboard.cpp", 48, 214 },
{ PROC_LINKS(place_in_scope, 0), false, "place_in_scope", 14, "Wraps the code contained in the range between cursor and mark with a new curly brace scope.", 91, "G:\\projects\\4ed\\code\\custom\\4coder_scope_commands.cpp", 53, 106 },
{ PROC_LINKS(play_with_a_counter, 0), false, "play_with_a_counter", 19, "Example of query bar", 20, "G:\\projects\\4ed\\code\\custom\\4coder_examples.cpp", 47, 29 },
{ PROC_LINKS(profile_clear, 0), false, "profile_clear", 13, "Clear all profiling information from 4coder's self profiler.", 60, "G:\\projects\\4ed\\code\\custom\\4coder_profile.cpp", 46, 226 },
{ PROC_LINKS(profile_disable, 0), false, "profile_disable", 15, "Prevent 4coder's self profiler from gathering new profiling information.", 72, "G:\\projects\\4ed\\code\\custom\\4coder_profile.cpp", 46, 219 },
{ PROC_LINKS(profile_enable, 0), false, "profile_enable", 14, "Allow 4coder's self profiler to gather new profiling information.", 65, "G:\\projects\\4ed\\code\\custom\\4coder_profile.cpp", 46, 212 },
{ PROC_LINKS(profile_inspect, 0), true, "profile_inspect", 15, "Inspect all currently collected profiling information in 4coder's self profiler.", 80, "G:\\projects\\4ed\\code\\custom\\4coder_profile_inspect.cpp", 54, 886 },
{ PROC_LINKS(project_command_F1, 0), false, "project_command_F1", 18, "Run the command with index 1", 28, "G:\\projects\\4ed\\code\\custom\\4coder_project_commands.cpp", 55, 1140 },
{ PROC_LINKS(project_command_F10, 0), false, "project_command_F10", 19, "Run the command with index 10", 29, "G:\\projects\\4ed\\code\\custom\\4coder_project_commands.cpp", 55, 1194 },
{ PROC_LINKS(project_command_F11, 0), false, "project_command_F11", 19, "Run the command with index 11", 29, "G:\\projects\\4ed\\code\\custom\\4coder_project_commands.cpp", 55, 1200 },
{ PROC_LINKS(project_command_F12, 0), false, "project_command_F12", 19, "Run the command with index 12", 29, "G:\\projects\\4ed\\code\\custom\\4coder_project_commands.cpp", 55, 1206 },
{ PROC_LINKS(project_command_F13, 0), false, "project_command_F13", 19, "Run the command with index 13", 29, "G:\\projects\\4ed\\code\\custom\\4coder_project_commands.cpp", 55, 1212 },
{ PROC_LINKS(project_command_F14, 0), false, "project_command_F14", 19, "Run the command with index 14", 29, "G:\\projects\\4ed\\code\\custom\\4coder_project_commands.cpp", 55, 1218 },
{ PROC_LINKS(project_command_F15, 0), false, "project_command_F15", 19, "Run the command with index 15", 29, "G:\\projects\\4ed\\code\\custom\\4coder_project_commands.cpp", 55, 1224 },
{ PROC_LINKS(project_command_F16, 0), false, "project_command_F16", 19, "Run the command with index 16", 29, "G:\\projects\\4ed\\code\\custom\\4coder_project_commands.cpp", 55, 1230 },
{ PROC_LINKS(project_command_F2, 0), false, "project_command_F2", 18, "Run the command with index 2", 28, "G:\\projects\\4ed\\code\\custom\\4coder_project_commands.cpp", 55, 1146 },
{ PROC_LINKS(project_command_F3, 0), false, "project_command_F3", 18, "Run the command with index 3", 28, "G:\\projects\\4ed\\code\\custom\\4coder_project_commands.cpp", 55, 1152 },
{ PROC_LINKS(project_command_F4, 0), false, "project_command_F4", 18, "Run the command with index 4", 28, "G:\\projects\\4ed\\code\\custom\\4coder_project_commands.cpp", 55, 1158 },
{ PROC_LINKS(project_command_F5, 0), false, "project_command_F5", 18, "Run the command with index 5", 28, "G:\\projects\\4ed\\code\\custom\\4coder_project_commands.cpp", 55, 1164 },
{ PROC_LINKS(project_command_F6, 0), false, "project_command_F6", 18, "Run the command with index 6", 28, "G:\\projects\\4ed\\code\\custom\\4coder_project_commands.cpp", 55, 1170 },
{ PROC_LINKS(project_command_F7, 0), false, "project_command_F7", 18, "Run the command with index 7", 28, "G:\\projects\\4ed\\code\\custom\\4coder_project_commands.cpp", 55, 1176 },
{ PROC_LINKS(project_command_F8, 0), false, "project_command_F8", 18, "Run the command with index 8", 28, "G:\\projects\\4ed\\code\\custom\\4coder_project_commands.cpp", 55, 1182 },
{ PROC_LINKS(project_command_F9, 0), false, "project_command_F9", 18, "Run the command with index 9", 28, "G:\\projects\\4ed\\code\\custom\\4coder_project_commands.cpp", 55, 1188 },
{ PROC_LINKS(project_command_lister, 0), false, "project_command_lister", 22, "Open a lister of all commands in the currently loaded project.", 62, "G:\\projects\\4ed\\code\\custom\\4coder_project_commands.cpp", 55, 1092 },
{ PROC_LINKS(project_fkey_command, 0), false, "project_fkey_command", 20, "Run an 'fkey command' configured in a project.4coder file.  Determines the index of the 'fkey command' by which function key or numeric key was pressed to trigger the command.", 175, "G:\\projects\\4ed\\code\\custom\\4coder_project_commands.cpp", 55, 1030 },
{ PROC_LINKS(project_go_to_root_directory, 0), false, "project_go_to_root_directory", 28, "Changes 4coder's hot directory to the root directory of the currently loaded project. With no loaded project nothing hapepns.", 125, "G:\\projects\\4ed\\code\\custom\\4coder_project_commands.cpp", 55, 1056 },
{ PROC_LINKS(project_reprint, 0), false, "project_reprint", 15, "Prints the current project to the file it was loaded from; prints in the most recent project file version", 105, "G:\\projects\\4ed\\code\\custom\\4coder_project_commands.cpp", 55, 1102 },
{ PROC_LINKS(query_replace, 0), false, "query_replace", 13, "Queries the user for two strings, and incrementally replaces every occurence of the first string with the second string.", 120, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 1296 },
{ PROC_LINKS(query_replace_identifier, 0), false, "query_replace_identifier", 24, "Queries the user for a string, and incrementally replace every occurence of the word or token found at the cursor with the specified string.", 140, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 1317 },
{ PROC_LINKS(query_replace_selection, 0), false, "query_replace_selection", 23, "Queries the user for a string, and incrementally replace every occurence of the string found in the selected range with the specified string.", 141, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 1333 },
{ PROC_LINKS(quick_swap_buffer, 0), false, "quick_swap_buffer", 17, "Change to the most recently used buffer in this view - or to the top of the buffer stack if the most recent doesn't exist anymore", 129, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 1720 },
{ PROC_LINKS(redo, 0), false, "redo", 4, "Advances forwards through the undo history of the current buffer.", 65, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 1900 },
{ PROC_LINKS(redo_all_buffers, 0), false, "redo_all_buffers", 16, "Advances forward through the undo history in the buffer containing the most recent regular edit.", 96, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 1997 },
{ PROC_LINKS(rename_file_query, 0), false, "rename_file_query", 17, "Queries the user for a new name and renames the file of the current buffer, altering the buffer's name too.", 107, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 1474 },
{ PROC_LINKS(reopen, 0), false, "reopen", 6, "Reopen the current buffer from the hard drive.", 46, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 1758 },
{ PROC_LINKS(replace_in_all_buffers, 0), false, "replace_in_all_buffers", 22, "Queries the user for a needle and string. Replaces all occurences of needle with string in all editable buffers.", 112, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 1206 },
{ PROC_LINKS(replace_in_buffer, 0), false, "replace_in_buffer", 17, "Queries the user for a needle and string. Replaces all occurences of needle with string in the active buffer.", 109, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 1197 },
{ PROC_LINKS(replace_in_range, 0), false, "replace_in_range", 16, "Queries the user for a needle and string. Replaces all occurences of needle with string in the range between cursor and the mark in the active buffer.", 150, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 1188 },
{ PROC_LINKS(reverse_search, 0), false, "reverse_search", 14, "Begins an incremental search up through the current buffer for a user specified string.", 87, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 1129 },
{ PROC_LINKS(reverse_search_identifier, 0), false, "reverse_search_identifier", 25, "Begins an incremental search up through the current buffer for the word or token under the cursor.", 98, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 1141 },
{ PROC_LINKS(save, 0), false, "save", 4, "Saves the current buffer.", 25, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 1748 },
{ PROC_LINKS(save_all_dirty_buffers, 0), false, "save_all_dirty_buffers", 22, "Saves all buffers marked dirty (showing the '*' indicator).", 59, "G:\\projects\\4ed\\code\\custom\\4coder_default_framework.cpp", 56, 454 },
{ PROC_LINKS(save_to_query, 0), false, "save_to_query", 13, "Queries the user for a file name and saves the contents of the current buffer, altering the buffer's name too.", 110, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 1441 },
{ PROC_LINKS(search, 0), false, "search", 6, "Begins an incremental search down through the current buffer for a user specified string.", 89, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 1123 },
{ PROC_LINKS(search_identifier, 0), false, "search_identifier", 17, "Begins an incremental search down through the current buffer for the word or token under the cursor.", 100, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 1135 },
{ PROC_LINKS(seek_beginning_of_line, 0), false, "seek_beginning_of_line", 22, "Seeks the cursor to the beginning of the visual line.", 53, "G:\\projects\\4ed\\code\\custom\\4coder_helper.cpp", 45, 2246 },
{ PROC_LINKS(seek_beginning_of_textual_line, 0), false, "seek_beginning_of_textual_line", 30, "Seeks the cursor to the beginning of the line across all text.", 62, "G:\\projects\\4ed\\code\\custom\\4coder_helper.cpp", 45, 2234 },
{ PROC_LINKS(seek_end_of_line, 0), false, "seek_end_of_line", 16, "Seeks the cursor to the end of the visual line.", 47, "G:\\projects\\4ed\\code\\custom\\4coder_helper.cpp", 45, 2252 },
{ PROC_LINKS(seek_end_of_textual_line, 0), false, "seek_end_of_textual_line", 24, "Seeks the cursor to the end of the line across all text.", 56, "G:\\projects\\4ed\\code\\custom\\4coder_helper.cpp", 45, 2240 },
{ PROC_LINKS(select_all, 0), false, "select_all", 10, "Puts the cursor at the top of the file, and the mark at the bottom of the file.", 79, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 555 },
{ PROC_LINKS(select_next_scope_absolute, 0), false, "select_next_scope_absolute", 26, "Finds the first scope started by '{' after the cursor and puts the cursor and mark on the '{' and '}'.", 102, "G:\\projects\\4ed\\code\\custom\\4coder_scope_commands.cpp", 53, 57 },
{ PROC_LINKS(select_next_scope_after_current, 0), false, "select_next_scope_after_current", 31, "If a scope is selected, find first scope that starts after the selected scope. Otherwise find the first scope that starts after the cursor.", 139, "G:\\projects\\4ed\\code\\custom\\4coder_scope_commands.cpp", 53, 66 },
{ PROC_LINKS(select_prev_scope_absolute, 0), false, "select_prev_scope_absolute", 26, "Finds the first scope started by '{' before the cursor and puts the cursor and mark on the '{' and '}'.", 103, "G:\\projects\\4ed\\code\\custom\\4coder_scope_commands.cpp", 53, 82 },
{ PROC_LINKS(select_prev_top_most_scope, 0), false, "select_prev_top_most_scope", 26, "Finds the first scope that starts before the cursor, then finds the top most scope that contains that scope.", 108, "G:\\projects\\4ed\\code\\custom\\4coder_scope_commands.cpp", 53, 99 },
{ PROC_LINKS(select_surrounding_scope, 0), false, "select_surrounding_scope", 24, "Finds the scope enclosed by '{' '}' surrounding the cursor and puts the cursor and mark on the '{' and '}'.", 107, "G:\\projects\\4ed\\code\\custom\\4coder_scope_commands.cpp", 53, 27 },
{ PROC_LINKS(select_surrounding_scope_maximal, 0), false, "select_surrounding_scope_maximal", 32, "Selects the top-most scope that surrounds the cursor.", 53, "G:\\projects\\4ed\\code\\custom\\4coder_scope_commands.cpp", 53, 39 },
{ PROC_LINKS(set_eol_mode_from_contents, 0), false, "set_eol_mode_from_contents", 26, "Sets the buffer's line ending mode to match the contents of the buffer.", 71, "G:\\projects\\4ed\\code\\custom\\4coder_eol.cpp", 42, 125 },
{ PROC_LINKS(set_eol_mode_to_binary, 0), false, "set_eol_mode_to_binary", 22, "Puts the buffer in bin line ending mode.", 40, "G:\\projects\\4ed\\code\\custom\\4coder_eol.cpp", 42, 112 },
{ PROC_LINKS(set_eol_mode_to_crlf, 0), false, "set_eol_mode_to_crlf", 20, "Puts the buffer in crlf line ending mode.", 41, "G:\\projects\\4ed\\code\\custom\\4coder_eol.cpp", 42, 86 },
{ PROC_LINKS(set_eol_mode_to_lf, 0), false, "set_eol_mode_to_lf", 18, "Puts the buffer in lf line ending mode.", 39, "G:\\projects\\4ed\\code\\custom\\4coder_eol.cpp", 42, 99 },
{ PROC_LINKS(set_face_size, 0), false, "set_face_size", 13, "Set face size of the face used by the current buffer.", 53, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 740 },
{ PROC_LINKS(set_face_size_this_buffer, 0), false, "set_face_size_this_buffer", 25, "Set face size of the face used by the current buffer; if any other buffers are using the same face a new face is created so that only this buffer is effected", 157, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 782 },
{ PROC_LINKS(set_mark, 0), false, "set_mark", 8, "Sets the mark to the current position of the cursor.", 52, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 115 },
{ PROC_LINKS(set_mode_to_notepad_like, 0), false, "set_mode_to_notepad_like", 24, "Sets the edit mode to Notepad like.", 35, "G:\\projects\\4ed\\code\\custom\\4coder_default_framework.cpp", 56, 499 },
{ PROC_LINKS(set_mode_to_original, 0), false, "set_mode_to_original", 20, "Sets the edit mode to 4coder original.", 38, "G:\\projects\\4ed\\code\\custom\\4coder_default_framework.cpp", 56, 493 },
{ PROC_LINKS(setup_build_bat, 0), false, "setup_build_bat", 15, "Queries the user for several configuration options and initializes a new build batch script.", 92, "G:\\projects\\4ed\\code\\custom\\4coder_project_commands.cpp", 55, 1074 },
{ PROC_LINKS(setup_build_bat_and_sh, 0), false, "setup_build_bat_and_sh", 22, "Queries the user for several configuration options and initializes a new build batch script.", 92, "G:\\projects\\4ed\\code\\custom\\4coder_project_commands.cpp", 55, 1086 },
{ PROC_LINKS(setup_build_sh, 0), false, "setup_build_sh", 14, "Queries the user for several configuration options and initializes a new build shell script.", 92, "G:\\projects\\4ed\\code\\custom\\4coder_project_commands.cpp", 55, 1080 },
{ PROC_LINKS(setup_new_project, 0), false, "setup_new_project", 17, "Queries the user for several configuration options and initializes a new 4coder project with build scripts for every OS.", 120, "G:\\projects\\4ed\\code\\custom\\4coder_project_commands.cpp", 55, 1067 },
{ PROC_LINKS(show_filebar, 0), false, "show_filebar", 12, "Sets the current view to show it's filebar.", 43, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 711 },
{ PROC_LINKS(show_scrollbar, 0), false, "show_scrollbar", 14, "Sets the current view to show it's scrollbar.", 45, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 697 },
{ PROC_LINKS(show_the_log_graph, 0), true, "show_the_log_graph", 18, "Parses *log* and displays the 'log graph' UI", 44, "G:\\projects\\4ed\\code\\custom\\4coder_log_parser.cpp", 49, 991 },
{ PROC_LINKS(snipe_backward_whitespace_or_token_boundary, 0), false, "snipe_backward_whitespace_or_token_boundary", 43, "Delete a single, whole token on or to the left of the cursor and post it to the clipboard.", 90, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 179 },
{ PROC_LINKS(snipe_forward_whitespace_or_token_boundary, 0), false, "snipe_forward_whitespace_or_token_boundary", 42, "Delete a single, whole token on or to the right of the cursor and post it to the clipboard.", 91, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 187 },
{ PROC_LINKS(snippet_lister, 0), true, "snippet_lister", 14, "Opens a snippet lister for inserting whole pre-written snippets of text.", 72, "G:\\projects\\4ed\\code\\custom\\4coder_combined_write_commands.cpp", 62, 237 },
{ PROC_LINKS(string_repeat, 0), false, "string_repeat", 13, "Example of query_user_string and query_user_number", 50, "G:\\projects\\4ed\\code\\custom\\4coder_examples.cpp", 47, 179 },
{ PROC_LINKS(suppress_mouse, 0), false, "suppress_mouse", 14, "Hides the mouse and causes all mosue input (clicks, position, wheel) to be ignored.", 83, "G:\\projects\\4ed\\code\\custom\\4coder_default_framework.cpp", 56, 475 },
{ PROC_LINKS(swap_panels, 0), false, "swap_panels", 11, "Swaps the active panel with it's sibling.", 41, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 1698 },
{ PROC_LINKS(theme_lister, 0), true, "theme_lister", 12, "Opens an interactive list of all registered themes.", 51, "G:\\projects\\4ed\\code\\custom\\4coder_lists.cpp", 44, 785 },
{ PROC_LINKS(to_lowercase, 0), false, "to_lowercase", 12, "Converts all ascii text in the range between the cursor and the mark to lowercase.", 82, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 581 },
{ PROC_LINKS(to_uppercase, 0), false, "to_uppercase", 12, "Converts all ascii text in the range between the cursor and the mark to uppercase.", 82, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 568 },
{ PROC_LINKS(toggle_filebar, 0), false, "toggle_filebar", 14, "Toggles the visibility status of the current view's filebar.", 60, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 725 },
{ PROC_LINKS(toggle_fps_meter, 0), false, "toggle_fps_meter", 16, "Toggles the visibility of the FPS performance meter", 51, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 734 },
{ PROC_LINKS(toggle_fullscreen, 0), false, "toggle_fullscreen", 17, "Toggle fullscreen mode on or off.  The change(s) do not take effect until the next frame.", 89, "G:\\projects\\4ed\\code\\custom\\4coder_default_framework.cpp", 56, 529 },
{ PROC_LINKS(toggle_highlight_enclosing_scopes, 0), false, "toggle_highlight_enclosing_scopes", 33, "In code files scopes surrounding the cursor are highlighted with distinguishing colors.", 87, "G:\\projects\\4ed\\code\\custom\\4coder_default_framework.cpp", 56, 513 },
{ PROC_LINKS(toggle_highlight_line_at_cursor, 0), false, "toggle_highlight_line_at_cursor", 31, "Toggles the line highlight at the cursor.", 41, "G:\\projects\\4ed\\code\\custom\\4coder_default_framework.cpp", 56, 505 },
{ PROC_LINKS(toggle_line_numbers, 0), false, "toggle_line_numbers", 19, "Toggles the left margin line numbers.", 37, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 839 },
{ PROC_LINKS(toggle_line_wrap, 0), false, "toggle_line_wrap", 16, "Toggles the line wrap setting on this buffer.", 45, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 847 },
{ PROC_LINKS(toggle_mouse, 0), false, "toggle_mouse", 12, "Toggles the mouse suppression mode, see suppress_mouse and allow_mouse.", 71, "G:\\projects\\4ed\\code\\custom\\4coder_default_framework.cpp", 56, 487 },
{ PROC_LINKS(toggle_paren_matching_helper, 0), false, "toggle_paren_matching_helper", 28, "In code files matching parentheses pairs are colored with distinguishing colors.", 80, "G:\\projects\\4ed\\code\\custom\\4coder_default_framework.cpp", 56, 521 },
{ PROC_LINKS(toggle_show_whitespace, 0), false, "toggle_show_whitespace", 22, "Toggles the current buffer's whitespace visibility status.", 58, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 830 },
{ PROC_LINKS(toggle_virtual_whitespace, 0), false, "toggle_virtual_whitespace", 25, "Toggles virtual whitespace for all files.", 41, "G:\\projects\\4ed\\code\\custom\\4coder_code_index.cpp", 49, 1363 },
{ PROC_LINKS(tutorial_maximize, 0), false, "tutorial_maximize", 17, "Expand the tutorial window", 26, "G:\\projects\\4ed\\code\\custom\\4coder_tutorial.cpp", 47, 20 },
{ PROC_LINKS(tutorial_minimize, 0), false, "tutorial_minimize", 17, "Shrink the tutorial window", 26, "G:\\projects\\4ed\\code\\custom\\4coder_tutorial.cpp", 47, 34 },
{ PROC_LINKS(uncomment_line, 0), false, "uncomment_line", 14, "If present, delete '//' at the beginning of the line after leading whitespace.", 78, "G:\\projects\\4ed\\code\\custom\\4coder_combined_write_commands.cpp", 62, 137 },
{ PROC_LINKS(undo, 0), false, "undo", 4, "Advances backwards through the undo history of the current buffer.", 66, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 1848 },
{ PROC_LINKS(undo_all_buffers, 0), false, "undo_all_buffers", 16, "Advances backward through the undo history in the buffer containing the most recent regular edit.", 97, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 1926 },
{ PROC_LINKS(view_buffer_other_panel, 0), false, "view_buffer_other_panel", 23, "Set the other non-active panel to view the buffer that the active panel views, and switch to that panel.", 104, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 1686 },
{ PROC_LINKS(view_jump_list_with_lister, 0), false, "view_jump_list_with_lister", 26, "When executed on a buffer with jumps, creates a persistent lister for all the jumps", 83, "G:\\projects\\4ed\\code\\custom\\4coder_jump_lister.cpp", 50, 59 },
{ PROC_LINKS(word_complete, 0), false, "word_complete", 13, "Iteratively tries completing the word to the left of the cursor with other words in open buffers that have the same prefix string.", 130, "G:\\projects\\4ed\\code\\custom\\4coder_search.cpp", 45, 433 },
{ PROC_LINKS(word_complete_drop_down, 0), false, "word_complete_drop_down", 23, "Word complete with drop down menu.", 34, "G:\\projects\\4ed\\code\\custom\\4coder_search.cpp", 45, 679 },
{ PROC_LINKS(write_block, 0), false, "write_block", 11, "At the cursor, insert a block comment.", 38, "G:\\projects\\4ed\\code\\custom\\4coder_combined_write_commands.cpp", 62, 94 },
{ PROC_LINKS(write_hack, 0), false, "write_hack", 10, "At the cursor, insert a '// HACK' comment, includes user name if it was specified in config.4coder.", 99, "G:\\projects\\4ed\\code\\custom\\4coder_combined_write_commands.cpp", 62, 82 },
{ PROC_LINKS(write_note, 0), false, "write_note", 10, "At the cursor, insert a '// NOTE' comment, includes user name if it was specified in config.4coder.", 99, "G:\\projects\\4ed\\code\\custom\\4coder_combined_write_commands.cpp", 62, 88 },
{ PROC_LINKS(write_space, 0), false, "write_space", 11, "Inserts a space.", 16, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 67 },
{ PROC_LINKS(write_text_and_auto_indent, 0), false, "write_text_and_auto_indent", 26, "Inserts text and auto-indents the line on which the cursor sits if any of the text contains 'layout punctuation' such as ;:{}()[]# and new lines.", 145, "G:\\projects\\4ed\\code\\custom\\4coder_auto_indent.cpp", 50, 440 },
{ PROC_LINKS(write_text_input, 0), false, "write_text_input", 16, "Inserts whatever text was used to trigger this command.", 55, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 59 },
{ PROC_LINKS(write_todo, 0), false, "write_todo", 10, "At the cursor, insert a '// TODO' comment, includes user name if it was specified in config.4coder.", 99, "G:\\projects\\4ed\\code\\custom\\4coder_combined_write_commands.cpp", 62, 76 },
{ PROC_LINKS(write_underscore, 0), false, "write_underscore", 16, "Inserts an underscore.", 22, "G:\\projects\\4ed\\code\\custom\\4coder_base_commands.cpp", 52, 73 },
{ PROC_LINKS(write_zero_struct, 0), false, "write_zero_struct", 17, "At the cursor, insert a ' = {};'.", 33, "G:\\projects\\4ed\\code\\custom\\4coder_combined_write_commands.cpp", 62, 100 },
};
static i32 fcoder_metacmd_ID_allow_mouse = 0;
static i32 fcoder_metacmd_ID_auto_indent_line_at_cursor = 1;
static i32 fcoder_metacmd_ID_auto_indent_range = 2;
static i32 fcoder_metacmd_ID_auto_indent_whole_file = 3;
static i32 fcoder_metacmd_ID_b50_rg = 4;
static i32 fcoder_metacmd_ID_backspace_alpha_numeric_boundary = 5;
static i32 fcoder_metacmd_ID_backspace_char = 6;
static i32 fcoder_metacmd_ID_basic_change_active_panel = 7;
static i32 fcoder_metacmd_ID_begin_clipboard_collection_mode = 8;
static i32 fcoder_metacmd_ID_build_in_build_panel = 9;
static i32 fcoder_metacmd_ID_build_search = 10;
static i32 fcoder_metacmd_ID_center_view = 11;
static i32 fcoder_metacmd_ID_change_active_panel = 12;
static i32 fcoder_metacmd_ID_change_active_panel_backwards = 13;
static i32 fcoder_metacmd_ID_change_to_build_panel = 14;
static i32 fcoder_metacmd_ID_clean_all_lines = 15;
static i32 fcoder_metacmd_ID_clean_trailing_whitespace = 16;
static i32 fcoder_metacmd_ID_clear_all_themes = 17;
static i32 fcoder_metacmd_ID_clear_clipboard = 18;
static i32 fcoder_metacmd_ID_click_set_cursor = 19;
static i32 fcoder_metacmd_ID_click_set_cursor_and_mark = 20;
static i32 fcoder_metacmd_ID_click_set_cursor_if_lbutton = 21;
static i32 fcoder_metacmd_ID_click_set_mark = 22;
static i32 fcoder_metacmd_ID_clipboard_record_clip = 23;
static i32 fcoder_metacmd_ID_close_all_code = 24;
static i32 fcoder_metacmd_ID_close_build_panel = 25;
static i32 fcoder_metacmd_ID_close_panel = 26;
static i32 fcoder_metacmd_ID_command_documentation = 27;
static i32 fcoder_metacmd_ID_command_lister = 28;
static i32 fcoder_metacmd_ID_comment_line = 29;
static i32 fcoder_metacmd_ID_comment_line_toggle = 30;
static i32 fcoder_metacmd_ID_copy = 31;
static i32 fcoder_metacmd_ID_cursor_mark_swap = 32;
static i32 fcoder_metacmd_ID_custom_api_documentation = 33;
static i32 fcoder_metacmd_ID_cut = 34;
static i32 fcoder_metacmd_ID_decrease_face_size = 35;
static i32 fcoder_metacmd_ID_default_file_externally_modified = 36;
static i32 fcoder_metacmd_ID_default_startup = 37;
static i32 fcoder_metacmd_ID_default_try_exit = 38;
static i32 fcoder_metacmd_ID_default_view_input_handler = 39;
static i32 fcoder_metacmd_ID_delete_alpha_numeric_boundary = 40;
static i32 fcoder_metacmd_ID_delete_char = 41;
static i32 fcoder_metacmd_ID_delete_current_scope = 42;
static i32 fcoder_metacmd_ID_delete_file_query = 43;
static i32 fcoder_metacmd_ID_delete_line = 44;
static i32 fcoder_metacmd_ID_delete_range = 45;
static i32 fcoder_metacmd_ID_display_key_codes = 46;
static i32 fcoder_metacmd_ID_display_text_input = 47;
static i32 fcoder_metacmd_ID_double_backspace = 48;
static i32 fcoder_metacmd_ID_duplicate_line = 49;
static i32 fcoder_metacmd_ID_execute_any_cli = 50;
static i32 fcoder_metacmd_ID_execute_previous_cli = 51;
static i32 fcoder_metacmd_ID_exit_4coder = 52;
static i32 fcoder_metacmd_ID_go_to_user_directory = 53;
static i32 fcoder_metacmd_ID_goto_beginning_of_file = 54;
static i32 fcoder_metacmd_ID_goto_end_of_file = 55;
static i32 fcoder_metacmd_ID_goto_first_jump = 56;
static i32 fcoder_metacmd_ID_goto_first_jump_same_panel_sticky = 57;
static i32 fcoder_metacmd_ID_goto_jump_at_cursor = 58;
static i32 fcoder_metacmd_ID_goto_jump_at_cursor_same_panel = 59;
static i32 fcoder_metacmd_ID_goto_line = 60;
static i32 fcoder_metacmd_ID_goto_next_jump = 61;
static i32 fcoder_metacmd_ID_goto_next_jump_no_skips = 62;
static i32 fcoder_metacmd_ID_goto_prev_jump = 63;
static i32 fcoder_metacmd_ID_goto_prev_jump_no_skips = 64;
static i32 fcoder_metacmd_ID_hide_filebar = 65;
static i32 fcoder_metacmd_ID_hide_scrollbar = 66;
static i32 fcoder_metacmd_ID_hit_sfx = 67;
static i32 fcoder_metacmd_ID_hms_demo_tutorial = 68;
static i32 fcoder_metacmd_ID_if0_off = 69;
static i32 fcoder_metacmd_ID_if_read_only_goto_position = 70;
static i32 fcoder_metacmd_ID_if_read_only_goto_position_same_panel = 71;
static i32 fcoder_metacmd_ID_increase_face_size = 72;
static i32 fcoder_metacmd_ID_interactive_kill_buffer = 73;
static i32 fcoder_metacmd_ID_interactive_new = 74;
static i32 fcoder_metacmd_ID_interactive_open = 75;
static i32 fcoder_metacmd_ID_interactive_open_or_new = 76;
static i32 fcoder_metacmd_ID_interactive_switch_buffer = 77;
static i32 fcoder_metacmd_ID_jump_to_definition = 78;
static i32 fcoder_metacmd_ID_jump_to_definition_at_cursor = 79;
static i32 fcoder_metacmd_ID_jump_to_last_point = 80;
static i32 fcoder_metacmd_ID_keyboard_macro_finish_recording = 81;
static i32 fcoder_metacmd_ID_keyboard_macro_replay = 82;
static i32 fcoder_metacmd_ID_keyboard_macro_start_recording = 83;
static i32 fcoder_metacmd_ID_kill_buffer = 84;
static i32 fcoder_metacmd_ID_kill_tutorial = 85;
static i32 fcoder_metacmd_ID_left_adjust_view = 86;
static i32 fcoder_metacmd_ID_list_all_functions_all_buffers = 87;
static i32 fcoder_metacmd_ID_list_all_functions_all_buffers_lister = 88;
static i32 fcoder_metacmd_ID_list_all_functions_current_buffer = 89;
static i32 fcoder_metacmd_ID_list_all_functions_current_buffer_lister = 90;
static i32 fcoder_metacmd_ID_list_all_locations = 91;
static i32 fcoder_metacmd_ID_list_all_locations_case_insensitive = 92;
static i32 fcoder_metacmd_ID_list_all_locations_of_identifier = 93;
static i32 fcoder_metacmd_ID_list_all_locations_of_identifier_case_insensitive = 94;
static i32 fcoder_metacmd_ID_list_all_locations_of_selection = 95;
static i32 fcoder_metacmd_ID_list_all_locations_of_selection_case_insensitive = 96;
static i32 fcoder_metacmd_ID_list_all_locations_of_type_definition = 97;
static i32 fcoder_metacmd_ID_list_all_locations_of_type_definition_of_identifier = 98;
static i32 fcoder_metacmd_ID_list_all_substring_locations = 99;
static i32 fcoder_metacmd_ID_list_all_substring_locations_case_insensitive = 100;
static i32 fcoder_metacmd_ID_load_project = 101;
static i32 fcoder_metacmd_ID_load_theme_current_buffer = 102;
static i32 fcoder_metacmd_ID_load_themes_default_folder = 103;
static i32 fcoder_metacmd_ID_load_themes_hot_directory = 104;
static i32 fcoder_metacmd_ID_make_directory_query = 105;
static i32 fcoder_metacmd_ID_miblo_decrement_basic = 106;
static i32 fcoder_metacmd_ID_miblo_decrement_time_stamp = 107;
static i32 fcoder_metacmd_ID_miblo_decrement_time_stamp_minute = 108;
static i32 fcoder_metacmd_ID_miblo_increment_basic = 109;
static i32 fcoder_metacmd_ID_miblo_increment_time_stamp = 110;
static i32 fcoder_metacmd_ID_miblo_increment_time_stamp_minute = 111;
static i32 fcoder_metacmd_ID_mouse_wheel_change_face_size = 112;
static i32 fcoder_metacmd_ID_mouse_wheel_scroll = 113;
static i32 fcoder_metacmd_ID_move_down = 114;
static i32 fcoder_metacmd_ID_move_down_10 = 115;
static i32 fcoder_metacmd_ID_move_down_5 = 116;
static i32 fcoder_metacmd_ID_move_down_textual = 117;
static i32 fcoder_metacmd_ID_move_down_to_blank_line = 118;
static i32 fcoder_metacmd_ID_move_down_to_blank_line_end = 119;
static i32 fcoder_metacmd_ID_move_down_to_blank_line_skip_whitespace = 120;
static i32 fcoder_metacmd_ID_move_left = 121;
static i32 fcoder_metacmd_ID_move_left_alpha_numeric_boundary = 122;
static i32 fcoder_metacmd_ID_move_left_alpha_numeric_or_camel_boundary = 123;
static i32 fcoder_metacmd_ID_move_left_token_boundary = 124;
static i32 fcoder_metacmd_ID_move_left_whitespace_boundary = 125;
static i32 fcoder_metacmd_ID_move_left_whitespace_or_token_boundary = 126;
static i32 fcoder_metacmd_ID_move_line_down = 127;
static i32 fcoder_metacmd_ID_move_line_up = 128;
static i32 fcoder_metacmd_ID_move_right = 129;
static i32 fcoder_metacmd_ID_move_right_alpha_numeric_boundary = 130;
static i32 fcoder_metacmd_ID_move_right_alpha_numeric_or_camel_boundary = 131;
static i32 fcoder_metacmd_ID_move_right_token_boundary = 132;
static i32 fcoder_metacmd_ID_move_right_whitespace_boundary = 133;
static i32 fcoder_metacmd_ID_move_right_whitespace_or_token_boundary = 134;
static i32 fcoder_metacmd_ID_move_up = 135;
static i32 fcoder_metacmd_ID_move_up_10 = 136;
static i32 fcoder_metacmd_ID_move_up_5 = 137;
static i32 fcoder_metacmd_ID_move_up_to_blank_line = 138;
static i32 fcoder_metacmd_ID_move_up_to_blank_line_end = 139;
static i32 fcoder_metacmd_ID_move_up_to_blank_line_skip_whitespace = 140;
static i32 fcoder_metacmd_ID_multi_paste = 141;
static i32 fcoder_metacmd_ID_multi_paste_interactive = 142;
static i32 fcoder_metacmd_ID_multi_paste_interactive_quick = 143;
static i32 fcoder_metacmd_ID_music_start = 144;
static i32 fcoder_metacmd_ID_music_stop = 145;
static i32 fcoder_metacmd_ID_open_all_code = 146;
static i32 fcoder_metacmd_ID_open_all_code_recursive = 147;
static i32 fcoder_metacmd_ID_open_file_in_quotes = 148;
static i32 fcoder_metacmd_ID_open_in_other = 149;
static i32 fcoder_metacmd_ID_open_long_braces = 150;
static i32 fcoder_metacmd_ID_open_long_braces_break = 151;
static i32 fcoder_metacmd_ID_open_long_braces_semicolon = 152;
static i32 fcoder_metacmd_ID_open_matching_file_cpp = 153;
static i32 fcoder_metacmd_ID_open_panel_hsplit = 154;
static i32 fcoder_metacmd_ID_open_panel_vsplit = 155;
static i32 fcoder_metacmd_ID_page_down = 156;
static i32 fcoder_metacmd_ID_page_up = 157;
static i32 fcoder_metacmd_ID_paste = 158;
static i32 fcoder_metacmd_ID_paste_and_indent = 159;
static i32 fcoder_metacmd_ID_paste_next = 160;
static i32 fcoder_metacmd_ID_paste_next_and_indent = 161;
static i32 fcoder_metacmd_ID_place_in_scope = 162;
static i32 fcoder_metacmd_ID_play_with_a_counter = 163;
static i32 fcoder_metacmd_ID_profile_clear = 164;
static i32 fcoder_metacmd_ID_profile_disable = 165;
static i32 fcoder_metacmd_ID_profile_enable = 166;
static i32 fcoder_metacmd_ID_profile_inspect = 167;
static i32 fcoder_metacmd_ID_project_command_F1 = 168;
static i32 fcoder_metacmd_ID_project_command_F10 = 169;
static i32 fcoder_metacmd_ID_project_command_F11 = 170;
static i32 fcoder_metacmd_ID_project_command_F12 = 171;
static i32 fcoder_metacmd_ID_project_command_F13 = 172;
static i32 fcoder_metacmd_ID_project_command_F14 = 173;
static i32 fcoder_metacmd_ID_project_command_F15 = 174;
static i32 fcoder_metacmd_ID_project_command_F16 = 175;
static i32 fcoder_metacmd_ID_project_command_F2 = 176;
static i32 fcoder_metacmd_ID_project_command_F3 = 177;
static i32 fcoder_metacmd_ID_project_command_F4 = 178;
static i32 fcoder_metacmd_ID_project_command_F5 = 179;
static i32 fcoder_metacmd_ID_project_command_F6 = 180;
static i32 fcoder_metacmd_ID_project_command_F7 = 181;
static i32 fcoder_metacmd_ID_project_command_F8 = 182;
static i32 fcoder_metacmd_ID_project_command_F9 = 183;
static i32 fcoder_metacmd_ID_project_command_lister = 184;
static i32 fcoder_metacmd_ID_project_fkey_command = 185;
static i32 fcoder_metacmd_ID_project_go_to_root_directory = 186;
static i32 fcoder_metacmd_ID_project_reprint = 187;
static i32 fcoder_metacmd_ID_query_replace = 188;
static i32 fcoder_metacmd_ID_query_replace_identifier = 189;
static i32 fcoder_metacmd_ID_query_replace_selection = 190;
static i32 fcoder_metacmd_ID_quick_swap_buffer = 191;
static i32 fcoder_metacmd_ID_redo = 192;
static i32 fcoder_metacmd_ID_redo_all_buffers = 193;
static i32 fcoder_metacmd_ID_rename_file_query = 194;
static i32 fcoder_metacmd_ID_reopen = 195;
static i32 fcoder_metacmd_ID_replace_in_all_buffers = 196;
static i32 fcoder_metacmd_ID_replace_in_buffer = 197;
static i32 fcoder_metacmd_ID_replace_in_range = 198;
static i32 fcoder_metacmd_ID_reverse_search = 199;
static i32 fcoder_metacmd_ID_reverse_search_identifier = 200;
static i32 fcoder_metacmd_ID_save = 201;
static i32 fcoder_metacmd_ID_save_all_dirty_buffers = 202;
static i32 fcoder_metacmd_ID_save_to_query = 203;
static i32 fcoder_metacmd_ID_search = 204;
static i32 fcoder_metacmd_ID_search_identifier = 205;
static i32 fcoder_metacmd_ID_seek_beginning_of_line = 206;
static i32 fcoder_metacmd_ID_seek_beginning_of_textual_line = 207;
static i32 fcoder_metacmd_ID_seek_end_of_line = 208;
static i32 fcoder_metacmd_ID_seek_end_of_textual_line = 209;
static i32 fcoder_metacmd_ID_select_all = 210;
static i32 fcoder_metacmd_ID_select_next_scope_absolute = 211;
static i32 fcoder_metacmd_ID_select_next_scope_after_current = 212;
static i32 fcoder_metacmd_ID_select_prev_scope_absolute = 213;
static i32 fcoder_metacmd_ID_select_prev_top_most_scope = 214;
static i32 fcoder_metacmd_ID_select_surrounding_scope = 215;
static i32 fcoder_metacmd_ID_select_surrounding_scope_maximal = 216;
static i32 fcoder_metacmd_ID_set_eol_mode_from_contents = 217;
static i32 fcoder_metacmd_ID_set_eol_mode_to_binary = 218;
static i32 fcoder_metacmd_ID_set_eol_mode_to_crlf = 219;
static i32 fcoder_metacmd_ID_set_eol_mode_to_lf = 220;
static i32 fcoder_metacmd_ID_set_face_size = 221;
static i32 fcoder_metacmd_ID_set_face_size_this_buffer = 222;
static i32 fcoder_metacmd_ID_set_mark = 223;
static i32 fcoder_metacmd_ID_set_mode_to_notepad_like = 224;
static i32 fcoder_metacmd_ID_set_mode_to_original = 225;
static i32 fcoder_metacmd_ID_setup_build_bat = 226;
static i32 fcoder_metacmd_ID_setup_build_bat_and_sh = 227;
static i32 fcoder_metacmd_ID_setup_build_sh = 228;
static i32 fcoder_metacmd_ID_setup_new_project = 229;
static i32 fcoder_metacmd_ID_show_filebar = 230;
static i32 fcoder_metacmd_ID_show_scrollbar = 231;
static i32 fcoder_metacmd_ID_show_the_log_graph = 232;
static i32 fcoder_metacmd_ID_snipe_backward_whitespace_or_token_boundary = 233;
static i32 fcoder_metacmd_ID_snipe_forward_whitespace_or_token_boundary = 234;
static i32 fcoder_metacmd_ID_snippet_lister = 235;
static i32 fcoder_metacmd_ID_string_repeat = 236;
static i32 fcoder_metacmd_ID_suppress_mouse = 237;
static i32 fcoder_metacmd_ID_swap_panels = 238;
static i32 fcoder_metacmd_ID_theme_lister = 239;
static i32 fcoder_metacmd_ID_to_lowercase = 240;
static i32 fcoder_metacmd_ID_to_uppercase = 241;
static i32 fcoder_metacmd_ID_toggle_filebar = 242;
static i32 fcoder_metacmd_ID_toggle_fps_meter = 243;
static i32 fcoder_metacmd_ID_toggle_fullscreen = 244;
static i32 fcoder_metacmd_ID_toggle_highlight_enclosing_scopes = 245;
static i32 fcoder_metacmd_ID_toggle_highlight_line_at_cursor = 246;
static i32 fcoder_metacmd_ID_toggle_line_numbers = 247;
static i32 fcoder_metacmd_ID_toggle_line_wrap = 248;
static i32 fcoder_metacmd_ID_toggle_mouse = 249;
static i32 fcoder_metacmd_ID_toggle_paren_matching_helper = 250;
static i32 fcoder_metacmd_ID_toggle_show_whitespace = 251;
static i32 fcoder_metacmd_ID_toggle_virtual_whitespace = 252;
static i32 fcoder_metacmd_ID_tutorial_maximize = 253;
static i32 fcoder_metacmd_ID_tutorial_minimize = 254;
static i32 fcoder_metacmd_ID_uncomment_line = 255;
static i32 fcoder_metacmd_ID_undo = 256;
static i32 fcoder_metacmd_ID_undo_all_buffers = 257;
static i32 fcoder_metacmd_ID_view_buffer_other_panel = 258;
static i32 fcoder_metacmd_ID_view_jump_list_with_lister = 259;
static i32 fcoder_metacmd_ID_word_complete = 260;
static i32 fcoder_metacmd_ID_word_complete_drop_down = 261;
static i32 fcoder_metacmd_ID_write_block = 262;
static i32 fcoder_metacmd_ID_write_hack = 263;
static i32 fcoder_metacmd_ID_write_note = 264;
static i32 fcoder_metacmd_ID_write_space = 265;
static i32 fcoder_metacmd_ID_write_text_and_auto_indent = 266;
static i32 fcoder_metacmd_ID_write_text_input = 267;
static i32 fcoder_metacmd_ID_write_todo = 268;
static i32 fcoder_metacmd_ID_write_underscore = 269;
static i32 fcoder_metacmd_ID_write_zero_struct = 270;
#endif
