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
 
const int N = 205;
const int M = 25005;
const int INF = 0x3f3f3f3f;
int mp[N][N];
vector < int > ei[N];
int ev[M] , ew[M];
int cnt;
const int S = 0 , T = 1;
 
void addEdge(int u , int v , int w) {
    ev[cnt] = v; ew[cnt] = w;
    ei[u].push_back(cnt++);
    ev[cnt] = u; ew[cnt] = 0;
    ei[v].push_back(cnt++);
}
 
int n , m;
int xa[N],xb[N],ya[N],yb[N];
void init() {
    scanf(II,&n,&m);
    rep (i,m) scanf(IIII,&xa[i],&ya[i],&xb[i],&yb[i]);
    rep (i,m) { xb[i]++; yb[i]++; }
    vector < int > xs , ys;
    rep (i,m) { xs.push_back(xa[i]); xs.push_back(xb[i]);
                ys.push_back(ya[i]); ys.push_back(yb[i]); }
    sort(xs.begin() , xs.end()); xs.erase( unique(xs.begin(),xs.end()) , xs.end());
    sort(ys.begin() , ys.end()); ys.erase( unique(ys.begin(),ys.end()) , ys.end());
    rep (i,m) {
        int xf = lower_bound(xs.begin() , xs.end() , xa[i]) - xs.begin();
        int xt = lower_bound(xs.begin() , xs.end() , xb[i]) - xs.begin();
        int yf = lower_bound(ys.begin() , ys.end() , ya[i]) - ys.begin();
        int yt = lower_bound(ys.begin() , ys.end() , yb[i]) - ys.begin();
        repi (i,xf,xt - 1) repi (j,yf,yt - 1) mp[i][j] = 1;
    }
    int xn = xs.size() , yn = ys.size();
    rep (i,xn-1) addEdge (S,      i+2, xs[i + 1] - xs[i]);
    rep (i,yn-1) addEdge (i+xn+1, T,   ys[i + 1] - ys[i]);
    rep (i,xn-1) rep (j,yn-1) if ( mp[i][j] ) addEdge( i+2, j+xn+1, INF );
}
 
int icf[N], pre[N], vis[N];
int BFS() {
    memset(vis , 0 , sizeof(vis));
    memset(icf , 0 , sizeof(icf));
    icf[S] = INF;
    queue < int > que;
    vis[S] = 1;
    que.push(S);
    while (!que.empty()) {
        int u = que.front(); que.pop();
        foreach (_i,ei[u]) {
            int i = ei[u][_i];
            int v = ev[i], w = ew[i];
            if (!w) continue;
            if (vis[v]) continue;
            if (checkMax( icf[v] , min(icf[u],w) )) pre[v] = i;
            vis[v] = 1;
            que.push(v);
        }
    }
    return icf[T];
}
 
int EK() {
    int ans = 0;
    int icr;
    while ( (icr = BFS()) ) {
        ans += icr;
        int u = T;
        while (u != S) {
            int i = pre[u];
            ew[i] -= icr;
            ew[i ^ 1] += icr;
            u = ev[i ^ 1];
        }
    }
    return ans;
}
 
void solve() {
    printf(IN,EK());
}
 
 
#ifdef ENABLE_LL
#undef int
#endif
int main(){
    init();
    solve();
    return 0;
}