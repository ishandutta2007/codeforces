#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 5005
#define MX 300005

using namespace std;
typedef long long int ll;

ll dp[2][SIZE];
int A[MX];

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	sort(A,A+n);
	int zn=n%k;
	int pos=0;
	memset(dp,-1,sizeof(dp));
	dp[pos][0]=0;
	for(int i=0;i<k;i++)
	{
		pos^=1;
		memset(dp[pos],-1,sizeof(dp[pos]));
		for(int j=0;j<=min(i,zn);j++)
		{
			if(dp[pos^1][j]==-1) continue;
			int cnt=j*(n/k+1)+(i-j)*(n/k);
			if(cnt+n/k<=n)
			{
				ll vl=A[cnt+n/k-1]-A[cnt];
				if(dp[pos][j]==-1) dp[pos][j]=dp[pos^1][j]+vl;
				else dp[pos][j]=min(dp[pos][j],dp[pos^1][j]+vl);
			}
			if(cnt+n/k+1<=n)
			{
				ll vl=A[cnt+n/k]-A[cnt];
				if(dp[pos][j+1]==-1) dp[pos][j+1]=dp[pos^1][j]+vl;
				else dp[pos][j+1]=min(dp[pos][j+1],dp[pos^1][j]+vl);
			}
		}
	}
	printf("%I64d\n",dp[pos][zn]);
	return 0;
}