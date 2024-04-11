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
const int N = 40;

int n, m, typ, siz, d[N], g[N][N], f[1 << N / 2];
ll nei[N];

void Dfs(int u) {
	++siz;
	for(int v = 0; v < n; ++v) {
		if(g[u][v]) {
			if(d[v] == -1) {
				d[v] = d[u] ^ 1;
				Dfs(v);
			} else if(d[v] != (d[u] ^ 1)) {
				typ = 0;
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		memset(d, 0xff, sizeof(d));
		rd(n, m);
		for(int i = 1; i <= m; ++i) {
			int u, v; rd(u, v);
			--u; --v;
			g[u][v] = g[v][u] = 1;
			nei[u] |= 1LL << v;
			nei[v] |= 1LL << u;
		}
		for(int S = 0; S < 1 << n / 2; ++S) {
			ll n_S = 0;
			for(int i = 0; i < n / 2; ++i)
				if((S >> i) & 1) n_S |= nei[i];
			if(!(n_S & S)) ++f[S];
		}
		for(int i = 0; i < n / 2; ++i)
			for(int S = 0; S < 1 << n / 2; ++S) if((~S >> i) & 1)
				f[S | (1 << i)] += f[S];
		ll tot = 1LL << n, A = 0, B = 1, C = 1, D = 1;
		int U = (1 << n / 2) - 1;
		for(int S = 0; S < 1 << (n + 1) / 2; ++S) {
			ll n_S = 0;
			for(int i = 0; i < (n + 1) / 2; ++i)
				if((S >> i) & 1) n_S |= nei[n / 2 + i];
			if(!((n_S >> (n / 2)) & S))
				A += f[U ^ (U & n_S)];
		}
		for(int i = 0; i < n; ++i) {
			if(d[i] == -1) {
				typ = 1;
				d[i] = siz = 0;
				Dfs(i);
				if(siz == 1) D *= 2;
				B *= 2;
				C *= typ ? 2 : 0;
			}
		}
		tot = tot - A * 2 - B + C + D * 2 - (m == 0) * (1LL << n);
		printf("%lld\n", tot);
	} return 0;
}