#include <iostream>
typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;

} LNode, *LinkList;

LinkList List_HeadInsert(LinkList &L)
{
    LNode *s;
    ElemType x;
    L = (LinkList)malloc(sizeof(LNode)); //创建头结点
    L->next = NULL;                      //初始化为空链表
    scanf("%d", &x);
    while (x != 666)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

int main()
{
    return 0;
}