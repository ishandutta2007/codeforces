//    
#include <bits/stdc++.h>
using namespace std;
#define mem(a, x) memset(a, x, sizeof(a))
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
#define go(G, u) for(int o = G.head[u], v = G.to[o]; o; o = G.nxt[o], v = G.to[o])
template <class T> inline void rd(T &x) {
    x = 0; T f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    x *= f;
} 
template <class T> inline void ckmax(T &a, T b) {if(a < b) a = b;}
template <class T> inline void ckmin(T &a, T b) {if(a > b) a = b;}
 
const int N = 1005;
int n, x, y, deg[N], qu[N], l = 1, r;
bool isleaf[N];
 
struct Graph {
    int to[N << 1], nxt[N << 1], head[N], cnt;
    inline void add(int u, int v) {
        to[++cnt] = v;
        nxt[cnt] = head[u];
        head[u] = cnt;
    }
} G;

inline int query(int u, int v) {
	printf("? %d %d\n", u, v), fflush(stdout);
	int ans; rd(ans); return ans;
}

inline int putans(int u) {
	printf("! %d\n", u), fflush(stdout);
	exit(0);
}

int main() {
	rd(n); fu(i, 1, n - 1) rd(x), rd(y), ++deg[x], ++deg[y], G.add(x, y), G.add(y, x);
	fu(i, 1, n) if(deg[i] == 1) qu[++r] = i, isleaf[i] = 1;
	while(l < r) {
		int u[2]; u[0] = qu[l++], u[1] = qu[l++];
		int lca = query(u[0], u[1]);
		if(lca == u[0] || lca == u[1]) putans(lca);
		fu(k, 0, 1) go(G, u[k]) 
			if(!isleaf[v]) {
				--deg[v];
				if(deg[v] == 1) isleaf[v] = 1, qu[++r] = v; 
			}
	}
	putans(qu[r]);
}