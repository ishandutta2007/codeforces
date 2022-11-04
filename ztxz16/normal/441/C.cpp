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

int n, m, k, tot, now;
pair <int, int> a[100005];

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
	{
		if (i & 1)
			for (int j = 1; j <= m; j++)
				a[++tot] = make_pair(i, j);
		else
			for (int j = m ;j >= 1; j--)
				a[++tot] = make_pair(i, j);
	}
	
	for (int i = 1; i <= k; i++)
	{
		if (i == k)
		{
			printf("%d ", tot - now);
			for (int j = now + 1; j <= tot; j++)
				printf("%d %d ", a[j].first, a[j].second);
			printf("\n");
		}
		
		else
		{
			printf("2 ");
			for (int j = now + 1; j <= now + 2; j++)
				printf("%d %d ", a[j].first, a[j].second);
			printf("\n");
			now += 2;
		}
	}
	
	return 0;
}