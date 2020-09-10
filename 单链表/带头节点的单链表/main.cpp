#include <iostream>
typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;

} LNode, *LinkList;

bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
        return false;
    L->data = NULL;
    return true;
}

bool Empty(LinkList L)
{
    if (L->next == NULL)
        return true;
    else
        return false;
}

int main()
{
    return 0;
}