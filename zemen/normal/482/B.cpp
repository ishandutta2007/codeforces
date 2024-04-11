#include <bits/stdc++.h>
using namespace std;
#define INF int(1e9+1)
#define INFL ll(2e18+INF)
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef long double ld;
typedef complex <ld> point;
void solve();

#define NAME "b"
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

int delta[30][100002];

int L[100002];
int R[100002];
int Q[100002];

int a[100002];

const int base = (1 << 17);
int t[base * 2];

int get(int l, int r, int v = 1, int cl = 0, int cr = base) {
	if (l <= cl && cr <= r)
		return t[v];
	if (r <= cl || cr <= l)
		return (1 << 30) - 1;
	int cc = (cl + cr) / 2;
	return get(l, r, v * 2, cl, cc) & get(l, r, v * 2 + 1, cc, cr);
}

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int l, r, q;
		scanf("%d%d%d", &l, &r, &q);
		--l;
		L[i] = l;
		R[i] = r;
		Q[i] = q;
		for (int j = 0; j < 30; ++j)
			if (q & (1 << j))
				delta[j][l]++, delta[j][r]--;
	}
	for (int i = 0; i < 30; ++i) {
		int sum = 0;
		for (int j = 0; j < n; ++j) {
			sum += delta[i][j];
			if (sum)
				a[j] |= (1 << i);
		}
	}
	for (int i = 0; i < n; ++i)
		t[i + base] = a[i];
	for (int i = n; i < base; ++i)
		t[i + base] = (1 << 30) - 1;
	for (int i = base - 1; i > 0; --i)
		t[i] = (t[i * 2] & t[i * 2 + 1]);
	for (int i = 0; i < m; ++i) {
		if (get(L[i], R[i]) != Q[i]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	for (int i = 0; i < n; ++i)
		cout << a[i] << ' ';
	cout << '\n';
}