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
const int kN = 2e3 + 5, kM = 1e4 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;


int n, rt[2], w[kN], typ[2][kN], lim[2][kN], d[2][kN], fa[2][kN];
std::vector <int> E[2][kN];
void Add(int col, int u, int v) {
	E[col][u].push_back(v);
}
void Dfs(int col, int u) {
	d[col][u] = d[col][fa[col][u]] + 1;
	for(auto v : E[col][u]) if(v != fa[col][u]) {
		fa[col][v] = u; Dfs(col, v);
	}
}
std::set <int> S;
void DrawTyp(int col, int u, int cur_typ) {
	if(typ[col][u]) S.insert(typ[col][u]);
	else typ[col][u] = cur_typ;
	for(auto v : E[col][u]) if(v != fa[col][u]) {
		DrawTyp(col, v, cur_typ);
	}
}

namespace NetFlow {

struct Edge {
	int v, nxt, c, p;
} E[kM];
int head[kN], cnt, s, t;
void Init() {
	cnt = 0;
	memset(head, 0xff, sizeof(head));
}
void Add(int u, int v, int c, int p) {
	E[cnt] = (Edge) { v, head[u], c, p }; head[u] = cnt++;
	E[cnt] = (Edge) { u, head[v], 0, -p }; head[v] = cnt++;
}

int d[kN], cur[kN];
bool in_que[kN], vis[kN];
std::queue <int> que;
bool Spfa() {
	memcpy(cur, head, sizeof(cur));
	memset(vis, false, sizeof(vis));
	memset(d, ~0x3f, sizeof(d));
	d[s] = 0;
	que.push(s); in_que[s] = true;
	while(!que.empty()) {
		int u = que.front(); que.pop();
		in_que[u] = false;
		for(int i = head[u]; ~i; i = E[i].nxt) {
			int v = E[i].v, p = E[i].p, c = E[i].c;
			if(c && d[u] + p > d[v]) {
				d[v] = d[u] + p;
				if(!in_que[v]) {
					in_que[v] = true;
					que.push(v);
				}
			}
		}
	}
	return d[t] > -kInf;
}
int IncrFlow(int u, int res_f, int &tot_p) {
	if(u == t) return res_f;
	vis[u] = true;
	int dlt, ret = 0;
	for(int &i = cur[u]; ~i; i = E[i].nxt) {
		int v = E[i].v, c = E[i].c, p = E[i].p;
		if(!vis[v] && c && d[u] + p == d[v] && (dlt = IncrFlow(v, std::min(res_f, c), tot_p))) {
			E[i].c -= dlt; E[i ^ 1].c += dlt;
			res_f -= dlt; ret += dlt; tot_p += dlt * p;
			if(!res_f) break;
		}
	}
	return ret;
}
void Dinic(int &max_f, int &max_p) {
	max_f = max_p = 0;
	while(Spfa()) max_f += IncrFlow(s, kInf, max_p); 
}

};

int Calc() {
	NetFlow::Init();
	int tot_lim_0 = 0, tot_lim_1 = 0, max_f, max_p;
	NetFlow::s = 3 * n + 1; NetFlow::t = 3 * n + 2;
	for(int i = 1; i <= n; ++i) {
		NetFlow::Add(typ[0][i] + n, i, 1, w[i]);
		NetFlow::Add(i, typ[1][i] + 2 * n, 1, 0);
	}
	for(int i = 1; i <= n; ++i) {
		NetFlow::Add(NetFlow::s, i + n, lim[0][i], 0);
		NetFlow::Add(i + 2 * n, NetFlow::t, lim[1][i], 0);
		if(lim[0][i] < 0 || lim[1][i] < 0) return -1;
		tot_lim_0 += lim[0][i];
		tot_lim_1 += lim[1][i];
	}
	if(tot_lim_0 != tot_lim_1) return -1;
	NetFlow::Dinic(max_f, max_p);
	return max_f == tot_lim_0 ? max_p : -1;
}

int lim_p[kN], idx[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		NetFlow::Init();
		rd(n, rt[0], rt[1]);
		for(int i = 1; i <= n; ++i) rd(w[i]);
		for(int c = 0; c < 2; ++c) {
			for(int i = 1; i < n; ++i) {
				int u, v; rd(u, v);
				Add(c, u, v); Add(c, v, u);
			}
		}
		for(int c = 0; c < 2; ++c) {
			int q; rd(q);
			for(int i = 1; i <= q; ++i) {
				rd(lim_p[i], lim[c][i]);
				idx[i] = i;
			}
			Dfs(c, rt[c]);
			std::sort(idx + 1, idx + q + 1, [&](const int &x, const int &y) {
				return d[c][lim_p[x]] > d[c][lim_p[y]];
			});
			for(int i = 1; i <= q; ++i) {
				S.clear();
				DrawTyp(c, lim_p[idx[i]], idx[i]);
				for(auto j : S) lim[c][idx[i]] -= lim[c][j];
			}
		}
		printf("%d\n", Calc());
	} return 0;
}