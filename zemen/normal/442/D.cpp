#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
#include <memory.h>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <complex>

using namespace std;

#define INF 1000000001
#define INFL 1000000000000000001ll
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef long double ld;
typedef complex <ld> point;

#define NAME "d"

vector <int> g[1000001];
int d[1000001][23];

void dfs(int u) {
	for (int i = 0; i < sz(g[u]); ++i) {
		int v = g[u][i];
		dfs(v);
	}
	d[u][0] = u;
	for (int i = 1; i < 23; ++i) {
		int V = -1;
		for (int j = 0; j < sz(g[u]); ++j) {
			int v = g[u][j];
			if (V == -1 || d[V][i - 1] > d[v][i - 1])
				V = v;
		}
		d[u][i] = INF;
		for (int j = 0; j < sz(g[u]); ++j) {
			int v = g[u][j];
			if (V == v)
				d[u][i] = min(d[u][i], d[v][i]);
			else
				d[u][i] = min(d[u][i], d[v][i - 1]);
		}
	}
	//~ cerr << "u " << u + 1 << '\n';
	//~ for (int i = 0; i <= 4; ++i)
		//~ cerr << d[u][i] + 1 << ' ';
	//~ cerr << '\n';
}

int f[23];

int main() {
	srand(time(0));
	cout.setf(ios::fixed);
	cout.precision(10);
	#ifdef _GEANY
	assert(freopen(NAME ".in", "r", stdin));
	#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int p;
		scanf("%d", &p);
		--p;
		g[p].pb(i + 1);
	}
	++n;
	dfs(0);
	for (int i = 1; i < 23; ++i) {
		f[i] = INF;
		for (int j = 0; j < sz(g[0]); ++j)
			f[i] = min(f[i], d[g[0][j]][i]);
	}
	//~ for (int i = 1; i < 5; ++i)
		//~ cerr << f[i] + 1 << ' ';
	//~ cerr << '\n';
	int c = 1;
	for (int i = 0; i < n - 1; ++i) {
		while (i >= f[c] - 1)
			++c;
		cout << c << ' ';
	}
	cout << '\n';
}