#include <stdio.h>
#include <stdlib.h>

typedef struct st
{
    int roll;
    char name[20];
    float percentage;
    struct st *next;
} ST;

void ADD_DETAILS(ST **);
void SHOW(ST *);
void MODIFY(ST *);
void SORT(ST *);
void DELETE(ST **);
void SAVE(ST *);
void LOAD(ST **);
