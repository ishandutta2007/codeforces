#include <cstdio>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#define BT 20
#define SIZE 200005

using namespace std;

int dp[SIZE][BT];
int ans[SIZE][BT];
int cur[SIZE][BT];
char str[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",&str);
	memset(dp,0,sizeof(dp));
	for(int t=1;(1<<t)<=n;t++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=t;j++) cur[i][j]=0;
		}
		for(int i=0;i+(1<<t)<=n;i++)
		{
			for(int j=0;j<t;j++)
			{
				cur[i][j]=dp[i][j]+dp[i+(1<<(t-1))][j];
			}
			if(str[i+(1<<(t-1))]==str[i+(1<<(t-1))-1]) cur[i][t]++;
		}
		for(int i=0;i<n;i++)
		{
			ans[i][t]=0;
			for(int j=0;j<=t;j++)
			{
				dp[i][j]=cur[i][j];
				int a=dp[i][j],b=(1<<(t-j))-a;
				ans[i][t]+=min(a,b);
			}
		}
	}
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		int t=0;
		while((1<<t)<r-l+1) t++;
		printf("%d\n",(ans[l][t]+1)/2);
	}
	return 0;
}