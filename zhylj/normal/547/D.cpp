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
const int kM = 1e6 + 5, kN = 4e5 + 15, kX = 2e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

namespace Net {

	struct Edge {
		int v, nxt, c, idx;
	} E[kM];
	int head[kN], w[kN], S, T, s, t, cnt;
	void Init(int ns, int nt) {
		memset(head, 0xff, sizeof(head));
		s = ns; t = nt; cnt = 0;
	}
	void TAdd(int u, int v, int c, int idx) {
		E[cnt] = (Edge) { v, head[u], c, idx }; head[u] = cnt++;
		E[cnt] = (Edge) { u, head[v], 0, idx }; head[v] = cnt++;
	}
	void Add(int u, int v, int low, int upp, int idx = 0) {
		//printf("%d %d [%d,%d]\n", u, v, low, upp);
		if(low != upp) TAdd(u, v, upp - low, idx);
		w[u] -= low; w[v] += low;
	}
	int tot = 0;
	void Build() {
		Add(t, s, 0, kInf);
		S = t + 1; T = t + 2;
		for(int i = 1; i <= t; ++i) {
			if(w[i] > 0) TAdd(S, i, w[i], 0), tot += w[i];
			if(w[i] < 0) TAdd(i, T, -w[i], 0);
		}
	}
	int lev[kN], cur[kN];
	std::queue <int> que;
	int GetLev(int ss, int tt) {
		memcpy(cur, head, sizeof(cur));
		memset(lev, 0, sizeof(lev));
		lev[ss] = 1; que.push(ss);
		while(!que.empty()) {
			int u = que.front(); que.pop();
			for(int i = head[u]; ~i; i = E[i].nxt) {
				int c = E[i].c, v = E[i].v;
				if(c && !lev[v]) {
					lev[v] = lev[u] + 1;
					que.push(v);
				}
			}
		}
		return lev[tt];
	}
	int Incr(int u, int res_f, int tt) {
		if(u == tt) return res_f;
		int ret = 0, dlt;
		for(int &i = cur[u]; ~i; i = E[i].nxt) {
			int c = E[i].c, v = E[i].v;
			if(c && lev[v] > lev[u] && (dlt = Incr(v, std::min(res_f, c), tt))) {
				E[i].c -= dlt; E[i ^ 1].c += dlt;
				ret += dlt; res_f -= dlt;
				if(!res_f) break;
			}
		}
		return ret;
	}
	int Dinic(int ss, int tt) {
		int max_f = 0;
		while(GetLev(ss, tt)) {
			max_f += Incr(ss, kInf, tt);
		}
		return max_f;
	}
	int col[kN];
	void Construct() {
		for(int i = 1; i <= kX; ++i) {
			for(int j = head[i]; ~j; j = E[j].nxt) {
				int v = E[j].v, idx = E[j].idx;
				if(idx) col[idx] = E[j].c;
			}
		}
	}

}

int n, p[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n); Net::Init(kX * 2, kX * 2 + 1);
		for(int i = 1; i <= n; ++i) {
			int x, y; rd(x, y);
			Net::Add(x, y + kX, 0, 1, i);
			++p[y + kX]; ++p[x];
		}
		for(int i = 1; i <= kX; ++i) {
			if(p[i] > 0) Net::Add(Net::s, i, p[i] / 2, (p[i] + 1) / 2);
			if(p[i + kX] > 0) Net::Add(i + kX, Net::t, p[i + kX] / 2, (p[i + kX] + 1) / 2);
		}
		Net::Build();
		Net::Dinic(Net::S, Net::T);
		Net::Construct();
		for(int i = 1; i <= n; ++i) {
			printf("%c", Net::col[i] ? 'b' : 'r');
		}
		printf("\n");
	} return 0;
}