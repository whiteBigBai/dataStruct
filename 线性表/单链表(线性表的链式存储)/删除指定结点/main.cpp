#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;

} LNode, *LinkList;

/**
 * 删除指定结点p
 **/
bool DeleteNode(LNode *p)
{
    if (p == NULL)
        return false;
    LNode *q = p->next;
    p->data = p->next->data;
    p->next = q->next;
    free(q);
    return true;
}