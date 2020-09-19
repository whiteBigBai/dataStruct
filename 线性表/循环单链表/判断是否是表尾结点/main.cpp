/*
 * @Date: 2020-09-19 11:28:40
 * @LastEditors: bailiang
 * @LastEditTime: 2020-09-19 15:51:36
 */
#include <iostream>
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