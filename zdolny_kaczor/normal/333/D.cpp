# include <cstdio>
# include <vector>
using namespace std;
const int MN = 1020;
int a[MN][MN];
bool seen[MN][MN];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int k = 0; k < m; ++k)
			scanf("%d", &a[i][k]);
	int low = 0, high = 1e9, ans = 0;
	while (low <= high)
	{
		for (int i = 0; i < m; ++i)
			for (int k = 0; k < m; ++k)
				seen[i][k] = false;
		int med = (low + high) / 2;
		bool poss = false;
		for (int i = 0; i < n && !poss; ++i)
		{
			vector <int> currrow;
			for (int k = 0; k < m; ++k)
				if (a[i][k] >= med)
				{
					currrow.push_back(k);
				}
			for (int y = 0; y < currrow.size() && !poss; ++y)
				for (int z = y + 1; z < currrow.size() && !poss; ++z)
					if (seen[currrow[y]][currrow[z]])
						poss = true;
					else
						seen[currrow[y]][currrow[z]] = true;
		}
		if (!poss)
			high = med - 1;
		else
		{
			ans = med;
			low = med + 1;
		}
	}
	printf("%d\n", ans);
}