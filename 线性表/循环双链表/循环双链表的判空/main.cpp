#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct DNode
{
    ElemType data;
    struct DNode *prior, *next;

} DNode, *DLinkList;

/**
 * @description:  判断循环双链表是否为空
 * @param {type} 
 * @return {type} 
 */
bool Empty(DLinkList L){
    if(L->next==L)
        return true;
    else
        return false;
}