# include <cstdio>
int dx[128], dy[128];
char tab[1311];
int main()
{
	dx['D'] = 1;
	dx['U'] = -1;
	dy['R'] = 1;
	dy['L'] = -1;
	int n;
	scanf("%d%s", &n, tab);
	int res = 0;
	for (int i = 0; i < n; ++i)
		for (int k = i; k < n; ++k)
		{
			int x = 0, y = 0;
			for (int l = i; l <= k; ++l)
			{
				x+=dx[tab[l]];
				y+=dy[tab[l]];
			}
			if (x == 0 && y == 0)
				res++;
		}
	printf("%d\n", res);
}