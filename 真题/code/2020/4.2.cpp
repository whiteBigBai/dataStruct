#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode
{
    int data; //数据
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef BiTNode *ElemType;
typedef struct LinkNode
{ //链式队列结点
    BiTNode *data;
    struct LinkNode *next;
} LinkNode;

typedef struct
{                           //链式队列
    LinkNode *front, *rear; //队列的队头和队尾指针
} LinkQueue;

/**
 * @description: 初始化队列(不带头结点) 
 * @param {type} 
 * @return {type} 
 */
void InitQueue(LinkQueue &Q)
{
    Q.front = NULL;
    Q.rear = NULL;
}

/**
 * @description: 判断队列是否为空(不带头结点) 
 * @param {type} 
 * @return {type} 
 */
bool IsEmpty(LinkQueue Q)
{
    if (Q.front == NULL)
        return true;
    else
        return false;
}

/**
 * @description:  新元素入队(不带头结点)
 * @param {type} 
 * @return {type} 
 */
void EnQueue(LinkQueue &Q, ElemType e)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = e;
    s->next = NULL;
    if (Q.front == NULL)
    {
        Q.front = s;
        Q.rear = s;
    }
    else
    {
        Q.rear->next = s;
        Q.rear = s;
    }
}

/**
 * @description:  出队操作(不带头结点)
 * @param {type} 
 * @return {type} 
 */
bool DeQueue(LinkQueue &Q, ElemType &e)
{
    if (Q.front == NULL) //空队
        return false;
    LinkNode *p = Q.front;
    e = p->data;
    Q.front = p->next;
    if (Q.rear == p)
    {
        Q.front = NULL;
        Q.rear = NULL;
    }
    free(p);
    return true;
}

bool CreateBiTree(BiTree *T)
{
    int e;
    scanf("%d", &e);
    if (e == 0)
    {
        *T = NULL;
    }
    else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if (!T)
        {
            exit(-2);
        }
        (*T)->data = e;
        CreateBiTree(&(*T)->lchild); //创建左子树
        CreateBiTree(&(*T)->rchild); //创建右子树
    }
    return true;
}

void visit(ElemType &e)
{
    printf("%d ", e->data);
}

void LevelOrder(BiTree T)
{
    LinkQueue Q;
    InitQueue(Q); //初始化辅助队列
    BiTNode *p = (BiTNode *)malloc(sizeof(BiTNode));
    EnQueue(Q, T); //将根结点入队
    int max=0;
    while (!IsEmpty(Q))
    {                  //队列不空则循环
        DeQueue(Q, p); //队头结点出队
        visit(p);      //访问出队结点
        if(p->data>max){
            max=p->data;
        }
        
        if (p->lchild != NULL)
            EnQueue(Q, p->lchild); //左孩子入队
        if (p->rchild != NULL)
            EnQueue(Q, p->rchild); //右孩子入队
    }
    printf("%d ", max);
}

int main(int argc, char **argv)
{
    //10 25 0 5 0 0 2 6 0 0 0
    BiTree T;
    printf("创建树，输入0为空树：\n");
    CreateBiTree(&T);
    LevelOrder(T);
    return 0;
}