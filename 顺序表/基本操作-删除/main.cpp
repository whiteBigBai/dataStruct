#include <iostream>
#define MaxSize 10
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;

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

int main()
{
    return 0;
}