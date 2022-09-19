# include <cstdio>
const int MN = 1010;
char map[MN][MN];
int size[MN][MN];
int nr[MN][MN];
int m, n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
inline bool out (int x, int y)
{
	return x < 0 || x >= n || y < 0 || y >= m;
}
int dfs(int x, int y, int cnr)
{
	if (nr[x][y] || out(x, y) || map[x][y] == '*')
		return 0;
	nr[x][y] = cnr;
	int res = 1;
	for (int i = 0; i < 4; ++i)
		res += dfs (x + dx[i], y + dy[i], cnr);
	return res;
}
void mark(int x, int y, int val)
{
	if (size[x][y] || out(x, y) || map[x][y] == '*')
		return;
	size[x][y] = val;
	for (int i = 0; i < 4; ++i)
		mark (x + dx[i], y + dy[i], val);
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%s", map[i]);
	int cou = 1;
	for (int i = 0; i < n; ++i)
		for (int k = 0; k < m; ++k)
			if (nr[i][k] == 0 && map[i][k] == '.')
			{
				mark (i, k, dfs(i, k, cou));
				cou ++;
			}
	for (int i = 0; i < n; ++i)
		for (int k = 0; k < m; ++k)
			if (map[i][k] == '*')
			{
				int cou = 0;
				int amo[4];
				int nrs[4];
				for (int l = 0; l < 4; ++l)
				{
					int x = i + dx [l];
					int y = k + dy [l];
					if (out(x, y))
						amo[l] = nrs[l] = 0;
					else
					{
						amo[l] = size[x][y];
						nrs[l] = nr[x][y];
					}
				}
				int res = 1;
				for (int l = 0; l < 4; ++l)
				{
					bool use = true;
					for (int o = 0; o < l; ++o)
						if (nrs[o] == nrs[l])
							use = false;
					if (use)
						res += amo[l];
				}
				map[i][k] = '0' + res % 10;
			}
	for (int i = 0; i < n; ++i)
		printf("%s\n", map[i]);
}