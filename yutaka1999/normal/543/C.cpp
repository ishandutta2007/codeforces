#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 22
#define BT (1<<21)
#define INF 1000000005

using namespace std;

int dp[BT];
int A[SIZE][SIZE],mn[SIZE];
char mp[SIZE][SIZE];
int cnt[30];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%s",&mp[i]);
	for(int i=0;i<n;i++)
	{
		mn[i]=INF;
		for(int j=0;j<m;j++)
		{
			scanf("%d",&A[i][j]);
			mn[i]=min(mn[i],A[i][j]);
		}
	}
	for(int S=0;S<1<<n;S++) dp[S]=INF;
	dp[0]=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<26;j++)
		{
			int S=0,sum=0,mx=0;
			for(int k=0;k<n;k++)
			{
				if(mp[k][i]-'a'==j)
				{
					S|=1<<k;
					sum+=A[k][i];
					mx=max(mx,A[k][i]);
				}
			}
			if(S>0)
			{
				sum-=mx;
				for(int T=(1<<n)-1;T>=0;T--)
				{
					dp[T|S]=min(dp[T|S],dp[T]+sum);
				}
			}
		}
	}
	int ret=INF;
	for(int S=0;S<1<<n;S++)
	{
		if(dp[S]==INF) continue;
		int sum=dp[S];
		for(int i=0;i<n;i++)
		{
			if(!(S>>i&1))
			{
				sum+=mn[i];
			}
		}
		ret=min(ret,sum);
	}
	printf("%d\n",ret);
	return 0;
}