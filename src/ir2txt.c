//#define PRINT_CODES

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "ir-table.c"

void
put_name (int c)
{
    int i, l;
    char *n;
    n = codes[c].name;
    l = strlen (n);
    for (i = 0; i < l; i++)
        putchar (tolower (n[i]));
}

int
main (int argc, char *argv[])
{
    int c, imax, lo, hi;
    char p;

    imax = sizeof (codes) / sizeof (struct ircode);
    while ((c = getchar ()) > -1) {
        c--;
#ifdef PRINT_CODES
        printf (";%02x\n", c + 1);
#endif
        if (c > imax - 1) {
            puts ("ill\n");
            continue;
        }
        putchar ('v');
        put_name (c);
        if ((p = codes[c].param))
            putchar (' ');
        switch (p) {
        case 'b':   // byte
        case 'w':   // word
        case 'l':   // local label index
            lo = getchar ();
            hi = getchar ();
            printf ("%d", lo + (hi << 8));
            break;
        // global label string
        case 's':
            while ((c = getchar ()))
                putchar (c);
        }
        putchar (10);
    }
    return 0;
}
