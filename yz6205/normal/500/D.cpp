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

#define int long long
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

const int N = 200005;
vector < int > ei[N];
vector < int > e;
int n;
double base[N];
int wei[N]; // map_key: for each index x in 'vector e' , the index here is (x / 2 + 1)

void init(){
    scanf("%lld",&n);
    rep (i,n - 1) {
        int u , v , w; scanf("%lld%lld%lld",&u,&v,&w);
        e.push_back(v);
        ei[u].push_back(i * 2);
        e.push_back(u);
        ei[v].push_back(i * 2 + 1);
        wei[i + 1] = w;
    }
}

int size[N];
void dfs(int u = 1 , int f = 0 ) {
    size[u] = 1;
    foreach (i,ei[u]) {
        int v = e[ ei[u][i] ];
        if (v == f) continue;
        dfs (v,u);
        size[u] += size[v];

        int n1 = size[v] , n2 = n - size[v];
        base[ ei[u][i] / 2 + 1 ] = (double) (1) *
            ( n1 * n2 * (n2 - 1) + n1 * (n1 - 1) * n2 )
            /
            ( n * (n - 1) * (n - 2) / 6 );
    }
}

void solve() {
    double ans = 0;
    repa (i , n - 1) ans += wei[i] * base[i];
    int q;
    scanf("%lld",&q);
    while (q--) {
        int eid , nlen;
        scanf("%lld%lld",&eid,&nlen);
        ans -= base[eid] * (wei[eid] - nlen);
        wei[eid] = nlen;
        printf("%.10lf\n",ans);
    }
}

#undef int
int main(){
    init();
    dfs();
    solve();
    return 0;
}