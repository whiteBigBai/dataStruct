#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LNode *LocateElem(LinkList L, ElemType e)
{
    LNode *p = L->next;
    while (p != NULL && p->data != e)
        p = p->next;
    return p;
}

int	main(int argc, char *argv[])
{
    return 0;
}
