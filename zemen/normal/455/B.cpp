#include <bits/stdc++.h>
using namespace std;
#define INF int(1e9+1)
#define INFL ll(2e18+INF)
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef long double ld;
typedef complex <ld> point;
void solve();

#define NAME "b"
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

int to[200001][26];
bool ok[200001][2];

const int root = 1;
int nodes = 2;

char s[1000001];

void dfs(int u) {
	bool term = true;
	for (int i = 0; i < 26; ++i)
		if (to[u][i])
			dfs(to[u][i]), term = false;
	if (term) {
		ok[u][0] = 0;
		ok[u][1] = 1;
		return;
	}
	for (int i = 0; i < 26; ++i) {
		int v = to[u][i];
		if (!v)
			continue;
		if (!ok[v][0])
			ok[u][0] = true;
		if (!ok[v][1])
			ok[u][1] = true;
	}
}

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		scanf("%s", s);
		int cur = root;
		for (int j = 0; s[j]; ++j) {
			int c = s[j] - 'a';
			if (!to[cur][c])
				to[cur][c] = nodes++;
			cur = to[cur][c];
		}
	}
	dfs(root);
	bool b1 = ok[root][0];
	bool b2 = ok[root][1];
	//~ cerr << b1 << ' ' << b2 << '\n';
	if (b1 && b2)
		cout << "First\n";
	else if (!b1)
		cout << "Second\n";
	else {
		if (k % 2)
			cout << "First\n";
		else
			cout << "Second\n";
	}
}