#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n;
int test;
ll a[300009];
ll b[300009];
ll dp[300009][3];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i]>>b[i];
        }
        dp[n+1][0]=0;
        dp[n+1][1]=0;
        dp[n+1][2]=0;
        for(int i=n; i>1; i--)
        {
            for(int j=0; j<=2; j++)
            {
                dp[i][j]=-1;
                for(int k=0; k<=2; k++)
                {
                    if(a[i-1]+j==a[i]+k) continue;
                    ll ww=k*b[i]+dp[i+1][k];
                    if(dp[i][j]==-1 || ww<dp[i][j]) dp[i][j]=ww;
                }
            }
        }
        ll ans=dp[2][0];
        ans=min(ans, b[1]+dp[2][1]);
        ans=min(ans, b[1]+b[1]+dp[2][2]);
        cout<<ans<<endl;
    }

    return 0;
}