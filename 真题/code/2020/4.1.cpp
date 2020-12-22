#include <stdio.h>
#include <stdlib.h>

LinkList DisCreat(LinkList &A)
{
    i = 0;
    B = (LinkList)malloc(sizeof(LNode));
    B->next = NULL;
    LNode *ra = A, *rb = B;

    p = A->next;
    A->next = NULL;
    while (p != NULL)
    {
        i++;
        if (i % 2 == 0)
        {
            rb->next = p;
            rb = p;
        }
        else
        {
            ra->next = p;
            ra = p;
        }
        p = p->next;
    }
    ra->next = NULL;
    rb->next = NULL;
    return B;
}