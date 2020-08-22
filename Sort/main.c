#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

int main()
{
	srand(time(NULL));
	int ar[100];
	int n = sizeof(ar)/sizeof(int);
/*	Input(ar, n);	
	InsertSort(ar, n);
	Output(ar, n);

	Input(ar, n);
	BinInsertSort(ar, n);
	Output(ar, n);

	Input(ar, n);
	ShellSort(ar,n);
	Output(ar, n);
*/
	Input(ar, n);
	BubbleSort(ar, n);
	Output(ar, n);
/*
	Input(ar, n);
	QuickSort(ar, 0, n-1);
	Output(ar, n);

	Input(ar, n);
	SelectSort(ar,n);
	Output(ar, n);

	Input(ar, n);
	MergeSort(ar ,n);
	Output(ar, n);
*/
	return 0;
}
