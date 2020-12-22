#include <stdio.h>
#include <stdlib.h>

void Swap(int i, int j)
{
    int temp = 0;
    temp = i;
    i = j;
    j = temp;
}

/*
 要求实现如下功能：
    将数组 C[1:n]中所有奇数移到偶数之前，要求时间复杂度为 O(n)。
*/
void move(int C[], int len)
{
    int i = 0;       //i表示左端偶数元素的下标
    int j = len - 1; ////j表示右端奇数元素的下标
    int temp = 0;
    while (i < j)
    {
        while (i < j && (C[i] % 2 != 0)) //从前向后找到一个偶数元素
            i++;
        while (i < j && (C[j] % 2 != 1)) //从后向前找到一个奇数元素
            j--;
        if (i < j)
        {
            //Swap(C[i], C[j]); //交换这两个元素
            temp = C[i];
            C[i] = C[j];
            C[j] = temp;
            i++;
            j--;
        }
    }
}

void printList(int C[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("arr[%d]=%d\n", i, C[i]);
    }
}

int main(int argc, char **argv)
{
    int C[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = sizeof(C) / sizeof(int);
    move(C, len);
    printList(C, len);
    return 0;
}
