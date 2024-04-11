#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef std::vector <int> vector;
const int N = 510, mod = 998244353;

int n;
vector a[2 * N];
int appear[N][N], o[2 * N];
bool used[N][N], alive[2 * N];
bool vis[N], G[N][N];
int mr[N], ml[N];

inline void ban(int id, bool key = false) {
	alive[id] = false;
	for (int i = 0; i < n; ++i) {
		if (key) used[i][ a[id][i] ] = true;
		--appear[i][ a[id][i] ];
	}
}

bool dfs(int x) {
	for (int i = 0; i < n; ++i)
		if (G[x][i] && !vis[i]) {
			vis[i] = true;
			if (ml[i] == -1 || dfs(ml[i]))
				return ml[i] = x, mr[x] = i, true;
		}
	return false;
}

inline bool check(int u, int v) {
	for (int i = 0; i < n; ++i) if (a[u][i] == a[v][i]) return true;
	return false;
}

int que[N];
bool bd[N];

bool bfs(int si) {
	int h, t = 1, i, j, x;
	*que = si, vis[si] = true;
	for (h = 0; h < t; ++h) {
		x = que[h];
		for (i = 0; i < n; ++i)
			if (G[i][x] && !vis[mr[i]]) vis[mr[i]] = true, que[t++] = mr[i];
	}
	for (i = 0; i < n; ++i) for (j = 0; j < n; ++j) appear[i][j] = 0;
	for (h = 0; h < t; ++h) {
		x = que[h];
		for (i = 0; i < n; ++i)
			if (++appear[i][a[x + n][i]] == 2) return false;
	}
	for (h = 0; h < t; ++h) bd[que[h]] = true;
	return true;
}

void work() {
	int i, j, k, t, ans = 1;
	cin >> n;
	for (i = 0; i < n; ++i) for (j = 0; j < n; ++j) appear[i][j] = used[i][j] = false;
	for (i = 0; i < 2 * n; ++i) {
		a[i].resize(n), alive[i] = true, o[i] = i;
		for (j = 0; j < n; ++j) {
			cin >> a[i][j], --a[i][j];
			++appear[j][ a[i][j] ];
		}
	}
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			for (k = 0; k < n; ++k) if (!used[j][k] && appear[j][k] == 1) break;
			if (k < n) break;
		}
		if (j == n) {
			j = 0;
			for (k = 0; k < n && used[j][k]; ++k);
		}
		for (t = i; t < 2 * n && !(alive[t] && a[t][j] == k); ++t);
		assert(t != 2 * n);
		a[i].swap(a[t]), std::swap(o[i], o[t]), std::swap(alive[i], alive[t]);
		ban(i, true);
		for (j = i + 1; j < 2 * n; ++j)
			if (alive[j] && check(i, j)) ban(j);
	}

	memset(ml, -1, n << 2);
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j) G[i][j] = check(i, j + n);

	for (i = 0; i < n; ++i)
		memset(vis, false, n), assert(dfs(i));

	memset(bd, false, n);
	for (i = 0; i < n; ++i) {
		memset(vis, false, n);
		if (!bd[i] && bfs(i)) {
			ans = 2 * ans % mod;
		}
	}

	cout << ans << '\n';
	for (i = 0; i < n; ++i) cout << o[i] + 1 << (i == n - 1 ? '\n' : ' ');
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}