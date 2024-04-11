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

int n, x, i, ans, f[1000005];

int main()
{
	scanf("%d", &n);
	f[1] = 0;
	for (i = 1; i <= n; i++)
		f[i] = f[i - 1] ^ i;
	ans = 0;
	for (i = 1; i <= n; i++)
		scanf("%d", &x), ans ^= x;
	for (i = 2; i <= n; i++)
	{
		ans ^= f[n % i];
		if ((n / i) & 1)
			ans ^= f[i - 1];
	}

	printf("%d\n", ans);
	return 0;
}