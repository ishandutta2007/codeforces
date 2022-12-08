#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#define MOD 1000000007
#define forn(a, n) for(int a = 0; a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define EPS 0.000000000001
typedef long long tint;
using namespace std;

map<pair<int, long long>, long long> dp;
tint nums[512];
tint costs[512];
    int n;

tint gcd(tint a, tint b)
{
    return a?(gcd(b%a, a)):b;
}

long long calcdp(int i, long long d)
{
    
    if(dp.count(make_pair(i, d))) return dp[make_pair(i,d)];
    dp[make_pair(i,d)]=1000000000000LL;
     
    long long &ans=dp[make_pair(i,d)];
    

    if(i==n)
    {
        if(d==1){ ans=0;}
        return ans;
    }   
    
    ans=min(ans, calcdp(i+1, d));
    ans=min(ans, calcdp(i+1, gcd(d, nums[i]))+costs[i]);
    return ans;
}

int main()
{
#ifdef ACMTUYO
    freopen("B.in","r",stdin);
#endif
    cin >> n;
    forn(i, n) cin >> nums[i];
    forn(i, n) cin >> costs[i];
    
    tint ans=calcdp(0, 0);
    
    if(ans<1000000000000LL) cout << ans << endl; else cout << -1 << endl;
    
    return 0;
}