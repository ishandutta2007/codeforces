#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 205
#define MX 1005
#define MOD 1000000007

using namespace std;
typedef long long int ll;

int A[SIZE];
int dp[2][SIZE][MX];

int main()
{
	int n,K;
	scanf("%d %d",&n,&K);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	sort(A,A+n);
	int pos=0;
	memset(dp[pos],0,sizeof(dp[pos]));
	dp[pos][0][0]=1;
	for(int i=0;i<n;i++)
	{
		pos^=1;
		memset(dp[pos],0,sizeof(dp[pos]));
		int diff=A[i]-(i==0?0:A[i-1]);
		for(int j=0;j<=i;j++)
		{
			for(int k=0;k<=K;k++)
			{
				if(dp[pos^1][j][k]==0) continue;
				int nxt=k+j*diff;
				if(nxt>K) continue;
				if(j>0)
				{
					dp[pos][j-1][nxt]+=(ll) dp[pos^1][j][k]*(ll) j%MOD;
					if(dp[pos][j-1][nxt]>=MOD) dp[pos][j-1][nxt]-=MOD;
				}
				dp[pos][j+1][nxt]+=dp[pos^1][j][k];
				if(dp[pos][j+1][nxt]>=MOD) dp[pos][j+1][nxt]-=MOD;
				dp[pos][j][nxt]+=(ll) dp[pos^1][j][k]*(ll) (j+1)%MOD;
				if(dp[pos][j][nxt]>=MOD) dp[pos][j][nxt]-=MOD;
			}
		}
	}
	int ret=0;
	for(int i=0;i<=K;i++)
	{
		ret+=dp[pos][0][i];
		if(ret>=MOD) ret-=MOD;
	}
	printf("%d\n",ret);
	return 0;
}