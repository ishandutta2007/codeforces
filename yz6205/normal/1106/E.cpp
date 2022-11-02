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

const int N = 100005;
const int K = 205;
vector < pr > bg[N] , ed[N];
multiset < pr > st;
int n , m , k;
int dp[N][K];

void init() {
    scanf(III,&n,&m,&k);
    rep (i,k) {
        int s , t , w , d; scanf(IIII,&s,&t,&d,&w);
        ses(s);ses(t);ses(w);see(d);
        bg[s].push_back( pr(w,d) );
        ed[t].push_back( pr(w,d) );
        ses(bg[s].size());see(ed[t].size());
    }
}

void solve() {
    for (int i=n;i >= 1;i--) {
        foreach (_,ed[i]) st.insert( ed[i][_] );

        ses(ed[i].size());see(st.size());
        rep (j,m + 1) dp[i][j] = st.empty() ? dp[i + 1][j] : dp[st.rbegin()->R + 1][j] + st.rbegin()->L;
        repa(j,m    ) dp[i][j] = min(dp[i][j] , dp[i + 1][j - 1]);
        see(dp[i][0]);

        foreach (_,bg[i]) st.erase( st.find( bg[i][_] ) );
    }
    int ans = dp[1][0] ; repa (i,m) ans = min(ans , dp[1][i]);
    printf(IN,ans);
}


#ifdef ENABLE_LL
#undef int
#endif
int main(){
    init();
    solve();
    return 0;
}