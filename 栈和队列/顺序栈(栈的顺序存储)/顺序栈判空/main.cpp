#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10
typedef int ElemType;
typedef struct{
    ElemType data[MaxSize];
    int top;
}SqStack;

/**
 * @description: 判断栈空
 * @param {type} 
 * @return {type} 
 */
bool StackEmpty(SqStack S){
    if(S.top==-1)
        return true;
    else
        return false;
}