#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int BinSearch(int arr[], int key, int n)
{
	int left = 0, right = n - 1, middle = 0;
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
	int arr[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++)
	{
		scanf("%d", &arr[i]);
	}
	int key;
	scanf("%d", &key);
	int middle = BinSearch(arr, key, MAX_SIZE);
	printf("索引位置为: %d", middle);
	return 0;
}
