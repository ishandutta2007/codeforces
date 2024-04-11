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
const int N = 5e5 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, q, b[N], flag[N]; ll s[N][18], s2[N][18], a[N];
void Build() {
	for(int i = 1; i < 18; ++i)
		for(int j = 0; j <= n; ++j) {
			s[j][i] = std::max(s[j][i - 1], s[j + (1 << (i - 1))][i - 1]);
			s2[j][i] = std::min(s2[j][i - 1], s2[j + (1 << (i - 1))][i - 1]);
		}
}
ll QueryS1(int l, int r) {
	int k = b[r - l + 1];
	return std::max(s[l][k], s[r - (1 << k) + 1][k]);
}
ll QueryS2(int l, int r) {
	int k = b[r - l + 1];
	return std::min(s2[l][k], s2[r - (1 << k) + 1][k]);
}
ll Abs(ll x) { return x < 0 ? -x : x; }

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, q);
		b[0] = -1;
		for(int i = 1; i <= n; ++i) b[i] = b[i >> 1] + 1;
		for(int i = 1; i <= n; ++i) rd(a[i]);
		for(int i = 1; i <= n; ++i) {
			int x; rd(x); a[i] = x - a[i];
			s[i][0] = s[i - 1][0] + a[i];
			s2[i][0] = s[i][0];
		}
		Build();
		while(q--) {
			int l, r; rd(l, r);
			if(s[l - 1][0] != s[r][0]) printf("-1\n");
			else if(QueryS2(l, r) < s[l - 1][0]) printf("-1\n");
			else {
				printf("%lld\n", QueryS1(l, r) - s[l - 1][0]);
			}
			//printf("Q: %d\n", QueryS(l, r));
		}
	} return 0;
}