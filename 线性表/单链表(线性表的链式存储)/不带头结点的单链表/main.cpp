#include <stdio.h>
#include <stdlib.h>
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

int	main(int argc, char *argv[])
{
    return 0;
}
