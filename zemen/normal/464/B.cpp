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

int a[8][3];

ll sqr(ll a) {
	return a * a;
}

void brute(int x) {
	if (x == 8) {
		int s[3] = {0, 0, 0};
		for (int c = 0; c < 3; ++c)
			for (int i = 0; i < 8; ++i)
				s[c] += a[i][c];
		for (int c = 0; c < 3; ++c) {
			if (s[c] % 4)
				return;
			s[c] >>= 2;
		}
		if (a[0][0] * 2 == s[0] && a[0][1] * 2 == s[1] && a[0][2] * 2 == s[2])
			return;
		ll dist = -1;
		for (int i = 0; i < 8; ++i) {
			int q[3] = {s[0] - a[i][0], s[1] - a[i][1], s[2] - a[i][2]};
			ll cdist = sqr(s[0] - 2 * a[i][0]) + sqr(s[1] - 2 * a[i][1]) + sqr(s[2] - 2 * a[i][2]);
			if (i) {
				if (cdist != dist)
					return;
			} else {
				dist = cdist;
			}
			int ok = 0;
			for (int j = 0; j < 8; ++j)
				ok += (a[j][0] == q[0] && a[j][1] == q[1] && a[j][2] == q[2]);
			if (ok != 1)
				return;
		}
		pair <ll, int> qwer = make_pair(-1, -1);
		for (int i = 0; i < 8; ++i) {
			pair <ll, int> qw = make_pair(INFL, 0);
			for (int j = 0; j < 8; ++j) {
				if (j == i)
					continue;
				ll dist = sqr(a[i][0] - a[j][0]) + sqr(a[i][1] - a[j][1]) + sqr(a[i][2] - a[j][2]);
				if (dist < qw.first)
					qw = make_pair(dist, 1);
				else if (dist == qw.first)
					qw.second++;
			}
			//~ cerr << qw.first << ' ' << qw.second << '\n';
			if (qw.second != 3)
				return;
			if (!i)
				qwer = qw;
			else if (qw != qwer)
				return;
		}
		
		cout << "YES\n";
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 3; ++j)
				cout << a[i][j] << ' ';
			cout << '\n';
		}
		exit(0);
	}
	sort(a[x], a[x] + 3);
	do {
		brute(x + 1);
	} while (next_permutation(a[x], a[x] + 3));
}

void solve() {
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 3; ++j)
			cin >> a[i][j];
	brute(0);
	cout << "NO\n";
}