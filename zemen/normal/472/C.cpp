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

char s[100001][2][55];
int p[200001];
char min_s[55];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < 2 * n; ++i) {
		scanf("%s", s[i / 2][i % 2]);
	}
	for (int i = 0; i < n; ++i) {
		int c;
		scanf("%d", &c);
		--c;
		p[i] = c;
		//~ p[c] = i;
	}
	for (int i = 0; i < n; ++i) {
		//~ cerr << min_s << '\n';
		int q = p[i];
		bool ok1 = (strcmp(s[q][0], min_s) > 0);
		bool ok2 = strcmp(s[q][1], min_s) > 0;
		if (ok1 && ok2) {
			if (strcmp(s[q][0], s[q][1]) > 0)
				strcpy(min_s, s[q][1]);
			else
				strcpy(min_s, s[q][0]);
		} else if (ok1)
			strcpy(min_s, s[q][0]);
		else if (ok2)
			strcpy(min_s, s[q][1]);
		else {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}