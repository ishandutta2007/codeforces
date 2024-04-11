# include <cstdio>
const int MN = 2e3 + 44;
int u[MN];
void init()
{
	for (int i = 0; i < MN; ++i)
		u[i] = i;
}
int find(int x)
{
	if (u[x] == x)
		return x;
	else
		return u[x] = find(u[x]);
}
void unite(int a, int b)
{
	u[find(a)] = find(b);
}
int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	init();
	for (int i = 0; i + k <= n; ++i)
	{
		for (int pos = 0; pos * 2 < k; ++pos)
			unite(i + pos, i + k - pos - 1);
	}
	long long res = 1;
	for (int i = 0; i < n; ++i)
		if (find(i) == i)
			res = res * m % ((int)1e9 + 7);
	printf("%d\n", (int) res);
}