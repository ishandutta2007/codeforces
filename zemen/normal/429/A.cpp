#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cassert>
#include <ctime>
#include <memory.h>

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <complex>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex <ld> point;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 1000000001
#define INFL 2000000000000000001ll

#define NAME "a"

char val[100001];
vector <int> g[100001];
vector <int> res;

void dfs(int u, int prev = -1, int prev2 = -1) {
	if ((prev2 == -1 && val[u]) || (prev2 != -1 && val[u] != val[prev2])) {
		res.pb(u);
	}
	for (int i = 0; i < (int) g[u].size(); ++i) {
		int v = g[u][i];
		if (v == prev)
			continue;
		dfs(v, u, prev);
	}
}

int main() {
	#ifdef _GEANY
	assert(freopen(NAME ".in", "r", stdin));
	#endif
	//~ C0mputer1A2013
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		g[u].pb(v);
		g[v].pb(u);
	}
	for (int i = 0; i < n; ++i) {
		int t;
		scanf("%d", &t);
		val[i] = t;
	}
	for (int i = 0; i < n; ++i) {
		int t;
		scanf("%d", &t);
		val[i] ^= t;
	}
	dfs(0);
	cout << (int) res.size() << '\n';
	for (int i = 0; i < (int) res.size(); ++i)
		cout << res[i] + 1 << '\n';
}