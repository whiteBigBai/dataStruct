#include <stdio.h>
#include <stdlib.h>
typedef struct LinkNode
{
    int data;              //存放数据
    struct LinkNode *next; //存放指针
} LinkNode, *LinkList;

LinkList ListTailInsert(LinkList &L)
{
    int x;
    L = (LinkList)malloc(sizeof(LinkNode));
    LinkNode *s, *r = L;
    scanf("%d", &x);
    while (x != 666)
    {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

bool Adjust(LinkList &L)
{
    LinkNode *p1, *pre, *p, *q;
    if (L->next == NULL)
    {
        return false;
    }
    p1 = L->next;
    pre = p1;
    p = p1->next;

    while (p)
    {
        q = p->next;
        if (p->data >= p1->data)
        {
            pre = p;
            p = q;
        }
        else
        {
            pre->next = p->next;
            p->next = L->next;
            L->next = p;
            p = q;
        }
    }
    return true;
}


int main(int argc, char **argv)
{
    LinkList  L;
    ListTailInsert(L);
    /*while (P!=NULL)
    {
        printf("%d", P->data);
        P=P->next;
    }
    printf("\n");*/
    
    Adjust(L);
    LinkList P=L->next;
    while (P!=NULL)
    {
        printf("%d", P->data);
        P=P->next;
    }
}
