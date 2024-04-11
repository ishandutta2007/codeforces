#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair <ll, ll> pr;
const int N = 400054;

int n;
ll K, Len, a[N];
pr pts[N];

inline void up(ll &x, const ll y) {x < y ? x = y : 0;}
inline void down(ll &x, const ll y) {x > y ? x = y : 0;}
inline ll min(const ll x, const ll y) {return x < y ? x : y;}

inline bool perfect() {
	ll s = Len / K;
	for (int i = 0; i < n; ++i) if (a[i] % s) return false;
	return Len == K * s;
}

inline bool check_inf(ll x) {
	ll s = 0;
	for (int i = 0; i < n; ++i) s += a[i] / x;
	return s >= K;
}

inline bool check_sup(ll x) {
	ll s = 0;
	for (int i = 0; i < n; ++i) s += (a[i] - 1) / x + 1;
	return s <= K;
}

void work() {
	int i, cnt = 0; ll inf, sup, L, R, M, u, v, ans;
	scanf("%lld%d%lld", &Len, &n, &K), a[n] = Len;
	for (i = 0; i < n; ++i) scanf("%lld", a + i);
	for (u = v = *a, i = n; i; --i) up(v, a[i] -= a[i - 1]), down(u, a[i]);
	if (K += ++n, perfect()) {putchar(48), putchar(10); return;}
	for (L = 1, R = min(u, Len / K); L < R; check_inf(M = (L + R + 1) / 2) ? L = M : R = M - 1);
	inf = L;
	for (L = (Len - 1) / K + 1, R = v; L < R; check_sup(M = (L + R) / 2) ? R = M : L = M + 1);
	sup = R;
	for (i = 0; i < n; ++i)
		if ((u = (a[i] - 1) / sup + 1) > (v = a[i] / inf))
			pts[cnt++] = pr(a[i] / u, -( (a[i] - 1) / v + 1) );
	std::sort(pts, pts + cnt), v = sup, ans = LLONG_MAX;
	for (i = 0; i < cnt; ++i)
		if (-pts[i].second > v) down(ans, v - pts[i].first), v = -pts[i].second;
	printf("%lld\n", min(ans, v - inf));
}

int main() {
	int T;
	for (scanf("%d", &T); T; --T) work();
	return 0;
}