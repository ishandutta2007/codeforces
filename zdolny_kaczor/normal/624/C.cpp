# include <cstdio>
# include <cstdlib>
const int MN = 504;
bool is[MN][MN];
int n, m;
int color[MN];
void err()
{
	printf("No\n");
	exit(0);
}
void dfs(int x, int col)
{
// 	printf("dfs %d %d\n", x, col);
	if (color[x] == (col ^ 3))
		err();
// 	printf ("go on");
	if (color[x] == col)
		return;
	color[x] = col;
	for (int i = 1; i <= n; ++i)
		if (!is[x][i] && i != x)
			dfs(i, col ^ 3);
}
char mapping[] = "bac";
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		is[x][y] = is[y][x] = true;
	}
	bool found = false;
	for (int i = 1; i <= n; ++i)
	{
		if (color[i])
			continue;
		bool isolated = true;
		for (int k = 1; k <= n; ++k)
			if (i != k && !is[i][k])
				isolated = false;
		if (!isolated)
		{
// 			printf("%d is not isolated\n", i);
			if (found)
				err();
			found = true;
			dfs(i, 2);
		}
	}
	for (int i = 1; i <= n; ++i)
		for (int k = i + 1; k <= n; ++k)
			if (is[i][k] && color[i] * color[k] == 2)
				err();
	printf("Yes\n");
	for (int i = 1; i <= n; ++i)
		putchar(mapping[color[i]]);
	putchar('\n');
}