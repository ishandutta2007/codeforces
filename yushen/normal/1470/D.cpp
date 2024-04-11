#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
int T, n, m, col[Maxn];
vector <int> ans, Ve[Maxn];
bool vis[Maxn];
void dfs(int u, int c)
{
	vis[u] = true;
	bool flag = 0;
	for (auto v : Ve[u])
		flag |= (vis[v] && col[v] == 1);
	if (flag) c = 0;
	if (c) ans.push_back(u);
	col[u] = c;
	for (auto v : Ve[u])
		if (!vis[v])
			dfs(v, c ^ 1);
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			vis[i] = false, col[i] = 0, Ve[i].clear();
		ans.clear();
		for (int i = 1; i <= m; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			Ve[x].push_back(y), Ve[y].push_back(x);
		}
		dfs(1, 1);
		bool flag = true;
		for (int i = 1; i <= n; i++)
			if (!vis[i])
				flag = false;
		if (!flag) puts("NO");
		else
		{
			puts("YES");
			printf("%d\n", (int) ans.size());
			for (auto u : ans)
				printf("%d ", u);
			puts("");
		}
	}
	return 0;
}