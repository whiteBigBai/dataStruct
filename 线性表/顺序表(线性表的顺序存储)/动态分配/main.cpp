#include <stdio.h>
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

bool ListInsert(SeqList &L, int i, ElemType e)
{
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= L.MaxSize)
    {
        IncreaseSize(L, InitSize);
    }
    for (int j = L.length; j >= i; j--)
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;
    L.length++;
    return true;
}

int main(int argc, char **argv)
{
    SeqList L;
    InitList(L);
    for (int i = 0; i < 21; i++)
    {
        ListInsert(L,i+1,i+1);
        printf("L.data[%d]=%d\n", i, L.data[i]);
        printf("L.MaxSize=%d\n", L.MaxSize);
        printf("L.length=%d\n", L.length);
    }
    return 0;
}