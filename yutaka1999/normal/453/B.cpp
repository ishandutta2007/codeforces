#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define MX 100000000
#define BT 1<<16

using namespace std;

int pr[16]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
int bit[65];
int dp[105][BT];
int bef[105][BT];
int ans[105];

int main()
{
	int n;
	scanf("%d",&n);
	int pos=0;
	for(int i=1;i<59;i++)
	{
		bit[i]=0;
		for(int j=0;j<16;j++)
		{
			if(i%pr[j]==0)
			{
				bit[i]|=1<<j;
			}
		}
	}
	for(int i=0;i<BT;i++)
	{
		dp[0][i]=MX;
		bef[0][i]=-1;
	}
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		for(int j=0;j<BT;j++)
		{
			dp[i][j]=MX;
			bef[i][j]=-1;
		}
		for(int S=0;S<BT;S++)
		{
			for(int j=1;j<59;j++)
			{
				if((S|bit[j])==S+bit[j])
				{
					int T=S|bit[j];
					if(dp[i][T]>dp[i-1][S]+abs(a-j))
					{
						dp[i][T]=dp[i-1][S]+abs(a-j);
						bef[i][T]=j;
					}
				}
			}
		}
	}
	int mn=MX;
	for(int j=0;j<BT;j++) mn=min(mn,dp[n][j]);
	for(int j=0;j<BT;j++)
	{
		if(mn==dp[n][j])
		{
			int sz=n-1,S=j;
			for(int i=n;i>=1;i--)
			{
				ans[sz--]=bef[i][S];
				S-=bit[bef[i][S]];
			}
			for(int i=0;i<n;i++)
			{
				if(i!=0) printf(" ");
				printf("%d",ans[i]);
			}puts("");
			break;
		}
	}
	return 0;
}