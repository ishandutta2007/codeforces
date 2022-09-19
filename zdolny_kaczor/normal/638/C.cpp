# include <cstdio>
# include <vector>
using namespace std;
const int MN = 2e5 + 44;
vector <pair <int, int> > graph[MN];
vector <int> ans[MN];
void dfs(int x, int y = -1, int color = -1)
{
	int last = 0;
	for (auto v : graph[x])
		if (v.first != y)
		{
			if (last == color)
				last++;
			ans[last].push_back(v.second);
			dfs(v.first, x, last);
			last++;
		}
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a].push_back(make_pair(b, i));
		graph[b].push_back(make_pair(a, i));
	}
	dfs(1);
	int max;
	for (max = 0; ans[max].size(); ++max)
		;
	printf("%d\n", max);
	for (int i = 0; i < max; ++i)
	{
		printf("%d", (int) ans[i].size());
		for (auto x : ans[i])
			printf(" %d", x);
		printf("\n");
	}
}