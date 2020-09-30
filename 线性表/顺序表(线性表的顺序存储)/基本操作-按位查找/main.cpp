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
 * @description:  按位查找元素 
 * @param {type} 
 * @return {type} 
 */
ElemType GetElem(SqList L, int i)
{
    return L.data[i - 1];
}
/**
 * @description: 初始化线性表 
 * @param {type} 
 * @return {type} 
 */
void InitList(SqList &L)
{

    for (int i = 0; i < MaxSize; i++)
        L.data[i] = 0;
    L.length = 0;
}

/**
 * @description:   插入元素
 * @param {type} 
 * @return {type} 
 */
bool ListInsert(SqList &L, int i, ElemType e)
{
    if (i < 1 || i > L.length + 1)
        return false;
    if (i >= MaxSize)
        return false;
    for (int j = L.length; j >= i; j--)
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;
    L.length++;
    return true;
}

int main(int argc, char **argv)
{
    SqList L;
    InitList(L);
    ListInsert(L, 1, 1);
    ListInsert(L, 2, 2);
    ListInsert(L, 3, 3);
    ListInsert(L, 4, 4);
    ListInsert(L, 5, 5);
    ElemType result = GetElem(L, 4);
    printf("result=%d", result);
    return 0;
}