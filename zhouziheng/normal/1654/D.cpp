#include<cstdio>
#include<vector>

using namespace std;

const long long MOD=998244353,G=3;
int add(int x,int y){return x+y>=MOD?x+y-MOD:x+y;}
int sub(int x,int y){return x>=y?x-y:x+MOD-y;}

long long fast_pow(long long b,long long p)
{
	long long ans=1;while(p){if(p&1)ans=ans*b%MOD;b=b*b%MOD;p>>=1;}
	return ans;
}
long long INV(long long x){return fast_pow(x,MOD-2);}

vector<int> dv[300000];

bool is_prm[300000];int prm_lst[300000],prm_cnt;

void init(int N)
{
	for(int i=2;i<=N;i++)is_prm[i]=1;
	for(int i=2;i<=N;i++)
	{
		if(is_prm[i]){prm_lst[++prm_cnt]=i;dv[i].push_back(i);}
		for(int j=1;j<=prm_cnt&&prm_lst[j]*i<=N;j++)
		{
			int u=prm_lst[j];is_prm[u*i]=0;dv[u*i]=dv[i];dv[u*i].push_back(u);
			if(i%u==0)
			{
				break;
			}
		}
	}
}

struct e
{
	int to,x,y;e(int _to=0,int _x=0,int _y=0):x(_x),y(_y),to(_to){}
};
vector<e> ed[300000];

long long dp[300000];int cnt[300000],maxn[300000];

void dfs_bas(int u,int f)
{
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i].to;if(v==f)continue;
		int x=ed[u][i].x,y=ed[u][i].y;
		dp[v]=dp[u]*y%MOD*INV(x)%MOD;
		for(int j=0;j<dv[y].size();j++)
		{
			cnt[dv[y][j]]++;
		}
		for(int j=0;j<dv[x].size();j++)
		{
			cnt[dv[x][j]]--;maxn[dv[x][j]]=max(maxn[dv[x][j]],-cnt[dv[x][j]]);
		}
		dfs_bas(v,u);
		for(int j=0;j<dv[y].size();j++)
		{
			cnt[dv[y][j]]--;
		}
		for(int j=0;j<dv[x].size();j++)
		{
			cnt[dv[x][j]]++;
		}
	}
}

int main()
{
	init(200000);
	int T=0;scanf("%d",&T);
	while(T--)
	{
		int n=0;scanf("%d",&n);
		for(int i=1,u=0,v=0,x=0,y=0;i<n;i++)
		{
			scanf("%d%d%d%d",&u,&v,&x,&y);ed[u].push_back(e(v,x,y)),ed[v].push_back(e(u,y,x));
		}
		dp[1]=1;
		dfs_bas(1,0);
		long long ans=0;for(int i=1;i<=n;i++)ans=add(ans,dp[i]);
		for(int i=1;i<=n;i++)ans=ans*fast_pow(i,maxn[i])%MOD;
		printf("%lld\n",ans);
		
		for(int i=1;i<=n;i++)ed[i].clear(),maxn[i]=dp[i]=cnt[i]=0;
	}
}