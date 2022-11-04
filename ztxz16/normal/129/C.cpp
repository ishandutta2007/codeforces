#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#define PQ priority_queue
#define OO 2147483647

using namespace std;

struct point
{
	int x, y;
}Can[16][10005], Now, New;

int dx[9] = {-1, 0, 1, -1, 1, -1, 0, 1, 0};
int dy[9] = {-1, -1, -1, 0, 0, 1, 1, 1, 0};
int i, j, k, d;
int sum[16], h2[16][16], tag;
char Map[16][16][16];

int main()
{
	for (i = 1; i <= 8; i++)
		gets(Map[0][i] + 1);
	for (i = 1; i <= 8; i++)
		for (j = 1; j <= 8; j++)
			for (k = 1; k <= 8; k++)
			{
				if (Map[i - 1][j - 1][k] == 'S')
					Map[i][j][k] = 'S';
				else
					Map[i][j][k] = '.';
			}
			
	Can[0][1].x = 8, Can[0][1].y = 1;
	sum[0] = 1;
	for (i = 0; i < 8; i++)
	{
		tag++;
		for (j = 1; j <= sum[i]; j++)
		{
			Now = Can[i][j];
			for (d = 0; d < 9; d++)
			{
				New.x = Now.x + dx[d];
				New.y = Now.y + dy[d];
				if (New.x < 1 || New.x > 8 || New.y < 1 || New.y > 8)
					continue;
				if (Map[i + 1][New.x][New.y] == 'S' || Map[i][New.x][New.y] == 'S' || h2[New.x][New.y] == tag)
					continue;
				sum[i + 1]++;
				Can[i + 1][sum[i + 1]] = New;
				h2[New.x][New.y] = tag;
			}
		}
	}
	
	if (sum[8] == 0)
		printf("LOSE\n");
	else
		printf("WIN\n");
	return 0;
}