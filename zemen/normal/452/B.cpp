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

void solve() {
	int n, m;
	cin >> n >> m;
	if (n == 0) {
		printf("%d %d\n%d %d\n%d %d\n%d %d\n", 0, m - 1, 0, 0, 0, m, 0, 1);
		return;
	}
	if (m == 0) {
		printf("%d %d\n%d %d\n%d %d\n%d %d\n", n - 1, 0, 0, 0, n, 0, 1, 0);
		return;
	}
	int a = min(n, m);
	int b = max(n, m);
	ld res1 = 2 * sqrtl(a * a + b * b) + b;
	ld res2 = 2 * sqrtl((a - 1) * (a - 1) + b * b) + sqrtl(a * a + b * b);
	if (res1 > res2) {
		if (n >= m)
			printf("%d %d\n%d %d\n%d %d\n%d %d\n", n, m, 0, 0, n, 0, 0, m);
		else
			printf("%d %d\n%d %d\n%d %d\n%d %d\n", n, m, 0, 0, 0, m, n, 0);
	} else {
		if (n >= m)
			printf("%d %d\n%d %d\n%d %d\n%d %d\n", 0, 1, n, m, 0, 0, n, m - 1);
		else
			printf("%d %d\n%d %d\n%d %d\n%d %d\n", 1, 0, n, m, 0, 0, n - 1, m);
	}
}