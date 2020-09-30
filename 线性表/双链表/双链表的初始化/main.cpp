#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct DNode
{
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

/**
 * 初始化双链表
 **/
bool InitDLinkList(DLinkList &L)
{
    L = (DNode *)malloc(sizeof(DNode)); //分配一个头结点
    if (L == NULL) //内存不足，分配失败
        return false;
    L->prior = NULL;//头结点的prior永远指向NULL
    L->next = NULL;//头结点之后暂时还没有结点
    return true;
}
/**
 * 判断双链表是否为空（带头结点）
 **/
bool Empty(DLinkList L){
    if(L->next==NULL)
        return true;
    else
        return false;
}