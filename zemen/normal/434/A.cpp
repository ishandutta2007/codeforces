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

#define NAME "a"

int a[100001];
ll old[100001];
ll _new[100001];
vector <int> g[100001];

int main() {
	srand(time(0));
	cout.setf(ios::fixed);
	cout.precision(10);
	#ifdef _GEANY
	assert(freopen(NAME ".in", "r", stdin));
	#endif
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a[i];
		--a[i];
	}
	ll sum = 0;
	for (int i = 0; i < m - 1; ++i)
		sum += abs(a[i] - a[i + 1]);
	for (int i = 0; i < m; ++i) {
		if (i && a[i] != a[i - 1]) {
			old[a[i]] += abs(a[i] - a[i - 1]);
			g[a[i]].pb(a[i - 1]);
		}
		if (i < m - 1 && a[i] != a[i + 1]) {
			old[a[i]] += abs(a[i] - a[i + 1]);
			g[a[i]].pb(a[i + 1]);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (g[i].empty())
			continue;
		sort(g[i].begin(), g[i].end());
		int pos = g[i][g[i].size() / 2];
		for (int j = 0; j < (int) g[i].size(); ++j)
			_new[i] += abs(pos - g[i][j]);
	}
	ll best = sum;
	for (int i = 0; i < n; ++i) {
		best = min(best, sum - old[i] + _new[i]);
	}
	cout << best << '\n';
}