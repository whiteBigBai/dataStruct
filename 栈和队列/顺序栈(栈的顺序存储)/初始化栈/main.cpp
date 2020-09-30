#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int top;
} SqStack;

/**
 * @description:  初始化顺序栈
 * @param {type} 
 * @return {type} 
 */
void InitStack(SqStack &S)
{
    S.top = -1;
}