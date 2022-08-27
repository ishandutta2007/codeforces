#include <bits/stdc++.h>
#define gcd std::__gcd

typedef long long ll;
const int N = 1000054, D = 7000;

int n;
int f[D];
ll a[N], d[N];

inline void up(ll &x, const ll y) {x < y ? x = y : 0;}

ll solve(ll x) {
	int i, j, cnt = 0, tot;
	for (i = 1; (ll)i * i < x; ++i) x % i || (d[cnt++] = i, d[cnt++] = x / i);
	if ((ll)i * i == x) d[cnt++] = i;
	std::sort(d, d + cnt), memset(f, 0, cnt << 2);
	for (i = 0; i < n; ++i) ++f[std::lower_bound(d, d + cnt, gcd(a[i], x)) - d];
	for (i = cnt - 1; i; --i) {
		for (tot = 0, j = i; j < cnt; ++j) d[j] % d[i] || (tot += f[j]);
		if (tot >= (n + 1) / 2) return d[i];
	}
	return 1;
}

int main() {
	int i; ll ans = 1;
	char *_ = new char; std::mt19937 gen(time(NULL)	+ (unsigned long)_); delete _;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) scanf("%lld", a + i);
	for (i = 0; i < 12; ++i) up(ans, solve(a[gen() % n]));
	printf("%lld\n", ans);
	return 0;
}