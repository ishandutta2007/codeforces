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

#ifdef ENABLE_LL
#define int long long
#endif

#ifdef ENABLE_LL
#define I "%lld"
#define II "%lld%lld"
#define III "%lld%lld%lld"
#define IIII "%lld%lld%lld%lld"
#define IN "%lld\n"
#define IIN "%lld%lld\n"
#define IIIN "%lld%lld%lld\n"
#define IIIIN "%lld%lld%lld%lld\n"
#else
#define I "%d"
#define II "%d%d"
#define III "%d%d%d"
#define IIII "%d%d%d%d"
#define IN "%d\n"
#define IIN "%d%d\n"
#define IIIN "%d%d%d\n"
#define IIIIN "%d%d%d%d\n"
#endif

#ifdef __LOCALE__
#define see(a) std::cout << #a << "=" << a << std::endl
#define ses(a) std::cout << #a << "=" << a << " " 
#else
#define see(a) //std::cout << #a << "=" << a << std::endl
#define ses(a)
#endif
#define foreach(a,b) for (int a=0;a<(int)b.size();a++)
#define rep(i,n) for (int i=0;i<n;i++)
#define repa(i,n) for (int i=1;i<=n;i++)
#define repi(i,a,b) for (int i=a;i<=b;i++) 
#define repb(i,a,b) for (int i=a;i>=b;i--)
typedef pair < int , int > pr;
typedef pair < pr  , int > prr;
#define L first
#define R second
template <class T> inline bool checkMin(T& a , T b) { return (a > b ? a=b,1 : 0); }
template <class T> inline bool checkMax(T& a , T b) { return (a < b ? a=b,1 : 0); }

const int N = 600005;
vector < int > ei[N];
int ev[N];
int cnt;

void addEdge (int u, int v) {
    ev[cnt] = v; ei[u].push_back(cnt++);
    ev[cnt] = u; ei[v].push_back(cnt++);
}

int n , k , d;
int isp[N];
int fr[N];
void BFS() {
    queue < int > que;
    repa (i,n) if (isp[i]) { que.push(i); fr[i] = i; }
    while (!que.empty()) {
        int u = que.front(); que.pop();
        foreach (_i,ei[u]) {
            int i = ei[u][_i], v = ev[i];
            if (fr[v]) continue;
            fr[v] = fr[u];
            que.push(v);
        }
    }
}

void init() {
    scanf(III,&n,&k,&d);
    rep (i,k) { int r; scanf(I,&r); isp[r] = 1; }
    rep (i,n-1) {
        int u , v; scanf(II,&u,&v);
        addEdge (u,v);
    }
}

void solve() {
    BFS();
    vector < int > ans;
    rep (i,n-1) if ( fr[ ev[i*2] ] != fr[ ev[i*2+1] ] ) ans.push_back(i + 1);
    printf(IN,(int)ans.size());
    foreach (i,ans) { printf(I,ans[i]); putchar(' '); }
}


#ifdef ENABLE_LL
#undef int
#endif
int main(){
    init();
    solve();
    return 0;
}