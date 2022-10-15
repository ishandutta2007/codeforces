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
const int N = 5e5 + 5;

int n, m, fa[N], U[N], V[N], W[N], d[N];

int Find(int x) { return fa[x] == x ? x : fa[x] = Find(fa[x]); }
void Merge(int x, int y) { fa[Find(x)] = Find(y); }

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m);
		for(int i = 1; i <= n * 2; ++i) fa[i] = i, d[i] = -1;
		for(int i = 1; i < n; ++i) {
			int u, v, w; rd(u, v, w);
			U[i] = u; V[i] = v; W[i] = w;
			if(w != -1) {
				if(__builtin_parity(w) == 0) {
					Merge(u, v);
					Merge(u + n, v + n);
				} else {
					Merge(u, v + n);
					Merge(u + n, v);
				}
			}
		}
		for(int i = 1; i <= m; ++i) {
			int u, v, p; rd(u, v, p);
			p = __builtin_parity(p);
			if(p) Merge(u + n, v), Merge(v + n, u);
			else Merge(u, v), Merge(u + n, v + n);
		}
		bool flag = true;
		for(int i = 1; i <= n; ++i)
			if(Find(i) == Find(i + n)) { flag = false; break; }
		if(!flag) {
			printf("NO\n");
		} else {
			printf("YES\n");
			for(int i = 1; i <= n; ++i) {
				if(d[Find(i)] == -1) {
					d[Find(i)] = 0;
					d[Find(i + n)] = 1;
				}
				d[i] = d[Find(i)];
			}
			for(int i = 1; i < n; ++i) {
				if(W[i] != -1) printf("%d %d %d\n", U[i], V[i], W[i]);
				else printf("%d %d %d\n", U[i], V[i], d[U[i]] ^ d[V[i]]);
			}
		}
	} return 0;
}