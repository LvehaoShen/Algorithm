#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <memory.h>
#define MAXSIZE 100
typedef struct string string;
struct string {
	char str[MAXSIZE];
	int Length;
};
void GetNextval(int* nextval, string pat)
{
	int j = 0;
	int k = -1;
	nextval[0] = -1;
	while (j < pat.Length - 1)
	{
		if (k == -1 || pat.str[j] == pat.str[k])
		{
			j++;
			k++;
			if (pat.str[j] == pat.str[k])
				nextval[j] = nextval[k];
			else
				nextval[j] = k;
		}
		else
			k = nextval[k];
	}
}
int kmp(string pat, string txt)
{
	int nextval[MAXSIZE];
	GetNextval(nextval, pat);
	int i = 0;
	int j = 0;
	while (i < txt.Length && j < pat.Length)
	{
		if (j == -1 || txt.str[i] == pat.str[j])
		{
			i++;
			j++;
		}
		else
			j = nextval[j];
	}
	if (j >= pat.Length)
		return(i - pat.Length);
	else
		return -1;
}
int main()
{
	string pat, txt;
	scanf("%s", pat.str);
	scanf("%s", txt.str);
	pat.Length = strlen(pat.str);
	txt.Length = strlen(txt.str);
	int i=kmp(pat, txt);
	return 0;
}
