#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
void quick_sort(int ar[], int low, int high);
int split(int ar[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int* i, int* j)
int main()
{
	int ar[10];
	for(int i;i!=10;++i)
		scanf("%d",&ar[i]);
	quick_sort(ar, 0, 9);
	for (int i = 0; i != 10; ++i)
		printf("%d ", ar[i]);
	return 0;
}
void swap(int* i, int* j)
{
	int temp = *j;
	*j = *i;
	*i = temp;
}
void quick_sort(int ar[], int low, int high)
{
	int middle;
	if (low >= high)
		return;
	middle =partition (ar, low, high);
	quick_sort(ar, low, middle - 1);
	quick_sort(ar, middle + 1, high);
}
int split(int ar[], int low, int high)
{
	int part_element = ar[low];
	for (;;)
	{
		while (low < high && part_element <= ar[high])
			high--;
		if (low >= high)
			break;
		else
			ar[low++] = ar[high];
		while (low < high && part_element >= ar[low])
			low++;
		if (low >= high)
			break;
		else
			ar[high--] = ar[low];
	}
	ar[high] = part_element;
	return high;
}//TEXTBOOK

int partition(int arr[], int low, int high) {
	int k = low, pivot = arr[high];
	for (int i = low; i < high; ++i)
		if (arr[i] <= pivot)
		{
			if (k == i)
				k++;
			else
				swap(&arr[i], &arr[k++]);
		}			
        swap(&arr[k], &arr[high]);
	return k;
}//CLRS 
