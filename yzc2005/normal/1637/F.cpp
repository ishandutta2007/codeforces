#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, K = 18;
int n, h[N], fa[N], id[N], rev[N], lg[N], mn[K][N], *val = *mn, l[N], r[N], dfn;
vector<int> e[N];
int s[N];
void dfs(int u) {
	l[u] = ++dfn;
	for (auto v : e[u]) {
		if (v == fa[u]) continue;
		fa[v] = u, dfs(v);
	}
	r[u] = dfn;
}
int query(int l, int r) {
	if (l > r) return n + 1;
	int k = lg[r - l + 1];
	return min(mn[k][l], mn[k][r - (1 << k) + 1]);
}
inline void add(int l, int r) {
	if (l > r) return;
	++s[l], --s[r];
}
int main() {	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &h[i]), id[i] = i;
	sort(id + 1, id + n + 1, [&](int i, int j) {
		return h[i] > h[j];
	});
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	dfs(1);
	for (int i = 1; i <= n; ++i)
		rev[id[i]] = i;
	for (int i = 1; i <= n; ++i)
		val[l[i]] = rev[i];
	for (int i = 2; i <= n; ++i)
		lg[i] = lg[i >> 1] + 1;
	for (int k = 1; k < K; ++k)
		for (int i = 1; i + (1 << k) - 1 <= n; ++i)
			mn[k][i] = min(mn[k - 1][i], mn[k - 1][i + (1 << (k - 1))]);
	for (int u = 1; u <= n; ++u) {
		vector<int> vec = {min(query(1, l[u] - 1), query(r[u] + 1, n))};
		for (auto v : e[u])
			if (v != fa[u]) vec.emplace_back(query(l[v], r[v]));
		sort(vec.begin(), vec.end());
		while ((int) vec.size() < 2)
			vec.emplace_back(n + 1);
		add(rev[u], vec[0]);
		add(rev[u], vec[1]);
	}
	long long ans = 0;
	for (int i = 1; i <= n; ++i)
		assert(s[i] >= 0), ans += s[i] * h[id[i]];
	printf("%lld\n", ans);
	return 0;
}