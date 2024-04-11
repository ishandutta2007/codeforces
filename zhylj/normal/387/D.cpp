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
const int N = 1e3 + 5, M = 1e5 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

struct Edge {
	int v, nxt, c;
} E[M];
int head[N], e_cnt, s, t;
void Init() { memset(head, 0xff, sizeof(head)); e_cnt = 0; }
void Add(int u, int v, int c) {
	E[e_cnt] = (Edge) { v, head[u], c }; head[u] = e_cnt++;
	E[e_cnt] = (Edge) { u, head[v], 0 }; head[v] = e_cnt++;
}
int lev[N], cur_ed[N];
std::queue <int> que;
bool GetLev() {
	memset(lev, 0, sizeof(lev));
	memcpy(cur_ed, head, sizeof(cur_ed));
	que.push(s); lev[s] = 1;
	while(!que.empty()) {
		int u = que.front(); que.pop();
		for(int i = head[u]; ~i; i = E[i].nxt) {
			int v = E[i].v, c = E[i].c;
			if(c && !lev[v]) {
				lev[v] = lev[u] + 1;
				que.push(v);
			}
		}
	}
	return lev[t] != 0;
}
int Incr(int u, int res_f) {
	if(u == t) return res_f;
	int dlt, ret = 0;
	for(int &i = cur_ed[u]; ~i; i = E[i].nxt) {
		int v = E[i].v, c = E[i].c;
		if(c && lev[v] == lev[u] + 1 && (dlt = Incr(v, std::min(res_f, c)))) {
			E[i].c -= dlt; E[i ^ 1].c += dlt;
			res_f -= dlt; ret += dlt;
			if(!res_f) break;
		}
	}
	return ret;
}
int Dinic() {
	int max_f = 0;
	while(GetLev())
		max_f += Incr(s, Inf);
	return max_f;
}

int n, m, U[N], V[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m);
		for(int i = 1; i <= m; ++i)
			rd(U[i], V[i]);
		int ans = Inf;
		for(int i = 1; i <= n; ++i) {
			int cnt = 0, tot = 0, cur_ans;
			for(int j = 1; j <= m; ++j) {
				int u = U[j], v = V[j];
				if(u == i || v == i) ++cnt;
			}
			cnt = 2 * n - 1 - cnt;
			Init();
			s = 2 * n + 1; t = 2 * n + 2;
			for(int j = 1; j <= m; ++j) {
				int u = U[j], v = V[j];
				if(u != i && v != i) {
					Add(u, v + n, 1);
					++tot;
				}
			}
			for(int j = 1; j <= n; ++j)
				if(j != i) {
					Add(s, j, 1);
					Add(j + n, t, 1);
				}
			cur_ans = 2 * (n - 1 - Dinic()) + (tot - (n - 1)) + cnt;
			ans = std::min(ans, cur_ans);
		}
		printf("%d\n", ans);
	} return 0;
}