#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
/**
 * 按位查找,返回第i个元素（带头结点）
 **/
LNode *GetElem(LinkList L, int i)
{
    if (i < 0)
        return NULL;
    int j = 0;
    LNode *p = L;
    while (p!=NULL && j <i)
    {
        p = p->next;
        j++;
    }
    return p;
}