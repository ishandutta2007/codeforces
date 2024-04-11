#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

int FASTBUFFER;

int n, v, now, succ, ans, s[3005];

int main()
{
	scanf("%d %d", &n, &v);
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		s[a] += b;
	}
	
	for (int i = 1; i <= 3003; i++)
	{
		succ = now;
		now = s[i];
		if (succ >= v)
			ans += v;
		else if (succ + now >= v)
			ans += v, now = succ + now - v;
		else
			ans += (succ + now), now = 0;
	}
	
	printf("%d\n", ans);
	return 0;
}