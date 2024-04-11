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

const int INF = 0x3f3f3f3f;
const int N = 105;
const int M = 2000005;
int dis[N][N];
char s[N];
int a[M];
int n, m;

void init() {
    scanf(I,&n);
    rep (i,n) {
        scanf("%s",s);
        rep (j,n) dis[i][j] = ( s[j] == '1' ? 1 : INF);
    } 
    rep (r,n) rep (u,n) rep (v,n) checkMin( dis[u][v], dis[u][r] + dis[r][v] );
    rep (i,n) dis[i][i] = 0;
    scanf(I,&m);
    rep (i,m) scanf(I,&a[i]);
    rep (i,m) a[i] --;
}

void solve() {
    vector < int > ans;
    ans.push_back(a[0]);
    ans.push_back(a[1]);
    repi (i,2,m-1) {
        int d = ans.size();
        ses(ans[d-2]);ses(ans[d-1]);see(a[i]);
        if (dis[ ans[d-2] ][ a[i] ] == dis[ ans[d-2] ][ ans[d-1] ] + dis[ ans[d-1] ][ a[i] ] ) ans.pop_back();
        ans.push_back(a[i]);
    }
    printf(IN,(int)ans.size());
    foreach (i,ans) printf("%d ", ans[i] + 1);
}


#ifdef ENABLE_LL
#undef int
#endif
int main(){
    init();
    solve();
    return 0;
}