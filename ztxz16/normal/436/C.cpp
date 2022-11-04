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

int n, m, k, w, i, j, l1, l2, now, ans, aa[1005], bb[1005], Hash[1005], f[1005][1005], v[1005], sel[1005];
char a[1005][15][15];

int main()
{
	scanf("%d %d %d %d", &n, &m, &k, &w);
	for (i = 1; i <= k; i++)
		for (j = 1; j <= n; j++)
			scanf("%s", a[i][j] + 1);
	for (i = 1; i < k; i++)
		for (j = i + 1; j <= k; j++)
		{
			for (l1 = 1; l1 <= n; l1++)
				for (l2 = 1; l2 <= m; l2++)
					f[i][j] += (a[i][l1][l2] != a[j][l1][l2]);
			f[j][i] = f[i][j];
		}
	for (i = 1; i <= k; i++)
		v[i] = n * m, sel[i] = 0;
	for (i = 1; i <= k; i++)
	{
		now = -1;
		for (j = 1; j <= k; j++)
			if (Hash[j] == 0)
			{
				if (now == -1 || v[j] < v[now])
					now = j;
			}
		ans += v[now];
		Hash[now] = 1;
		aa[i] = now, bb[i] = sel[now];
		for (j = 1; j <= k; j++)
			if (f[now][j] * w < v[j])
				v[j] = f[now][j] * w, sel[j] = now;
	}
	
	printf("%d\n", ans);
	for (i = 1; i <= k; i++)
		printf("%d %d\n", aa[i], bb[i]);
	return 0;
}