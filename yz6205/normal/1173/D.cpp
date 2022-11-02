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

const long long MOD = 998244353;
const int N = 200005;
vector < int > e[N];
long long ans = 1;
long long fac[N];
int n;

void dfs(int u,int f) {
    long long ns = e[u].size() - (u != 1);
    (ans *= fac[ns + (u != 1)]) %= MOD;
    foreach(i,e[u]) {
        int v = e[u][i];
        if (v == f) continue;
        dfs(v,u);
    }
}

int main(){
    scanf("%d",&n);
    rep (i,n-1) {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    
    fac[0] = 1;
    repa (i,n) fac[i] = (fac[i - 1] * i) % MOD;

    dfs(1,0);
    printf("%lld\n",ans * n % MOD);
    return 0;
}