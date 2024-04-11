#include<bits/stdc++.h>
#define maxh 21
#define maxn 1000050
#define F(i)	fa[0][i]
using namespace std;

int n,m;

int tot;
int head[maxn],edge[maxn],nxt[maxn];

int fa[maxh][maxn];

void join(int u,int v)
{
	edge[tot]=v; nxt[tot]=head[u]; head[u]=tot++;
}

void init()
{
	tot=0;
	memset(head,-1,sizeof(head));
	
	scanf("%d%d",&n,&m);
	for (int i=2;i<=n;++i) 
	{
		scanf("%d",&F(i));
		join(F(i),i);
	}
}


int Fk(int v)
{
	for (int i=0;i<maxh;++i)
		if (m>>i&1)
			v=fa[i][v];
	return v;
}

int dep[maxn]={maxn};
int leaf[maxn];

int dp[maxn][2];

int Min(int i,int j)
{
	return dep[i]<dep[j]?i:j;
}

int dfs(int i)
{
	for (int j=1;fa[j-1][i];++j)
		fa[j][i]=fa[j-1][fa[j-1][i]];
	
	int mx=0;
	for (int k=head[i];~k;k=nxt[k])
	{
		int j=edge[k];
		dep[j]=dep[i]+1;
		dfs(j);
		if (dep[leaf[j]]-dep[i]<=m)
		{
			dp[i][0]+=dp[j][0];
			mx=max(mx,dp[j][1]-dp[j][0]);
			leaf[i]=Min(leaf[j],leaf[i]);
		} else	mx=max(mx,dp[j][1]);
	}
	
	if (!~head[i])
		leaf[i]=i,dp[i][0]=1;
	dp[i][1]=max(dp[i][1],dp[i][0]+mx);
	
//	cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<" "<<leaf[i]<<" "<<mx<<endl;
	
	return leaf[i];
}

void solve()
{
	dfs(1); 
	printf("%d\n",dp[1][1]);
} 

int main()
{
//	freopen("c.in","r",stdin);
	init();
	solve();
	return 0;
}