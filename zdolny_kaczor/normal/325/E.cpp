# include <cstdio>
# include <set>
const int MN = 1e5 + 44;
const int NONE = -1;
int per[MN];
int u[MN];
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
	int n;
	scanf("%d", &n);
	if (n % 2 == 1)
	{
		int in = 0;
		for (int i = 0; i < n; ++i)
		{
			if (in == 0 && i != 0)
			{
				printf("-1\n");
				return 0;
			}
			in = (2 * in + 1) % n;
		}
		if (in != 0)
			printf("-1\n");
		else
			for (int i = 0; i <= n; ++i)
			{
				printf("%d ", in);
				in = (in * 2 + 1) % n;
			}
	}
	else
	{
		for (int i = 0; i < n / 2; ++i)
		{
			per[i] = (i * 2) % n;
			per[i + n / 2] = (i * 2 + 1) % n;
		}
		for (int i = 0; i < n; ++i)
			u[i] = i;
		for (int i = 0; i < n; ++i)
			unite(i, per[i]);
		for (int i = 0; i < n / 2; ++i)
		{
			if (find(i) != find(i + n / 2))
			{
				std::swap(per[i], per[i + n / 2]);
				unite(i, i + n / 2);
			}
		}
	}
	int wh = 0;
	do
	{
		printf("%d ", wh);
		wh = per[wh];
	}
	while (wh);
	printf("0\n");
}