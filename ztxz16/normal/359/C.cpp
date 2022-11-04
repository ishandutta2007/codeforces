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
#define mo 1000000007

using namespace std;

long long FASTBUFFER;

multiset <long long> b;
multiset <long long>::iterator it;
long long n, x, i, j, Ans, Min, Now, Sur, s, a[100005];

long long sumi(long long a, long long b);

int main()
{
	scanf("%I64d %I64d", &n, &x);
	for (i = 1; i <= n; i++)
		scanf("%I64d", &a[i]), s += a[i];
	for (i = 1; i <= n; i++)
		b.insert(s - a[i]);
	Now = *b.begin(), Sur = 0, it = b.begin();
	while (1)
	{
		for (; it != b.end(); ++it)
			if (*it == Now)
				Sur++;
			else
				break;
		if (Sur % x > 0)
		{
			Min = Now;
			break;
		}
		
		Sur /= x;
		Now++;
	}
	
	if (Min > s)
		Min = s;
	Ans = sumi(x, Min);
	printf("%I64d\n", Ans);
	return 0;
}

long long sumi(long long a, long long b)
{
	long long ret = 1, c = a;
	while (b > 0)
	{
		if (b & 1LL)
			ret *= c, ret %= mo;
		c *= c, c %= mo;
		b >>= 1;
	}
	
	return ret;
}