#include <bits/stdc++.h>
#define EB emplace_back
#define fail "NO\n"
using std::cin;
using std::cout;

typedef std::vector <int> vector;
const int N = 300054, M = N * 2;

int n, E = 0, curv, cura;
int to[M], first[N], next[M];
int a[N], p[N], dep[N];
int cnt = 0, o[N], id[N];
int cntb = 0, ob[N];
vector ch[N];

inline void addedge(int u, int v) {
	to[++E] = v, next[E] = first[u], first[u] = E,
	to[++E] = u, next[E] = first[v], first[v] = E;
}

void dfs(int x) {
	int i, y;
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != p[x])
			p[y] = x, dep[y] = dep[x] + 1, ch[x].EB(y), dfs(y);
	std::sort(ch[x].begin(), ch[x].end(), [] (const int x, const int y) {return a[x] < a[y];});
}

void dfs0(int x) {
	o[++cnt] = x, id[x] = cnt;
	for (int y : ch[x]) dfs0(y);
	ob[++cntb] = x;
}

bool check(int x) {
	if (a[x] != cntb++) return false; 
	for (int y : ch[x]) if (a[y] >= cura && !check(y)) return false;
	return true;
}

int main() {
	int i, u, v; long long ans = 0;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n;
	for (i = 1; i <= n; ++i) cin >> a[i];
	for (i = 1; i < n; ++i) cin >> u >> v, addedge(u, v);
	dfs(1), dfs0(1), curv = cura = n + 1;
	for (i = 2; i <= n; ++i) if (a[p[i]] < a[i] && a[p[i]] < cura) curv = p[i], cura = a[p[i]];
	for (i = 1; i < cura; ans += dep[ob[i++]]) if (a[ob[i]] != i) return cout << fail, 0;
	if (curv != n + 1) {
		for (v = curv; v != 1; v = p[v]) std::swap(a[v], a[p[v]]);
		cntb = cura;
		if (!check(1)) return cout << fail, 0;
		u = 1, *a = INT_MAX;
		for (i = dep[curv]; i; --i) {
			v = 0;
			for (int y : ch[u]) if (a[u] < a[y] && a[y] < a[v]) v = y;
			u = v;
		}
		if (u != curv) return cout << fail, 0;
		ans += dep[curv];
	}
	cout << "YES\n" << ans << '\n';
	for (i = 1; i <= n; ++i) cout << id[i] << (i == n ? '\n' : ' ');
	return 0;
}