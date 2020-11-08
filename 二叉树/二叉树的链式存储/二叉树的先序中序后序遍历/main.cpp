#include <stdio.h>
#include <stdlib.h>

struct ElemType
{
    int value;
};

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

/**
 * @description:  先序遍历
 * @param {type} 
 * @return {type} 
 */
void PreOrder(BiTree T)
{
    if (T != NULL)
    {
        visit(T);            //访问根结点
        PreOrder(T->lchild); //递归遍历左子树
        PreOrder(T->rchild); //递归遍历右子树
    }
}

/**
 * @description: 中序遍历
 * @param {type} 
 * @return {type} 
 */
void InOrder(BiTree T)
{
    if (T != NULL)
    {
        InOrder(T->lchild); //递归遍历左子树
        visit(T);           //访问根结点
        InOrder(T->rchild); //递归遍历右子树
    }
}

/**
 * @description: 后序遍历
 * @param {type} 
 * @return {type} 
 */
void PostOrder(BiTree T)
{
    if (T != NULL)
    {
        PostOrder(T->lchild); //递归遍历左子树
        PostOrder(T->rchild); //递归遍历右子树
        visit(T);             //访问根结点
    }
}

void visit(BiTNode *p)
{
    printf("%c", p->data);
}

/**
 * @description: 求树的深度
 * @param {type} 
 * @return {type} 
 */
int treeDepth(BiTree T)
{
    if (T == NULL)
    {
        return 0;
    }
    else
    {
        int l = treeDepth(T->lchild);
        int r = treeDepth(T->rchild);
        return l > r ? l + 1 : r + 1; //树的深度=Max(左子树深度，右子树深度)+1
    }
}
