# include <cstdio>
const int MN = 1e5 + 44;
bool cyclic[MN];
int u[MN];
void init(int n)
{
	for (int i = 1; i <= n; ++i)
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
	a = find(a);
	b = find(b);
	if (a != b)
	{
		u[b] = a;
		if (cyclic[b])
			cyclic[a] = true;
	}
	else
		cyclic[a] = true;
}
int main()
{
	int m, n;
	scanf("%d%d", &n, &m);
	init(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		unite(a, b);
	}
	int res = 0;
	for (int i = 1; i <= n; ++i)
		if (find(i) == i && !cyclic[i])
			res++;
	printf("%d\n", res);
}