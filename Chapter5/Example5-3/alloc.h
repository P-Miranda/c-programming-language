#ifndef ALLOC_H
#define ALLOC_H

#define ALLOCSIZE 10000 /* size of available space*/

char *alloc(int n); /* return pointer to n characters */
void afree(char *p); /* free storage pointed to by p */

#endif
