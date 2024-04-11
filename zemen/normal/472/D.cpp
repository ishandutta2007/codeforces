#include <bits/stdc++.h>
using namespace std;
#define INF int(1e9+1)
#define INFL ll(2e18+INF)
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef long double ld;
typedef complex <ld> point;
void solve();

#define NAME "d"
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
	cout << "YES\n";
	#ifdef _GEANY
		fprintf(stderr, "Time: %.3fs\n", double(clock() - start) / CLOCKS_PER_SEC);
	#endif
}

int a[2001][2001];
bool used[2001];
pair <int, int> dist[2001];

vector <int> g[2001];

void myassert(bool expr) {
	if (!expr) {
		cout << "NO\n";
		exit(0);
	}
}

void dfs(int s, int u, ll w = 0, int prev = -1) {
	//~ cerr << s << ' ' << u << ' ' << '\n';
	myassert(w == a[s][u]);
	for (int i = 0; i < sz(g[u]); ++i) {
		int v = g[u][i];
		if (v == prev)
			continue;
		dfs(s, v, w + a[u][v], u);
	}
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", a[i] + j);
	for (int i = 0; i < n; ++i) {
		myassert(a[i][i] == 0);
		for (int j = 0; j < n; ++j) {
			myassert(a[i][j] == a[j][i]);
			if (i != j)
				myassert(a[i][j] != 0);
		}
	}
	used[0] = 1;
	for (int i = 0; i < n; ++i)
		dist[i] = make_pair(a[0][i], 0);
	for (int ii = 0; ii < n - 1; ++ii) {
		int u = -1;
		for (int i = 0; i < n; ++i) {
			if (used[i])
				continue;
			if (u == -1 || dist[i] < dist[u])
				u = i;
		}
		assert(u != -1);
		g[u].push_back(dist[u].second);
		g[dist[u].second].push_back(u);
		used[u] = 1;
		for (int i = 0; i < n; ++i) {
			if (used[i])
				continue;
			dist[i] = min(dist[i], make_pair(a[u][i], u));
		}
	}
	for (int i = 0; i < n; ++i)
		dfs(i, i);
}