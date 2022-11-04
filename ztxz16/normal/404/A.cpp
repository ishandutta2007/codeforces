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

int n, i, j;
char s[305][305];

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%s", s[i] + 1);
	for (i = 1; i <= n; i++)
		if (s[i][i] != s[1][1] || s[i][n - i + 1] != s[1][1])
		{
			printf("NO\n");
			return 0;
		}
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
		{
			if (i == j || i + j - 1 == n)
				continue;
			if (s[i][j] == s[1][1] || s[i][j] != s[1][2])
			{
				printf("NO\n");
				return 0;
			}
		}
	printf("YES\n");
	return 0;
}