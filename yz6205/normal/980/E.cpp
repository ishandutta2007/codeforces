#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

#ifdef __LOCALE__
#define see(a) std::cout << #a << "=" << a << std::endl
#else
#define see(a) //std::cout << #a << "=" << a << std::endl
#endif
#define foreach(a,b) for (int a=0;a<(int)b.size();a++)
#define rep(i,n) for (int i=0;i<n;i++)
#define repa(i,n) for (int i=1;i<=n;i++)
#define repi(i,a,b) for (int i=a;i<=b;i++) 
typedef pair < int , int > Point;

const int N = 1000005;
const int L = 25;
vector < int > e[N];
int fa[N][L];
int chs[N];
int dep[N];
int n,k;

void dfs (int u,int f,int d) {
    dep[u] = d;
    fa[u][0] = f;
    repa (i,L - 1) fa[u][i] = fa[ fa[u][i - 1] ][ i - 1 ];
    foreach (i,e[u]) {
        int v = e[u][i];
        if (v == f) continue;
        dfs(v,u,d + 1);
    }
}

void init(){
    scanf("%d%d",&n,&k);
    rep (i,n - 1) {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(n,0,1);
    k = n - k;
}

int getFaChs(int u) {
    int f = u;
    for (int i=L - 1;i >= 0;i--) if (!chs[ fa[f][i] ]) f = fa[f][i];
    f = fa[f][0];
    return dep[u] - dep[f];
}

void solve() {
    chs[0]  = 1;
    for (int i=n;i>=1;i--) {
        if (chs[i]) continue;
        int dis = getFaChs(i);
        if (dis <= k) {
            int pos = i;
            while (!chs[pos]) {
                chs[pos] = 1;
                pos = fa[pos][0];
            }
            k -= dis;
        }
    }
    repa (i,n) if (!chs[i]) printf("%d ",i);
    puts("");
}

int main(){
    init();
    solve();     
    return 0;
}