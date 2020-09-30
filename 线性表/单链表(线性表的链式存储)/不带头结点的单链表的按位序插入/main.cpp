#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;

} LNode, *LinkList;
bool ListInsert(LinkList &L, int i, ElemType e)
{
    if (i < 1)
        return false;
    if (i == 1)
    {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L = s;
        return true;
    }
    LNode *p;
    int j = 1; //当前p指向的是第几个结点
    p = L;     //p指向第1个结点（注意 不是第0个）
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

int mian()
{
    return 0;
}
