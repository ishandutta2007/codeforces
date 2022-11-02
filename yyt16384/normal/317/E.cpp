#include <cstdio>
#include <cstring>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 405;
const int SZ = 101;
const int SZ2 = 205;
const int DR[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
const char CH[4] = {'L', 'U', 'R', 'D'};

int n;
int x1, y1, x2, y2;
int X[MAXN];
int Y[MAXN];
bool a[SZ2][SZ2];
int dist[SZ2][SZ2];
int predir[SZ2][SZ2];
int transf[4];

void init()
{
	scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &n);
	x1 += SZ; y1 += SZ;
	x2 += SZ; y2 += SZ;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", &X[i], &Y[i]);
		X[i] += SZ; Y[i] += SZ;
		a[X[i]][Y[i]] = true;
	}
}

void BFS()
{
	static int que[SZ2 * SZ2][2];
	int qb = 0, qe = 1;

	memset(dist, -1, sizeof(dist));
	que[0][0] = x2;
	que[0][1] = y2;
	dist[x2][y2] = 0;

	while (qb < qe)
	{
		int x = que[qb][0], y = que[qb][1];
		++qb;
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + DR[i][0];
			int ny = y + DR[i][1];
			if (nx < 0 || nx >= SZ2 || ny < 0 || ny >= SZ2 || a[nx][ny] || dist[nx][ny] != -1)
				continue;
			dist[nx][ny] = dist[x][y] + 1;
			predir[nx][ny] = i ^ 2;
			que[qe][0] = nx;
			que[qe][1] = ny;
			++qe;
			if (nx == x1 && ny == y1) return;
		}
	}
}

bool work1()
{
	const int SZQ = SZ2 * SZ2;
	static int que[SZQ];
	int qb = 0, qe = 0;

	for (int tx = x1, ty = y1; tx != x2 || ty != y2; )
	{
		int dir = predir[tx][ty];
		que[qe] = dir;
		qe = (qe + 1) % SZQ;
		tx += DR[dir][0]; ty += DR[dir][1];
	}

	while (!(x1 == x2 && y1 == y2) && x1 >= 0 && x1 < SZ2 && y1 >= 0 && y1 < SZ2)
	{
		int dir = que[qb];
		qb = (qb + 1) % SZQ;
		x1 += DR[dir][0]; y1 += DR[dir][1];
		printf("%c", CH[dir]);
		int tx = x2 + DR[dir][0], ty = y2 + DR[dir][1];
		if (tx < 0 || tx >= SZ2 || ty < 0 || ty >= SZ2 || !a[tx][ty])
			x2 = tx, y2 = ty, que[qe] = dir, qe = (qe + 1) % SZQ;
	}

	return x1 == x2 && y1 == y2;
}

void flip_x()
{
	for (int i = 0; i < SZ2 / 2; ++i)
		for (int j = 0; j < SZ2; ++j)
		{
			bool tmp = a[i][j]; a[i][j] = a[SZ2 - i - 1][j]; a[SZ2 - i - 1][j] = tmp;
		}
	transf[0] = 2; transf[2] = 0;
}

void flip_y()
{
	for (int i = 0; i < SZ2; ++i)
		for (int j = 0; j < SZ2 / 2; ++j)
		{
			bool tmp = a[i][j]; a[i][j] = a[i][SZ2 - j - 1]; a[i][SZ2 - j - 1] = tmp;
		}
	transf[1] = 3; transf[3] = 1;
}

void work2()
{
	for (int i = 0; i < 4; ++i)
		transf[i] = i;
	if (x1 > x2)
	{
		x1 = SZ2 - x1 - 1;
		x2 = SZ2 - x2 - 1;
		flip_x();
	}
	if (y1 > y2)
	{
		y1 = SZ2 - y1 - 1;
		y2 = SZ2 - y2 - 1;
		flip_y();
	}

	while (x1 < SZ2)
	{
		printf("%c", CH[transf[2]]);
		++x1; ++x2;
	}
	while (y1 < SZ2)
	{
		printf("%c", CH[transf[1]]);
		++y1; ++y2;
	}

	while (x2 >= 0)
	{
		printf("%c", CH[transf[0]]);
		--x1; --x2;
	}
	while (y2 >= 0)
	{
		printf("%c", CH[transf[3]]);
		--y1; --y2;
	}

	int xl, yl;
	for (int i = 0; i < SZ2; ++i)
	{
		bool fl = false;
		for (int j = 0; j < SZ2; ++j)
			if (a[i][j])
			{
				xl = i; yl = j;
				fl = true; break;
			}
		if (fl) break;
	}

	while (x2 < xl)
	{
		printf("%c", CH[transf[2]]);
		++x1; ++x2;
	}
	while (y2 < yl - 1)
	{
		printf("%c", CH[transf[1]]);
		++y1; ++y2;
	}

	while (y1 < y2)
	{
		printf("%c", CH[transf[1]]);
		++y1;
	}

	printf("%c", CH[transf[0]]);
	--x1; --x2;
	printf("%c", CH[transf[1]]);
	++y1; ++y2;

	while (x1 < x2)
	{
		printf("%c", CH[transf[2]]);
		++x1;
	}
}

void solve()
{
	if (n == 0)
	{
		printf("-1\n");
		return;
	}
	BFS();
	if (dist[x1][y1] == -1)
	{
		printf("-1\n");
		return;
	}

	if (!work1()) work2();
	printf("\n");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("8777.in", "r", stdin);
	freopen("8777.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}