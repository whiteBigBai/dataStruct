#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct DNode
{
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;


bool Empty(DLinkList L){
    if(L->next==NULL)
        return true;
    else
        return false;
}