#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
void Input(int ar[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		ar[i] = rand();
	}
	printf("ÅÅÐòÇ°£º\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", ar[i]);
	}
	printf("\n");
}
void Output(int ar[], int n)
{
	printf("ÅÅÐòºó£º\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", ar[i]);
	}
	printf("\n");
}
void InsertSort(int ar[], int n)
{
	int temp;
	int j;
	for (int i = 1; i < n; ++i)
	{
		if (ar[i] < ar[i - 1])
		{
			temp = ar[i];
			for (j = i - 1; j >= 0 && ar[j] > temp; j--)
			{
				ar[j + 1] = ar[j];
			}
			ar[j + 1] = temp;
		}
	}
}
void BinInsertSort(int ar[], int n)
{
	int low;
	int high;
	int mid;
	int temp;
	int j;
	for (int i = 1; i < n; ++i)
	{
		if (ar[i] < ar[i - 1])
		{
			temp = ar[i];
			low = 0;
			high = i - 1;
			while (low <= high)
			{
				mid = (low + high) / 2;
				if (temp > ar[mid])
				{
					low = mid + 1;
				}
				else
				{
					high = mid - 1;
				}
			}
			for (j = i - 1; j >= high + 1; j--)
			{
				ar[j + 1] = ar[j];
			}
			ar[j + 1] = temp;
		}
	}
}
void ShellSort(int ar[], int n)
{
	int temp;
	int j;
	int d = n / 2;
	while (d > 0)
	{
		for (int i = d; i < n; ++i)
		{
			if (ar[i] < ar[i - d])
			{
				temp = ar[i];
				for (j = i - d; j >= 0 && ar[j] > temp; j -= d)
				{
					ar[j + d] = ar[j];
				}
				ar[j + d] = temp;
			}
		}
		d /= 2;
	}
}
void BubbleSort(int ar[], int n)
{
	int temp;
	int exchange;
	for (int i = 1; i < n - 1; ++i)
	{
		exchange = 0;
		for (int j = 0; j < n - i; ++j)
		{

			if (ar[j] > ar[j + 1])
			{
				temp = ar[j];
				ar[j] = ar[j + 1];
				ar[j + 1] = temp;
				exchange = 1;
			}
		}
		if (exchange == 0)
			return;
	}
}
void QuickSort(int ar[], int s, int t)
{
	int i = s;
	int j = t;
	int temp;
	if (s < t)
	{
		temp = ar[s];
		while (i != j)
		{
			while (j > i && ar[j] >= temp)
			{
				j--;
			}
			ar[i] = ar[j];
			while (i < j && ar[i] <= temp)
			{
				i++;
			}
			ar[j] = ar[i];
		}
		ar[i] = temp;
		QuickSort(ar, s, i - 1);
		QuickSort(ar, i + 1, t);
	}
}
void SelectSort(int ar[], int n)
{
	int min = INT_MAX;
	int k;
	for (int i = 0; i < n; ++i)
	{
		k = i;
		for (int j = i; j < n; ++j)
		{
			if (ar[j] < min)
			{
				min = ar[j];
				k = j;
			}
		}
		if (i != k)
		{
			ar[k] = ar[i];
			ar[i] = min;
		}
		min = INT_MAX;
	}
}
void MergeSort(int ar[], int n)
{
	int length;
	for (length = 1; length < n; length *= 2)
	{
		MergePass(ar, length, n);
	}
}
void Merge(int ar[], int low, int mid, int high)
{
	int i = low;
	int j = mid + 1;
	int* tempar = malloc(sizeof(int) * (high - low + 1));
	int k = 0;
	while (i <= mid && j <= high)
	{
		if (ar[i] <= ar[j])
		{
			tempar[k] = ar[i];
			i++;
			k++;
		}
		else
		{
			tempar[k] = ar[j];
			j++;
			k++;
		}
	}
	while (i <= mid)
	{
		tempar[k] = ar[i];
		i++;
		k++;
	}
	while (j <= high)
	{
		tempar[k] = ar[j];
		j++;
		k++;
	}
	for (k = 0, i = low; i <= high; i++, k++)
	{
		ar[i] = tempar[k];
	}
	free(tempar);
}
void MergePass(int ar[], int length, int n)
{
	int i;
	for (i = 0; i + 2 * length - 1 < n; i += 2 * length)
	{
		Merge(ar, i, i + length - 1, i + 2 * length - 1);
	}
	if (i + length - 1 < n)
	{
		Merge(ar, i, i + length - 1, n - 1);
	}
}