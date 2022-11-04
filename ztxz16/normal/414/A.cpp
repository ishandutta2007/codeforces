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

int n, k, i, need, ans[100005];

int main()
{
	scanf("%d %d", &n, &k);
	if (n == 1 && k == 0)
	{
		printf("1\n");
		return 0;
	}
	
	if ((n >> 1) > k || n == 1)
	{
		printf("-1\n");
		return 0;
	}
	
	need = 1 + (k - (n >> 1));
	for (i = 1; i <= n; i++)
		ans[i] = i;
	for (i = 1; i * need <= n; i++);
	ans[1] = need * i;
	ans[2] = need * (i + 1);
	for (i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}