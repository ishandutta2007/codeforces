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

int c[100001];
int C[100001];
bool used[100001];
vector <int> g[100001];
vector <int> t[100001];
vector <bool> doubled[100001];
bool fix_last;

bool dfs(int u) {
	used[u] = true;
	C[u] ^= 1;
	bool ret = c[u];
	for (int i = 0; i < sz(g[u]); ++i) {
		int v = g[u][i];
		if (used[v])
			continue;
		t[u].push_back(v);
		ret |= dfs(v);
		C[u] ^= 1;
	}
	return ret;
}

bool dfs2(int u) {
	for (int i = 0; i < sz(t[u]); ++i) {
		int v = t[u][i];
		doubled[u].push_back(dfs2(v));
		C[u] ^= doubled[u].back();
	}
	return C[u] != c[u];
}

vector <int> res;
void dfs3(int u) {
	res.push_back(u);
	for (int i = 0; i < sz(t[u]); ++i) {
		int v = t[u][i];
		if (doubled[u][i]) {
			res.push_back(v);
			res.push_back(u);
		}
		dfs3(v);
		res.push_back(u);
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 0; i < n; ++i)
		scanf("%d", c + i);
	int st = -1;
	for (int i = 0; i < n; ++i) {
		if (used[i])
			continue;
		bool need = dfs(i);
		if (!need)
			continue;
		if (st != -1) {
			cout << -1 << '\n';
			return;
		}
		if (dfs2(i))
			fix_last = true;
		st = i;
	}
	if (st != -1) {
		dfs3(st);
		if (fix_last)
			res.pop_back();
	}
	cout << sz(res) << '\n';
	for (int i = 0; i < sz(res); ++i) {
		cout << res[i] + 1 << ' ';
	}
	cout << '\n';
}