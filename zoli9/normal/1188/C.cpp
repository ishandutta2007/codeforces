#include <bits/stdc++.h>
using namespace std;
int n, k;
long long MOD=998244353;
vector<int> t;
long long dp[1009][1009];
int elotteindex[1009];
long long ans=0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    t.resize(n);
    for(int i=0; i<n; i++)
    {
        cin>>t[i];
    }
    sort(t.begin(), t.end());
    int meddig=t.back()/(k-1);
    for(int x=1; x<=meddig; x++)
    {
        int i1=-1;
        for(int i=0; i<n; i++)
        {
            while(t[i1+1]+x<=t[i]) i1++;
            elotteindex[i]=i1;
        }
        dp[0][1]=1;
        for(int i=2; i<=k; i++) dp[0][i]=0;
        for(int lt=1; lt<n; lt++)
        {
            for(int i=1; i<=k; i++)
            {
                if(i==1)
                {
                    dp[lt][i]=(dp[lt-1][i]+1)%MOD;
                    continue;
                }
                if(elotteindex[lt]>=0)
                {
                    dp[lt][i]=(dp[lt-1][i]+dp[elotteindex[lt]][i-1])%MOD;
                }
                else
                {
                    dp[lt][i]=dp[lt-1][i];
                }
            }
        }
        ans=(ans+dp[n-1][k])%MOD;
    }
    cout<<ans<<endl;
    return 0;
}