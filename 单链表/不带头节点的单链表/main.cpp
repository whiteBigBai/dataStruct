#include <iostream>
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

bool InitList(LinkList &L)
{
    L = NULL;
    return true;
}

bool Empty(LinkList L)
{
    return (L == NULL);
}

int main()
{
    return 0;
}