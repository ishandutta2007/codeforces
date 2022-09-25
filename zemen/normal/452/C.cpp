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

ld fact[1000001];

ld c(int n, int k) {
	return fact[n] / (fact[k] * fact[n - k]);
}

void solve() {
	int n, m;
	cin >> n >> m;
	if (m == 1) {
		cout << 1.0 / n << '\n';
		return;
	}
	if (n == 1) {
		cout << 1.0 << '\n';
		return;
	}
	ld res = 0;
	int rem = n * m - m;
	ld pr = 1.0;
	int p1 = rem - n + 2;
	int p2 = m * n - n + 1;
	while (p1 <= rem || p2 <= m * n - 1) {
		if (p1 <= rem && pr <= 1e9) {
			pr *= p1;
			//~ cerr << "* " << p1 << '\n';
			++p1;
		} else {
			assert(p2 <= m * n - 1);
			pr /= p2;
			//~ cerr << "/ " << p2 << '\n';
			++p2;
		}
	}
	for (int i = 1; i <= min(n, m); ++i) {
	//~ for (int i = 1; i <= 1; ++i) {
		//~ cerr << pr << '\n';
		res += pr * ld(i) / ld(n);
		pr *= (n - i);
		pr *= (m - i);
		pr /= (i);
		pr /= (rem - n + i + 1);
	}
	cout << res << '\n';
}