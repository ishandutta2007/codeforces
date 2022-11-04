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

int n, m, i, j, k, ans;
int s1[405][405], s2[405][405], s3[405][405], s4[405][405];
char str[405][405];

int main()
{
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		scanf("%s", str[i] + 1);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			s1[i][j] = s1[i][j - 1] + str[i][j] - '0', s2[i][j] = s2[i - 1][j] + str[i][j] - '0';
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			if (str[i][j] == '1')
				s3[i][j] = 0;
			else
				s3[i][j] = s3[i - 1][j - 1] + 1;
	for (i = n; i >= 1; i--)
		for (j = 1; j <= m; j++)
			if (str[i][j] == '1')
				s4[i][j] = 0;
			else
				s4[i][j] = s4[i + 1][j - 1] + 1;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
		{
			if (str[i][j] == '1')
				continue;
			for (k = 1; j - k >= 1 && j + k <= m && i - k >= 1 && str[i - k][j - k] == '0' && str[i - k][j + k] == '0'; k++)
				ans += (s1[i - k][j + k] == s1[i - k][j - k - 1]);
			for (k = 1; j - k >= 1 && j + k <= m && i + k <= n && str[i + k][j - k] == '0' && str[i + k][j + k] == '0'; k++)
				ans += (s1[i + k][j + k] == s1[i + k][j - k - 1]);
			for (k = 1; i - k >= 1 && i + k <= n && j - k >= 1 && str[i + k][j - k] == '0' && str[i - k][j - k] == '0'; k++)
				ans += (s2[i + k][j - k] == s2[i - k - 1][j - k]);
			for (k = 1; i - k >= 1 && i + k <= n && j + k <= m && str[i + k][j + k] == '0' && str[i - k][j + k] == '0'; k++)
				ans += (s2[i + k][j + k] == s2[i - k - 1][j + k]);
			for (k = 1; i - k >= 1 && j + k <= m && str[i][j + k] == '0' && str[i - k][j] == '0'; k++)
				ans += (s3[i][j + k] > k);
			for (k = 1; i + k <= n && j - k >= 1 && str[i + k][j] == '0' && str[i][j - k] == '0'; k++)
				ans += (s3[i + k][j] > k);
			for (k = 1; i - k >= 1 && j - k >= 1 && str[i - k][j] == '0' && str[i][j - k] == '0'; k++)
				ans += (s4[i - k][j] > k);
			for (k = 1; i + k <= n && j + k <= m && str[i + k][j] == '0' && str[i][j + k] == '0'; k++)
				ans += (s4[i][j + k] > k);
		}
	
	printf("%d\n", ans);
	return 0;
}