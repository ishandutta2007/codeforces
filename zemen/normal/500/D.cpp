#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

typedef long long ll;
typedef long double ld;

const int INF = 1000001000;
const ll INFL = 2000000000000001000;
int solve();


int main()
{
	srand(2317);
	cout.precision(10);
	cout.setf(ios::fixed);
	#ifdef LOCAL
	freopen("d.in", "r", stdin);
	#else
	#endif
	int tn = 1;
	for (int i = 0; i < tn; ++i)
		solve();
	#ifdef LOCAL
	cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
	#endif
}

pair <int, int> ed[100001];
int weight[100001];
vector <pair <int, int> > g[100001];
int cnt[100001];
int h[100001];
int n;
ld SUM = 0;

void dfs(int u, int prev = 0)
{
	h[u] = h[prev] + 1;
	cnt[u] = 1;
	for (int i = 0; i < sz(g[u]); ++i)
	{
		int v = g[u][i].first;
		if (v == prev)
			continue;
		dfs(v, u);
		cnt[u] += cnt[v];
	}
	for (int i = 0; i < sz(g[u]); ++i)
	{
		int v = g[u][i].first;
		int w = g[u][i].second;
		if (v == prev)
			continue;
		SUM += ld(w) * ld(cnt[v]) * ld(n - cnt[v]);
	}
}

int solve()
{
	cin >> n;
	for (int i = 0; i < n - 1; ++i)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		--u, --v;
		ed[i] = make_pair(u, v);
		weight[i] = w;
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
	}
	ld C = ld(n) * ld(n - 1) * ld(n - 2);
	C /= 6;
	dfs(0);
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int e, w;
		scanf("%d%d", &e, &w);
		--e;
		int delta = weight[e] - w;
		weight[e] = w;
		int v = h[ed[e].first] > h[ed[e].second] ? ed[e].first : ed[e].second;
		SUM -= ld(delta) * ld(cnt[v]) * ld(n - cnt[v]);
		cout << (n - 2) * SUM / C << '\n';
	}
	return 0;
}