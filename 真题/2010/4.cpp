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
        L.data[i] = 0;
    L.length = 0;
}

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

/*
 要求实现如下功能：
    将数组 C[1:n]中所有奇数移到偶数之前，要求时间复杂度为 O(n)。
*/

void move(SqList &S)
{

    int i = 1;
    int j = S.length;
    int temp;
    while (i < j)
    {
        while (i < j && (S.data[j] % 2 == 0)) //只要j下标的值为偶数j下标就往前移
            j--;
        while (i < j && (S.data[i] % 2 == 1)) //只要i下标的值为奇数i下标就往后移
            i++;
        if (i < j)
        {
            temp = S.data[i];
            S.data[i] = S.data[j];
            S.data[j] = temp;
        }
    }
}

void printList(SqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        printf("data[%d]=%d\n", i, L.data[i]);
    }
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
    printList(L);
    move(L);
    printList(L);
    return 0;
}