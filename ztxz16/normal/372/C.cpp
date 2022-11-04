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

long long ans, f[200005], g[200005], Min;
int pos[500005], h, tot, n, m, d, a[200005], b[200005], t[200005], len;
int i, j;

int main()
{
	scanf("%d %d %d", &n, &m, &d);
	for (i = 1; i <= m; i++)
		scanf("%d %d %d", &a[i], &b[i], &t[i]), ans += b[i];
	for (i = 1; i <= n; i++)
		f[i] = abs(a[1] - i);
	for (i = 2; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
			g[j] = f[j];
		if ((long long)(t[i] - t[i - 1]) * d >= n)
			len = n;
		else
			len = (t[i] - t[i - 1]) * d;
		tot = 0;
		h = 1;
		for (j = 1; j <= len + 1 && j <= n; j++)
		{
			while (tot >= h && g[j] < g[pos[tot]])
				tot--;
			pos[++tot] = j;
		}
		
		f[1] = g[pos[h]];
		for (j = 2; j <= n; j++)
		{
			if (j - len - 1 >= 1 && pos[h] == j - len - 1)
				h++;
			if (j + len <= n)
			{
				while (tot >= h && g[j + len] < g[pos[tot]])
					tot--;
				pos[++tot] = j + len;
			}
			
			f[j] = g[pos[h]];
		}
		
		for (j = 1; j <= n; j++)
			f[j] += abs(a[i] - j);
	}
	
	Min = f[1];
	for (i = 1; i <= n; i++)
		Min = min(f[i], Min);
	ans -= Min;
	cout << ans << endl;
	return 0;
}