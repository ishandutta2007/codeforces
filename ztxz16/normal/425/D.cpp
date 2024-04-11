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
#include <cmath>
#define PQ priority_queue
#define OO 2147483647
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)

int FASTBUFFER;

using namespace std;

int n, i, x, y, j, k, ans;
int l[100005], tot;
vector <int> a[100005];
vector <int> :: iterator it;

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d %d", &x, &y), a[x].push_back(y);
	x = (int)sqrt(n) + 1;
	for (i = 0; i <= 100000; i++)
	{
		sort(a[i].begin(), a[i].end());
		if (a[i].size() > x)
			l[++tot] = i;
	}
	
	for (j = 1; j < tot; j++)
		for (k = j + 1; k <= tot; k++)
		{
			int a1 = l[j], a2 = l[k], t1 = a[a1].size(), t2 = a[a2].size(), dd = a2 - a1;
			int now1 = 0, now2 = 0, now3 = 0;
			for (y = 0; y < t2; y++)
			{
				int now = a[a2][y];
				while (a[a2][now3] < now + dd && now3 < t2)
					now3++;
				while (a[a1][now1] < now && now1 < t1)
					now1++;
				while (a[a1][now2] < now + dd && now2 < t1)
					now2++;
				if (a[a2][now3] == now + dd && a[a1][now1] == now && a[a1][now2] == now + dd)
					ans++;
			}
		}
	for (i = 0; i <= 100000; i++)
	{
		if (a[i].size() > x)
			continue;
		int tot = a[i].size();
		for (j = 0; j < tot - 1; j++)
			for (k = j + 1; k < tot; k++)
			{
				int now = i - (a[i][k] - a[i][j]);
				if (now < 0)
					break;
				if (a[now].size() <= x)
					continue;
				it = lower_bound(a[now].begin(), a[now].end(), a[i][k]);
				if (it == a[now].end() || (*it) != a[i][k])
					continue;
				it = lower_bound(a[now].begin(), a[now].end(), a[i][j]);
				if (it == a[now].end() || (*it) != a[i][j])
					continue;
				ans++;
			}
		for (j = 0; j < tot - 1; j++)
			for (k = j + 1; k < tot; k++)	
			{
				int now = i + (a[i][k] - a[i][j]);
				if (now > 100000)
					break;
				it = lower_bound(a[now].begin(), a[now].end(), a[i][k]);
				if (it == a[now].end() || (*it) != a[i][k])
					continue;
				it = lower_bound(a[now].begin(), a[now].end(), a[i][j]);
				if (it == a[now].end() || (*it) != a[i][j])
					continue;
				ans++;
			}
	}
	
	printf("%d\n", ans);
	
	return 0;
}