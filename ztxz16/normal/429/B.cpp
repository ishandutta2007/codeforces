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

int n, m, i, j, v[1005][1005];
long long f1[1005][1005], f2[1005][1005], f3[1005][1005], f4[1005][1005], ans;

int main()
{
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			scanf("%d", &v[i][j]);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			f1[i][j] = max(f1[i - 1][j], f1[i][j - 1]) + v[i][j];
	for (i = n; i >= 1; i--)
		for (j = 1; j <= m; j++)
			f2[i][j] = max(f2[i + 1][j], f2[i][j - 1]) + v[i][j];
	for (i = 1; i <= n; i++)
		for (j = m; j >= 1; j--)
			f3[i][j] = max(f3[i - 1][j], f3[i][j + 1]) + v[i][j];
	for (i = n; i >= 1; i--)
		for (j = m; j >= 1; j--)
			f4[i][j] = max(f4[i + 1][j], f4[i][j + 1]) + v[i][j];
	for (i = 2; i < n; i++)
		for (j = 2; j < m; j++)
			ans = max(ans, max(f1[i - 1][j] + f4[i + 1][j] + f2[i][j - 1] + f3[i][j + 1], f1[i][j - 1] + f4[i][j + 1] + f2[i + 1][j] + f3[i - 1][j]));
	cout << ans << endl;
	return 0;
}