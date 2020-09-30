#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10 //定义栈中元素的最大个数
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize]; //静态数组存放栈中元素
    int top;                //栈顶指针
} SqStack;