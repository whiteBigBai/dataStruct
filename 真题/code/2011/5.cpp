#include <stdio.h>
#include <stdlib.h>

int BinSearch(int arr[], int key, int n)
{
	int left = 0, right = n, middle = 0;
	while (left < right)
	{
		middle = (left + right) / 2;
		if (key > arr[middle])
		{
			left = middle + 1;
		}
		else if (key < arr[middle])
		{
			right = middle - 1;
		}
		else
		{
			return middle;
		}
	}
	return 0;
}

int main(int argc, char **argv)
{
	int len=0;
	printf("请输入数组元素的个数");
	scanf("%d",&len);
	int arr[len];
	for (int i = 0; i < len; i++)
	{
		printf("请输入数组元素");
		scanf("%d", &arr[i]);
	}
	int key;
	printf("请输入关键字");
	scanf("%d", &key);
	int middle = BinSearch(arr, key, len);
	printf("索引位置为: %d", middle);
	return 0;
}
