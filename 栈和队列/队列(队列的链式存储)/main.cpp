#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LinkNode
{ //链式队列结点
    ElemType data;
    struct LinkNode *next;
} LinkNode;

typedef struct
{                           //链式队列
    LinkNode *front, *rear; //队列的队头和队尾指针
} LinkQueue;

/**
 * @description:  初始化队列(带头结点) 
 * @param {type} 
 * @return {type} 
 */
void InitQueue(LinkQueue &Q)
{
    //申请头结点，并将队头和队尾指针都指向头结点
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front->next = NULL; //头结点的next指向NULL
}

/**
 * @description: 初始化队列(不带头结点) 
 * @param {type} 
 * @return {type} 
 */
void InitQueue1(LinkQueue &Q)
{
    Q.front = NULL;
    Q.rear = NULL;
}

/**
 * @description:  判断队列是否为空(带头结点)
 * @param {type} 
 * @return {type} 
 */
bool IsEmpty(LinkQueue Q)
{
    if (Q.front == Q.rear) //或者if(Q.front->next==NULL)
        return true;
    else
        return false;
}
/**
 * @description: 判断队列是否为空(不带头结点) 
 * @param {type} 
 * @return {type} 
 */
bool IsEmpty1(LinkQueue Q)
{
    if (Q.front == NULL)
        return true;
    else
        return false;
}

/**
 * @description: 新元素入队(带头结点) 
 * @param {type} 
 * @return {type} 
 */
void EnQueue(LinkQueue &Q, ElemType e)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = e;
    s->next = NULL; //创建新结点，插入到链尾
    Q.rear->next = s;
    Q.rear = s;
}

/**
 * @description:  新元素入队(不带头结点)
 * @param {type} 
 * @return {type} 
 */
void EnQueue1(LinkQueue &Q, ElemType e)
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
 * @description: 出队操作(带头结点) 
 * @param {type} 
 * @return {type} 
 */
bool DeQueue(LinkQueue &Q, ElemType &e)
{
    if (Q.front == Q.rear)
        return false; //空队
    LinkNode *p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)
        Q.rear = Q.front;
    free(p);
    return true;
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