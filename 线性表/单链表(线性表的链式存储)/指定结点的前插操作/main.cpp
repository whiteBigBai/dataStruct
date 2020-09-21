#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;

} LNode, *LinkList;

//前插操作 在p结点之前插入元素e
bool InsertPriorNode(LNode *p,ElemType e){
    if(p==NULL)
        return false;
    LNode *s=(LNode*)malloc(sizeof(LNode));
    if(s==NULL)
        return false;
    s->next=p->next;
    p->next=s;
    s->data=p->data;
    p->data=e;
    return true;
}
int	main(int argc, char *argv[])
{
    return 0;
}