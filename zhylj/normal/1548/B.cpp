#include <bits/stdc++.h>

template <typename T> inline void rd(T& x) {
	int si = 1; char c = getchar(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
	while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 2e5 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, b_cnt[N]; ll a[N], d[N], st[21][N];
ll Gcd(ll a, ll b) {
	return b ? Gcd(b, a % b) : a;
}
void Init() {
	for(int i = 1; i < n; ++i)
		st[0][i] = d[i];
	for(int i = 1; i <= 20; ++i)
		for(int j = 1; j < n; ++j)
			st[i][j] = Gcd(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
}
ll Query(int l, int r) {
	int k = b_cnt[r - l + 1];
	return Gcd(st[k][l], st[k][r - (1 << k) + 1]);
}

ll Abs(ll x) { return x < 0 ? -x : x; }

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n); b_cnt[0] = -1;
		for(int i = 1; i <= n; ++i) b_cnt[i] = b_cnt[i >> 1] + 1;
		for(int i = 1; i <= n; ++i) rd(a[i]);
		for(int i = 1; i < n; ++i) d[i] = Abs(a[i + 1] - a[i]);
		int ans = 0;
		Init();
		for(int l = 1, r = 1; l <= n; ++l) {
			if(r < l) r = l;
			while(r < n && Query(l, r) != 1) ++r;
			ans = std::max(ans, r - l + 1);
		}
		printf("%d\n", ans);
		for(int i = 0; i <= 20; ++i)
			for(int j = 1; j < n; ++j)
				st[i][j] = 0;
	} return 0;
}