#include <stdio.h>
#include <stdlib.h>

//辅助全局变量，用于查找结点p的前驱(中序前驱)
BiTNode *p;            //p指向目标结点
BiTNode *pre = NULL;   //指向当前访问节点的前驱
BiTNode *final = NULL; //用于记录最终结果

struct ElemType
{
    char value;
};

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void InOrder(BiTree T)
{
    if (T != NULL)
    {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

void visit(BiTNode *q)
{
    if (q == p)      //当前访问结点刚好是结点p
        final = pre; //找到p的前驱
    else
        pre = q; //pre指向当前访问的结点
}