#include <stdio.h>
#include <stdlib.h>

void insertSort(int* arr, int n)
{
	int i, j, temp, ind;
	
	for (i = 1;i < n;i++)
	{
		ind = i;
		temp = arr[i];
		for (j = i - 1;j >= 0;j--)
		{
			if (temp < arr[j])
			{
				ind--;
				arr[j + 1] = arr[j];
			}
			else break;
		}
		arr[ind] = temp;
	}
}

int binarySearch(int* arr, int k, int l, int r)
{
	int mid = (l + r) / 2;
	
	if (k < arr[0]) return -1;
	
	if (l > r) 
	{
		while (arr[mid] > k ) mid--;
		return mid;
	}
	
	if (k == arr[mid]) return mid;
	else if (k < arr[mid]) return binarySearch(arr, k, l, mid - 1);
	else return binarySearch(arr, k, mid + 1, r);
}

int main()
{
	int n, k, i, * arr;
	scanf("%d %d", &n, &k);
	arr = (int*)malloc(sizeof(int) * n);
	
	for (i = 0;i < n;i++) 
  	{
		scanf("%d", &arr[i]);
	}
	insertSort(arr, n);
	printf(" %d", binarySearch(arr, k, 0, n - 1));
	
	free(arr);
	return 0;
}
