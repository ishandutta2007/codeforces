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

int n, c, a[N], nxt[N], v_nxt[N], cur_d[N], lst_l[N], lst[N], v_lst[N];

struct Bit {
	int T[N];
	void Modify(int o, int v) { for(; o <= n; o += o & -o) T[o] += v; }
	int Query(int o) { int ret = 0; for(; o; o -= o & -o) ret += T[o]; return ret; }
} A, B;
int ans[N]; std::vector <pii> Q[N], M[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= n; ++i) {
			rd(a[i]); c = std::max(c, a[i]);
		}
		for(int i = 1; i <= c; ++i) v_nxt[i] = n + 1;
		for(int i = n; i; --i) {
			nxt[i] = v_nxt[a[i]];
			v_nxt[a[i]] = i;
		}
		for(int i = 1; i <= n; ++i) {
			lst[i] = v_lst[a[i]];
			v_lst[a[i]] = i;
			if(i - lst[i] != cur_d[a[i]]) {
				int L = lst_l[a[i]] ? nxt[lst_l[a[i]]] : v_nxt[a[i]], R = i - 1;
				if(L <= R) {
					M[lst[lst_l[a[i]]] + 1].push_back(mkp(L, 1));
					M[lst[lst_l[a[i]]] + 1].push_back(mkp(R + 1, -1));
					M[lst[i] + 1].push_back(mkp(L, -1));
					M[lst[i] + 1].push_back(mkp(R + 1, 1));
				}
				cur_d[a[i]] = i - lst[i];
				lst_l[a[i]] = lst[i];
			}
		}
		for(int i = 1; i <= c; ++i) {
			int L = lst_l[i] ? nxt[lst_l[i]] : v_nxt[i];
			M[lst[lst_l[i]] + 1].push_back(mkp(L, 1));
			M[v_lst[i] + 1].push_back(mkp(L, -1));
		}
		int q; rd(q);
		for(int i = 1; i <= q; ++i) {
			int l, r; rd(l, r);
			Q[l].push_back(mkp(i, r));
		}
		for(int i = 1; i <= c; ++i)
			if(v_nxt[i]) A.Modify(v_nxt[i], 1);
		for(int i = 1; i <= n; ++i) {
			for(auto j : M[i]) B.Modify(j.fi, j.se);
			for(auto j : Q[i]) {
				ans[j.fi] = A.Query(j.se) + (B.Query(j.se) == 0);
			}
			A.Modify(i, -1);
			A.Modify(nxt[i], 1);
		}
		for(int i = 1; i <= q; ++i)
			printf("%d\n", ans[i]);
	} return 0;
}