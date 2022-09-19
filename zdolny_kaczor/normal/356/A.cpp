# include <cstdio>
const int MN = 3e5 + 44;
int u[MN];
void remove(int x)
{
	u[x] = x + 1;
}
int next(int x)
{
	if (u[x] == x)
		return x;
	else
		return u[x] = next(u[x]);
}
int ans[MN];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n + 1; ++i)
		u[i] = i;
	for (int i = 0; i < m; ++i)
	{
		int l, r, x;
		scanf("%d%d%d", &l, &r, &x);
		int pos = next(l);
		while (pos <= r)
		{
			if (pos == x)
				pos = next(pos + 1);
			else
			{
				ans[pos] = x;
				remove(pos);
				pos = next(pos);
			}
		}
	}
	for (int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
}