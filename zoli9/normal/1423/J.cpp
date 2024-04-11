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

ll MOD=1e9+7;
vll dp[8];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        ll n;
        cin>>n;
        ll ans;
        if(n%4==0)
        {
            ans=(((n/4+1)%MOD)*(((n/4+1))%MOD))%MOD;
        }
        else if(n%4==1)
        {
            ans=(((n/4+1)%MOD)*(((n/4+1))%MOD))%MOD;
        }
        else if(n%4==2)
        {
            ans=(((n/4+1)%MOD)*(((n/4+2))%MOD))%MOD;
        }
        else
        {
            ans=(((n/4+1)%MOD)*(((n/4+2))%MOD))%MOD;
        }
        cout<<ans<<'\n';
        /*vi d;
        while(n>0)
        {
            d.push_back(n%2);
            n/=2;
        }
        int s=d.size();
        for(int i=0; i<8; i++) dp[i].resize(s);
        for(int i=0; i<8; i++)
        {
            if(d[0]+2*i<8) dp[i][0]=1;
            else dp[i][0]=0;
            if(i>0) dp[i][0]=(dp[i][0]+dp[i-1][0])%MOD;
        }
        for(int j=1; j<s; j++)
        {
            for(int i=0; i<8; i++)
            {
                dp[i][j]=0;
                int cnt=d[j]+2*i;
                int minsend=max(0, cnt-7);
                int maxsend=min(7, cnt);
                if(minsend<=maxsend)
                {
                    dp[i][j]=(dp[i][j]+dp[maxsend][j-1])%MOD;
                    if(minsend>0)
                    {
                        dp[i][j]=(dp[i][j]-dp[minsend-1][j-1]+MOD)%MOD;
                    }
                }
                if(i>0) dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
            }
        }
        cout<<dp[0][s-1]<<'\n';*/
    }
    return 0;
}