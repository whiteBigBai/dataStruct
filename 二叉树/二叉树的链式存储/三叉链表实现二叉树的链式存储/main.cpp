#include <stdio.h>
#include <stdlib.h>

struct ElemType
{
    int value;
};
//三叉链表--->方便找父结点
typedef struct BiTNode
{
    ElemType data;                   //数据域
    struct BiTNode *lchild, *rchild; //左,右孩子指针
    struct BiTNode *parent; //父结点指针
} BiTNode, *BiTree;