# include <cstdio>
# include <algorithm>
using namespace std;
const int MN = 2e5 + 44;
pair <pair <int, int>, int> tab[MN];
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n * 2 - 1; ++i)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			tab[i] = make_pair(make_pair(x, y), i + 1);
		}
		sort(tab, tab + n * 2 - 1);
		printf("YES\n");
		for (int i = 0; i < n - 1; ++i)
			if (tab[i * 2].first.second > tab[i * 2 + 1].first.second)
				printf("%d ", tab[i * 2].second);
			else
				printf("%d ", tab[i * 2 + 1].second);
		printf("%d\n", tab[2 * n - 2].second);
	}
}