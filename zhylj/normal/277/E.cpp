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
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int M = 5e5 + 5, N = 1000 + 5;
const ff Inf = 1e9, Eps = 1e-9;

struct Edge {
	int v, nxt, c; ff w;
} E[M];
int head[N], e_cnt, s, t;
void Init() { memset(head, 0xff, sizeof(head)); e_cnt = 0; }
void Add(int u, int v, int c, ff w) {
	E[e_cnt] = (Edge) { v, head[u], c, w }; head[u] = e_cnt++;
	E[e_cnt] = (Edge) { u, head[v], 0, -w }; head[v] = e_cnt++;
}
ff d[N]; int cur_ed[N];
bool vis[N];
std::queue <int> que;
bool Spfa() {
	for(int i = 1; i < N; ++i) d[i] = Inf;
	memcpy(cur_ed, head, sizeof(cur_ed));
	que.push(s); vis[s] = true; d[s] = 0;
	while(!que.empty()) {
		int u = que.front(); que.pop(); vis[u] = false;
		for(int i = head[u]; ~i; i = E[i].nxt) {
			int v = E[i].v, c = E[i].c; ff w = E[i].w;
			if(c && d[u] + w < d[v]) {
				d[v] = d[u] + w;
				if(!vis[v]) que.push(v), vis[v] = true;
			}
		}
	}
	return d[t] + Eps < Inf;
}
int Incr(int u, int res_f) {
	if(u == t) return res_f;
	int dlt, ret = 0;
	vis[u] = true;
	for(int &i = cur_ed[u]; ~i; i = E[i].nxt) {
		int v = E[i].v, c = E[i].c; ff w = E[i].w;
		if(c && !vis[v] && fabs(d[u] + w - d[v]) < Eps &&
			(dlt = Incr(v, std::min(res_f, c)))) {
			E[i].c -= dlt; E[i ^ 1].c += dlt;
			res_f -= dlt; ret += dlt;
			if(!res_f) break;
		}
	}
	vis[u] = false;
	return ret;
}
void SSP(ff &max_c, int &max_f) {
	max_c = 0; max_f = 0;
	while(Spfa()) {
		int dlt = Incr(s, Inf);
		max_c += dlt * d[t];
		max_f += dlt;
	}
}

int n, x[N], y[N];
ff Dist(int i, int j) {
	return sqrt(
		(x[i] - x[j]) * (x[i] - x[j]) +
		(y[i] - y[j]) * (y[i] - y[j])
	);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n); Init();
		for(int i = 1; i <= n; ++i)
			rd(x[i], y[i]);
		s = n * 2 + 1; t = n * 2 + 2;
		for(int i = 1; i <= n; ++i) {
			Add(s, i, 2, 0);
			for(int j = 1; j <= n; ++j)
				if(y[j] < y[i])
					Add(i, j + n, 1, Dist(i, j));
			Add(i + n, t, 1, 0);
		}
		ff max_c; int max_f;
		SSP(max_c, max_f);
		if(max_f + 1 == n) printf("%.9lf\n", max_c);
		else printf("-1\n");
	} return 0;
}