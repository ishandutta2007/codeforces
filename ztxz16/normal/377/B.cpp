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
	int v1, v2, tag;
	
	friend bool operator < (Node a, Node b)
	{
		return a.v1 < b.v1;
	}
}a[100005], b[100005];

multimap <int, int> x;
int Ans[100005], n, m, s;
int i, l, r, mid;

int check(int ans);

int main()
{
	scanf("%d %d %d", &n, &m, &s);
	for (i = 1; i <= m; i++)
		scanf("%d", &b[i].v1), b[i].tag = i;
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i].v1);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i].v2), a[i].tag = i;
	sort(b + 1, b + m + 1);
	sort(a + 1, a + n + 1);
	l = 1, r = m + 1;
	while (l < r)
	{
		mid = ((l + r) >> 1);
		if (check(mid) == 1)
			r = mid;
		else
			l = mid + 1;
	}
	
	if (l > m)
		printf("NO\n");
	else
	{
		check(l);
		printf("YES\n");
		for (i = 1; i <= m; i++)
			printf("%d ", Ans[i]);
		printf("\n");
	}
	
	return 0;
}

int check(int ans)
{
	int ss = s, now = m, now2 = n;
	x.clear();
	while (now > 0)
	{
		while (now2 >= 1 && a[now2].v1 >= b[now].v1)
			x.insert(make_pair(a[now2].v2, a[now2].tag)), now2--;
		if (x.begin() == x.end() || x.begin()->first > ss)
			return 0;
		ss -= x.begin()->first;
		int sel = x.begin()->second;
		for (int i = now; i >= 1 && i >= now - ans + 1; i--)
			Ans[b[i].tag] = sel;
		now -= ans;
		x.erase(x.begin());
	}
	
	return 1;
}