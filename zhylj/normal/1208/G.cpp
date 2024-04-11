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

int n, k, p_cnt, p[N], phi[N];
bool flag[N];
void Sieve() {
	phi[1] = 1;
	for(int i = 2; i <= n; ++i) {
		if(!flag[i]) {
			p[++p_cnt] = i;
			phi[i] = i - 1;
		}
		for(int j = 1; p[j] * i <= n && j <= p_cnt; ++j) {
			flag[i * p[j]] = true;
			if(i % p[j] == 0) {
				phi[i * p[j]] = phi[i] * p[j];
				break;
			}
			phi[i * p[j]] = phi[i] * (p[j] - 1);
		}
	}
}

int a[N], m;

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, k);
		Sieve();
		ll ans_1 = 1e18, ans_2 = 1e18;
		for(int i = 3; i <= n; i += 2) 
			a[++m] = phi[i];
		std::sort(a + 1, a + m + 1);
		if(m >= k) {
			ans_1 = 1;
			for(int i = 1; i <= k; ++i)
				ans_1 += a[i];
		}
		m = 0;
		for(int i = 2; i <= n; ++i) 
			a[++m] = phi[i];
		std::sort(a + 1, a + m + 1);
		ans_2 = 1;
		for(int i = 1; i <= k + 1; ++i)
			ans_2 += a[i];
		printf("%lld\n", std::min(ans_1, ans_2));
	} return 0;
}