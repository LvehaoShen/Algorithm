#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <memory.h>
void GetNextval(int** nextval, char* pat)
{
	int j = 0;
	int k = -1;
	*nextval = malloc(sizeof(strlen(pat)));
	(*nextval)[0] = -1;
	while (j < strlen(pat) - 1)
	{
		if (k == -1 || pat[j] == pat[k])
		{
			j++;
			k++;
			if (pat[j] == pat[k])
				(*nextval)[j] = (*nextval)[k];
			else
				(*nextval)[j] = k;
		}
		else
			k = (*nextval)[k];
	}
}
int kmp(char* pat, char* txt)
{
	int* nextval = NULL;
	GetNextval(&nextval, pat);
	int i = 0; 
	int j = 0;
	while (i < (int)strlen(txt) && j < (int)strlen(pat))
	{
		if (j == -1 || txt[i] == pat[j])
		{
			i++;
			j++;
		}
		else
			j = nextval[j];
	}
	if (j >= (int)strlen(pat))
		return(i - (int)strlen(pat));
	else
		return -1;
}
int main()
{
	char pat[100] ;
	char txt[100] ;
	scanf("%s", pat);
	scanf("%s", txt);
	int i = kmp(pat, txt);
	return 0;
}
