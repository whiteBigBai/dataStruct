#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;

} LNode, *LinkList;

//后插操作：在p结点之后插入元素e
bool InsertNextNode(LNode *p, ElemType e)
{
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s==NULL) //若内存分配失败
        return false;
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}

int	main(int argc, char *argv[])
{
    return 0;
}