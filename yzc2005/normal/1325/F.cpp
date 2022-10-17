#include <bits/stdc++.h>
using namespace std;
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
#define go(G, u) for(int i = G.head[u], v = G.to[i]; i; i = G.nxt[i], v = G.to[i])
template <class T> inline void rd(T &x) {
    x = 0; T f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    x *= f;
} 

inline void ckmax(int &a, int b) {if(a < b) a = b;}

const int N = 100005, M = 400005, blk = 505;
struct Graph {
    int to[M], nxt[M], head[N], cnt;
    inline void add(int u, int v) {
        to[++cnt] = v;
        nxt[cnt] = head[u];
        head[u] = cnt;
    }
} G;

int n, m, x, y, sq, fa[N], sum[blk], dep[N];
bool vis[N];

void dfs(int u) {
    ++sum[dep[u] % (sq - 1)];
    vis[u] = 1;
    go(G, u) {
        if(vis[v]) {
            if(dep[u] - dep[v] + 1 < sq) continue;
            puts("2"); printf("%d\n", dep[u] - dep[v] + 1);
            do {
                printf("%d ", u);
                u = fa[u];
            } while(u != v);
            printf("%d\n", v);
            exit(0);
        }         
        dep[v] = dep[u] + 1;
        fa[v] = u;
        dfs(v);
    }
}

int main() {
    rd(n), rd(m); 
    sq = ceil(sqrt(n));
    fu(i, 1, m) rd(x), rd(y), G.add(x, y), G.add(y, x);
    dfs(1);
    puts("1");
    int d = max_element(sum, sum + sq - 1) - sum;
    int cnt = 0;
    fu(u, 1, n) if(dep[u] % (sq - 1) == d && ++cnt <= sq) printf("%d ", u);
    return 0;
}