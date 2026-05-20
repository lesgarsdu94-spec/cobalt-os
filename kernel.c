/*
 * ============================================================================
 * NovaTech Cobalt OS - v0.01 (April 5, 1971 Spec)
 * Module: kernel.c (Monolithic Kernel Shell Console)
 * ============================================================================
 */

volatile char* video_memory = (volatile char*) 0xB8000;
int cursor_pos = 0;

extern void display_startup_logo(volatile char* video_mem, int* cursor_position);
extern int get_file_count();
extern const char* get_file_path(int index);
extern const char* get_file_dir(int index);
extern const char* get_file_name(int index);
extern const char* read_file_by_path(const char* path);

void print_string(const char* str, char color) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            cursor_pos = ((cursor_pos / 80) + 1) * 80;
        } else {
            video_memory[cursor_pos * 2] = str[i];
            video_memory[cursor_pos * 2 + 1] = color;
            cursor_pos++;
        }
    }
}

int strings_equal(const char* a, const char* b) {
    int i = 0;
    while (a[i] != '\0' || b[i] != '\0') {
        if (a[i] != b[i]) return 0;
        i++;
    }
    return 1;
}

void execute_command(const char* cmd, const char* arg) {
    print_string("\n$ ", 0x07);
    print_string(cmd, 0x0F);
    if (arg[0] != '\0') { print_string(" ", 0x0F); print_string(arg, 0x0F); }
    print_string("\n", 0x07);

    if (strings_equal(cmd, "ls")) {
        if (arg[0] == '\0') {
            print_string("Root Topology:\n", 0x0E);
            for (int i = 0; i < get_file_count(); i++) {
                print_string("  ", 0x07);
                print_string(get_file_path(i), 0x0A);
                print_string("\n", 0x07);
            }
        } else {
            for (int i = 0; i < get_file_count(); i++) {
                if (strings_equal(get_file_dir(i), arg)) {
                    print_string("  ", 0x07);
                    print_string(get_file_name(i), 0x0A);
                    print_string("\n", 0x07);
                }
            }
        }
    } else if (strings_equal(cmd, "cat")) {
        const char* content = read_file_by_path(arg);
        if (content != 0) print_string(content, 0x0F);
        else print_string("cat: file not found\n", 0x0C);
    }
}

void kernel_main(void) {
    for (int i = 0; i < 80 * 25 * 2; i++) video_memory[i] = 0;

    display_startup_logo(video_memory, &cursor_pos);

    const char* boot_msg = read_file_by_path("/etc/motd");
    print_string(boot_msg, 0x0E);

    execute_command("ls", "");
    execute_command("cat", "/boot.wav");
    execute_command("cat", "/bin/paint");
}
