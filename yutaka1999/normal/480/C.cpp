#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <stack>
#define SIZE 5005
#define MOD 1000000007

using namespace std;
typedef long long int ll;

int dp[2][SIZE];

int main()
{
	int n,a,b,k;
	scanf("%d %d %d %d",&n,&a,&b,&k);a--;b--;
	int pos=0;
	dp[pos][a]=1;
	for(int i=0;i<k;i++)
	{
		pos^=1;
		memset(dp[pos],0,sizeof(dp[pos]));
		for(int j=0;j<n;j++)
		{
			int d=abs(b-j)-1;
			if(d>=1)
			{
				dp[pos][j+1]+=dp[pos^1][j];
				if(dp[pos][j+1]>=MOD) dp[pos][j+1]-=MOD;
				dp[pos][min(j+d+1,n)]+=MOD-dp[pos^1][j];
				if(dp[pos][min(j+d+1,n)]>=MOD) dp[pos][min(j+d+1,n)]-=MOD;
				dp[pos][max(j-d,0)]+=dp[pos^1][j];
				if(dp[pos][max(j-d,0)]>=MOD) dp[pos][max(j-d,0)]-=MOD;
				dp[pos][j]+=MOD-dp[pos^1][j];
				if(dp[pos][j]>=MOD) dp[pos][j]-=MOD;
			}
		}
		for(int j=1;j<n;j++)
		{
			dp[pos][j]+=dp[pos][j-1];
			if(dp[pos][j]>=MOD) dp[pos][j]-=MOD;
		}
	}
	int ret=0;
	for(int j=0;j<n;j++)
	{
		ret+=dp[pos][j];
		if(ret>=MOD) ret-=MOD;
	}
	printf("%d\n",ret);
	return 0;
}