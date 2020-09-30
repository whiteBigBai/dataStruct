#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct DNode
{
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

/**
 * 删除p结点的后继结点
 **/
bool DeleteNextNode(DNode *p)
{
    if (p == NULL)
        return false;
    DNode *q = p->next; //找到p的后继结点q
    if (q == NULL)      //如果p没有后继
        return false;
    p->next = q->next;
    if (q->next != NULL) //q结点不是最后一个节点
        q->next->prior = p;
    free(q);
    return true;
}

void DestoryList(DLinkList &L)
{
    //循环释放各个数据结点
    while (L->next != NULL)
        DeleteNextNode(L);
    free(L);
    L = NULL;
}