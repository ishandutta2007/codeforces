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
        vi a(n+2);
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
        }
        vi dp(n+10, 0);
        dp[n+1]=0;
        for(int i=n; i>=1; i--)
        {
            if(a[i]==0)
            {
                dp[i]=min(dp[i+2], dp[i+3]);
                if(a[i+1]==0)
                {
                    dp[i]=min(dp[i], dp[i+4]);
                }
                else
                {
                    dp[i]=min(dp[i], dp[i+4]+1);
                }
            }
            else
            {
                dp[i]=min(dp[i+2], dp[i+3])+1;
                if(a[i+1]==0)
                {
                    dp[i]=min(dp[i], dp[i+4]+1);
                }
                else
                {
                    dp[i]=min(dp[i], dp[i+4]+2);
                }
            }
        }
        cout<<dp[1]<<'\n';
    }
    return 0;
}