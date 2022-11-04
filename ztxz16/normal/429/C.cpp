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

vector <int> v[105];
int n, i, full, j, x, a[105];
int f[20000005], id[20000005];

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (i = 1; i <= n; i++)
		id[1 << (i - 1)] = i;
	sort(a + 1, a + n + 1);
	if (a[1] != 1 || a[n] > n)
	{
		printf("NO\n");
		return 0;
	}
	
	full = (1 << (n - 1));
	v[0].push_back(0);
	for (i = 1; i < full; i++)
	{
		if (id[i])
			continue;
		int s = 0;
		for (j = i; j > 0; j -= (j & (0 - j)))
			s += a[id[j & (0 - j)]];
		if (s <= n)
			v[s].push_back(i);
	}
	
	f[1] = 1;
	x = 1;
	for (i = 1; i < full; i++)
	{
		if (!f[i])
			continue;
		while (i >= (1 << x))
			x++;
		int now = a[x + 1] - 1;
		for (j = 0; j < v[now].size(); j++)
		{
			int y = v[now][j];
			if ((y & i) == y)
				f[i + (1 << x) - y] = 1;
		}
	}
	
	if (f[full])
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}