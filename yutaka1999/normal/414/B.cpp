#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define MOD 1000000007
#define SIZE 2005

using namespace std;

int dp[2][SIZE];

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int pos=0;
	memset(dp[pos],0,sizeof(dp[pos]));
	for(int i=1;i<=n;i++) dp[pos][i]=1;
	for(int i=1;i<=k-1;i++)
	{
		memset(dp[pos^1],0,sizeof(dp[pos^1]));
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j+=i)
			{
				dp[pos^1][j]+=dp[pos][i];
				if(dp[pos^1][j]>=MOD) dp[pos^1][j]-=MOD;
			}
		}
		pos^=1;
	}
	int ret=0;
	for(int i=1;i<=n;i++)
	{
		ret+=dp[pos][i];
		if(ret>=MOD) ret-=MOD;
	}
	printf("%d\n",ret);
	return 0;
}