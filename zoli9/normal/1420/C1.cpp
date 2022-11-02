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

ll dp[300009][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        int n, q;
        cin>>n>>q;
        vll a(n+2);
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
        }
        dp[n][0]=a[n];
        dp[n][1]=0;
        for(int i=n-1; i>=1; i--)
        {
            dp[i][0]=dp[i+1][0];
            dp[i][0]=max(dp[i][0], dp[i+1][1]+a[i]);
            dp[i][1]=dp[i+1][1];
            dp[i][1]=max(dp[i][1], dp[i+1][0]-a[i]);
        }
        cout<<dp[1][0]<<'\n';
    }
    return 0;
}