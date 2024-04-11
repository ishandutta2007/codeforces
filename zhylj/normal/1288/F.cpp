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
const int N = 400 + 5, INF = 0x3f3f3f3f;

struct Edge {
	int v, nxt, c, w;
} E[N * 10];
int e_cnt, head[N];
void Add(int u, int v, int c, int w) {
	E[e_cnt] = (Edge) { v, head[u], c, w }; head[u] = e_cnt++;
	E[e_cnt] = (Edge) { u, head[v], 0, -w }; head[v] = e_cnt++;
}
int s, t, cur_ed[N], d[N];
std::queue <int> que;
bool Spfa() {
	memset(d, 0x3f, sizeof(d));
	memcpy(cur_ed, head, sizeof(cur_ed));
	d[s] = 0; que.push(s);
	while(!que.empty()) {
		int u = que.front(); que.pop();
		for(int i = head[u]; ~i; i = E[i].nxt) {
			int v = E[i].v, c = E[i].c, w = E[i].w;
			if(c && d[u] + w < d[v]) {
				d[v] = d[u] + w;
				que.push(v);
			}
		}
	}
	return d[t] < INF;
}
bool vis[N];
int Incr(int u, int res_f, int &tot_w) {
	if(u == t) return res_f;
	vis[u] = true;
	int ret = 0, dlt;
	for(int &i = cur_ed[u]; ~i; i = E[i].nxt) {
		int v = E[i].v, c = E[i].c, w = E[i].w;
		if(c && !vis[v] && d[u] + w == d[v] &&
				(dlt = Incr(v, std::min(res_f, c), tot_w))) {
			E[i].c -= dlt; E[i ^ 1].c += dlt;
			res_f -= dlt; ret += dlt;
			tot_w += dlt * w;
			if(!res_f) break;
		}
	}
	vis[u] = false;
	return ret;
}
pii MCMF() {
	int max_f = 0, max_c = 0;
	while(Spfa())
		max_f += Incr(s, INF, max_c);
	return mkp(max_f, max_c);
}

char str_1[N], str_2[N];
int tot;

void AddLR(int u, int v, int l, int r, int w) {
	Add(u, v, r - l, w);
	Add(u, t, l, 0); tot += l;
	Add(s, v, l, 0);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		memset(head, 0xff, sizeof(head));
		int n_1, n_2, m, r, b; rd(n_1, n_2, m, r, b);
		scanf("%s%s", str_1 + 1, str_2 + 1);
		int ss = n_1 + n_2 + 1, tt = ss + 1;
		s = tt + 1; t = s + 1;
		for(int i = 1; i <= m; ++i) {
			int u, v; rd(u, v);
			Add(u, n_1 + v, 1, r);
			Add(n_1 + v, u, 1, b);
		}
		Add(tt, ss, INF, 0);
		for(int i = 1; i <= n_1; ++i) {
			char c = str_1[i];
			if(c == 'R') {
				AddLR(ss, i, 1, INF, 0);
			} else if(c == 'B') {
				AddLR(i, tt, 1, INF, 0);
			} else {
				Add(ss, i, INF, 0);
				Add(i, tt, INF, 0);
			}
		}
		for(int i = 1; i <= n_2; ++i) {
			char c = str_2[i];
			if(c == 'B') {
				AddLR(ss, n_1 + i, 1, INF, 0);
			} else if(c == 'R') {
				AddLR(n_1 + i, tt, 1, INF, 0);
			} else {
				Add(ss, n_1 + i, INF, 0);
				Add(n_1 + i, tt, INF, 0);
			}
		}
		pii p = MCMF();
		if(p.fi == tot) {
			printf("%d\n", p.se);
			for(int i = 0; i < m; ++i) {
				if(E[i << 2 | 1].c) printf("R");
				else if(E[i << 2 | 3].c) printf("B");
				else printf("U");
			}
			printf("\n");
		} else {
			printf("-1\n");
		}
	} return 0;
}