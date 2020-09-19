/*
 * @Date: 2020-09-19 15:12:05
 * @LastEditors: bailiang
 * @LastEditTime: 2020-09-19 15:52:26
 */
#include <iostream>
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