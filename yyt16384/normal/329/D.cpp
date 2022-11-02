#include <cstdio>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 105;
const int DR[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
const char CH[4] = {'<', '^', '>', 'v'};

int n;
char a[MAXN][MAXN];

void init()
{
	scanf("%d%*d", &n);
}

void add(int x, int y, int dir, int len)
{
	for (int i = 0; i < len; ++i)
	{
		if (i < len / 2  - 1 || i % 2 == 0) a[x][y] = CH[dir];
		else a[x][y] = '.';
		x += DR[dir][0]; y += DR[dir][1];
	}
}

void solve()
{
	add(0, 0, 3, n - 1);
	for (int i = 0; i < n - 1; i += 2)
	{
		add(n - 1, i, 2, 1);
		add(n - 1, i + 1, 1, n - 1);
		add(1, i + 1, 2, 1);
		add(1, i + 2, 3, n - 2);
	}
	add(n - 2, n - 1, 2, 1);
	add(n - 1, n - 1, 1, n - 1);
	add(0, n - 1, 0, n - 1);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			printf("%c", a[i][j]);
		printf("\n");
	}
	printf("1 1\n");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("8775.in", "r", stdin);
	freopen("8775.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}