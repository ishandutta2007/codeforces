#include <bits/stdc++.h>
using namespace std;
#define INF int(1e9+1)
#define INFL ll(2e18+INF)
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef long double ld;
typedef complex <ld> point;
void solve();

#define NAME "d"
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

queue <int> s[3];
int t[3];

inline void update(queue <int> &s, int T) {
	while (!s.empty() && s.front() == T)
		s.pop();
}

void solve() {
	int k, n[3];
	cin >> k;
	for (int i = 0; i < 3; ++i)
		cin >> n[i];
	for (int i = 0; i < 3; ++i)
		cin >> t[i];
	int T = 0;
	int res = 0;
	while (k || !s[0].empty() || !s[1].empty() || !s[2].empty()) {
		update(s[0], T);
		update(s[1], T + t[0]);
		update(s[2], T + t[0] + t[1]);
		while (k && sz(s[0]) < n[0] && sz(s[1]) < n[1] && sz(s[2]) < n[2]) {
			//~ cerr << "add " << T << '\n';
			s[0].push(T + t[0]);
			s[1].push(T + t[0] + t[1]);
			s[2].push(T + t[0] + t[1] + t[2]);
			res = T + t[0] + t[1] + t[2];
			--k;
		}
		++T;
	}
	cout << res << '\n';
}