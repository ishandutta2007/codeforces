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
typedef pair < int , int > pr;
typedef pair < pr  , int > prr;
#define L first
#define R second

const int N = 100005;
const int K = 16;
vector < int > e[N];
int fa[N][K];
int dep[N];
int size[N];
int n;

void dfs_makeFaDepSiz(int u = 1 , int f = 0 , int d = 1) {
    size[u] = 1;
    dep[u] = d;
    fa[u][0] = f;
    repa (i,K - 1) fa[u][i] = fa [ fa[u][i - 1] ][i - 1];
    foreach (i,e[u]) {
        int v = e[u][i];
        if (v == f) continue;
        dfs_makeFaDepSiz (v, u , d + 1);
        size[u] += size[v];
    }
}

void init(){
    scanf("%d",&n);
    rep (i,n - 1) {
        int a,b ; scanf("%d%d" , &a , &b);
        e[a].push_back(b) ; e[b].push_back(a);
    }
}

inline int upMove(int u , int d) {
    int x = 0;
    while (d) {
        if (d & 1) u = fa[u][x]; 
        x++;
        d >>= 1;
    }
    return u;
}

int LCA(int p , int q) {
    int dp = dep[p] , dq = dep[q];
    if (dp < dq) swap(dp , dq) , swap(p , q);
    p = upMove(p , dp - dq);
    if (p == q) return p;
    for (int i=K - 1;i>=0;i--) if (fa[p][i] != fa[q][i]) p = fa[p][i] , q = fa[q][i];
    return fa[p][0];
}

void solve(int p , int q) { 
    if (p == q) { printf("%d\n",n) ; return; }
    int dp = dep[p] , dq = dep[q];
    if (dp < dq) swap(dp , dq) , swap(p , q);
    int l = LCA (p,q) , dl = dep[l] , um = dq - dl;
    if (dp == dq) printf("%d\n",n - size[upMove(p,um - 1)] - size[upMove(q,um - 1)]);
    else {
        if ( (dp - dq) % 2 == 1 ) puts("0");
        else printf("%d\n", size[ upMove(p,um + (dp - dq) / 2)      ] 
                          - size[ upMove(p,um + (dp - dq) / 2 - 1)  ]) ;
    }
}

int main(){
    init();
    dfs_makeFaDepSiz (); 
    int m ; scanf("%d",&m);
    while (m--) {
        int p , q ; scanf("%d%d",&p,&q);
        solve (p,q);
    }
    return 0;
}