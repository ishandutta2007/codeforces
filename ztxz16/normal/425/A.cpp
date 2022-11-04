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

int n, k, i, j, l, t1, t2, s, ans;
int a[205], b1[205], b2[205];

int main()
{
	scanf("%d %d", &n, &k);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	ans = -OO;
	for (i = 1; i <= n; i++)
		for (j = i; j <= n; j++)
		{
			t1 = t2 = s = 0;
			for (l = i; l <= j; l++)
				b1[++t1] = a[l], s += a[l];
			for (l = 1; l <= n; l++)
				if (l < i || l > j)
					b2[++t2] = a[l];
			sort(b1 + 1, b1 + t1 + 1, greater <int>());
			sort(b2 + 1, b2 + t2 + 1, greater <int>());
			for (l = 1; l <= k && l <= t2; l++)
				if (t1 >= 1 && b2[l] > b1[t1])
					s += (b2[l] - b1[t1]), t1--;
			ans = max(ans, s);
		}
	
	printf("%d\n", ans);
	return 0;
}