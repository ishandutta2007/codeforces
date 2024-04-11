#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

int FASTBUFFER;

int n, i, j, ans;
char str[100005];

int cmp(int l1, int r1, int l2, int r2);

int main()
{
	gets(str + 1);
	n = strlen(str + 1);
	for (i = 1; i <= n; i++)
	{
		j = i + 1;
		while (str[j] == '0')
			j++;
		j--;
		if (cmp(i, j, 1, i - 1) > 0)
			ans = 1;
		else
			ans++;
		i = j;
	}
	
	printf("%d\n", ans);
	return 0;
}

int cmp(int l1, int r1, int l2, int r2)
{
	if (r1 - l1 > r2 - l2)
		return 1;
	if (r1 - l1 < r2 - l2)
		return -1;
	for (i = 0; i <= r1 - l1; i++)
	{
		if (str[l1 + i] > str[l2 + i])
			return 1;
		if (str[l1 + i] < str[l2 + i])
			return -1;
	}
	
	return 0;
}