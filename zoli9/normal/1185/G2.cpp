#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int db[4];
int total[4];
int n;
int TT;
int t[59];
int g[59];
ll MOD=1e9+7;
ll a[59][2509]; // db1, total
ll bc[59][59][2509];
ll dp[59][59][59][4]; //1, 2, 3, last
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>TT;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i]>>g[i];
        db[g[i]]++;
        total[g[i]]+=t[i];
    }
    a[0][0]=1;
    bc[0][0][0]=1;
    for(int i=1; i<=n; i++)
    {
        if(g[i]==1)
        {
            for(int db1=db[1]; db1>=1; db1--)
            {
                for(int tot=total[1]; tot>=t[i]; tot--)
                {
                    a[db1][tot]+=a[db1-1][tot-t[i]];
                    a[db1][tot]%=MOD;
                }
            }
        }
        else
        {
            for(int db2=db[2]; db2>=0; db2--)
            {
                for(int db3=db[3]; db3>=0; db3--)
                {
                    for(int tot=total[2]+total[3]; tot>=t[i]; tot--)
                    {
                        if(g[i]==2 && db2>0)
                        {
                            bc[db2][db3][tot]+=bc[db2-1][db3][tot-t[i]];
                            bc[db2][db3][tot]%=MOD;
                        }
                        if(g[i]==3 && db3>0)
                        {
                            bc[db2][db3][tot]+=bc[db2][db3-1][tot-t[i]];
                            bc[db2][db3][tot]%=MOD;
                        }
                    }
                }
            }
        }
    }
    for(int i=0; i<=db[1]; i++)
    {
        for(int j=0; j<=db[2]; j++)
        {
            for(int k=0; k<=db[3]; k++)
            {
                for(int elozo=0; elozo<=3; elozo++)
                {
                    if(i==0 && j==0 && k==0)
                    {
                        dp[i][j][k][elozo]=1;
                        continue;
                    }
                    if(elozo!=1 && i>0)
                    {
                        ll plusz=((ll)(i)*dp[i-1][j][k][1])%MOD;
                        dp[i][j][k][elozo]=(dp[i][j][k][elozo]+plusz)%MOD;
                    }
                    if(elozo!=2 && j>0)
                    {
                        ll plusz=((ll)(j)*dp[i][j-1][k][2])%MOD;
                        dp[i][j][k][elozo]=(dp[i][j][k][elozo]+plusz)%MOD;
                    }
                    if(elozo!=3 && k>0)
                    {
                        ll plusz=((ll)(k)*dp[i][j][k-1][3])%MOD;
                        dp[i][j][k][elozo]=(dp[i][j][k][elozo]+plusz)%MOD;
                    }
                }
            }
        }
    }
    ll ans=0;
    for(int i=0; i<=db[1]; i++)
    {
        for(int j=0; j<=db[2]; j++)
        {
            for(int k=0; k<=db[3]; k++)
            {
                for(int total1=0; total1<=min(TT, total[1]); total1++)
                {
                    if(a[i][total1]>0 && bc[j][k][TT-total1]>0 && dp[i][j][k][0]>0)
                    {
                        ans=(ans+(((a[i][total1]*bc[j][k][TT-total1])%MOD)*dp[i][j][k][0])%MOD)%MOD;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}