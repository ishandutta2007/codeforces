# include <cstdio>
const int MN = 3e3 + 44;
const int range = 1e3;
bool is[range * 2 + 1][range * 2 + 1];
int x[MN], y[MN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", x + i, y + i);
		x[i] += range;
		y[i] += range;
		is[x[i]][y[i]] = true;
	}
	int res = 0;
	for (int i = 0; i < n; ++i)
		for (int k = i + 1; k < n; ++k)
			if ((x[i] - x[k] & 1) == 0 && (y[i] - y[k] & 1) == 0 && is[(x[i] + x[k]) / 2][(y[i] + y[k]) / 2])
				res++;
	printf("%d\n", res);
}