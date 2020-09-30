#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;

typedef struct LinkNode
{
    ElemType data; //数据域
    struct LinkNode *next;//指针域
} * LiStack; //栈类型定义