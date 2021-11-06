#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

/* Write a cross-referencer that prints a list of all words in a document, and,
 * for each word, a list of the line numbers on which it occurs. Remove noise
 * words like "the", "and", and so on. */

struct llist{ /* the line list node */
    int line;   /* occurence line */
    struct llist* prev; /* prev line list node */
};
/* Note: store from last to first for easier comparison with repeated lines */ 

struct tnode{ /* the tree node */
    char *word;     /* points to the text */
    int count;      /* number of occurences */
    struct llist * linelist; /* list on line appearances */
    struct tnode *left; /* left child */
    struct tnode *right;/* right child */
};

struct tnode *addtree(struct tnode *, char *, int line);
void treeprint(struct tnode *);
struct llist *addline(struct llist* prev, int line);
int getword(char *, int, int*);

char *exclude_words[] = {
    "the",
    "and",
    "to",
    "a",
    "an"
};

#define NEXCLUDES (sizeof exclude_words / sizeof exclude_words[0])

/* word frequency count */
int main(){
    struct tnode *root;
    char word[MAXWORD];
    int currentLine = 1;

    root = NULL;

    while(getword(word, MAXWORD, &currentLine) != EOF)
        if(isalpha(word[0]))
            root = addtree(root, word, currentLine);

    treeprint(root);

    return 0;
}

struct tnode *talloc(void);
char *strdup_(char *);
int check_exclude_words(char *w);

/* check_exclude_words: check word agains exclude list, return 1 if matches any, 
 * 0 otherwise */
int check_exclude_words(char *w){
    int i = 0;

    for(i=0; i<NEXCLUDES; i++){
        if(strcmp(w, exclude_words[i])== 0)
            return 1;
    }
    return 0;
}

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w, int line){
    int cond;

    /* check for excluded words */
    if(check_exclude_words(w))
        return p;

    if(p==NULL){ /* a new word has arrived */
        p = talloc(); /* make a new node */
        p->word = strdup_(w);
        p->count = 1;
        p->left = p->right = NULL;
        p->linelist = addline(NULL, line);
    } else if((cond = strcmp(w, p->word)) == 0) {
        p->count++; /* repeated word */
        /* check if needs to add line */
        if(p->linelist->line != line)
            p->linelist = addline(p->linelist, line);
    } else if(cond < 0) /* less than into left subtree */
        p->left = addtree(p->left, w, line);
    else /* greater than into right subtree */
        p->right = addtree(p->right, w, line);

    return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p){
    if(p!=NULL){
        treeprint(p->left);
        struct llist *lineptr = p->linelist;
        printf("%4d %s: ", p->count, p->word);
        while(lineptr != NULL){
            printf("%d", lineptr->line);
            lineptr = lineptr->prev;
            if(lineptr != NULL)
                printf(",");
        }
        printf("\n");
        treeprint(p->right);
    }
}

struct llist *lalloc(void);
struct llist *addline(struct llist* prev, int line){
    struct llist* lnode = lalloc();
    if(lnode == NULL) {
        fprintf(stderr, "Failed to allocate lnode\n");
        return NULL;
    }
    lnode->line = line;
    lnode->prev = prev;
    return lnode;
}

#include <stdlib.h>

/* talloc: make a tnode */
struct tnode *talloc(void){
    return (struct tnode *) malloc(sizeof(struct tnode));
}

/* lalloc: make a llist node */
struct llist *lalloc(void){
    return (struct llist *) malloc(sizeof(struct llist));
}

/* strdup_: make a duplicate of s */
char *strdup_(char *s){
    char *p;

    p = (char *) malloc(strlen(s)+1); /* +1 for '\0' */
    if(p!=NULL)
        strcpy(p,s);
    return p;
}

/* getword: get next word or character from input */
int getword(char *word, int lim, int *currentLine){
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while(isspace(c = getch())){
        if(c == '\n') {
            (*currentLine)++;
        }
    }

    if(c != EOF)
        *w++ = c;

    if(!isalpha(c)){
        *w = '\0';
        return c;
    }

    for(; --lim > 0; w++)
        if(!isalnum(*w = getch())){
            ungetch(*w);
            break;
        }

    *w = '\0';
    return word[0];

}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void){ /* get a (possibly pushed back) character */
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){ /* push character back on input */
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
