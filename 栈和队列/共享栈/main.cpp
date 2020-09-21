#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int top0;
    int top1;
} ShStack;

/**
 * @description: 初始化共享栈 
 * @param {type} 
 * @return {type} 
 */
void InitStack(ShStack &S)
{
    S.top0 = -1;
    S.top1 = MaxSize;
}

/**
 * @description: 判断栈满 
 * @param {type} 
 * @return {type} 
 */
bool FullStack(ShStack S)
{
    if (S.top0 + 1 == S.top1)
        return true;
    else
        return false;
}
