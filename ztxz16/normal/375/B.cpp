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
#include <functional>
#define PQ priority_queue
#define OO 2147483647
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)

int FASTBUFFER;

using namespace std;

int n, m, i, j, ans;
int up[5005][5005], a[5005];
char str[5005][5005];

int main()
{
	scanf("%d %d", &n, &m);
	for (i = 0; i <= n; i++)
		gets(str[i] + 1);
	for (j = 1; j <= n; ++j)
		for (i = 1; i <= m; ++i)
			if (str[j][i] == '1')
				up[j][i] = up[j][i - 1] + 1;
			else
				up[j][i] = 0;
	for (i = 1; i <= m; ++i)
	{
		for (j = 1; j <= n; ++j)
			a[j] = up[j][i];
		sort(a + 1, a + n + 1, greater <int>());
		for (j = 1; j <= n; ++j)
			ans = max(ans, j * a[j]);
	}
	
	printf("%d\n", ans);
	return 0;
}