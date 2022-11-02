#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, m, ct, x[Maxn], y[Maxn], w[Maxn], ans[Maxn];
set <int> Se[Maxn];
bool vis[Maxn];
queue <int> Qu;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &w[i]);
	for (int i = 1; i <= m; i++)
		scanf("%d%d", &x[i], &y[i]), Se[x[i]].insert(i), Se[y[i]].insert(i);
	for (int i = 1; i <= m; i++)
		w[x[i]]--, w[y[i]]--;
	for (int i = 1; i <= n; i++)
		if (w[i] >= 0)
			Qu.push(i), vis[i] = true;
	while (!Qu.empty())
	{
		int u = Qu.front();
		Qu.pop();
		for (set <int> :: iterator it = Se[u].begin(); it != Se[u].end(); it++)
		{
			int now = *it;
			ans[++ct] = now;
			if (x[now] == u)
			{
				Se[y[now]].erase(now), w[y[now]]++;
				if (w[y[now]] >= 0 && !vis[y[now]]) Qu.push(y[now]), vis[y[now]] = true;
			}
			else
			{
				Se[x[now]].erase(now), w[x[now]]++;
				if (w[x[now]] >= 0 && !vis[x[now]]) Qu.push(x[now]), vis[x[now]] = true;
			}
		}
	}
	if (ct == m)
	{
		puts("ALIVE");
		for (int i = ct; i >= 1; i--)
			printf("%d ", ans[i]);
	}
	else puts("DEAD");
	return 0;
}