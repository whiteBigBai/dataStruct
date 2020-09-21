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
 * @description: 出栈操作 
 * @param {type} 
 * @return {type} 
 */
bool Pop(SqStack &S, ElemType &e)
{
    if (S.top == -1) //栈空 报错
        return false;
    e = S.data[S.top];//栈顶元素先出栈
    S.top = S.top - 1;//指针再减1
    return true;
}
int	main(int argc, char *argv[])
{
    return 0;
}

