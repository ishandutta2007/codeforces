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

#define NAME "c"

char a[1002][12][12];
int d[1002][1002];
bool used[1002];
vector <pair <int, int> > res;
pair <int, int> dist[1002];

int main() {
	srand(time(0));
	cout.setf(ios::fixed);
	cout.precision(10);
	#ifdef _GEANY
	assert(freopen(NAME ".in", "r", stdin));
	#endif
	int n, m, k, w;
	cin >> n >> m >> k >> w;
	for (int i = 0; i < k; ++i) {
		for (int x = 0; x < n; ++x)
			scanf("%s", a[i][x]);
	}
	for (int i1 = 0; i1 < k; ++i1)
		for (int i2 = 0; i2 < i1; ++i2) {
			for (int x = 0; x < n; ++x)
				for (int y = 0; y < m; ++y) {
					d[i1][i2] += (a[i1][x][y] != a[i2][x][y]);
				}
			d[i1][i2] *= w;
			d[i2][i1] = d[i1][i2];
		}
	for (int i = 0; i < k; ++i) {
		d[i][k] = d[k][i] = n * m;
		dist[i] = mp(n * m, -1);
	}
	n = k + 1;
	used[k] = 1;
	int ans = 0;
	for (int it = 0; it < n - 1; ++it) {
		int u = -1;
		for (int i = 0; i < n; ++i) {
			if (used[i])
				continue;
			if (u == -1 || dist[i] < dist[u])
				u = i;
		}
		used[u] = 1;
		ans += dist[u].fi;
		res.pb(mp(u, dist[u].se));
		for (int i = 0; i < n; ++i) {
			if (used[i])
				continue;
			dist[i] = min(dist[i], mp(d[u][i], u));
		}
	}
	cout << ans << '\n';
	for (int i = 0; i < n - 1; ++i)
		cout << res[i].fi + 1 << ' ' << res[i].se + 1 << '\n';
}