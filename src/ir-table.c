struct ircode {
    char *name;
    char param;
};

struct ircode codes[] = {
    {"SEG_CODE",    0},
    {"SEG_DATA",    0},
    {"DATAB",       'b'},
    {"DATAW",       'w'},
    {"BSSB",        'b'},
    {"DEFLOCAL",    'i'},
    {"DEFGLOBAL",   'l'},
    {"LOCAL",       'i'},
    {"GLOBAL",      'l'},
    {"IMPORT",      'l'},
    {"EXPORT",      'l'},
    {"SWAP",        0},
    {"LDAL",        'b'},
    // TODO: Where are the other loads
    // with // constants?
    {"LDA",         0},
    {"LDB",         0},
    // Add stack pointer to primary.
    {"ADDSP",       0},
    // Add secondary to primary.
    {"ADDA",        0},
    {"ADDB",        0},
    {"INCA",        0},
    {"DECA",        0},
    {"DECB",        0},
    {"SIGNEXT",     0},
    {"STA",         0},
    {"STAL",        0},
    {"PUTCHAR",     0},
    {"PUTINT",      0},
    {"GETCHAR",     0},
    {"GETUCHAR",    0},
    {"GETINT",      0},
    {"PUSHA",       0},
    {"PUSHB",       0},
    {"POPA",        0},
    {"POPB",        0},
    {"SWAPSTACK",   0},
    {"INCS1",       0},
    {"INCS2",       0},
    {"DECS1",       0},
    {"DECS2",       0},
    {"SPHL",        0},
    {"CALL",        0},
    {"CALLPTR",     0},
    {"RET",         0},
    {"JMP",         'i'},
    {"JMPNZ",       'i'},
    {"JMPZ",        'i'},
    {"JMPCASE",     'i'},
    {"BOOL",        0},
    {"LNEG",        0},
    {"NEG",         0},
    {"ASLA",        0},
    {"ASL",         0},
    {"ASR",         0},
    {"LSR",         0},
    {"SUB",         0},
    {"MUL",         0},
    {"DIV",         0},
    {"UDIV",        0},
    {"AND",         0},
    {"OR",          0},
    {"XOR",         0},
    {"COMPA",       0},
    {"COMPB",       0},
    {"EQ",          0},
    {"NE",          0},
    {"LT",          0},
    {"LTE",         0},
    {"GT",          0},
    {"GTE",         0},
    {"ULT",         0},
    {"ULTE",        0},
    {"UGT",         0},
    {"UGTE",        0},
    {"SRCLINE",     0},
    {NULL,          0}
};
