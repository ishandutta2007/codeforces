#include<cstdio>
#include<vector>

using namespace std;

const long long INF=1e18;

int deg[100];

struct e
{
	int to,val;e(int _to=0,int _val=0):to(_to),val(_val){}
};
vector<e> ed[100];

long long dp[100][2][100][100];

long long calc(long long *D,int c,long long x)
{
	int l=0,r=c;
	while(l<r)
	{
		int mid=(l+r+1)>>1;if(D[mid]>x)l=mid;else r=mid-1;
	}
	return l;
}

void Solve_son(int u,int c,int f)
{
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i].to;if(v==f)continue;
		Solve_son(v,c,u);
		if(deg[v]==1)
		{
			dp[v][0][c][0]=INF;
			for(int k=1;k<=c;k++)dp[v][0][c][k]=dp[v][1][c-k][c-k]+ed[u][i].val;
		}
		else
		{
			dp[v][0][c][0]=INF;
			for(int k=1;k<=c;k++)
			{
				long long L=0,R=INF;
				while(L!=R)
				{
					long long mid=(L+R)>>1;int tot=0;
					for(int j=0;j<ed[v].size();j++)
					{
						int x=ed[v][j].to;if(x==u)continue;
						tot+=calc(dp[x][0][c],k,mid);
					}
					if(tot>=k)L=mid+1;else R=mid;
				}
				dp[v][0][c][k]=L+ed[u][i].val;
			}
		}
	}
}

void Solve_fa(int u,int c,int f)
{
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i].to;if(v==f)continue;
		dp[v][1][c][0]=INF;
		if(deg[u]==1)
		{
			for(int k=1;k<=c;k++)dp[v][1][c][k]=dp[v][0][c-k][c-k]+ed[u][i].val;
		}
		else
		{
			for(int k=1;k<=c;k++)
			{
				long long L=0,R=INF;
				while(L!=R)
				{
					long long mid=(L+R)>>1;int tot=0;
					if(f)tot+=calc(dp[u][1][c],k,mid);
					for(int j=0;j<ed[u].size();j++)
					{
						int x=ed[u][j].to;if(x==v||x==f)continue;
						tot+=calc(dp[x][0][c],k,mid);
					}
					if(tot>=k)L=mid+1;else R=mid;
				}
				dp[v][1][c][k]=L+ed[u][i].val;
			}
		}
		
		Solve_fa(v,c,u);
	}
}

int cnt[100];
void dfs_bas(int u,int f)
{
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i].to;if(v==f)continue;
		dfs_bas(v,u);cnt[u]+=cnt[v];
	}
}

int main()
{
	int n=0;scanf("%d",&n);
	for(int i=1,u=0,v=0,w=0;i<n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);ed[u].push_back(e(v,w)),ed[v].push_back(e(u,w));deg[u]++,deg[v]++;
	}
	int s=0,m=0;scanf("%d%d",&s,&m);
	for(int i=1;i<=m;i++)
	{
		Solve_son(s,i,0);Solve_fa(s,i,0);
		/*for(int u=1;u<=n;u++)
		{
			printf("0 %d: \n",u);for(int j=0;j<=i;j++)printf("%lld ",dp[u][0][i][j]);puts("");
		}
		for(int u=1;u<=n;u++)
		{
			printf("1 %d: \n",u);for(int j=0;j<=i;j++)printf("%lld ",dp[u][1][i][j]);puts("");
		}
		puts("\n");*/
	}
	for(int i=1,x=0;i<=m;i++){scanf("%d",&x);cnt[x]++;}
	dfs_bas(s,0);
	long long ans=INF;
	for(int i=0;i<ed[s].size();i++)ans=min(ans,dp[ed[s][i].to][0][m][cnt[ed[s][i].to]]);
	printf("%lld",ans);
}