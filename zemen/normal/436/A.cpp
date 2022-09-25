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

vector <pair <int, int> > a[2];
int c[2];
multiset <int> s[2];
int h;

void update(int id) {
	while (c[id] < sz(a[id]) && a[id][c[id]].fi <= h) {
		s[id].insert(a[id][c[id]].se);
		++c[id];
	}
}

int main() {
	srand(time(0));
	cout.setf(ios::fixed);
	cout.precision(10);
	#ifdef _GEANY
	assert(freopen(NAME ".in", "r", stdin));
	#endif
	int n, X;
	cin >> n >> X;
	for (int i = 0; i < n; ++i) {
		int t, h, m;
		cin >> t >> h >> m;
		a[t].pb(mp(h, m));
	}
	sort(a[0].begin(), a[0].end());
	sort(a[1].begin(), a[1].end());
	int res = 0;
	for (int q = 0; q < 2; ++q) {
		s[0].clear();
		s[1].clear();
		c[0] = c[1] = 0;
		h = X;
		update(0);
		update(1);
		int moves = 0;
		for (moves = 0; ; ++moves) {
			int id = (moves + q) % 2;
			if (s[id].empty())
				break;
			int d = *s[id].rbegin();
			h += d;
			s[id].erase(s[id].find(d));
			update(0);
			update(1);
		}
		res = max(res, moves);
	}
	cout << res << '\n';
}