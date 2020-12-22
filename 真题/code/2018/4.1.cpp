#include <stdio.h>
#include <stdlib.h>
typedef struct LinkNode
{
    int data;              //存放数据
    struct LinkNode *next; //存放指针
} LinkNode, *LinkList;

void Print_Reverse_List(LinkList L)
{
    if (L == NULL)
    {
        return;
    }
    if (L->next != NULL)
    {
        Print_Reverse_List(L->next);
    }
    printf("%d ", L->data);
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
    Print_Reverse_List(L);
    return 0;
}