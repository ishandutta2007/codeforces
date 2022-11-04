#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <functional>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

long long FASTBUFFER;

long long n, m, i, l, r, mid, a, s, s1, s2;
long long p[100005], b[100005];

int main()
{
	scanf("%I64d %I64d %I64d", &n, &m, &a);
	for (i = 1; i <= n; i++)
		scanf("%I64d", &b[i]);
	for (i = 1; i <= m; i++)
		scanf("%I64d", &p[i]);
	sort(b + 1, b + n + 1, greater <int>());
	sort(p + 1, p + m + 1);
	l = 0, r = min(n, m);
	while (l < r)
	{
		mid = ((l + r + 1) >> 1);
		s = a;
		for (i = 1; i <= mid; i++)
		{
			s -= max(p[mid - i + 1] - b[i], 0LL);
			if (s < 0)
				break;
		}
		
		if (s < 0)
			r = mid - 1;
		else
			l = mid;
	}
	
	if (l == 0)
	{
		printf("0 0\n");
		return 0;
	}
	
	s1 = s2 = 0;
	for (i = 1; i <= l; i++)
		s1 += min(b[i], p[l - i + 1]), s2 += max(p[l - i + 1] - b[i], 0LL);
	printf("%I64d %I64d\n", l, max(s1 - max(a - s2, 0LL), 0LL));
	return 0;
}