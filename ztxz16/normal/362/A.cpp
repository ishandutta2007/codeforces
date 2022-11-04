#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

int FASTBUFFER;

int dx[4] = {2, 2, -2, -2};
int dy[4] = {2, -2, 2, -2};

int test, i, j, tt, ans, x1, y1, x2, y2;
int htag, Hash[16][16][16][16];
char str[16][16];

void dfs(int x1, int y1, int x2, int y2);

int main()
{
	scanf("%d", &test);
	while (test > 0)
	{
		test--;
		for (i = 1; i <= 8; i++)
			scanf("%s", str[i] + 1);
		htag++, tt = 0;
		for (i = 1; i <= 8; i++)
			for (j = 1; j <= 8; j++)
				if (str[i][j] == 'K')
				{
					if (tt == 0)
						x1 = i, y1 = j, tt++;
					else
						x2 = i, y2 = j;
				}
		ans = 0;
		dfs(x1, y1, x2, y2);
		if (ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	return 0;
}

void dfs(int x1, int y1, int x2, int y2)
{
	int xx, yy, xx2, yy2, d1, d2;
	if (Hash[x1][y1][x2][y2] == htag || ans == 1)
		return;
	Hash[x1][y1][x2][y2] = htag;
	if (x1 == x2 && y1 == y2 && str[x1][y1] != '#')
		ans = 1;
	for (d1 = 0; d1 < 4; d1++)
		for (d2 = 0; d2 < 4; d2++)
		{
			xx = x1 + dx[d1], yy = y1 + dy[d1];
			xx2 = x2 + dx[d2], yy2 = y2 + dy[d2];
			if (xx < 1 || xx > 8 || yy < 1 || yy > 8)
				continue;
			if (xx2 < 1 || xx2 > 8 || yy2 < 1 || yy2 > 8)
				continue;
			dfs(xx, yy, xx2, yy2);
		}
}