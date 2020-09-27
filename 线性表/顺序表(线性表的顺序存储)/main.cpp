#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10
typedef int ElemType;

typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;

/**
 * @description:  初始化顺序表
 * @param {type} 
 * @return {type} 
 */
void InitList(SqList &L)
{
    for (int i = 0; i < MaxSize; i++)
    {
        L.data[i] = 0;
    }
    L.length = 0;
}