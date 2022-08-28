#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <cmath>
#include <string>
#define SIZE 405

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

ll dp[SIZE],fac[SIZE];
ll dp2[SIZE];
ll way[SIZE][SIZE];

int main()
{
	int T,MOD;
	scanf("%d %d",&T,&MOD);
	fac[0]=1;
	for(int i=1;i<SIZE;i++) fac[i]=fac[i-1]*(ll) i%MOD;
	way[0][0]=1;
	for(int i=1;i<SIZE;i++)
	{
		for(int j=1;j<SIZE;j++)
		{
			for(int k=1;k<=i;k++)
			{
				way[i][j]+=way[i-k][j-1]*fac[k]%MOD;
				if(way[i][j]>=MOD) way[i][j]-=MOD;
			}
		}
		dp[i]=fac[i];
		for(int j=3;j<i;j++)
		{
			dp[i]-=way[i][j]*dp[j]%MOD;
			if(dp[i]<0) dp[i]+=MOD;
		}
		if(i>2)
		{
			for(int j=1;j<i;j++)
			{
				dp[i]-=2LL*fac[j]*dp2[i-j]%MOD;
				if(dp[i]<0) dp[i]+=MOD;
			}
		}
		dp2[i]=fac[i];
		for(int j=1;j<i;j++)
		{
			dp2[i]-=fac[j]*dp2[i-j]%MOD;
			if(dp2[i]<0) dp2[i]+=MOD;
		}
		//if(i<=5) printf("%d : %lld %lld\n",i,dp[i],dp2[i]);
	}
	//return 0;
	while(T--)
	{
		int n;
		scanf("%d",&n);
		printf("%lld\n",dp[n]);
	}
	return 0;
}