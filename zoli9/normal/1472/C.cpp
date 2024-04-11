#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//(double)clock() / CLOCKS_PER_SEC;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        vll a(n);
        for(int i=0; i<n; i++) cin>>a[i];
        vll dp(n+1);
        dp[n]=0;
        ll ans=0;
        for(int i=n-1; i>=0; i--)
        {
            int x=i+a[i];
            if(n<x) x=n;
            dp[i]=a[i]+dp[x];
            ans=max(ans, dp[i]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}