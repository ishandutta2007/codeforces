#include <bits/stdc++.h>
using namespace std;
#define INF int(1e9+1)
#define INFL ll(2e18+INF)
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef long double ld;
typedef complex <ld> point;
void solve();

#define NAME "c"
#define LOCAL_INPUT NAME ".in"
//~ #define LOCAL_OUTPUT NAME ".out"
//~ #define INPUT NAME ".in"
//~ #define OUTPUT NAME ".out"

int main() {
	srand(time(0));
	cout.setf(ios::fixed);
	cout.precision(10);
	#ifdef _GEANY
		clock_t start = clock();
		#ifdef LOCAL_INPUT
			assert(freopen(LOCAL_INPUT, "r", stdin));
		#endif
		#ifdef LOCAL_OUTPUT
			assert(freopen(LOCAL_OUTPUT, "w", stdout));
		#endif
	#else
		#ifdef INPUT
			assert(freopen(INPUT, "r", stdin));
		#endif
		#ifdef OUTPUT
			assert(freopen(OUTPUT, "w", stdout));
		#endif
	#endif
	int tn = 1;
	for (int i = 0; i < tn; ++i)
		solve();
	#ifdef _GEANY
		fprintf(stderr, "Time: %.3fs\n", double(clock() - start) / CLOCKS_PER_SEC);
	#endif
}

int col[500001];
int rk[500001];
int diam[500001];
vector <int> g[500001];

int get(int u) {
	if (col[u] == u)
		return u;
	return col[u] = get(col[u]);
}

void join(int u, int v) {
	u = get(u), v = get(v);
	if (u == v)
		return;
	if (rk[u] > rk[v])
		swap(u, v);
	col[u] = v;
	int d1 = diam[u];
	int d2 = diam[v];
	diam[v] = max(d1, d2);
	diam[v] = max(diam[v], (d1 + 1) / 2 + (d2 + 1) / 2 + 1);
	if (rk[u] == rk[v])
		rk[v]++;
}

pair <int, int> far;

void dfs(int u, int prev = -1, int dist = 0) {
	far = max(far, make_pair(dist, u));
	for (int i = 0; i < sz(g[u]); ++i) {
		int v = g[u][i];
		if (v != prev)
			dfs(v, u, dist + 1);
	}
}

void calc_diam(int u) {
	far = make_pair(-1, -1);
	dfs(u);
	int v = far.second;
	far = make_pair(-1, -1);
	dfs(v);
	diam[u] = far.first;
}

void solve() {
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 0; i < n; ++i)
		col[i] = i;
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
		join(u, v);
	}
	for (int i = 0; i < n; ++i)
		if (col[i] == i)
			calc_diam(i);
	for (int i = 0; i < q; ++i) {
		int type;
		scanf("%d", &type);
		if (type == 1) {
			int u;
			scanf("%d", &u);
			--u;
			cout << diam[get(u)] << '\n';
		} else {
			int u, v;
			scanf("%d%d", &u, &v);
			--u, --v;
			join(u, v);
		}
	}
}