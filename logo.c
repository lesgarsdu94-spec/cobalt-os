/*
 * ============================================================================
 * NovaTech Cobalt OS - v0.01 (April 5, 1971 Spec)
 * Module: logo.c (System Branding Engine)
 * ============================================================================
 */

void display_startup_logo(volatile char* video_mem, int* cursor_position) {
    *cursor_position = 160; 

    const char* ascii_logo[] = {
        "  _   _                 _____ZWch   ____  ____  _   _ _ _____ ",
        " | \\ | |               |_   _|__ \\ / ___|/ ___|| | | | |_   _|",
        " |  \\| | _____   ____ _  | |    ) | |   | |    | |_| | | | |  ",
        " | . ` |/ _ \\ \\ / / _` | | |   / /| |   | |    |  _  | | | |  ",
        " | |\\  | (_) \\ V / (_| |_| |_ / /_| |___| |___ | | | | | | |  ",
        " |_| \\_|\\___/ \\_/ \\__,_|_____|____|\\____|\\____||_| |_|_| |_|  ",
        " ============================================================="
    };

    int logo_rows = 7;
    char brand_color = 0x0B; 

    for (int r = 0; r < logo_rows; r++) {
        *cursor_position = ((*cursor_position / 80) + 1) * 80 + 9; 
        for (int c = 0; ascii_logo[r][c] != '\0'; c++) {
            video_mem[*cursor_position * 2] = ascii_logo[r][c];
            video_mem[*cursor_position * 2 + 1] = brand_color;
            (*cursor_position)++;
        }
    }
    *cursor_position = ((*cursor_position / 80) + 2) * 80; 
}
