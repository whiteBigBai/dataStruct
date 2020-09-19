#include <iostream>
typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;

} LNode, *LinkList;

/**
 * @description: 判断循环链表是否为空
 */
bool Empty(LinkList L){
    if(L->next==L)
        return true;
    else
        return false;
}