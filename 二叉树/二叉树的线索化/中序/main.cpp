#include <stdio.h>
#include <stdlib.h>

ThreadNode *pre = NULL; //全局变量pre,指向当前访问结点的前驱
struct ElemType
{
    char value;
};

typedef struct ThreadNode
{
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag; //左右线索标志
} ThreadNode, *ThreadTree;

//初步建成的树 ltag和rtag都为0 表示左右指针都指向孩子结点  即还未线索化

void InThread(ThreadTree T)
{
    if (T != NULL)
    {
        InThread(T->lchild);
        visit(T);
        InThread(T->rchild);
    }
}

void visit(ThreadNode *q)
{
    if (q->lchild == NULL)
    {
        q->lchild = pre;
        q->ltag = 1;
    }
    if (pre != NULL && pre->rchild == NULL)
    {
        pre->rchild = q;
        pre->rtag = 1;
    }
    pre = q;
}

/**
 * @description:  中序线索化二叉树T
 * @param {type} 
 * @return {type} 
 */
void CreateInThread(ThreadTree T)
{
    pre = NULL;
    if (T != NULL)
    {
        InThread(T);
        if (pre->rchild == NULL)
        {
            pre->rtag = 1; //处理遍历的最后一个结点
        }
    }
}

/**
 * @description:  找到以p为根的子树中，第一个被中序遍历的结点
 * @param {type} 
 * @return {type} 
 */
ThreadNode *FirstNode(ThreadNode *p)
{
    //循环找到最左下结点(不一定是叶结点)
    while (p->ltag == 0)
        p = p->lchild;
    return p;
}

/**
 * @description:  在中序线索二叉树中找到结点p的后继结点
 * @param {type} 
 * @return {type} 
 */
ThreadNode *NextNode(ThreadNode *p)
{
    //右子树中最左下结点
    if (p->rtag == 0)
        return FirstNode(p->rchild);
    else
        return p->rchild; //rtag==1直接返回后继线索
}

/**
 * @description:  对中序线索二叉树进行中序遍历(利用线索实现的非递归算法)
 * @param {type}   
 * @return {type} 
 */
void InOrder(ThreadNode *T) //空间复杂度O(1)
{
    for (ThreadNode *p = FirstNode(T); p != NULL; p = NextNode(p))
        visit(p);
}

/**
 * @description:  找到以p为根的子树中，最后一个被中序遍历的结点
 * @param {type} 
 * @return {type} 
 */
ThreadNode *LastNode(ThreadNode *p)
{
    //循环找到最右下结点(不一定是叶结点)
    while (p->rtag == 0)
        p = p->rchild;
    return p;
}

/**
 * @description: 在中序线索二叉树中找到结点p的前驱结点
 * @param {type} 
 * @return {type} 
 */
ThreadNode *PreNode(ThreadNode *p)
{
    if (p->ltag == 0)
        return LastNode(p->lchild);
    else
        return p->lchild;
}

/**
 * @description: 对中序线索二叉树进行逆向中序遍历
 * @param {type} 
 * @return {type} 
 */
void RevInOrder(ThreadNode *T)
{
    for (ThreadNode *p = LastNode(T); p != NULL; p = PreNode(p))
        visit(p);
}