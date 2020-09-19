/*
 * @Date: 2020-09-19 15:04:22
 * @LastEditors: bailiang
 * @LastEditTime: 2020-09-19 15:52:14
 */
#include <iostream>
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