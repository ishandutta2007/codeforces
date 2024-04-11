#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 200005
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;

struct edge
{
	int to;
	ll cost;
	edge(int to=0,ll cost=0):to(to),cost(cost){}
};
vector <edge> vec[SIZE];
vector <edge> tree[SIZE];
vector <ll> cycle;
bool now[SIZE];
bool memo[SIZE];
ll dep[SIZE];
bool use[SIZE];
ll ans[2];

void dfs(int v=0,int p=-1,ll d=0)
{
	use[v]=true;
	dep[v]=d;
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		if(e.to!=p)
		{
			if(!use[e.to])
			{
				tree[v].push_back(e);
				dfs(e.to,v,d^e.cost);
			}
			else
			{
				cycle.push_back(dep[e.to]^d^e.cost);
				//printf("%lld\n",cycle[cycle.size()-1]);
			}
		}
	}
}
P solve(int v,int bit)
{
	ll zero=1,one=0;
	for(int i=0;i<tree[v].size();i++)
	{
		edge e=tree[v][i];
		P p=solve(e.to,bit);
		if(e.cost>>bit&1) swap(p.first,p.second);
		ans[0]+=p.first*zero+p.second*one;
		ans[0]%=MOD;
		ans[1]+=p.first*one+p.second*zero;
		ans[1]%=MOD;
		zero+=p.first,one+=p.second;
		if(zero>=MOD) zero-=MOD;
		if(one>=MOD) one-=MOD;
	}
	return P(zero,one);
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		ll c;
		scanf("%d %d %lld",&a,&b,&c);
		a--,b--;
		vec[a].push_back(edge(b,c));
		vec[b].push_back(edge(a,c));
	}
	ll ret=0;
	for(int t=0;t<n;t++)
	{
		if(!use[t])
		{
			cycle.clear();
			dfs(t);
			vector <ll> vx;
			for(int j=0;j<cycle.size();j++) memo[j]=false;
			for(int i=60;i>=0;i--)
			{
				int pos=-1;
				for(int j=0;j<cycle.size();j++)
				{
					if(!memo[j]&&(cycle[j]>>i&1))
					{
						memo[j]=true;
						pos=j;
						break;
					}
				}
				if(pos==-1) continue;
				vx.push_back(cycle[pos]);
				for(int j=0;j<cycle.size();j++)
				{
					if(!memo[j]&&(cycle[j]>>i&1))
					{
						cycle[j]^=cycle[pos];
					}
				}
			}
			for(int i=0;i<=60;i++)
			{
				ans[0]=ans[1]=0;
				solve(t,i);
				ll A=1,B=0;
				for(int j=0;j<vx.size();j++)
				{
					ll na=A,nb=B;
					if(!(vx[j]>>i&1)) na+=A,nb+=B;
					else na+=B,nb+=A;
					if(na>=MOD) na-=MOD;
					if(nb>=MOD) nb-=MOD;
					A=na,B=nb;
				}
				//if(i<=5) printf("%d : %lld %lld : %lld %lld\n",i,ans[0],ans[1],A,B);
				ll way=(A*ans[1]+B*ans[0])%MOD;
				ret+=way*((1LL<<i)%MOD)%MOD;
				if(ret>=MOD) ret-=MOD;
			}
		}
	}
	printf("%lld\n",ret);
	return 0;
}