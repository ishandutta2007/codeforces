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

int n, i, l, r, mid, a[500005];

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	l = 0, r = (n >> 1);
	while (l < r)
	{
		mid = ((l + r + 1) >> 1);
		for (i = 1; i <= mid; i++)
			if (a[i] * 2 > a[n - mid + i])
				break;
		if (i <= mid)
			r = mid - 1;
		else
			l = mid;
	}
	
	cout << n - l << endl;
	return 0;
}