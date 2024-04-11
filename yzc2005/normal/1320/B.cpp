#include <bits/stdc++.h>
using namespace std;
#define mem(a, x) memset(a, x, sizeof(a))
#define fail puts("NO"), exit(0)
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
template <class T> inline void rd(T &x) {
    x = 0; T f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    x *= f;
} 
template <class T> inline void ckmax(T &a, T b) {if(a < b) a = b;}
template <class T> inline void ckmin(T &a, T b) {if(a > b) a = b;}

const int N = 2e5 + 5, M = N;
int n, m, k, a[N], dis[N], diss[N], mx, mn;
bool able[N];

#define go(G, u) for(int o = G.head[u], v = G.to[o]; o; o = G.nxt[o], v = G.to[o])
struct Graph {
    int to[M], nxt[M], head[N], cnt;
    inline void add(int u, int v) {
        to[++cnt] = v;
        nxt[cnt] = head[u];
        head[u] = cnt;
    }
} G, G1;

inline void bfs() {
	queue <int> q;
	q.push(a[1]);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		go(G, u) {
			if(v == a[1] || dis[v]) continue;
			dis[v] = dis[u] + 1;
			q.push(v);
		}
	}
}

inline void bfss() {
	queue <int> q;
	q.push(a[k]);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		go(G1, u) {
			if(v == a[k] || diss[v]) continue;
			diss[v] = diss[u] + 1;
			q.push(v);
		}
	}
}

int main() {
	rd(n), rd(m);
	for(int i = 1, u, v; i <= m; ++i) rd(u), rd(v), G.add(u, v), G1.add(v, u);
	rd(k); fu(i, 1, k) rd(a[i]);
	bfs(), bfss();
	fu(i, 1, k - 1) {
		int u = a[i], f1 = 1, f2 = 0, mnlen = 1e9;
		go(G, u) ckmin(mnlen, diss[v]);
		go(G, u) {
			if(diss[v] != mnlen) continue;
			if(v == a[i + 1]) f1 = 0;
			else f2 = 1;
		}
		mn += f1, mx += f2;
	}
	printf("%d %d\n", mn, mx);
	return 0; 
}