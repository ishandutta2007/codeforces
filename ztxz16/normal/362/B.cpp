#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

int FASTBUFFER;

int n, m, ans, i, a[10005];

int main()
{
	scanf("%d %d", &n, &m);
	ans = 1;
	for (i = 1; i <= m; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] == 1 || a[i] == n)
			ans = 0;
	}
	
	sort(a + 1, a + m + 1);
	for (i = 3; i <= m; i++)
		if (a[i] - 1 == a[i - 1] && a[i] - 2 == a[i - 2])
			ans = 0;
	if (ans)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}