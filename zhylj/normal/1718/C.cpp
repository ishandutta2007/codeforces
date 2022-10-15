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
typedef std::pair <ll, ll> pii;
const int N = 2e5 + 5;

std::priority_queue <pii> h[N];
std::vector <ll> tot[N];
int n, q, p_cnt, p[N], a[N];

void Modify(int x, int y) {
	for(int j = 1; j <= p_cnt; ++j) {
		tot[j][x % p[j]] += y;
		h[j].push(mkp(tot[j][x % p[j]], x % p[j]));
	}
}
ll GetAns() {
	ll ret = 0;
	for(int i = 1; i <= p_cnt; ++i) {
		while(true) {
			auto x = h[i].top();
			if(tot[i][x.se] != x.fi) { h[i].pop(); continue; }
			ret = std::max(ret, x.fi * p[i]);
			break;
		}
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, q);
		p_cnt = 0;
		int _n = n;
		for(int i = 2; i <= n; ++i) {
			if(_n % i == 0)
				p[++p_cnt] = n / i;
			while(_n % i == 0) _n /= i;
		}
		for(int i = 1; i <= p_cnt; ++i) {
			tot[i].clear();
			tot[i].resize(p[i]);
			for(int j = 0; j < p[i]; ++j)
				tot[i][j] = 0;
		}
		for(int i = 1; i <= n; ++i) {
			rd(a[i]);
			Modify(i, a[i]);
		}
		printf("%lld\n", GetAns());
		for(int i = 1; i <= q; ++i) {
			int pos, x; rd(pos, x);
			Modify(pos, x - a[pos]);
			a[pos] = x;
			printf("%lld\n", GetAns());
		}
		for(int i = 1; i <= p_cnt; ++i) {
			while(!h[i].empty()) h[i].pop();
		}
	} return 0;
}