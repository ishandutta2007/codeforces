#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int T, n, cnt, head[Maxn], val[Maxn];
long long ans;
priority_queue <int> Pr; 
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
bool flag = false;
void dfs(int u, int fa)
{
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
		{
			dfs(to, u);
			if (!fa && !flag)
			{
				flag = true;
				continue;
			}
			Pr.push(val[u]);
		}
	}
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		flag = false;
		cnt = 0;
		while (!Pr.empty()) Pr.pop();
		ans = 0;
		scanf("%d", &n);
		memset(head, 0, sizeof(int[n + 1]));
		for (int i = 1; i <= n; i++)
			scanf("%d", &val[i]), ans += val[i];
		for (int i = 1; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			add(x, y), add(y, x);
		}
		dfs(1, 0);
		for (int i = 1; i < n; i++)
		{
			printf("%lld ", ans);
			if (i != n - 1) ans += Pr.top(), Pr.pop();
		}
	}
	return 0;
}