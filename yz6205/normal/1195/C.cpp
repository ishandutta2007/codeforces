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
int ha[N] , hb[N];
int n;

void init(){
    scanf("%lld",&n);
    rep (i,n) scanf("%lld",&ha[i]);
    rep (i,n) scanf("%lld",&hb[i]);
}

int dp[N][2][2];
void solve() {
    dp[0][0][0] = 0;
    dp[0][0][1] = hb[0];
    dp[0][1][0] = ha[0];
    rep (i,n - 1) {
        dp[i + 1][0][0] = max(dp[i][0][0] , max ( dp[i][0][1] , dp[i][1][0] ) );
        dp[i + 1][1][0] = max(dp[i][0][0] , dp[i][0][1]) + ha[i + 1];
        dp[i + 1][0][1] = max(dp[i][0][0] , dp[i][1][0]) + hb[i + 1];
    } 
    printf("%lld\n", max(dp[n - 1][0][0] , max(dp[n-1][0][1] , dp[n-1][1][0]) ) );
}

#undef int
int main(){
#define int long long
    init();
    solve();
    return 0;
}