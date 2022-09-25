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

char s[1000001];
char *t[100001];
char buf[1000001];
char tmp[1000001];
char from[100001];

int val[10];
int len[10];

#define mod 1000000007

inline int binpow(ll a, int x) {
	ll res = 1;
	while (x) {
		if (x & 1) {
			res *= a;
			res %= mod;
		}
		x >>= 1;
		a *= a;
		a %= mod;
	}
	return res;
}

pair <int, int> calc(char *s) {
	int n = strlen(s);
	ll l = 0;
	ll v = 0;
	for (int i = n - 1; i >= 0; --i) {
		v += ll(binpow(10, l)) * val[s[i] - '0'];
		v %= mod;
		l += len[s[i] - '0'];
		l %= mod - 1;
	}
	return make_pair(v, l);
}

void solve() {
	scanf("%s", s);
	int n;
	cin >> n;
	char *ptr = buf;
	for (int i = 0; i < n; ++i) {
		scanf("%s", tmp);
		from[i] = tmp[0];
		t[i] = ptr;
		for (int j = 3; tmp[j]; ++j) {
			ptr[0] = tmp[j];
			++ptr;
		}
		ptr[0] = 0;
		++ptr;
	}
	for (int i = 0; i < 10; ++i)
		val[i] = i, len[i] = 1;
	for (int i = n - 1; i >= 0; --i) {
		pair <int, int> q = calc(t[i]);
		val[from[i] - '0'] = q.first;
		len[from[i] - '0'] = q.second;
	}
	pair <int, int> q = calc(s);
	//~ cerr << q.second << '\n';
	cout << q.first << '\n';
}