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

void PostThread(ThreadTree T)
{
    if (T != NULL)
    {
        PostThread(T->lchild);
        PostThread(T->lchild);
        visit(T);
    }
}

void visit(ThreadNode *q)
{
    if (q->lchild == NULL)
    { //左子树为空 建立前驱线索
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
 * @description:  后续线索化二叉树T
 * @param {type} 
 * @return {type} 
 */
void CreatePostThread(ThreadTree T)
{
    pre = NULL;
    if (T != NULL)
    {
        PostThread(T);
        if (pre->rchild == NULL)
        {
            pre->rtag = 1;
        }
    }
}