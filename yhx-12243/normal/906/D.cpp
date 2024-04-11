#include <bits/stdc++.h>
#define ctz __builtin_ctz
using std::cin;
using std::cout;

typedef long long ll;
const int N = 100054;

int mod[50], beg[50];
int n, q, len = 0;
int a[N];
int pn = 0, c[N], p[9600];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline int lcm(int a, int b) {return a / std::__gcd(a, b) * b;}

ll PowerMod(ll a, int n, ll mod, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

void sieve(int n) {
	int i, j, v;
	memset(c, -1, sizeof c);
	for (i = 2; i <= n; ++i) {
		if (!~c[i]) p[pn] = i, c[i] = pn++;
		for (j = 0; (v = i * p[j]) <= n && j <= c[i]; ++j) c[v] = j;
	}
}

void getNT(int n, int &T, int &S) {
	int i, j, U; S = ctz(n), T = 1 << (S - (S > 0) - (S > 2)), n >>= S;
	for (i = 0; n != 1; ) {
		if (n >= N) {
			for (; p[i] * p[i] <= n && n % p[i]; ++i);
			if (n % p[i]) return T = lcm(T, n - 1), up(S, 1);
		} else i = c[n];
		for (j = 0, U = 1; !(n % p[i]); n /= p[i], ++j) U = U * (p[i] - !j);
		T = lcm(T, U), up(S, j);
	}
}

// check whether a^n < b
inline int check(int a, int n, int b) {
	int s = 1;
	for (; n && s < b; --n) s = s * a;
	return s < b ? s : -1;
}

int solve(int L, int R, int id) {
	if (L == R || a[L] == 1 || mod[id] == 1) return 1;
	int U = solve(L + 1, R, id + 1), p = mod[id], b = beg[id], s;
	return ~(s = check(a[L], U, b)) ? s : (PowerMod(a[L], U, p) + p - b) % p + b;
}

int main() {
	int i, l, r; sieve(N - 1);
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> *mod;
	for (*beg = 1; mod[len] != 1; ++len) getNT(mod[len], mod[len + 1], beg[len + 1]);
	for (i = 1; i <= n; ++i) cin >> a[i];
	for (cin >> q; q; --q) cin >> l >> r, cout << solve(l, r + 1, 0) % *mod << '\n';
	return 0;
}