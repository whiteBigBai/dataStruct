#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct DNode
{
    ElemType data;
    struct DNode *prior, *next;

} DNode, *DLinkList;

/**
 * @description: 初始化循环双链表
 * @param {type} 
 * @return {type} 
 */
bool InitDLinkList(DLinkList &L)
{
    L = (DNode *)malloc(sizeof(DNode));
    if (L == NULL)
        return false;
    L->prior = L;
    L->next = L;
    return true;
}