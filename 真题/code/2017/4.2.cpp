#include <stdio.h>
#include <stdlib.h>
typedef struct LinkNode
{
    int data;              //存放数据
    struct LinkNode *next; //存放指针
} LinkNode, *LinkList;

LinkList DeleteMin(LinkList &L)
{
    LinkNode *pre = L, *p = pre->next;
    LinkNode *minPre = pre, *minP = p;
    while (p != NULL)
    {
        if (p->data < minP->data)
        {
            minP = p;
            minPre = pre;
        }
        pre = p;
        p = p->next;
    }
    minPre->next = minP->next;
    free(minP);
    return L;
}

LinkList DeleteMax(LinkList &L)
{
    LinkNode *pre = L, *p = pre->next;
    LinkNode *maxPre = pre, *maxP = p;
    while (p != NULL)
    {
        if (p->data > maxP->data)
        {
            maxP = p;
            maxPre = pre;
        }
        pre = p;
        p = p->next;
    }
    maxPre->next = maxP->next;
    free(maxP);
    return L;
}

int main(int argc, char **argv)
{
    //创建单链表
    LinkList L = (LinkList)malloc(sizeof(LinkNode));
    LinkNode *p;
    L->next = NULL;
    p = L;

    for (int i = 0; i < 7; i++)
    {
        LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = i + 1;
        //尾插法
        p->next = s;
        p = s;
    }
    p->next = NULL;

    L = DeleteMax(L);
    LinkNode *t = (LinkNode *)malloc(sizeof(LinkNode));
    t = L->next;
    while (t->next != NULL)
    {
        printf("%d", t->data);
        t = t->next;
    }

    return 0;
}