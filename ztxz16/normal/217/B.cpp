#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#define PQ priority_queue
#define OO 2147483647

using namespace std;

int Sum, Error, MinError, sel;
int n, r, i, tot;
char Ans[1000005];

void Work(int a, int b);
void Make(int a, int b);

int main()
{
	scanf("%d %d", &n, &r);
	if (n == 1 && r == 1)
	{
		printf("0\nT\n");
		return 0;
	}
	
	for (i = 1; i < r; i++)
	{
		Sum = 1;
		Error = 0;
		Work(i, r);
		if (Sum != n)
			continue;
		if (Error < MinError || sel == 0)
			MinError = Error, sel = i;
	}
	
	if (sel == 0)
		printf("IMPOSSIBLE\n");
	else
	{
		Make(sel, r);
		printf("%d\n", MinError);
		for (i = 1; i <= tot; i++)
			printf("%c", Ans[i]);
		printf("\n");
	}
	
	return 0;
}

void Work(int a, int b)
{
	if (a == 0)
	{
		Sum = r + 1;
		return;
	}
	
	if (a == 1)
	{
		Sum += (b - 1);
		Error += (b - 2);
		return;
	}
	
	Sum += (b / a);
	Error += (b / a - 1);
	Work(b % a, a);
	return;
}

void Make(int a, int b)
{
	int i, Now;
	if (a == 1)
	{
		Ans[++tot] = 'T';
		for (i = 1; i < b; i++)
			Ans[++tot] = 'B';
		return;
	}
	
	Make(b % a, a);
	if (Ans[tot] == 'T')
		Now = 'B';
	else
		Now = 'T';
	for (i = 1; i <= b / a; i++)
		Ans[++tot] = Now;
	return;
}