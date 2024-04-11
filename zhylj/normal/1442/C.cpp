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
typedef std::pair <pii, pii> piiii;
const int kN = 4e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

ll QPow(ll a, ll b) {
	ll ret = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ret = ret * bas % kMod;
	return ret;
}

int n, m, d[25][kN], d2[25][kN], d3[25][kN]; bool vis[25][kN];
std::vector <int> E[2][kN];
void Add(int x, int u, int v) { E[x][u].push_back(v); }

std::deque <pii> que;
std::priority_queue <piiii, std::vector <piiii>, std::greater <piiii> > pq;
void Bfs() {
	que.push_back(mkp(0, 1));
	vis[0][1] = true; d[0][1] = 0;
	while(!que.empty()) {
		pii u = que.front(); que.pop_front();
		//printf("%d %d %d\n", u.fi, u.se, d[u.fi][u.se]);
		if(u.fi < 21 && d[u.fi + 1][u.se] > d[u.fi][u.se]) {
			//printf("%d\n", u.fi);
			d[u.fi + 1][u.se] = d[u.fi][u.se];
			vis[u.fi + 1][u.se] = true;
			que.push_front(mkp(u.fi + 1, u.se));
		} else if(u.fi == 21) {
			d2[0][u.se] = 22;
			d3[0][u.se] = d[u.fi][u.se];
			pq.push(
				mkp(
					mkp(22, d[u.fi][u.se]),
					mkp(0, u.se)
				)
			);
		}
		for(auto v : E[u.fi & 1][u.se]) {
			if(d[u.fi][v] > d[u.fi][u.se] + 1) {
				vis[u.fi][v] = true;
				d[u.fi][v] = d[u.fi][u.se] + 1;
				que.push_back(mkp(u.fi, v));
			}
		}
	}
}
bool vis2[2][kN];
void Bfs2() {
	while(!pq.empty()) {
		pii u = pq.top().se; pq.pop();
		if(vis2[u.fi][u.se]) continue;
		vis2[u.fi][u.se] = true;
		if(mkp(d2[u.fi ^ 1][u.se], d3[u.fi ^ 1][u.se]) >
			mkp(d2[u.fi][u.se] + 1, d3[u.fi][u.se])) {
			d2[u.fi ^ 1][u.se] = d2[u.fi][u.se] + 1;
			d3[u.fi ^ 1][u.se] = d3[u.fi][u.se];
			pq.push(
				mkp(
					mkp(d2[u.fi][u.se] + 1, d3[u.fi][u.se]),
					mkp(u.fi ^ 1, u.se)
				)
			);
		}
		for(auto v : E[u.fi][u.se]) {
			if(mkp(d2[u.fi][v], d3[u.fi][v]) >
				mkp(d2[u.fi][u.se], d3[u.fi][u.se] + 1)) {
				d2[u.fi][v] = d2[u.fi][u.se];
				d3[u.fi][v] = d3[u.fi][u.se] + 1;
				pq.push(
					mkp(
						mkp(d2[u.fi][u.se], d3[u.fi][u.se] + 1),
						mkp(u.fi, v)
					)
				);
			}
		}
	}
}

std::vector <pii> e;
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		memset(d, 0x3f, sizeof(d));
		memset(d2, 0x3f, sizeof(d2));
		memset(d3, 0x3f, sizeof(d3));
		rd(n, m);
		for(int i = 1; i <= m; ++i) {
			int u, v; rd(u, v);
			Add(0, u, v); Add(1, v, u);
			e.push_back(mkp(u, v));
		}
		Bfs(); Bfs2();
		ll ans = kInf; bool flag = false;
		for(int i = 0; i <= 22; ++i) if(vis[i][n]) {
			ans = std::min(ans, d[i][n] + (1LL << i) - 1);
			//printf("%d : %d %lld\n", i, d[i][n], d[i][n] + QPow(2, i) - 1);
			flag = true;
		}
		if(!flag) {
			ans = d2[0][n] < d2[1][n] ? 
				QPow(2, d2[0][n]) - 1 + d3[0][n] :
				QPow(2, d2[1][n]) - 1 + d3[1][n];
		}
		ans = (ans + kMod) % kMod;
		//printf("%lld\n", QPow(2, 189928) - 1 + 189992);
		printf("%lld\n", ans);
	} return 0;
}