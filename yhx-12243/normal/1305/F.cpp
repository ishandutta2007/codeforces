#include <bits/stdc++.h>
#define gcd std::__gcd

typedef long long ll;
typedef std::set <ll> set;
const int N = 200054;

int n, ans = 0;
ll a[N], pr[N];
set used;
std::mt19937 gen;

inline int uniform(int l, int r) {return std::uniform_int_distribution <int> (l, r) (gen);}
inline void down(int &x, const int y) {x > y ? x = y : 0;}
inline ll min(const ll x, const ll y) {return x < y ? x : y;}

void solve(ll x) {
	if (!x) return;
	int i, j, cnt = 0, cur;
	for (i = 2; (ll)i * i <= x; ++i)
		if (!(x % i)) for (pr[cnt++] = i; !(x % i); x /= i);
	if (x != 1) pr[cnt++] = x;
	for (i = 0; i < cnt; ++i)
		if (used.emplace(pr[i]).second) {
			for (cur = j = 0; j < n; ++j) {
				if (a[j] <= pr[i]) x = pr[i] - a[j];
				else x = a[j] % pr[i], x = min(x, pr[i] - x);
				if (cur + x >= ans) break;
				cur += x;
			}
			if (j == n) ans = cur;
		}
}

int main() {
	int i, pos;
	char *_ = new char; gen.seed(time(NULL) + (size_t)_); delete _;
	scanf("%d", &n), used.emplace(2);
	for (i = 0; i < n; ++i) scanf("%lld", a + i), ans += a[i] & 1;
	for (i = 0; i < 24; ++i)
		pos = uniform(0, n - 1), solve(a[pos]),
		solve(a[pos] - 1), solve(a[pos] + 1);
	printf("%d\n", ans);
	return 0;
}