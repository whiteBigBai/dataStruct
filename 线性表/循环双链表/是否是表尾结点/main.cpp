#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct DNode
{
    ElemType data;
    struct DNode *prior, *next;

} DNode, *DLinkList;

/**
 * @description: 判断结点p是否为循环双链表的表尾结点
 * @param {type} 
 * @return {type} 
 */
bool isTail(DLinkList L,DNode *p){
    if(p->next=L)
        return true;
    else
        return false;

}