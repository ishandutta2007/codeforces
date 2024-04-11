# include <cstdio>
# include <vector>
# include <algorithm>
using namespace std;
const int MN = 1e5 + 44;
vector <int> pos[MN];
pair <pair <int, int>, int> queries[MN];
int ans[MN];
int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i)
	{
		int x;
		scanf("%d", &x);
		if (x < MN)
			pos[x].push_back(i);
	}
	for (int i = 0; i < q; ++i)
	{
		scanf("%d%d", &queries[i].first.first, &queries[i].first.second);
		queries[i].second = i;
	}
	sort(queries, queries + q);
	for (int nr = 1; nr < MN; ++nr)
		if (pos[nr].size() >= nr)
		{
			int head = 0;
			for (int i = 0; i + nr - 1 < pos[nr].size(); ++i)
			//counting those which contain numbers from pos[i] to pos[i + nr - 1]
			{
				while (head < q && queries[head].first.first <= pos[nr][i])
				{
					if (queries[head].first.second >= pos[nr][i + nr - 1] && (i + nr == pos[nr].size() || queries[head].first.second < pos[nr][i + nr]))
						ans[queries[head].second]++;
					head++;
				}
			}
		}
	for (int i = 0; i < q; ++i)
		printf("%d\n", ans[i]);
}