#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;

} LNode, *LinkList;
/**
 * @description:  判断结点p是否是循环单链表的表尾结点
 * @param {type} 
 * @return {type} 
 */
bool isTail(LinkList L,LNode *p){
    if(p->next==L)
        return true;
    else
        return false;
}