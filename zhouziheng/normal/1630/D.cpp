#include<cstdio>
#include<algorithm>

using namespace std;

int gcd(int x,int y){return y?gcd(y,x%y):x;}

long long a[2000000];
long long dp[2000000][2];

int main()
{
	int T=0;scanf("%d",&T);
	while(T--)
	{
		int n=0,m=0;scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		int d=0;for(int i=1,b=0;i<=m;i++){scanf("%d",&b);d=gcd(b,d);}
		for(int i=n;i>=1;i--)
		{
			if(i+d>n)dp[i][0]=a[i],dp[i][1]=-a[i];
			else dp[i][0]=max(dp[i+d][0]+a[i],dp[i+d][1]-a[i]),
				dp[i][1]=max(dp[i+d][1]+a[i],dp[i+d][0]-a[i]);
		}
		long long sum1=0,sum2=0;for(int i=1;i<=d;i++)sum1+=dp[i][0],sum2+=dp[i][1];
		printf("%lld\n",max(sum1,sum2));
	}
}