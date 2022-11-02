#define ENABLE_LL
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
typedef pair < int , int > pr;
typedef pair < pr  , int > prr;
#define L first
#define R second

const int N = 200005;
const int MOD = 1e9 + 7;
pr d[N];
int n;

void init() {
    scanf(I,&n);
    rep (i,n) {
        int x , y; scanf(II,&x,&y);
        d[i] = pr(y , x);
    }
    d[n++] = pr(0,1);
    sort ( d , d + n );
}

bool osrCmp(int x , int y) {
    pr a = d[x] , b = d[y];
    return a.R == b.R ? a.L < b.L : a.R < b.R;
}

int dp[N] , spr[N];

void solve() {
    vector < int > osr;
    rep (i,n) osr.push_back(i);
    sort (osr.begin() , osr.end() , osrCmp);
    rep (i,n) ses(osr[i]);
    see("");
    dp[0] = 1; spr[0] = d[0].L;
    int oid = 0 , sspr = 0 , ans = dp[0];
    repa (i,n - 1) {
        sspr += d[i].L - d[i - 1].L;
        see(sspr);
        ses(oid);ses(sspr);see(ans);
        while (d[ osr[oid + 1] ].R <= d[i].L) {
            oid++;
            int nspr = d[i].L - d[ osr[oid] ].R + spr[ osr[oid] ];
            if (nspr == sspr) (ans += dp[ osr[oid] ]) %= MOD;
            else if (nspr < sspr) {
                sspr = nspr;
                ans = dp[ osr[oid] ];
            }
        }
        dp[i] = ans;
        see(dp[i]);
        spr[i] = sspr;
    }
    int mspr = spr[n - 1];
    rep (i,n) if (d[i].R > d[n - 1].L) mspr = min(mspr , spr[i]);
    see(mspr);
    int res = 0;
    rep (i,n) if (d[i].R > d[n - 1].L && spr[i] == mspr) (res += dp[i]) %= MOD;
    printf(IN,res);
}

#ifdef ENABLE_LL
#undef int
#endif
int main(){
    init();
    solve();
    return 0;
}