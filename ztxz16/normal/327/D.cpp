#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
char Ans1[1000005];
int Ans2[1000005], Ans3[1000005], tot;
int n, m, i, j, dis[505][505];
int hash[505][505], zlx[1000005], zly[1000005];
char str[505][505];

void bfs(int xx, int yy);
void Work(char c, int x, int y);

int main()
{
	scanf("%d %d\n", &n, &m);
	for (i = 1; i <= n; i++)
		gets(str[i] + 1);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			dis[i][j] = 16161616;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			if (str[i][j] == '.' && hash[i][j] == 0)
				bfs(i, j);
	printf("%d\n", tot);
	for (i = 1; i <= tot; i++)
		printf("%c %d %d\n", Ans1[i], Ans2[i], Ans3[i]);
	return 0;
}

void bfs(int xx, int yy)
{
	int x, y, x2, y2, h, t, d;
	zlx[1] = xx, zly[1] = yy;
	dis[xx][yy] = 0;
	for (h = t = 1; h <= t; h++)
	{
		x = zlx[h], y = zly[h];
		hash[x][y] = 1;
		for (d = 0; d < 4; d++)
		{
			x2 = x + dx[d];
			y2 = y + dy[d];
			if (x2 < 1 || x2 > n || y2 < 1 || y2 > m || str[x2][y2] != '.')
				continue;
			if (dis[x][y] + 1 < dis[x2][y2])
			{
				dis[x2][y2] = dis[x][y] + 1;
				zlx[++t] = x2, zly[t] = y2;
			}
		}
	}
	
	for (int i = 1; i <= t; i++)
		Work('B', zlx[i], zly[i]);
	for (int i = t; i > 1; i--)
		Work('D', zlx[i], zly[i]), Work('R', zlx[i], zly[i]);
	return;
}

void Work(char c, int x, int y)
{
	Ans1[++tot] = c;
	Ans2[tot] = x;
	Ans3[tot] = y;
	return;
}