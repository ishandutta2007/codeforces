# include <cstdio>
# include <cstdlib>
const int MN = 1e3 + 44;
int map[MN][MN];
int gcd(int a, int b)
{
	if (b)
		return gcd(b, a % b);
	else
		return a;
}
int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}
int n, m;
int x0 = -1, y0;
bool visited[MN][MN];
int dx[4] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
void dfs(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= m || visited[x][y] || !map[x][y])
		return;
	visited[x][y] = true;
	for (int i = 0; i < 4; ++i)
		dfs(x + dx[i], y + dy[i]);
}
void err()
{
	printf("-1\n");
	exit(0);
}
int read(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= m)
		return 0;
	else
		return map[x][y];
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int k = 0; k < m; ++k)
			scanf("%d", &map[i][k]);
	int div = 0;
	int cou = 0;
	for (int i = 0; i < n; ++i)
		for (int k = 0; k < m; ++k)
			if (map[i][k])
			{
				cou ++;
				if (x0 == -1)
				{
					dfs(i, k);
					x0 = i, y0 = k;
				}
				else
				{
					if (!visited[i][k])
						err();
					else
						div = gcd(div, lcm(x0 - i, y0 - k));
				}
			}
	if (div == 0)
	{
		if (cou < 3)
			err();
		div = cou - 1;
	}
	else
	{
		if (div < 0)
			div = - div;
// 			printf("div = %d\n", div);
		if (div <= 1)
			err();
		int odd = 0;
		for (int i = x0 % div; i < n; i += div)
			for (int k = y0 % div; k < m; k += div)
				if (read(i, k))
				{
// 					printf("in %d %d\n", i, k);
					int deg = 0;
					for (int nr = 0; nr < 4; ++nr)
					{
						int cou = 0;
						for (int x = 1; x < div; ++x)
							cou += read(i + x * dx[nr], k + x * dy[nr]);
						if (read(i + div * dx[nr], k + div * dy[nr]))
						{
							if (cou == div - 1)
								deg ++;
							else if (cou)
								err();
						}
						else if (cou)
							err();
					}
// 					printf("deg = %d\n", deg);
					if (deg % 2)
						odd++;
				}
		if (odd > 2)
			err();
	}
	for (int i = 2; i <= div; ++i)
		if (div % i == 0)
			printf("%d ", i);
	printf("\n");
}