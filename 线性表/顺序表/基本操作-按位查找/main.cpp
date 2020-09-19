#include <iostream>
#define MaxSize 10
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;

ElemType GetElem(SqList L, int i)
{
    return L.data[i - 1];
}
int main()
{
    return 0;
}