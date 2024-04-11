#include <bits/stdc++.h>
#define gcd std::__gcd
#define ctz __builtin_ctz
using std::cin;
using std::cout;

typedef long long ll;
typedef std::pair <ll, int> pair;
const int N = 1000054;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

int n, w = 0, ALL;
ll K, G = 0, pr[12];
ll prod[2050], f[12][2050];
pair a[N];

inline bool down(ll &x, const ll y) {return x > y ? x = y, 1 : 0;}
inline int min(const int x, const int y) {return x < y ? x : y;}

void factor(ll n) {
	int i;
	if (!(n & 1)) pr[w++] = 2, n >>= ctz(n);
	for (i = 3; (ll)i * i <= n; i += 2)
		if (!(n % i)) for (pr[w++] = i; !(n % i); n /= i);
	if (n != 1) pr[w++] = n;
}

inline ll norm(ll n) {ll x = n; for (int i = 0; i < w; ++i) for (; !(n % pr[i]); n /= pr[i]); return x / n;}
inline int Omega(ll n) {int i, ret = 0; for (i = 0; i < w; ++i) ret += !(n % pr[i]); return ret;}

void trans(int m, pair *E) {
	int i, j, $, S; bool succ = true; ll n = E->first, p$[12];
	for (i = 0; i < w; ++i) for (p$[i] = 1; !(n % pr[i]); n /= pr[i], p$[i] *= pr[i]);
	assert(n == 1);
	for (*prod = i = 1; i <= ALL; ++i) prod[i] = prod[i & (i - 1)] * p$[ctz(i)];
	for ($ = 0; $ < m && succ; ++$)
		for (succ = false, i = w - 1; i >= 0; --i)
			for (j = 0; j <= ALL; ++j) if (f[i][j] < INF)
				for (S = ~j & ALL; S; S = (S - 1) & ~j)
					succ |= prod[S] <= K && down(f[i + 1][j | S], f[i][j] + $[E].second);
}

int main() {
	int i, j = 0, omega; ll ans = INF;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> K;
	for (i = 0; i < n; ++i) cin >> a[i].first, G = gcd(G, a[i].first);
	factor(G), ALL = ~(-1 << w);
	for (i = 0; i < n; ++i) a[i].first = norm(a[i].first), cin >> a[i].second;
	std::sort(a, a + n), omega = Omega(a->first);
	memset(f, 63, sizeof f), **f = 0;
	for (i = 1; i <= n; ++i)
		if (i == n || a[i - 1].first != a[i].first)
			trans(min(omega, i - j), a + j), j = i;
		else omega = Omega(a[i].first);
	for (i = 0; i <= w; ++i) if (f[i][ALL] < INF) down(ans, f[i][ALL] * i);
	cout << (ans < INF ? ans : -1) << '\n';
	return 0;
}