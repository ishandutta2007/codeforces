#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n, T;
ll MOD=1000000007;
ll ans;
int db[4];
ll dp[29][29][29][4];
int t[29];
int g[29];
void f(int x, int sum)
{
    if(x==n+1)
    {
        if(sum==T)
        {
            ans=(ans+dp[db[1]][db[2]][db[3]][0])%MOD;
        }
        return;
    }
    f(x+1, sum);
    db[g[x]]++;
    f(x+1, sum+t[x]);
    db[g[x]]--;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>T;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i]>>g[i];
    }
    for(int i=0; i<=15; i++)
    {
        for(int j=0; j<=15; j++)
        {
            for(int k=0; k<=15; k++)
            {
                for(int elozo=0; elozo<=3; elozo++)
                {
                    if(i==0 && j==0 && k==0)
                    {
                        dp[i][j][k][elozo]=1;
                        continue;
                    }
                    if(elozo!=1)
                    {
                        if(i>0)
                        {
                            ll plusz=((ll)(i)*dp[i-1][j][k][1])%MOD;
                            dp[i][j][k][elozo]=(dp[i][j][k][elozo]+plusz)%MOD;
                        }
                    }
                    if(elozo!=2)
                    {
                        if(j>0)
                        {
                            ll plusz=((ll)(j)*dp[i][j-1][k][2])%MOD;
                            dp[i][j][k][elozo]=(dp[i][j][k][elozo]+plusz)%MOD;
                        }
                    }
                    if(elozo!=3)
                    {
                        if(k>0)
                        {
                            ll plusz=((ll)(k)*dp[i][j][k-1][3])%MOD;
                            dp[i][j][k][elozo]=(dp[i][j][k][elozo]+plusz)%MOD;
                        }
                    }
                }
            }
        }
    }

    f(1, 0);
    cout<<ans<<endl;

    return 0;
}