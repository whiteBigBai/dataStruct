#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10 //定义队列中元素的最大个数
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize]; //用静态数组存放队列元素
    int front, rear;        //队头指针和队尾指针  队尾指针指向队尾元素的后一个位置(下一个应该插入的位置)
} SqQueue;

/**
 * @description: 初始化队列
 * @param {type} 
 * @return {type} 
 */
void InitQueue(SqQueue &Q)
{
    Q.front = Q.rear = 0; //初始时，队头和队尾指针都指向0
}

/**
 * @description:  判断队列是否为空
 * @param {type} 
 * @return {type} 
 */
bool QueueEmpty(SqQueue Q)
{
    if (Q.rear == Q.front) //队空条件
        return true;
    else
        return false;
}

/**
 * @description: 判断队列是否已满
 * @param {type} 
 * @return {type} 
 */
bool QueueFull(SqQueue Q)
{
    if ((Q.rear + 1) % MaxSize == Q.front)
        return true;
    else
        return false;
}

/**
 * @description:   入队操作(循环队列)
 * @param {type} 
 * @return {type} 
 */
bool EnQueue(SqQueue &Q, ElemType e)
{
    if ((Q.rear + 1) % MaxSize == Q.front) //队列满报错
        return false;
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MaxSize; //队尾指针加1取模
    return true;
}

/**
 * @description:  出队操作
 * @param {type} 
 * @return {type} 
 */
bool DeQueue(SqQueue &Q, ElemType &e)
{
    if (Q.front == Q.rear) //队空，报错
        return false;
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

/**
 * @description: 获取队头元素的值
 * @param {type} 
 * @return {type} 
 */
bool GetHead(SqQueue Q, ElemType &e)
{
    if (Q.front == Q.rear) //队空，报错
        return false;
    e = Q.data[Q.front];
    return true;
}

/**
 * @description: 队列元素个数
 * @param {type} 
 * @return {type} 
 */
int ElemCount(SqQueue Q)
{
    return (Q.rear + MaxSize - Q.front) % MaxSize;
}

int main(int argc, char *argv[])
{
    return 0;
}
