#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10 //定义队列中元素的最大个数
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize]; //用静态数组存放队列元素
    int front, rear;        //队头指针和队尾指针  队尾指针指向队尾元素
    int size;
} SqQueue;

/**
 * @description: 初始化队列
 * @param {type} 
 * @return {type} 
 */
void InitQueue(SqQueue &Q)
{
    Q.front = 0;          //初始时，队头指针指向0
    Q.rear = MaxSize - 1; //队尾指针指向MaxSize-1
    Q.size = 0;
}

/**
 * @description:  判断队列是否为空
 * @param {type} 
 * @return {type} 
 */
bool QueueEmpty(SqQueue Q)
{
    if ((Q.rear + 1) % MaxSize == Q.front) //队空条件
        return true;
    else
        return false;
}

/**
 * @description: 判断队列是否已满 1.牺牲一个空间(Q.rear+2=Q.front) 2.增加tag或者size字段
 * @param {type} 
 * @return {type} 
 */
bool QueueFull(SqQueue Q)
{
    if (Q.size == MaxSize)
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
    if (Q.size==MaxSize) //队列满报错
        return false;
    Q.rear = (Q.rear + 1) % MaxSize; //队尾指针加1取模
    Q.data[Q.rear] = e;
    Q.size++;
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
    Q.size--;
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
    return Q.size;
}

int main(int argc, char *argv[])
{
    return 0;
}
