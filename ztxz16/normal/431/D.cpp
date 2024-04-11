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

typedef unsigned long long ll;

using namespace std;

ll m, k, l, r, mid, i, j;
ll C[105][105];

ll calc(ll n);

int main()
{
	cin >> m >> k;
	C[0][0] = 1;
	for (i = 1; i <= 100; i++)
	{
		C[i][0] = 1;
		for (j = 1; j <= 100; j++)
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
	}
	
	l = 1, r = 1000000000000000000LL;
	while (l < r)
	{
		mid = (l + ((r - l + 1) >> 1));
		if (calc(mid * 2 + 1) - calc(mid + 1) <= m)
			l = mid;
		else
			r = mid - 1;
	}
	
	cout << l << endl;
	return 0;
}

ll calc(ll n)
{
	int tot = 0, a[105] = {0}, s = 0;
	ll ret = 0;
	while (n)
		a[++tot] = (n & 1), n >>= 1;
	for (i = tot; i >= 1; i--)
	{
		if (a[i] == 1)
		{
			if (k - s >= 0 && k - s <= i - 1)
				ret += C[i - 1][k - s];
			s++;
		}
	}
	
	return ret;
}