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

vector <int> v[100005], ans;
int n, i, a, b, now, x, y, ff, val[100005];
int sjj[100005], h, t, father[100005];

int main()
{
	scanf("%d", &n);
	for (i = 1; i < n; i++)
		scanf("%d %d", &a, &b), v[a].push_back(b), v[b].push_back(a);
	for (i = 1; i <= n; i++)
		scanf("%d", &val[i]);
	for (i = 1; i <= n; i++)
		scanf("%d", &x), val[i] ^= x;
	sjj[1] = 1;
	for (h = t = 1; h <= t; h++)
	{
		now = sjj[h];
		ff = father[father[now]];
		if (ff != 0 && val[ff])
		{
			if (!val[now])
				ans.push_back(now);
		}
		
		else if (val[now])
			ans.push_back(now);
		for (x = 0; x < v[now].size(); x++)
		{
			y = v[now][x];
			if (y == father[now])
				continue;
			father[y] = now, sjj[++t] = y;
		}
	}
	
	printf("%d\n", ans.size());
	for (i = 0; i < ans.size(); i++)
		printf("%d\n", ans[i]);
	return 0;
}