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
#define INFL 2000000000000000001ll
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef long double ld;
typedef complex <ld> point;

#define NAME "b"

int n, m;
ll b;
ll best = INFL;

struct man {
	ll cost;
	ll mon;
	int mask;
	
	bool operator<(const man a) const {
		return mon < a.mon;
	}
};

man a[101];
ll d[2000001];

int main() {
	srand(time(0));
	cout.setf(ios::fixed);
	cout.precision(10);
	#ifdef _GEANY
	assert(freopen(NAME ".in", "r", stdin));
	#endif
	cin >> n >> m >> b;
	for (int i = 0; i < n; ++i) {
		int t;
		a[i].mask = 0;
		cin >> a[i].cost >> a[i].mon >> t;
		for (int j = 0; j < t; ++j) {
			int q;
			cin >> q;
			--q;
			a[i].mask |= (1 << q);
		}
	}
	sort(a, a + n);
	for (int i = 0; i < (1 << m); ++i)
		d[i] = INFL;
	d[0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < (1 << m); ++j)
			d[j | a[i].mask] = min(d[j | a[i].mask], d[j] + a[i].cost);
		best = min(best, d[(1 << m) - 1] + b * a[i].mon);
	}
	if (best == INFL)
		cout << -1 << '\n';
	else
		cout << best << '\n';
}