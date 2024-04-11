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

int t[23][2000001];
ll delta[23];
int tmp[2000001];

inline ll my_merge(int *res, int *a, int *at, int *b, int *bt, ll cinv) {
	ll inv = 0;
	while (a != at || b != bt) {
		if (a != at && (b == bt || a[0] <= b[0])) {
			res[0] = a[0];
			++a, ++res;
			--cinv;
		} else {
			res[0] = b[0];
			++b, ++res;
			inv += cinv;
		}
	}
	return inv;
}

int main() {
	srand(time(0));
	cout.setf(ios::fixed);
	cout.precision(10);
	#ifdef _GEANY
	assert(freopen(NAME ".in", "r", stdin));
	#endif
	int n;
	cin >> n;
	for (int i = 0; i < (1 << n); ++i)
		scanf("%d", t[0] + i);
	ll ic = 0;
	for (int deg = 1; deg <= n; ++deg) {
		for (int i = 0; i < (1 << n); i += (1 << deg)) {
			int *a = t[deg - 1] + i;
			int *b = t[deg - 1] + i + (1 << (deg - 1));
			int *c = t[deg - 1] + i + (1 << deg);
			ll q = my_merge(t[deg] + i, a, b, b, c, (1 << (deg - 1)));
			ll w = my_merge(tmp, b, c, a, b, (1 << (deg - 1)));
			//~ cerr << q << ' ' << w << '\n';
			ic += q;
			delta[deg] += w - q;
		}
	}
	//~ cerr << ic << '\n';
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int q;
		scanf("%d", &q);
		for (int i = 1; i <= q; ++i) {
			ic += delta[i];
			delta[i] = -delta[i];
		}
		cout << ic << '\n';
	}
}