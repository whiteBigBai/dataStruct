#include <stdio.h>
#include <stdlib.h>

struct ElemType
{
    int value;
};

//二叉树的结点(链式存储)

//找左右孩子结点 通过指针超简单
//找父结点只能从根开始遍历寻找

typedef struct BiTNode
{
    ElemType data;                   //数据域
    struct BiTNode *lchild, *rchild; //左,右孩子指针
} BiTNode, *BiTree;

//n个结点的二叉链表共有2n个指针,有n+1个空链域(可以用于构造线索二叉树)

int main(int argc, char *argv[])
{
    //定义一棵空树
    BiTree root = NULL;
    //插入根结点
    root = (BiTree)malloc(sizeof(BiTNode));
    root->data = {1};
    root->lchild = NULL;
    root->rchild = NULL;
    //插入新结点
    BiTNode *p = (BiTNode *)malloc(sizeof(BiTNode));
    p->data = {2};
    p->lchild = NULL;
    p->rchild = NULL;
    root->lchild = p; //作为根结点的左孩子

    return 0;
}
