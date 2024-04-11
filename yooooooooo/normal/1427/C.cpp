#include<cstdio>
#include<algorithm>
using namespace std;
int ans=0;
int r,n,x[100005],y[100005],t[100005],dp[100005],mx[100005];
const int inf=1e9;
int main()
{
	scanf("%d%d",&r,&n);
	for(int i=1;i<=n;i++)scanf("%d%d%d",&t[i],&x[i],&y[i]);
	x[0]=1;y[0]=1;dp[0]=mx[0]=0;t[0]=0;
	for(int i=1;i<=n;i++)
	{
		dp[i]=-inf;
		int j;
		for(j=i-1;j>=0&&t[i]-t[j]<2*r;j--)if(abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j])dp[i]=max(dp[i],dp[j]+1);
		if(j>=0)dp[i]=max(dp[i],mx[j]+1);
		mx[i]=max(mx[i-1],dp[i]);
		//printf("%d %d %d\n",i,j,dp[i]);
	}
	printf("%d\n",mx[n]);
	return 0;
}