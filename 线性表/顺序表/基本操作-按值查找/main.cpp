#include <iostream>
#define MaxSize 10
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;

int LocateElem(SqList L, ElemType e)
{
    for(int i=0;i<L.length;i++)
        if(L.data[i]==e)
            return i+1;
    return 0;
}
int main()
{
    return 0;
}