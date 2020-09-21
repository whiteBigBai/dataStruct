#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct DNode
{
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

/**
 * 在p结点之后插入s结点
 **/
bool InsertNextNode(DNode *p, DNode *s)
{
    if (p == NULL || s == NULL)
        return false;
    s->next = p->next;
    if (p->next != NULL) //如果p结点有后继结点
        p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}