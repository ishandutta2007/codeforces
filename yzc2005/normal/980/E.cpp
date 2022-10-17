#include <bits/stdc++.h>
using namespace std;
#define mem(a, x) memset(a, x, sizeof(a))
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

const int N = 1000005, K = 20, M = N << 1;

#define go(G, u) for(int i = G.head[u], v = G.to[i]; i; i = G.nxt[i], v = G.to[i])
struct Graph {
    int to[M], nxt[M], head[N], cnt;
    inline void add(int u, int v) {
        to[++cnt] = v;
        nxt[cnt] = head[u];
        head[u] = cnt;
    }
} G;

int n, k, x, y, fa[N][K];
bool chosen[N];

void dfs(int u) {
	go(G, u) {
		if(v == fa[u][0]) continue;
		fa[v][0] = u;
		fu(j, 1, 19) fa[v][j] = fa[fa[v][j - 1]][j - 1];
		dfs(v);
	}
}

int main() {
    int qwq;
	rd(n), chosen[n] = 1;
	rd(k), k = n - 1 - k;
	fu(i, 1, n - 1) rd(x), rd(y), G.add(x, y), G.add(y, x);
	dfs(n);
	fd(i, n - 1, 1) {
		if(chosen[i]) continue;
		int u = i, cnt = 1;
		fd(j, 19, 0) {
			if(!fa[u][j]) continue;
			if(chosen[fa[u][j]]) continue;
			u = fa[u][j], cnt += 1 << j;
		}
		if(k < cnt) continue;
		k -= cnt, u = i; 
		do {
			chosen[u] = 1;
			u = fa[u][0];
		} while(!chosen[u]);
	}
	fu(i, 1, n) if(!chosen[i]) printf("%d ", i);
	return 0;
}