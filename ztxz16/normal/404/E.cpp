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

int n, now, x1, x2, l, r, mid, ans, temp;
char str[1000005];

int Work(int lim);

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	gets(str + 1);
	n = strlen(str + 1);
	if (Work(OO))
	{
		printf("1\n");
		return 0;
	}
	
	l = 0, r = 2000000;
	while (l < r)
	{
		mid = (l + r + 1) >> 1;
		if (Work(mid) == 1)
			l = mid;
		else
			r = mid - 1;
	}
	
	ans = l;
	l = 0, r = 2000000;
	while (l < r)
	{
		mid = (l + r + 1) >> 1;
		if (Work(-mid) == 1)
			l = mid;
		else
			r = mid - 1;
	}
	
	ans += l;
	printf("%d\n", ans);
	return 0;
}

int Work(int lim)
{
	int i;
	now = x1 = x2 = 0;
	for (i = 1; i < n; i++)
	{
		temp = now;
		if (str[i] == 'L')
			now--;
		else
			now++;
		if (now == lim)
			now = temp;
		x1 = min(now, x1), x2 = max(now, x2);
	}
	
	if (str[n] == 'L')
		now--;
	else
		now++;
	if (now == lim)
		return 0;
	if (now < x1 || now > x2)
		return 1;
	return 0;
}