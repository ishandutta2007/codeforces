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
const int N = 1e6 + 5, MOD = 1e9 + 7;

int n, m, v_cnt, in_e[N], dep[N], f[N], vis[N];
std::vector <pii> E[N];
void Add(int u, int v, int w) {
	E[u].push_back(mkp(v, w));
}

std::queue <std::vector <int> > que;
void Solve() {
	que.push((std::vector <int>) { 1 });
	while(!que.empty()) {
		std::vector <int> S = que.front(), T[10]; que.pop();
		for(int u : S)
			for(pii e : E[u]) {
				int v = e.fi, w = e.se;
				if(dep[v] == dep[u] + 1 && !vis[v])
					in_e[v] = std::min(in_e[v], w);
			}
		for(int u : S)
			for(pii e : E[u]) {
				int v = e.fi, w = e.se;
				if(dep[v] == dep[u] + 1 && !vis[v]) {
					vis[v] = 1;
					assert(in_e[v] < 10);
					T[in_e[v]].push_back(v);
				}
			}
		int cur_f = f[S[0]];
		for(int w = 0; w < 10; ++w) {
			if(!T[w].empty()) {
				for(int v : T[w])
					f[v] = (10LL * cur_f + w) % MOD;
				que.push(T[w]);
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
		memset(in_e, 0x3f, sizeof(in_e));
		rd(n, m); v_cnt = n;
		for(int i = 1; i <= m; ++i) {
			int u, v; rd(u, v);
			std::vector <int> dig;
			for(int x = i; x; x /= 10)
				dig.push_back(x % 10);
			std::reverse(dig.begin(), dig.end());
			for(int j = 0, lst = u; j < dig.size(); ++j) {
				int c = dig[j];
				if(j == (int)dig.size() - 1)
					Add(lst, v, c);
				else Add(lst, ++v_cnt, c);
				lst = v_cnt;
			}
			for(int j = 0, lst = v; j < dig.size(); ++j) {
				int c = dig[j];
				if(j == (int)dig.size() - 1)
					Add(lst, u, c);
				else Add(lst, ++v_cnt, c);
				lst = v_cnt;
			}
		}
		std::queue <int> que;
		que.push(1); dep[1] = 1;
		while(!que.empty()) {
			int u = que.front(); que.pop();
			for(pii e : E[u]) {
				int v = e.fi, w = e.se;
				if(!dep[v]) {
					dep[v] = dep[u] + 1;
					que.push(v);
				}
			}
		}
		Solve();
		for(int i = 2; i <= n; ++i)
			printf("%d\n", f[i]);
	} return 0;
}