#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;

bool ListInsert(SqList &L, int i, ElemType e)
{
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= MaxSize)
        return false;
    for (int j = L.length; j >= i; j--)
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;
    L.length++;
    return true;
}

void InitList(SqList &L)
{
    for (int i = 0; i < MaxSize; i++)
        L.data[i] = 0;
    L.length = 0;
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
    ListInsert(L, 6, 6);
    ListInsert(L, 7, 7);
    ListInsert(L, 8, 8);
    ListInsert(L, 9, 9);
    ListInsert(L, 10, 10);
    for (int i = 0; i < L.length; i++)
    {
        printf("L.data[%d] = %d\n",i,L.data[i]);
    }
    
    return 0;
}