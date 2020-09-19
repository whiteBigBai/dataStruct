/*
 * @Date: 2020-09-19 09:07:23
 * @LastEditors: bailiang
 * @LastEditTime: 2020-09-19 15:51:47
 */
#include <iostream>
typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;

} LNode, *LinkList;

/**
 * @description: 初始化一个循环单链表
 * @param {type} 
 * @return {type} 
 */
bool InitList(LinkList &L){
    L=(LNode *)malloc(sizeof(LNode));//分配一个头结点
    if(L==NULL) //内存不足，分配失败
        return false;
    L->next=L; //头结点的next指向头结点
    return true;

}