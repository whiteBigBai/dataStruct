#include <stdio.h>
#include <stdlib.h>

//插入排序
void InsertSort(int A[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        if (A[i] < A[i - 1])                        //若A[i]关键字小于前驱
            temp = A[i];                            //用temp暂存A[i]
        for (j = i - 1; j >= 0 && A[j] > temp; --j) //检查所有前面已经排好序的元素
            A[j + 1] = A[j];                        //所有大于temp的元素都向后挪位
        A[j + 1] = temp;                            //复制到插入位置
    }
}

//插入排序  带哨兵
void InsertSort1(int A[], int n)
{
    int i, j;
    for (i = 2; i <= n; i++)
    { //依次将A[2]~A[n]插入到前面已排序序列
        if (A[i] < A[i] - 1)//若A[i]关键码小于其前驱，将A[i]插入有序列表
            A[0] = A[i];//复制为哨兵 A[0]不存放元素
        for (j = i - 1; A[0] < A[j]; --j)//从后往前查找待插入排序
            A[j + 1] = A[j];//向后挪位
        A[j + 1] = A[0];//复制到插入位置
    }
}