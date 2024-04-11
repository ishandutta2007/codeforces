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

char s[2001];
int p, n;

void fill_min(int x) {
	for (int i = x; i < n; ++i) {
		for (int j = 0; j < p; ++j) {
			if (i && s[i - 1] == j + 'a')
				continue;
			if (i > 1 && s[i - 2] == j + 'a')
				continue;
			s[i] = j + 'a';
			break;
		}
	}
}

bool add(int x) {
	//~ cerr << "add " << x << '\n';
	if (x == -1)
		return false;
	if (s[x] - 'a' == p - 1) {
		return add(x - 1);
	}
	++s[x];
	//~ cerr << "s " << x << " is " << s[x] << '\n';
	if (x && (s[x] == s[x - 1]))
		return add(x);
	else if (x > 1 && (s[x] == s[x - 2]))
		return add(x);
	else
		fill_min(x + 1);
	return true;
}

void solve() {
	cin >> n >> p;
	scanf("%s", s);
	if (p == 1) {
		cout << "NO\n";
		return;
	}
	if (p == 2) {
		if (s[0] == 'a') {
			if (n == 1)
				cout << "b\n";
			else
				cout << "ba\n";
		} else
			cout << "NO\n";
		return;
	}
	if (!add(n - 1)) {
		cout << "NO\n";
		return;
	}
	cout << s << '\n';
}