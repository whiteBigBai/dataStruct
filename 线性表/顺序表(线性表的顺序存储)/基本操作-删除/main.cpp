#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;

void InitList(SqList &L)
{
    for (int i = 0; i < MaxSize; i++)
    {
        L.data[i] = 0;
    }
    L.length = 0;
}

bool ListInsert(SqList &L, int i, ElemType e)
{
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= MaxSize)
        return false;
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

bool ListDelete(SqList &L, int i, ElemType &e)
{
    if (i < 1 || i > L.length)
        return false;
    e = L.data[i - 1];
    for (int j = i; i < L.length; j++)
        L.data[j - 1] = L.data[j];
    L.length--;
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
    ElemType x;
    ListDelete(L, 2, x);
    printf("x=%d", x);
    return 0;
}