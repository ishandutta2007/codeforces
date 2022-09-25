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

const int p[16] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
int a[1001];
int d[101][(1 << 16) + 1];
int pr[101][(1 << 16) + 1];
int m[65];
int ans[101];

void solve() {
	for (int i = 1; i <= 60; ++i) {
		for (int j = 0; j < 16; ++j)
			if (i % p[j] == 0)
				m[i] |= (1 << j);
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i <= n; ++i)
		for (int mask = 0; mask < (1 << 16); ++mask)
			d[i][mask] = INF;
	d[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int mask = 0; mask < (1 << 16); ++mask) {
			if (d[i][mask] == INF)
				continue;
			for (int k = 1; k <= 58; ++k) {
				if (mask & m[k])
					continue;
				int &q = d[i + 1][mask | m[k]];
				int q2 = d[i][mask] + abs(a[i] - k);
				if (q > q2) {
					q = q2;
					pr[i + 1][mask | m[k]] = k;
				}
			}
		}
	}
	int res = INF;
	int cm = -1;
	for (int mask = 0; mask < (1 << 16); ++mask) {
		if (res > d[n][mask]) {
			res = d[n][mask];
			cm = mask;
		}
	}
	//~ cerr << res << '\n';
	for (int i = n; i > 0; --i) {
		int q = ans[i - 1] = pr[i][cm];
		assert((cm & m[q]) == m[q]);
		cm ^= m[q];
	}
	assert(cm == 0);
	for (int i = 0; i < n; ++i)
		cout << ans[i] << ' ';
	cout << '\n';
}