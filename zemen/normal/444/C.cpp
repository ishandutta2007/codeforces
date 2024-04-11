#include <bits/stdc++.h>
using namespace std;
#define INF int(1e9+1)
#define INFL ll(2e18+INF)
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef long double ld;
typedef complex <ld> point;
void solve();

#define NAME "c"
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

#define base 131072
ll t[base * 2];
ll upd[base * 2];

inline void push(int v, int cl, int cr) {
	t[v * 2] += upd[v] * ((cr - cl) / 2);
	t[v * 2 + 1] += upd[v] * ((cr - cl) / 2);
	upd[v * 2] += upd[v];
	upd[v * 2 + 1] += upd[v];
	upd[v] = 0;
}

inline void update(int v) {
	t[v] = t[v * 2] + t[v * 2 + 1];
}

void add(int l, int r, ll delta, int v = 1, int cl = 0, int cr = base) {
	if (l <= cl && cr <= r) {
		t[v] += delta * (cr - cl);
		upd[v] += delta;
		return;
	}
	if (cr <= l || r <= cl)
		return;
	push(v, cl, cr);
	int cc = (cl + cr) / 2;
	add(l, r, delta, v * 2, cl, cc);
	add(l, r, delta, v * 2 + 1, cc, cr);
	update(v);
}

ll get(int l, int r, int v = 1, int cl = 0, int cr = base) {
	if (l <= cl && cr <= r)
		return t[v];
	if (cr <= l || r <= cl)
		return 0;
	push(v, cl, cr);
	int cc = (cl + cr) / 2;
	return get(l, r, v * 2, cl, cc) + get(l, r, v * 2 + 1, cc, cr);
}

map <int, int> seg;

void divide(int x) {
	auto it = seg.lower_bound(x);
	if (it->first == x)
		return;
	assert(it != seg.begin());
	--it;
	seg[x] = it->second;
}

void put(int l, int r, int x) {
	//~ cerr << "put " << l << ' ' << r << '\n';
	divide(l);
	divide(r);
	auto it = seg.lower_bound(l);
	while (it != seg.end() && it->first < r) {
		//~ cerr << "seg " << it->first << ' '<< it->second << '\n';
		auto nx = it;
		++nx;
		add(it->first, nx->first, abs(it->second - x));
		seg.erase(it);
		it = nx;
	}
	seg[l] = x;
	//~ for (auto &it: seg) {
		//~ cerr << it.first << ' ' << it.second << '\n';
	//~ }
}

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; ++i)
		seg[i] = i + 1;
	for (int i = 0; i < m; ++i) {
		int type, l, r;
		scanf("%d%d%d", &type, &l, &r);
		--l;
		if (type == 1) {
			int x;
			scanf("%d", &x);
			put(l, r, x);
		} else {
			//~ for (int i = 0; i < n; ++i) {
				//~ cerr << get(i, i + 1) << ' ';
			//~ }
			//~ cerr << '\n';
			cout << get(l, r) << '\n';
		}
	}
}