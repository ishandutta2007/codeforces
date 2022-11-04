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

struct Node
{
	int x, k, tag;
	
	friend bool operator < (Node a, Node b)
	{
		return a.k < b.k;
	}
}a[105];

int tot, n, m, b, i, j;
long long f[5000005], ans;

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%d %d %d", &n, &m, &b);
	for (i = 1; i <= n; i++)
	{
		int xx;
		scanf("%d %d %d", &a[i].x, &a[i].k, &tot);
		for (j = 1; j <= tot; j++)
			scanf("%d", &xx), a[i].tag += (1 << (xx - 1));
	}
	
	sort(a + 1, a + n + 1);
	int full = (1 << m) - 1;
	for (i = 1; i <= full; i++)	
		f[i] = (1LL << 60);
	ans = (1LL << 60);
	f[0] = 0;
	for (i = 1; i <= n; i++)
	{
		int xx = a[i].x, tt = a[i].tag;
		for (j = full; j >= 0; j--)
			f[j | tt] = min(f[j | tt], f[j] + xx);
		ans = min(ans, f[full] + (long long)a[i].k * b);
	}
	
	if (ans == (1LL << 60))
		ans = -1;
	cout << ans << endl;
	return 0;
}