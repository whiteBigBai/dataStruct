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
 * @description: 新元素入栈
 * @param {type} 
 * @return {type} 
 */
bool Push(SqStack &S, ElemType e)
{
    if (S.top == MaxSize - 1) //栈满 报错
        return false;
    S.top = S.top + 1;//指针先加1
    S.data[S.top] = e;//新元素入栈
    return true;
}