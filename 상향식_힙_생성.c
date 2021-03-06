#include <stdio.h>
#include <stdlib.h>

void downHeap(int i);

int H[100], n;

void bulidHeap()
{
	int i;
	for (i = n / 2;i >= 1;i--)
		downHeap(i);
	return;
}

void rBuildHeap(int i)
{
	if (i > n) return;
    rBuildHeap(2 * i);
	rBuildHeap(2 * i + 1);
	downHeap(i);
}

void downHeap(int i)
{
	int temp;
	if (i > n / 2 || (H[i] > H[i * 2] && H[i] > H[i * 2 + 1])) return;
	else if (H[i] < H[i * 2] || H[i] < H[i * 2 + 1])
	{
		if (H[i * 2] > H[i * 2 + 1])
		{
			temp = H[i * 2];
			H[i * 2] = H[i];
			H[i] = temp;
			downHeap(i * 2);
		}
		else
		{
			temp = H[i * 2 + 1];
			H[i * 2 + 1] = H[i];
			H[i] = temp;
			downHeap(i * 2 + 1);
		}
	}
}

void printHeap()
{
	int i;
	for (i = 1;i <= n;i++)
		printf(" %d", H[i]);
	printf("\n");
	return;
}

int main()
{
	int num;
	scanf("%d", &num);
	for (n = 1; n <= num; n++) 
		scanf("%d", &H[n]);
	n--;
	//buildHeap();
	rBuildHeap(1);
	printHeap();
	
	return 0;
}
