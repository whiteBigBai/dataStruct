#include <iostream>
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