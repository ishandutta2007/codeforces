#include<bits/stdc++.h>
#define db double
#define N 1010
using namespace std;

int n,m,num[N];
db dp[N][N],ans;

int main()
{
    int i,j,p,q;
    cin>>n>>m;
    for(i=1;i<=n;i++) scanf("%d",&num[i]);
    for(i=1;i<=n;i++) for(j=1;j<=n;j++) dp[i][j]=(num[i]>num[j]);
    for(i=1;i<=m;i++)
    {
	scanf("%d%d",&p,&q);
	for(j=1;j<=n;j++)
	{
	    dp[j][p]=dp[j][q]=(dp[j][p]+dp[j][q])*0.5;
	    dp[p][j]=dp[q][j]=1.0-dp[j][p];
	}
	dp[p][q]=dp[q][p]=0.5;
    }
    for(i=1;i<=n;i++)
    {
	for(j=i+1;j<=n;j++)
	{
	    ans+=dp[i][j];
	}
    }
    printf("%.8f",ans);
}