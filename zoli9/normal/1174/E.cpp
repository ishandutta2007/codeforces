#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
vector<pair<pii, pii> > ans;
int n;
int MOD=1e9+7;
int dp[1000009][20][2];
int hh[2]={1, 3};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int ketto=0;
    while((1<<ketto)<=n) ketto++;
    ketto--;
    dp[1][ketto][0]=1;
    if((1<<ketto)*3/2<=n) dp[1][ketto-1][1]=1;
    for(ll i=1; i<n; i++)
    {
        for(int x=0; x<=ketto; x++)
        {
            for(int y=0; y<=1; y++)
            {
                int marad=n/((1<<x)*hh[y]);
                int maradx, marady;
                if(x>0) maradx=n/((1<<(x-1))*hh[y]);
                if(y>0) marady=n/((1<<x)*hh[y-1]);
                dp[i+1][x][y]=(dp[i+1][x][y]+(1ll*dp[i][x][y]*(marad-i))%MOD)%MOD;
                if(x>0) dp[i+1][x-1][y]=(dp[i+1][x-1][y]+(1ll*dp[i][x][y]*(maradx-marad))%MOD)%MOD;
                if(y>0) dp[i+1][x][y-1]=(dp[i+1][x][y-1]+(1ll*dp[i][x][y]*(marady-marad))%MOD)%MOD;
            }
        }
    }
    cout<<dp[n][0][0]<<endl;

    return 0;
}