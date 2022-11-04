#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <string>
#define PQ priority_queue
#define OO 2147483647
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)

int FASTBUFFER;

using namespace std;

int n, i, a[100005], f[100005], g[100005], ans;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	f[1] = g[n] = 1;
	for (int i = 2; i <= n; i++)
		if (a[i] > a[i - 1])
			f[i] = f[i - 1] + 1;
		else
			f[i] = 1;
	for (int i = 1; i <= n; i++)
		ans = max(ans, f[i]);
	for (int i = n - 1; i >= 1; i--)
		if (a[i] < a[i + 1])
			g[i] = g[i + 1] + 1;
		else
			g[i] = 1;
	if (n == 1)
	{
		printf("1\n");
		return 0;
	}
	
	ans = max(ans, max(f[n - 1] + 1, g[2] + 1));
	for (int i = 2; i < n; i++)
	{
		if (a[i + 1] > a[i - 1] + 1)
			ans = max(ans, f[i - 1] + g[i + 1] + 1);
		else
			ans = max(ans, max(f[i - 1] + 1, g[i + 1] + 1));
	}
	
	printf("%d\n", ans);
	return 0;
}