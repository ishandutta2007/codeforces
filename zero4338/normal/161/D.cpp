#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=5e4+5;
long long dp[maxn][505];
long long ans;
int n,k;
int head[maxn],ver[maxn<<1],Next[maxn<<1];
int tot;
void add(int x,int y)
{
	ver[++tot]=y;Next[tot]=head[x];
	head[x]=tot;
}
void dfs(int now,int fa)
{
	dp[now][0]=1;
	for(int i=head[now];i;i=Next[i])
	{
		if(ver[i]!=fa)
		{
			dfs(ver[i],now);
			for(int j=0;j<k;j++)
				ans+=dp[ver[i]][j]*dp[now][k-j-1];
			for(int j=0;j<k;j++)
			    dp[now][j+1]+=dp[ver[i]][j];
		}
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n-1;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	dfs(1,1);
	printf("%I64d",ans);
	return 0;
}