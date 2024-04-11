#include <bits/stdc++.h>
#define N 20
#define NN 597569
#define popc __builtin_popcount
#define ctz __builtin_ctz
using namespace std;

typedef long long ll;

int V, E, n, c;
int u, v, i, j;
int G[N][N];
ll f[NN][N], ans;

inline void down(int &x, const int y) {x > y ? x = y : 0;}

int main(){
    scanf("%d%d", &V, &E);
    for(i = 1; i <= E; ++i){
        scanf("%d%d", &u, &v); --u; --v;
        G[u][v] = G[v][u] = 1;
    }
    for(i = 0; i < V; ++i) f[1 << i][i] = 1;
    n = 1 << V; ans = 0;
    for(i = 1; i < n; ++i){
        u = ctz(i); c = popc(i);
        for(v = 0; v < V; ++v){
            if(!f[i][v]) continue;
            if(G[v][u] && c > 2) ans += f[i][v];
            for(j = u + 1; j < V; ++j)
                if(!(i >> j & 1) && G[v][j])
                    f[i | 1 << j][j] += f[i][v];
        }
    }
    printf("%lld\n", ans >> 1);
    return 0;
}