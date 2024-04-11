#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1001000
#define M 5001000
#define all 4194303
using namespace std;

int n,dp[M],num[N];
bool have[M];

int dfs(int now)
{
	if(dp[now]) return dp[now];
	if(have[now]) return dp[now]=now;
	int i,t;
	for(i=0;(1 << i)<all;i++)
	{
		if((1 << i)&now)
		{
			t=dfs(now^(1 << i));
			if(t!=-1) return dp[now]=t;
		}
	}
	return dp[now]=-1;
}

int main()
{
	dp[0]=-1;
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) scanf("%d",&num[i]),have[num[i]]=1;
	for(i=1;i<=n;i++)
	{
		printf("%d ",dfs(num[i]^all));
	}
}