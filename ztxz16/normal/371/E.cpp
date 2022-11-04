#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ
#define ll long long

using namespace std;

ll FASTBUFFER;

struct Node
{
	ll x, tag;
	
	friend bool operator < (Node a, Node b)
	{
		return a.x < b.x;
	}
}a[500005];

ll s[500005];
ll n, i, k, sel, Max, now;

int main()
{
	scanf("%I64d", &n);
	for (i = 1; i <= n; i++)
		scanf("%I64d", &a[i].x), a[i].tag = i;
	scanf("%I64d", &k);
	sort(a + 1, a + n + 1);
	for (i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i].x;
	for (i = 1; i <= k; i++)
	{
		now += (a[i].x * i - s[i]);
		now += (s[k] - s[i] - a[i].x * (k - i));
	}
	
	now >>= 1;
	sel = 1, Max = now;
	for (i = k + 1; i <= n; i++)
	{
		now -= (s[i - 1] - s[i - 1 - k] - a[i - k].x * k);
		now += (a[i].x * k - s[i] + s[i - k]);
		if (now < Max)
			sel = i - k + 1, Max = now;
	}
	
	for (i = sel; i <= sel + k - 1; i++)
		if (i == sel + k - 1)
			printf("%I64d\n", a[i].tag);
		else
			printf("%I64d ", a[i].tag);
	return 0;
}