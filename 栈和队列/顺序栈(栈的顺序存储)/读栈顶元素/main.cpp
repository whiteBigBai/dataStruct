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
 * @description: 
 * @param {type} 
 * @return {type} 
 */
bool GetTop(SqStack S, ElemType &e)
{
    if (S.top == -1) //栈空 报错
        return false;
    e = S.data[S.top];//e 记录栈顶元素
    return true;
}