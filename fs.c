/*
 * ============================================================================
 * NovaTech Cobalt OS - v0.01 (April 5, 1971 Spec)
 * Module: fs.c (Hierarchical RAM Disk File Space with 38 Builtins)
 * ============================================================================
 */

#define TOTAL_FILES 42

typedef struct {
    const char* absolute_path;
    const char* filename;
    const char* directory;
    const char* content;
} UnixFile;

UnixFile root_filesystem[TOTAL_FILES] = {
    { "/etc/motd", "motd", "/etc", "\n  NovaTech Cobalt OS v0.01 -- April 5, 1971 Spec\n  Lifecycle: EOS Reached April 12, 1971.\n\n" },
    { "/usr/author", "author", "/usr", "Builder: NovaTech Systems Corp. (Cloud Build 2026)\n" },
    { "/boot.wav", "boot.wav", "/", "Audio: RIFF WAVE sound binary (C3, C2, E2, G2 Chord Map).\n" },
    
    /* --- The 38 Built-in Applications Map --- */
    { "/bin/paint", "paint", "/bin", " paint: Infinite spectrum canvas engine loaded.\n" },
    { "/bin/cat", "cat", "/bin", " cat: Concatenation text viewer tool.\n" },
    { "/bin/ls", "ls", "/bin", " ls: Directory mapping engine.\n" },
    { "/bin/ar", "ar", "/bin", " ar: Archive creation/extraction manager.\n" },
    { "/bin/as", "as", "/bin", " as: Core x86 assembler subsystem.\n" },
    { "/bin/b", "b", "/bin", " b: BCPL derived interpretative language compiler.\n" },
    { "/bin/bas", "bas", "/bin", " bas: Dialect interpreter for BASIC programming.\n" },
    { "/bin/cc", "cc", "/bin", " cc: NovaTech C Native Infrastructure Compiler.\n" },
    { "/bin/chown", "chown", "/bin", " chown: Change object ownership permissions.\n" },
    { "/bin/cmp", "cmp", "/bin", " cmp: Byte-by-byte file comparing matrix.\n" },
    { "/bin/cp", "cp", "/bin", " cp: File resource duplication module.\n" },
    { "/bin/date", "date", "/bin", " date: System Epoch Clock Reader.\n" },
    { "/bin/db", "db", "/bin", " db: Data block relational index table.\n" },
    { "/bin/dc", "dc", "/bin", " dc: Arbitrary-precision reverse-polish calculator.\n" },
    { "/bin/df", "df", "/bin", " df: Core storage allocation mapper.\n" },
    { "/bin/ed", "ed", "/bin", " ed: Line-oriented core interactive text editor.\n" },
    { "/bin/find", "find", "/bin", " find: Structural path searching tool.\n" },
    { "/bin/ld", "ld", "/bin", " ld: Executable object file linker.\n" },
    { "/bin/ln", "ln", "/bin", " ln: Virtual file systems reference linker.\n" },
    { "/bin/mail", "mail", "/bin", " mail: Intra-system user mailbox router.\n" },
    { "/bin/mesg", "mesg", "/bin", " mesg: Controls pipeline broadcast permissions.\n" },
    { "/bin/mkdir", "mkdir", "/bin", " mkdir: Generate hierarchical folder node.\n" },
    { "/bin/mkfs", "mkfs", "/bin", " mkfs: Format storage file table allocations.\n" },
    { "/bin/mount", "mount", "/bin", " mount: Attach dynamic sector trees.\n" },
    { "/bin/mv", "mv", "/bin", " mv: Relocate file structural references.\n" },
    { "/bin/od", "od", "/bin", " od: Octal/hexadecimal system dump tool.\n" },
    { "/bin/pr", "pr", "/bin", " pr: Text formatting filter for standard output.\n" },
    { "/bin/rm", "rm", "/bin", " rm: Unlink system file allocations.\n" },
    { "/bin/rmdir", "rmdir", "/bin", " rmdir: Clean layout directories.\n" },
    { "/bin/sh", "sh", "/bin", " sh: Command parsing interactive interface.\n" },
    { "/bin/stat", "stat", "/bin", " stat: Display file attributes and structural descriptors.\n" },
    { "/bin/strip", "strip", "/bin", " strip: Remove debugging symbol tables from files.\n" },
    { "/bin/sum", "sum", "/bin", " sum: Checksum verification processor.\n" },
    { "/bin/tap", "tap", "/bin", " tap: Magnetic tape stream sequence controller.\n" },
    { "/bin/tsort", "tsort", "/bin", " tsort: Topological node sorter engine.\n" },
    { "/bin/tty", "tty", "/bin", " tty: Print local terminal identifier attributes.\n" },
    { "/bin/umount", "umount", "/bin", " umount: Detach secondary sector mappings.\n" },
    { "/bin/wc", "wc", "/bin", " wc: Line, word, and character stream counter.\n" },
    { "/bin/who", "who", "/bin", " who: List active security terminal profiles.\n" }
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
