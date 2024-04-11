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

char s[10000];
char t[10000];
int to[10000];
int d[2005][2005];

void solve() {
	scanf("%s%s", s, t);
	int n = strlen(s);
	int m = strlen(t);
	for (int start = 0; start < n; ++start) {
		if (s[start] != t[0])
			continue;
		int cur = 1;
		int end = start + 1;
		while (end < n && cur < m) {
			if (s[end] == t[cur])
				++cur;
			++end;
		}
		if (cur == m)
			to[start] = end;
	}
	for (int i = 0; i < n; ++i)
		for (int x = 0; x <= n; ++x)
			d[i][x] = -INF;
	d[0][0] = 0;
	for (int i = 0; i < n; ++i)
		for (int x = 0; x <= n; ++x) {
			if (d[i][x] == -INF)
				continue;
			if (x + 1 <= n) {
				d[i + 1][x + 1] = max(d[i + 1][x + 1], d[i][x]);
				d[i + 1][x] = max(d[i + 1][x], d[i][x]);
			}
			if (to[i]) {
				int nx = x + to[i] - i - m;
				if (nx <= n)
					d[to[i]][nx] = max(d[to[i]][nx], d[i][x] + 1);
			}
		}
	for (int i = 0; i <= n; ++i)
		cout << d[n][i] << ' ';
	cout << '\n';
}