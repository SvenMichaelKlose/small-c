///////////////
/// MACHDEP ///
///////////////

// Intel 8080 architecture defs 
#define INTSIZE 2

/////////////////////
/// Miscellaneous ///
/////////////////////

#define FOREVER for(;;)
#define FALSE   0
#define TRUE    1
#define NO      0
#define YES     1

#define EOS     0
#define LF      10
#define BKSP    8
#define CR      13
#define FFEED   12
#define TAB     9

/////////////
/// TYPES ///
/////////////

// Possible entries for "ident".
#define VARIABLE    1
#define ARRAY       2
#define POINTER     3
#define FUNCTION    4

// Possible entries for "type"
// High order 14 bits give length of
// object.
// Low order 2 bits make type unique
// within length.
#define UNSIGNED    1
#define STRUCT      2
#define CCHAR       (1 << 2)
#define UCHAR       ((1 << 2) + 1)
#define CINT        (2 << 2)
#define UINT        ((2 << 2) + 1)

// Possible entries for "storage".
#define PUBLIC  1
#define AUTO    2
#define EXTERN  3

#define STATIC  4
#define LSTATIC 5
#define DEFAUTO 6

///////////////
/// SYMBOLS ///
///////////////

#define NAMESIZE    33
#define NAMEMAX     32

struct symbol {
    char name[NAMESIZE];

    // variable, array, pointer,
    // function 
    int identity;

    // char, int, uchar, unit 
    int type;

    // public, auto, extern, static
    // lstatic, defauto 
    int storage;
    int offset;

    // index of struct in tag table 
    int tag;

    // The size, in bytes, of a member
    // of a struct - only used for
    // member declarations.
    // TODO: Clear up real usage.
    int struct_size;
};
#define SYMBOL struct symbol

#define NUMBER_OF_GLOBALS   100
#define NUMBER_OF_LOCALS    20

////////////
/// TAGS ///
////////////

#ifdef SMALL_C
#define NULL_TAG 0
#else
#define NULL_TAG (TAG_SYMBOL *)0
#endif

// Maximum number of members in all
// structs and unions combined.
#define NUMMEMB     30

// Maximum number of tags.
#define NUMTAG      10

// Symbol add-on for unions and structs.
struct tag_symbol {
    char name[NAMESIZE];
    int size;
    int num_members;
    int first_member;
};
#define TAG_SYMBOL struct tag_symbol

///////////////////
/// BLOCK STACK ///
///////////////////

// "do"/"for"/"while"/"switch"
// statement stack 
#define WSTABSZ 20

// Actually for all loops.
struct while_rec { // TODO: Rename.
    int symbol_idx;
    int stack_pointer;
    int type;
    int case_test;

    // continue label ? 
    // TODO: What's this?
    int incr_def;

    // body of loop, switch ? 
    // TODO: What's this?
    int body_tab;

    // exit label 
    int while_exit;
};
#define WHILE struct while_rec

// possible entries for "wstyp" 
#define WSWHILE     0
#define WSFOR       1
#define WSDO        2
#define WSSWITCH    3

// "switch" label stack 
#define SWSTSZ  100

////////////////
/// LITERALS ///
////////////////

// literal pool 
#define LITABSZ 5000
#define LITMAX  LITABSZ-1

////////////////////
/// PREPROCESSOR ///
////////////////////

// input line 
#define LINESIZE        150
#define LINEMAX (LINESIZE-1)
#define MPMAX   LINEMAX

// macro (define) pool 
#define MACQSIZE        1500
#define MACMAX  (MACQSIZE-1)

// "include" stack 
#define INCLSIZ     3

// Path to include directories. set at
// compile time on host machine.
#define DEFLIB  inclib()

#ifndef SMALLC
extern char *inclib ();

WHILE *readwhile ();
WHILE *findwhile ();
WHILE *readswitch ();

#endif

//////////////////
/// STATEMENTS ///
//////////////////

// statement types (tokens) 
#define STIF        1
#define STWHILE     2
#define STRETURN    3
#define STBREAK     4
#define STCONT      5
#define STASM       6
#define STEXP       7
#define STDO        8
#define STFOR       9
#define STSWITCH    10

#define FETCH  1
#define REGA 1<<1
#define REGB 1<<2

///////////////
/// LVALUES ///
///////////////
//
// L-values** are expressions that refer
// to a memory location and can appear
// on the left-hand side of an
// assignment statement.

struct lvalue {
    // 0 for constant.
    SYMBOL *symbol;

    // 0 for static object.
    int indirect;

    // Type of pointer or array,
    // 0 for static and others.
    int ptr_type;

    // 0 if not struct.
    TAG_SYMBOL *tagsym;
};
#define LVALUE struct lvalue

///////////////////////
/// INITIALIZATIONS ///
///////////////////////

// Initialisation of global variables.
#define INIT_TYPE       NAMESIZE
#define INIT_LENGTH     NAMESIZE+1
#define INITIALS_SIZE   5*1024

struct initials_table {
    char name[NAMESIZE];
    int type;
    // length of data (array).
    int dim;
    // index of tag or zero.
    // TOOD: Comment doesn't match name.
    int data_len;
};

#define INITIALS struct initials_table

#ifndef SMALLC

// Check if 'sname' is a struct member.
SYMBOL *find_member (TAG_SYMBOL * tag,
                     char *sname);

#endif
