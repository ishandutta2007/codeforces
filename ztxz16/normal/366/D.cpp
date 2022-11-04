#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <set>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

int FASTBUFFER;

set <int> s;
set <int>::iterator it;

struct Node
{
	int a, b, c, d;
	
	void read()
	{
		scanf("%d %d %d %d", &a, &b, &c, &d);
		s.insert(d);
	}
	
	friend bool operator < (Node a, Node b)
	{
		return a.c < b.c;
	}
}a[10005], b[10005];

int n, m, i, j, tot, ans, now, fa, fb, f[10005];

int find(int i);

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++)
		a[i].read();
	ans = -OO;
	sort(a + 1, a + m + 1);
	for (it = s.begin(); it != s.end(); ++it)
	{
		now = *it;
		tot = 0;
		for (j = 1; j <= m; j++)
			if (a[j].d >= now)
				b[++tot] = a[j];
		if (tot == 0)
			continue;
		for (i = 1; i <= n; i++)
			f[i] = i;
		for (i = 1; i <= tot; i++)
		{
			fa = find(b[i].a), fb = find(b[i].b);
			if (fa != fb)
				f[fa] = fb;
			if (find(1) == find(n))
				break;
		}
		
	//	if (now == 5)
		//	printf("%d %d\n", b[i].c, i);
		if (i <= tot && now - b[i].c + 1 > ans)
			ans = now - b[i].c + 1;
	}
	
	if (ans <= 0)
		printf("Nice work, Dima!\n");
	else
		printf("%d\n", ans);
	return 0;
}

int find(int i)
{
	if (f[i] == i)
		return i;
	return f[i] = find(f[i]);
}