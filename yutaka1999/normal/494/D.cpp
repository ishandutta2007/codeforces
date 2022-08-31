#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005
#define MOD 1000000007
#define BT 20

using namespace std;
typedef long long int ll;

struct edge
{
	int to,cost;
	edge(int to=0,int cost=0):to(to),cost(cost){}
};
vector <edge> vec[SIZE];
ll dp[SIZE],dp2[SIZE],sum[SIZE],sum2[SIZE];//d(i,v)^2,d(i,v)
int nd[SIZE],par[SIZE][BT],dep[SIZE];
ll DP[SIZE];
int n;

void dfs(int v=0,int p=-1,int d=0,ll s=0)
{
	s%=MOD;
	par[v][0]=p;
	dep[v]=d;
	DP[v]=s;
	dp[v]=sum[v]=0;
	nd[v]=1;
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		if(e.to!=p)
		{
			dfs(e.to,v,d+1,s+(ll) e.cost);
			dp[v]+=dp[e.to]+2*(ll) e.cost*sum[e.to]%MOD+(ll) nd[e.to]*(ll) e.cost%MOD*(ll) e.cost%MOD;
			sum[v]+=sum[e.to]+(ll) nd[e.to]*(ll) e.cost%MOD;
			nd[v]+=nd[e.to];
			dp[v]%=MOD;
			sum[v]%=MOD;
		}
	}
	dp2[v]=dp[v];
	sum2[v]=sum[v];
}
void make(int v=0,int p=-1)
{
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		if(e.to!=p)
		{
			int d=n-nd[e.to];
			ll s=sum2[v]-(sum[e.to]+(ll) nd[e.to]*(ll) e.cost%MOD)+2*MOD;
			s%=MOD;
			ll t=2*(ll) e.cost*sum[e.to]%MOD+(ll) nd[e.to]*(ll) e.cost%MOD*(ll) e.cost%MOD;
			t%=MOD;
			dp2[e.to]=(dp2[v]-t)+2*s*(ll) e.cost%MOD+(ll) d*(ll) e.cost%MOD*(ll) e.cost%MOD+MOD;
			dp2[e.to]%=MOD;
			sum2[e.to]+=s+(ll) d*(ll) e.cost%MOD;
			sum2[e.to]%=MOD;
			make(e.to,v);
		}
	}
}
void LCAmake()
{
	for(int i=0;i+1<BT;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(par[j][i]==-1) par[j][i+1]=-1;
			else par[j][i+1]=par[par[j][i]][i];
		}
	}
}
int LCA(int a,int b)
{
	if(dep[a]>dep[b]) swap(a,b);//dep[a]<=dep[b]
	for(int i=BT-1;i>=0;i--)
	{
		if(par[b][i]==-1||dep[par[b][i]]<dep[a]) continue;
		b=par[b][i];
	}
	if(a==b) return a;
	for(int i=BT-1;i>=0;i--)
	{
		if(par[a][i]!=par[b][i])
		{
			a=par[a][i];
			b=par[b][i];
		}
	}
	return par[a][0];
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);a--;b--;
		vec[a].push_back(edge(b,c));
		vec[b].push_back(edge(a,c));
	}
	dfs();
	make();
	LCAmake();
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		int p=LCA(a,b);
		if(p!=b)
		{
			ll D=DP[a]+DP[b]-2*DP[p]+2*MOD;
			D%=MOD;
			ll pa=dp[b]+sum[b]*2LL*D%MOD+(ll) nd[b]*D%MOD*D%MOD;
			pa%=MOD;
			printf("%I64d\n",(pa*2-dp2[a]+MOD)%MOD);
		}
		else
		{
			ll D=DP[a]-DP[b]+MOD;
			D%=MOD;
			ll pa=(dp2[b]-dp[b]+MOD)+(sum2[b]-sum[b]+MOD)*2LL*D%MOD+(ll) (n-nd[b])*D%MOD*D%MOD;
			pa%=MOD;
			printf("%I64d\n",(dp2[a]-2*pa+2*MOD)%MOD);
		}
	}
	return 0;
}