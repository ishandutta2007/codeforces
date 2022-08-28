#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <map>
#include <functional>
#define SQR 800
#define MX 30005

using namespace std;

int dp[MX][SQR];
int cnt[MX];

int main()
{
	int n,d;
	scanf("%d %d",&n,&d);
	for(int i=0;i<n;i++)
	{
		int p;
		scanf("%d",&p);
		cnt[p]++;
	}
	memset(dp,-1,sizeof(dp));
	int mn=max(0,d-SQR/2);
	dp[d][d-mn]=0;
	int mx=0;
	for(int i=0;i<MX;i++)
	{
		for(int j=0;j<SQR;j++)
		{
			if(dp[i][j]==-1) continue;
			mx=max(mx,dp[i][j]+cnt[i]);
			int D=j+mn;
			if(j>0)
			{
				int nd=D-1;
				if(i+nd<MX) dp[i+nd][j-1]=max(dp[i+nd][j-1],dp[i][j]+cnt[i]);
			}
			if(j+1<SQR)
			{
				int nd=D+1;
				if(i+nd<MX) dp[i+nd][j+1]=max(dp[i+nd][j+1],dp[i][j]+cnt[i]);
			}
			int nd=D;
			if(i+nd<MX) dp[i+nd][j]=max(dp[i+nd][j],dp[i][j]+cnt[i]);
		}
	}
	printf("%d\n",mx);
	return 0;
}