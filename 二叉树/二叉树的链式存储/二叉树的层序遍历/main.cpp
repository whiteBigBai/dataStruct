#include <stdio.h>
#include <stdlib.h>

//二叉树的结点(链式存储)
typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//链式队列结点
typedef struct LinkNode
{
    BiTNode *data; //存结点的指针而不是结点
    struct LinkNode *next;
} LinkNode;

typedef struct
{
    LinkNode *front, *rear; //队头队尾
} LinkQueue;

/**
 * @description: 层序遍历
 * @param {type} 
 * @return {type} 
 */
void LevelOrder(BiTree T)
{
    LinkQueue Q;
    InitQueue(Q); //初始化辅助队列
    BiTree p;
    EnQueue(Q, T); //将根结点入队
    while (!IsEmpty(Q))
    {                  //队列不空则循环
        DeQueue(Q, p); //队头结点出队
        visit[p];      //访问出队结点
        if (p->lchild != NULL)
            EnQueue(Q, p->lchild); //左孩子入队
        if (p->rchild != NULL)
            EnQueue(Q, p->rchild); //右孩子入队
    }
}