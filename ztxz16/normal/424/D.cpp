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

int n, m, t, tp, tu, td, i, j, k, h[305][305];
int tol[305][305], tor[305][305], tod[305][305], tou[305][305];
int Ans, sx1, sx2, sy1, sy2;

set <pair <int, int> > s;
set <pair <int, int> > :: iterator it;

int main()
{
	scanf("%d %d %d", &n, &m, &t);
	scanf("%d %d %d", &tp, &tu, &td);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			scanf("%d", &h[i][j]);
	for (i = 1; i <= n; i++)
	{
		tor[i][1] = 0;
		for (j = 2; j <= m; j++)
			if (h[i][j] == h[i][j - 1])
				tor[i][j] = tor[i][j - 1] + tp;
			else if (h[i][j] < h[i][j - 1])
				tor[i][j] = tor[i][j - 1] + td;
			else
				tor[i][j] = tor[i][j - 1] + tu;
		tol[i][m] = 0;
		for (j = m - 1; j >= 1; j--)
			if (h[i][j] == h[i][j + 1])
				tol[i][j] = tol[i][j + 1] + tp;
			else if (h[i][j] < h[i][j + 1])
				tol[i][j] = tol[i][j + 1] + td;
			else
				tol[i][j] = tol[i][j + 1] + tu;
	}
	
	for (j = 1; j <= m; j++)
	{
		tod[1][j] = 0;
		for (i = 2; i <= n; i++)
			if (h[i][j] == h[i - 1][j])
				tod[i][j] = tod[i - 1][j] + tp;
			else if (h[i][j] < h[i - 1][j])
				tod[i][j] = tod[i - 1][j] + td;
			else
				tod[i][j] = tod[i - 1][j] + tu;
		tou[n][j] = 0;
		for (i = n - 1; i >= 1; i--)
			if (h[i][j] == h[i + 1][j])
				tou[i][j] = tou[i + 1][j] + tp;
			else if (h[i][j] < h[i + 1][j])
				tou[i][j] = tou[i + 1][j] + td;
			else
				tou[i][j] = tou[i + 1][j] + tu;
	}
	
	Ans = OO;
	for (i = 1; i < n; i++)
		for (j = i + 2; j <= n; j++)
		{
			s.clear();
			for (k = 1; k <= m; k++)
			{
				int now = tod[j][k] - tod[i][k] + tor[i][k] - tol[j][k];
				it = s.lower_bound(make_pair(t - now, 0));
				if (it != s.end())
				{
					if (now + it->first - t <= Ans)
						Ans = now + it->first - t, sx1 = i, sy1 = it->second, sx2 = j, sy2 = k;
				}
				
				if (it != s.begin())
				{
					it--;
					if (t - now - it->first <= Ans)
						Ans = t - now - it->first, sx1 = i, sy1 = it->second, sx2 = j, sy2 = k;
				}
				
				if (k > 1)
					now = tou[i][k - 1] - tou[j][k - 1] + tol[j][k - 1] - tor[i][k - 1], s.insert(make_pair(now, k - 1));
			}
		}
	
	printf("%d %d %d %d\n", sx1, sy1, sx2, sy2);
	return 0;
}