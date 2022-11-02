#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
ll MOD=998244353;
int n, m;
int a[200009];
ll w[200009];
ll sump=0;
ll sumn=0;

ll dp1[3009][3009];
ll dp2[3009][3009];

ll getinv(ll x)
{
    x%=MOD;
    ll kit=MOD-2;
    ll res=1;
    while(kit>0)
    {
        if(kit%2) res=(res*x)%MOD;
        kit/=2;
        x=(x*x)%MOD;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++)
    {
        cin>>w[i];
        if(a[i]==0) sumn+=w[i];
        else sump+=w[i];
    }
    for(int h=m; h>=0; h--)
    {
        for(int i=0; i<=h; i++)
        {
            int j=h-i;
            if(h==m)
            {
                dp1[i][j]=1;
                dp2[i][j]=1;
                continue;
            }
            dp1[i][j]=(dp1[i+1][j]*(sump+i+1))%MOD;
            dp1[i][j]=(dp1[i][j]*getinv(sump+sumn+i-j+MOD))%MOD;
            ll ppls=(dp1[i][j+1]*(sumn-j+MOD))%MOD;
            ppls=(ppls*getinv(sump+sumn+i-j+MOD))%MOD;
            dp1[i][j]=(dp1[i][j]+ppls)%MOD;

            dp2[i][j]=(dp2[i+1][j]*(sump+i))%MOD;
            dp2[i][j]=(dp2[i][j]*getinv(sump+sumn+i-j+MOD))%MOD;
            ll npls=(dp2[i][j+1]*(sumn-j-1+MOD))%MOD;
            npls=(npls*getinv(sump+sumn+i-j+MOD))%MOD;
            dp2[i][j]=(dp2[i][j]+npls)%MOD;
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(a[i]==0) cout<<(w[i]*dp2[0][0])%MOD<<'\n';
        else cout<<(w[i]*dp1[0][0])%MOD<<'\n';
    }

    return 0;
}