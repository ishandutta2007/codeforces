# include <cstdio>
# include <set>
using namespace std;
const int MN = 111;
const int MQ = 1e4 + 44;
int a[MN][MN];
struct query
{
	int t, i, k, x;
};
query tab[MQ];
int n, m, q;
void show()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int k = 1; k <= m; ++k)
			printf("%d ", a[i][k]);
		printf("\n");
	}
}
int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < q; ++i)
	{
		int t;
		scanf("%d", &t);
		tab[i].t = t;
		if (t == 1)
			scanf("%d", &tab[i].i);
		else if (t == 2)
			scanf("%d", &tab[i].k);
		else
			scanf("%d%d%d", &tab[i].i, &tab[i].k, &tab[i].x);
	}
	for (int i = q - 1; i >= 0; --i)
	{
		if (tab[i].t == 2)
		{
			int last = a[n][tab[i].k];
			for (int k = 1; k <= n; ++k)
				swap(last, a[k][tab[i].k]);
		}
		else if (tab[i].t == 1)
		{
			int last = a[tab[i].i][m];
			for (int k = 1; k <= m; ++k)
				swap(last, a[tab[i].i][k]);
		}
		else
		{
			a[tab[i].i][tab[i].k] = tab[i].x;
		}
	}
	show();
}