#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int Next[4] = {3, 2, 0, 1};
int Hash[505][505], f[505][505], x, y, d;

int main()
{
	f[200][200] = -1;
	Hash[200][200] = 1;
	d = 1, x = y = 200;
	while (1)
	{
		if (x < 100)
			break;
		if (Hash[x + dx[Next[d]]][y + dy[Next[d]]] == 0)
			f[x + dx[Next[d]]][y + dy[Next[d]]] = f[x][y] + 1, Hash[x + dx[Next[d]]][y + dy[Next[d]]] = 1, d = Next[d], x += dx[d], y += dy[d];
		else
			f[x + dx[d]][y + dy[d]] = f[x][y], Hash[x + dx[d]][y + dy[d]] = 1, x += dx[d], y += dy[d];
	}
	
	f[200][200] = 0;
	scanf("%d %d", &x, &y);
	printf("%d\n", f[x + 200][y + 200]);
	return 0;
}