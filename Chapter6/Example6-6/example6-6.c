#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define INT 1
#define FLOAT 2
#define STRING 3

#define CHOOSEN_TYPE (INT)

#define NSYM (2)

struct {
    char *name;
    int flags;
    int utype;
    union {
        int ival;
        float fval;
        char *sval;
    } u;
} symtab[NSYM];

int main(){

    symtab[0].name = "first";
    symtab[0].flags = 1;
    symtab[0].utype = CHOOSEN_TYPE;

    if(symtab[0].utype == INT) {
        symtab[0].u.ival = 10;
        printf("%d\n", symtab[0].u.ival);
    } else if(symtab[0].utype == FLOAT) {
        symtab[0].u.fval = 10.4;
        printf("%f\n", symtab[0].u.fval);
    } else if(symtab[0].utype == STRING) {
        symtab[0].u.sval = "value";
        printf("%s\n", symtab[0].u.sval);
    } else
        printf("bad type %d in symtab[0].utype\n", symtab[0].utype);

    return 0;
}

