#include <iostream>
#include <cstdio>
using namespace std;

//#define HASFILES

#define TASK ""

const int N = 20;

bool was[N][N][N];

int k, n, m;
	
int vx[] = {1, 0, 0, 0, 0, -1}, vy[] = {0, 1, 0, -1, 0, 0}, vz[] = {0, 0, 1, 0, -1, 0};

char field[N][N][N];

int DFS(int x, int y, int z)
{
	int ans = 0;
	was[x][y][z] = 1;
	int nx, ny, nz;
	for (int v = 0; v < 6; v++)
	{
		nx = x + vx[v];
		ny = y + vy[v];
		nz = z + vz[v];
		if (nx < 1 || nx > n || ny < 1 || ny > m || nz < 1 || nz > k)
			continue;
		if (field[nz][nx][ny] == '#')
			continue;
		if (was[nx][ny][nz])
			continue;
		ans += DFS(nx, ny, nz);
	}
	return ans + 1;
}

int main(int argc, char **argv)
{
#ifdef HASFILES
	freopen(TASK".in", "r", stdin);
	//freopen(TASK".out", "w", stdout);
#endif
	char buf[N];
	cin >> k >> n >> m;
	for (int i = k; i >= 1; i--)
	{
		for (int x = 1; x <= n; x++)
			cin >> field[i][x] + 1;	
	}
	int x, y;
	cin >> x >> y;
	cout << DFS(x, y, k);
	
	return 0;
}