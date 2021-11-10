#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define HASHSIZE 101

struct nlist{ /* table entry */
    struct nlist *next; /* next entry in chain */
    char *name;         /* defined name */
    char *defn;         /* replacement text */
};

static struct nlist *hashtab[HASHSIZE];     /* pointer table */


struct nlist *install(char *name, char *defn);
void printNList(struct nlist** hashtab, int tab_size);
void freeNList(struct nlist** hashtab, int tab_size);

/* word frequency count */
int main(){

    /* add some elements to hashtable */
    install("HASHSIZE", "101");
    install("MAXELEMEMS", "(1000)");
    install("MAX(a,b)", "((a > b) ? (a) : (b))");
    install("MIN(a,b)", "((a < b) ? (a) : (b))");

    printNList(hashtab, HASHSIZE);
    printf("Freeing hashtab...");
    freeNList(hashtab, HASHSIZE);
    printf("done!\n");

    return 0;
}

struct nlist *lookup(char *);
/* char *strdup(char *); */
unsigned hash(char *s);

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn){
    struct nlist *np;
    unsigned hashval;

    if((np = lookup(name)) == NULL) { /* not found */
        np = (struct nlist *) malloc(sizeof(*np));
        if(np == NULL || (np->name = strdup(name)) == NULL || (np->defn = strdup(defn)) == NULL)
            return NULL;

        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else {    /* already there */
        free((void *) np->defn);    /* free previous defn */
        if((np->defn = strdup(defn)) == NULL)
            return NULL;
        return np;
    }
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s){
    struct nlist *np;

    for(np = hashtab[hash(s)]; np != NULL; np = np->next)
        if(strcmp(s, np->name) == 0)
            return np; /* found */

    return NULL;    /* not found */
}

/* hash: form hash value for string s */
unsigned hash(char *s){
    unsigned hashval;

    for(hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;

    return hashval % HASHSIZE;
}

/* printNList: print hashtab contents */
void printNList(struct nlist** hashtab, int tab_size){
    int i;
    struct nlist *np = NULL;

    for(i=0;i<tab_size; i++){
        for(np = hashtab[i]; np != NULL; np=np->next)
            printf("Hashtab[%d]: name: %s | defn: %s\n", i, np->name, np->defn);
    }
    return;
}

/* freeNList: free all elements in table */
void freeNList(struct nlist** hashtab, int tab_size){
    int i;
    struct nlist *np = NULL;
    struct nlist *np_next = NULL;

    for(i=0;i<tab_size; i++){
        for(np = hashtab[i]; np != NULL; np=np_next){
            free((void*) np->name);
            free((void*) np->defn);
            np_next = np->next;
            free((void*) np);
        }
    }
    return;
}
