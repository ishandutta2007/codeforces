#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

const int inf = 1e9;

set<int> G[100001];
set<int> query[100001];
set<int> res[100001];
int ans[100001];

void dfs(int u, int fa = -1)
{
	set<int> lca;
	for (int v: G[u])
	{
		if (v == fa)
			continue;
		for (int q: query[v])
			if (query[u].count(q))
				ans[q] = inf;
		dfs(v, u);
		if (res[u].size() < res[v].size())
			swap(res[u], res[v]);
		for (int q: res[v])
		{
			if (query[u].count(q))
				ans[q]++;
			else if (res[u].count(q))
				lca.insert(q);
			else
				res[u].insert(q);
		}
	}
	for (int q: lca)
		res[u].erase(q), ans[q]++;
	for (int q: query[u])
	{
		if (res[u].count(q))
			ans[q]++;
		res[u].insert(q);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].insert(v);
		G[v].insert(u);
	}
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i)
	{
		int k;
		scanf("%d", &k);
		while (k--)
		{
			int u;
			scanf("%d", &u);
			query[u].insert(i);
		}
	}
	dfs(1);
	for (int i = 0; i < q; ++i)
		printf("%d\n", ans[i] < inf ? ans[i] : -1);
	return 0;
}