#include<cstdio>
#include<algorithm>

using namespace std;

int dp[2][30000];int a[300],b[300];

int main()
{
	int T=0;scanf("%d",&T);
	while(T--)
	{
		int n=0;scanf("%d",&n);
		int sum=0,sum2=0;for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i],sum2+=a[i]*a[i];
		for(int i=1;i<=n;i++)scanf("%d",&b[i]),sum+=b[i],sum2+=b[i]*b[i];
		
		for(int i=0;i<=sum;i++)dp[0][i]=0;dp[0][0]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=sum;j++){dp[1][j]=dp[0][j];dp[0][j]=0;}
			for(int j=0;j<=sum;j++)if(dp[1][j])dp[0][j+a[i]]=dp[0][j+b[i]]=1;
		}
		int ans=1e9;for(int i=0;i<=sum;i++)if(dp[0][i])ans=min(ans,(i*i+(sum-i)*(sum-i)));
		printf("%d\n",ans+(n-2)*sum2);
	}
}