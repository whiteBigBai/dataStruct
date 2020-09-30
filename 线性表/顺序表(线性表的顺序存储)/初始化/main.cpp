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

int	main(int argc, char *argv[])
{
    SqList L;
    InitList(L);
    for (int i = 0; i < MaxSize; i++)
    {
        printf("L.data[%d] = %d\n",i,L.data[i]);
    }
    
    return 0;
}