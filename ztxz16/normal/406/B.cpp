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

const int s = 1000000;
int x, n, i, Hash[s + 5];

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &x), Hash[x] = 1;
	printf("%d\n", n);
	for (i = 1; i <= s; i++)
		if (Hash[s - i + 1] == 0 && Hash[i] == 1)
			n--, printf("%d ", s - i + 1);
	for (i = 1; i <= s; i++)
		if (Hash[i] + Hash[s - i + 1] == 0 && n)
			n -= 2, printf("%d %d ", i, s - i + 1);
	return 0;
}