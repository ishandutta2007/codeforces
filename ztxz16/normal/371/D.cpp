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
int n, i, m, p, x, type, a[200005], b[200005];

void Add(int p, int x);

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]), s.insert(i);
	scanf("%d", &m);
	for (i = 1; i <= m; i++)
	{
		scanf("%d", &type);
		if (type == 1)
		{
			scanf("%d %d", &p, &x);
			if (s.find(p) != s.end())
				Add(p, x);
			else
			{
				it = s.upper_bound(p);
				if (it != s.end())
					Add(*it, x);
			}
		}
		
		else
		{
			scanf("%d", &x);
			if (s.find(x) == s.end())
				printf("%d\n", a[x]);
			else
				printf("%d\n", b[x]);
		}
	}
	
	return 0;
}

void Add(int p, int x)
{
	set <int>::iterator it;
	b[p] += x;
	if (b[p] >= a[p])
	{
		s.erase(s.find(p));
		x = b[p] - a[p], b[p] = a[p];
		it = s.upper_bound(p);
		if (x > 0 && it != s.end())
			Add(*it, x);
	}
}