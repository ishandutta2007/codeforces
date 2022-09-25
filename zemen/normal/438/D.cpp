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

#define base 131072
ll t_sum[base * 2];
int t_max[base * 2];

void update(int v) {
	t_sum[v] = t_sum[v * 2] + t_sum[v * 2 + 1];
	t_max[v] = max(t_max[v * 2], t_max[v * 2 + 1]);
}

ll get(int l, int r, int v = 1, int cl = 0, int cr = base) {
	if (l <= cl && cr <= r)
		return t_sum[v];
	if (r <= cl || cr <= l)
		return 0;
	int cc = (cl + cr) / 2;
	return get(l, r, v * 2, cl, cc) + get(l, r, v * 2 + 1, cc, cr);
}

void put(int v, int val) {
	v += base;
	t_sum[v] = t_max[v] = val;
	v /= 2;
	while (v) {
		update(v);
		v /= 2;
	}
}

void get_mod(int mod, int l, int r, int v = 1, int cl = 0, int cr = base) {
	if (r <= cl || cr <= l)
		return;
	if (cl + 1 == cr) {
		t_sum[v] = t_max[v] = t_sum[v] % mod;
		return;
	}
	int cc = (cl + cr) / 2;
	if (t_max[v * 2] >= mod)
		get_mod(mod, l, r, v * 2, cl, cc);
	if (t_max[v * 2 + 1] >= mod)
		get_mod(mod, l, r, v * 2 + 1, cc, cr);
	update(v);
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
	for (int i = 0; i < n; ++i) {
		int val;
		scanf("%d", &val);
		t_max[base + i] = t_sum[base + i] = val;
	}
	for (int i = base - 1; i > 0; --i)
		update(i);
	for (int i = 0; i < m; ++i) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int l, r;
			scanf("%d%d", &l, &r);
			--l;
			cout << get(l, r) << '\n';
		} else if (op == 2) {
			int l, r, mod;
			scanf("%d%d%d", &l, &r, &mod);
			--l;
			get_mod(mod, l, r);
		} else {
			assert(op == 3);
			int pos, val;
			scanf("%d%d", &pos, &val);
			--pos;
			put(pos, val);
		}
	}
}