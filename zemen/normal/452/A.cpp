#include <bits/stdc++.h>
using namespace std;
#define INF int(1e9+1)
#define INFL ll(2e18+INF)
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef long double ld;
typedef complex <ld> point;
void solve();

#define NAME "a"
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

string t[] = {
	"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"
};

void solve() {
	int n;
	string s;
	cin >> n;
	cin >> s;
	for (int i = 0; i < 8; ++i) {
		if (sz(t[i]) != n)
			continue;
		bool ok = true;
		for (int j = 0; j < n; ++j) {
			if (s[j] != '.' && s[j] != t[i][j]) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			cout << t[i] << '\n';
			return;
		}
	}
	assert(0);
}