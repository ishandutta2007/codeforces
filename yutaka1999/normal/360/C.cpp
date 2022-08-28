#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 2005
#define MOD 1000000007

using namespace std;
typedef long long int ll;

char str[SIZE];
ll dp[SIZE][SIZE];
ll sum[SIZE];

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	scanf("%s",&str);
	memset(dp,0,sizeof(dp));
	memset(sum,0,sizeof(sum));
	dp[0][0]=1;
	sum[0]=1;
	for(int i=0;i<n;i++)
	{
		int sm=str[i]-'a',lr=26-(sm+1);
		for(int j=0;j<=k;j++)
		{
			dp[i+1][j]=sum[j]*(ll) sm%MOD;
			for(int p=1;p<=i+1&&p*(n-i)<=j;p++)
			{
				dp[i+1][j]+=dp[i-p+1][j-p*(n-i)]*(ll) lr%MOD;
				dp[i+1][j]%=MOD;
			}
			sum[j]+=dp[i+1][j];
			sum[j]%=MOD;
		}
	}/*
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			printf("%llld ",dp[i][j]);
		}puts("");
	}*/
	ll ret=0;
	for(int i=0;i<=n;i++)
	{
		ret+=dp[i][k];
		ret%=MOD;
	}
	printf("%I64d\n",ret);
	return 0;
}