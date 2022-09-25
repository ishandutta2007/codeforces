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

#define NAME "b"

int a[100001];
vector <pair <int, int> > ed[200001];

int col[100001];
int rk[100001];
ld ans = 0;

int get(int u) {
	if (col[u] == u)
		return u;
	return col[u] = get(col[u]);
}

void join(int u, int v, int cost) {
	u = get(u);
	v = get(v);
	if (u == v)
		return;
	if (rk[u] > rk[v])
		swap(u, v);
	col[u] = v;
	ans += (ld(rk[u]) * ld(rk[v])) * ld(cost);
	rk[v] += rk[u];
}

int main() {
	srand(time(0));
	cout.setf(ios::fixed);
	cout.precision(10);
	#ifdef _GEANY
	assert(freopen(NAME ".in", "r", stdin));
	#endif
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int j = 0; j < m; ++j) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		int cost = min(a[u], a[v]);
		ed[cost].pb(mp(u, v));
	}
	for (int i = 0; i < n; ++i)
		col[i] = i, rk[i] = 1;
	for (int i = 100000; i >= 0; --i) {
		for (int j = 0; j < sz(ed[i]); ++j) {
			int u = ed[i][j].fi;
			int v = ed[i][j].se;
			join(u, v, i);
		}
	}
	cout << (2 * ans) / (ld(n) * ld(n - 1)) << '\n';
}