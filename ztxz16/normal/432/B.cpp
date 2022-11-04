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

int n, i, a[100005], b[100005], s1[100005], s2[100005];

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d %d", &a[i], &b[i]), s1[a[i]]++, s2[b[i]]++;
	for (i = 1; i <= n; i++)
		printf("%d %d\n", n - 1 + s1[b[i]], n - 1 - s1[b[i]]);
	return 0;
}