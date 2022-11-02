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

const int MOD = 1e9 + 7;
int n , l , r;
int dp[3][2];
int cnt[3];

int calc(int l , int r) {
    int rr = r - r % 3;
    int ll = l - (l - 1) % 3 - 1;
    return (rr - ll) / 3;
}

void init() {
    scanf(III,&n,&l,&r);
    cnt[0] = calc(l,r);
    cnt[1] = calc(l + 2 , r + 2);
    cnt[2] = calc(l + 1 , r + 1);
}

void solve() {
    dp[0][0] = 1;
    rep (i,n) {
        dp[0][1] = (dp[0][0] * cnt[0] + dp[1][0] * cnt[2] + dp[2][0] * cnt[1]) % MOD;
        dp[1][1] = (dp[0][0] * cnt[1] + dp[1][0] * cnt[0] + dp[2][0] * cnt[2]) % MOD;
        dp[2][1] = (dp[0][0] * cnt[2] + dp[1][0] * cnt[1] + dp[2][0] * cnt[0]) % MOD;
        dp[0][0] = dp[0][1] ; dp[1][0] = dp[1][1] ; dp[2][0] = dp[2][1];
    }
    printf(IN,dp[0][0]);
}


#ifdef ENABLE_LL
#undef int
#endif
int main(){
    init();
    solve();
    return 0;
}