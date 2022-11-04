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

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int n, m, s, i, j;
int Hash[505][505], lx[250005], ly[250005];
char str[505][505], ans[505][505];

void bfs(int i, int j);

int main()
{
	scanf("%d %d %d", &n, &m, &s);
	for (i = 1; i <= n; i++)
		scanf("%s", str[i] + 1);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			ans[i][j] = str[i][j];
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
		{
			if (str[i][j] == '.')
				bfs(i, j), i = n + 1, j = m + 1;
		}
	for (i = 1; i <= n; i++)	
		printf("%s\n", ans[i] + 1);
	return 0;
}

void bfs(int i, int j)
{
	int d, xx, yy, h, t, x, y;
	lx[1] = i, ly[1] = j;
	Hash[i][j] = 1;
	for (h = t = 1; h <= t; h++)
	{
		x = lx[h], y = ly[h];
		for (d = 0; d < 4; d++)
		{
			xx = x + dx[d], yy = y + dy[d];
			if (xx < 1 || xx > n || yy < 1 || yy > m)
				continue;
			if (xx == x && yy == y)
				continue;
			if (Hash[xx][yy] || str[xx][yy] != '.')
				continue;
			Hash[xx][yy] = 1, lx[++t] = xx, ly[t] = yy;
		}
	}
	
	for (d = t; d >= t - s + 1; d--)
		ans[lx[d]][ly[d]] = 'X';
	return;
}