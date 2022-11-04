#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

int FASTBUFFER;

int n, k, i, j, ans, s[16], a[105];

int main()
{
	scanf("%d %d", &n, &k);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	ans = 0;
	for (i = 1; i <= k; i++)
	{
		s[1] = s[2] = 0;
		for (j = i; j <= n; j += k)
			s[a[j]]++;
		ans += min(s[1], s[2]);
	}
	
	printf("%d\n", ans);
	return 0;
}