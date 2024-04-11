#include<bits/stdc++.h>
#define maxn 300500
#define modu 998244353
using namespace std;
typedef long long LL;

int n;

int tot;
int head[maxn],edge[maxn<<1],nxt[maxn<<1];

int d[maxn];

void join(int u,int v)
{
	++d[u],++d[v];
	edge[tot]=v; nxt[tot]=head[u]; head[u]=tot++;
	edge[tot]=u; nxt[tot]=head[v]; head[v]=tot++;
}

void init()
{
	tot=0;
	memset(head,-1,sizeof(head));
	
	scanf("%d",&n);
	for (int k=1;k<n;++k)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		join(u,v);
	}
}

LL inv(LL a)
{
	LL ans=1;
	for (int k=modu-2;k;k>>=1)
	{
		if (k&1)
			ans=ans*a%modu;
		a=a*a%modu;
	}
	return ans;
}

void upd(LL &x,LL y)
{
	y%=modu;
	if ((x+=y)>=modu)
		x-=modu;
}

LL dp[maxn][3];

void dfs(int i,int fa=0)
{
	dp[i][0]=0;
	dp[i][2]=1;
	LL even=1,odd=1;
	for (int k=head[i];~k;k=nxt[k])
	{
		int j=edge[k];
		if (fa==j)	continue;
		dfs(j,i);
		odd=odd*(dp[j][1]*2+dp[j][2])%modu;
//		even=even*(dp[j][0]*2+dp[j][2])%modu;
		dp[i][0]=(dp[i][0]*(dp[j][1]*2+dp[j][2])+even*dp[j][1])%modu;
		even=even*(dp[j][1]+dp[j][2])%modu;
		
		dp[i][2]=dp[i][2]*(dp[j][1]+dp[j][2])%modu;
	}
	
	for (int k=head[i];~k;k=nxt[k])
	{
		int j=edge[k];
		if (fa==j)	continue;
//		cout<<i<<" "<<j<<" "<<dp[j][1]*2+dp[j][2]<<" "<<dp[j][0]+dp[j][2]<<endl;
		upd(dp[i][1],odd*inv(dp[j][1]*2+dp[j][2])%modu*(dp[j][0]+dp[j][2]));
//		upd(dp[i][0],even*inv(dp[j][0]*2+dp[j][2])%modu*dp[j][1]);
	}
	
//	upd(dp[i][0],modu-even);
	
//	printf("%d %lld %lld %lld %lld %lld\n",i,dp[i][0],dp[i][1],dp[i][2],even,odd);
}

void solve()
{
	dfs(1);
	printf("%lld\n",(dp[1][1]+dp[1][2])%modu);
}

int main()
{
	init();
	solve();
	return 0;
}