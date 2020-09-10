#include <iostream>
#include <stdlib.h>
#define InitSize 10
typedef int ElemType;
typedef struct
{
    ElemType *data;
    int MaxSize;
    int length;
} SeqList;

void InitList(SeqList &L)
{
    L.data = (ElemType *)malloc(sizeof(ElemType) * InitSize);
    L.MaxSize = InitSize;
    L.length = 0;
}

void IncreaseSize(SeqList &L, int len)
{
    int *p = L.data;
    L.data = (ElemType *)malloc(sizeof(ElemType) * (L.MaxSize + len));
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = p[i];
    }
    L.MaxSize = L.MaxSize + len;
    free(p);
}

int main()
{
    return 0;
}