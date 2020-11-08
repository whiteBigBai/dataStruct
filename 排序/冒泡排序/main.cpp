#include <stdio.h>

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void BubbleSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = false;
        for (int j = n - 1; j > i; j--)
        {
            if (A[j - 1] > A[j])
            {
                swap(A[j - 1], A[j]);
                flag = true;
            }
        }
        for (int k = 0; k < 8; k++)
        {
            printf("第%d趟A[%d]=%d--->", i, k, A[k]);
        }
        printf("\n");
        if (flag == false)
            return;
    }
}

int main(int argc, char *argv[])
{
    int A[8] = {49, 38, 65, 97, 76, 13, 27, 49};
    BubbleSort(A, 8);
    return 0;
}
