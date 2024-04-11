#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MN 100
#define N 300100
#define M 110
using namespace std;

int n,ans=INF,num[N],dp[N][M];

inline void Min(int &u,int v){if(v<u) u=v;}
int main()
{
    memset(dp,0x3f,sizeof(dp));
    int i,j,t;
    cin>>n;
    for(i=1;i<=n;i++) scanf("%d",&num[i]);
    dp[0][0]=0;
    for(i=0;i<n;i++)
    {
	for(j=0;j<=MN;j++)
	{
	    t=min(num[i+1]/100,j);
	    Min(dp[i+1][j+num[i+1]/1000],dp[i][j]+num[i+1]);
	    Min(dp[i+1][j-t],dp[i][j]+num[i+1]-t*100);
	}
    }
    for(i=0;i<=MN;i++) Min(ans,dp[n][i]);
    cout<<ans;
}