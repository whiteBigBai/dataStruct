#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

/**
 * 求表的长度
 **/
int Length(LinkList L)
{
    int len = 0;
    LNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}