#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int n, m;
char t[1009][1009];
ll dp[1009][1009];
int meddig[1009][1009];
int lng[1009][1009];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll ans=0;

    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>t[i][j];
        }
    }
    for(int j=m; j>=1; j--)
    {
        for(int i=n; i>=1; i--)
        {
            if(i==n) meddig[i][j]=i;
            else
            {
                if(t[i][j]==t[i+1][j]) meddig[i][j]=meddig[i+1][j];
                else meddig[i][j]=i;
            }
            //cout<<i<<": "<<j<<". "<<meddig[i][j]<<endl;
            int df=meddig[i][j]-i+1;
            int s2=i+df;
            if(meddig[s2][j]+1!=s2+df) continue;
            //cout<<i<<":"<<j<<endl;
            int s3=s2+df;
            if(meddig[s3][j]+1<s3+df) continue;
            dp[i][j]=1;
            lng[i][j]=df;
            if(j<m)
            {
                if(t[i][j]==t[i][j+1] && t[s2][j]==t[s2][j+1] && t[s3][j]==t[s3][j+1] && lng[i][j]==lng[i][j+1])
                {
                    dp[i][j]+=dp[i][j+1];
                }
            }
            ans+=dp[i][j];
        }
    }
    cout<<ans<<endl;
    return 0;
}