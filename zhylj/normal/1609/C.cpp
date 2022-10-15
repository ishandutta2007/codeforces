#include <bits/stdc++.h>

#define gc() getchar()
template <typename T> inline void rd(T& x) {
	int si = 1; char c = gc(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = gc();
	while(isdigit(c)) x = x * 10 + c - 48, c = gc();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 1e6 + 5;

bool flag[N];
void Sieve() {
	for(int i = 2; i < N; ++i) if(!flag[i])
		for(int j = i << 1; j < N; j += i)
			flag[j] = true;
}

int a[N]; ll cnt[N][2];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	Sieve();
	while(test_case_cnt--) {
		int e, n; rd(n, e);
		for(int i = 1; i <= n; ++i) rd(a[i]);
		for(int i = 1; i <= (n << 1) + 1; ++i) cnt[i][0] = cnt[i][1] = 0;
		ll ans = 0;
		for(int i = n; i; --i) {
			if(flag[a[i]]) continue;
			int p_cnt = (a[i] == 1 ? 0 : 1);
			cnt[i][p_cnt] = 1;
			for(int j = p_cnt; j < 2; ++j)
				cnt[i][j] += cnt[i + e][j - p_cnt];
			ans += cnt[i][1];
			if(p_cnt) --ans;
		}
		printf("%lld\n", ans);
	} return 0;
}