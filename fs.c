/*
 * ============================================================================
 * NovaTech Cobalt OS - v0.01 (April 5, 1971 Spec)
 * Module: fs.c (Hierarchical RAM Disk File Space)
 * ============================================================================
 */

#define TOTAL_FILES 6

typedef struct {
    const char* absolute_path;
    const char* filename;
    const char* directory;
    const char* content;
} UnixFile;

UnixFile root_filesystem[TOTAL_FILES] = {
    {
        .absolute_path = "/etc/motd",
        .filename = "motd",
        .directory = "/etc",
        .content = "\n  NovaTech Cobalt OS v0.01 -- April 5, 1971 Spec\n  Lifecycle: EOS Reached April 12, 1971.\n\n"
    },
    {
        .absolute_path = "/usr/author",
        .filename = "author",
        .directory = "/usr",
        .content = "Builder: NovaTech Systems Corp. (Cloud Build 2026)\n"
    },
    {
        .absolute_path = "/boot.wav",
        .filename = "boot.wav",
        .directory = "/",
        .content = "Audio: RIFF WAVE sound binary (C3, C2, E2, G2 Chord Map).\n"
    },
    {
        .absolute_path = "/bin/ls",
        .filename = "ls",
        .directory = "/bin",
        .content = "Binary: Directory mapping tool builtin.\n"
    },
    {
        .absolute_path = "/bin/cat",
        .filename = "cat",
        .directory = "/bin",
        .content = "Binary: Concatenation text viewer builtin.\n"
    },
    {
        .absolute_path = "/bin/paint",
        .filename = "paint",
        .directory = "/bin",
        .content = "Binary: Painting Canvas (Infinite Spectrum Engine Enabled).\n"
    }
};

int get_file_count() { return TOTAL_FILES; }
const char* get_file_path(int i) { return (i >= 0 && i < TOTAL_FILES) ? root_filesystem[i].absolute_path : 0; }
const char* get_file_dir(int i) { return (i >= 0 && i < TOTAL_FILES) ? root_filesystem[i].directory : 0; }
const char* get_file_name(int i) { return (i >= 0 && i < TOTAL_FILES) ? root_filesystem[i].filename : 0; }

const char* read_file_by_path(const char* path) {
    for (int i = 0; i < TOTAL_FILES; i++) {
        int match = 1, j = 0;
        while (path[j] != '\0' || root_filesystem[i].absolute_path[j] != '\0') {
            if (path[j] != root_filesystem[i].absolute_path[j]) { match = 0; break; }
            j++;
        }
        if (match) return root_filesystem[i].content;
    }
    return 0;
}
