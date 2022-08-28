#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <stack>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

struct edge
{
	int to,cost;
	edge(int to=0,int cost=0):to(to),cost(cost){}
};
vector <edge> vec[SIZE];
bool use[SIZE];
int nd[SIZE];
int gt[SIZE];
int dep[SIZE];

//dS
void dfs(int v,int p)
{
	nd[v]=1;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i].to;
		if(to!=p&&!use[to])
		{
			dfs(to,v);
			nd[v]+=nd[to];
		}
	}
}
P center(int v,int p,int all)
{
	int mx=all-nd[v];
	P ret=P(SIZE,-1);
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i].to;
		if(to!=p&&!use[to])
		{
			ret=min(ret,center(to,v,all));
			mx=max(mx,nd[to]);
		}
	}
	ret=min(ret,P(mx,v));
	return ret;
}
ll mpow(ll m,ll t,ll M)
{
	if(t==0) return 1LL;
	ll ret=mpow(m,t/2,M);
	ret=ret*ret%M;
	if(t%2==1) ret=ret*m%M;
	return ret;
}
ll euler(ll M)
{
	ll ret=M;
	for(ll i=2;i*i<=M;i++)
	{
		if(M%i==0)
		{
			ret/=i;
			ret*=i-1;
			while(M%i==0) M/=i;
		}
	}
	if(M!=1)
	{
		ret/=M;
		ret*=M-1;
	}
	return ret;
}
ll M,em,bt;
map <int,int> mp;
ll ans,pl;
void dfs2(int v,int p=-1,ll A=1,ll B=0)
{
	//M|(A*x+B)  x mod M  ((M,10)=1)
	ll rv=M-(B*A%M);
	if(rv>=M) rv-=M;
	if(rv==0) pl++;
	ans+=mp[rv];
	//printf("%d %lld %lld : %lld %d\n",v,A,B,rv,mp[rv]);
	ll na=A*bt%M,nb=B*10LL%M;
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		if(e.to!=p&&!use[e.to])
		{
			ll mb=nb+e.cost;
			if(mb>=M) mb-=M;
			dfs2(e.to,v,na,mb);
		}
	}
}
void dfs3(int v,int p=-1,ll A=1,ll B=0)
{
	mp[B]++;
	ll na=A*10LL%M;
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		if(e.to!=p&&!use[e.to])
		{
			dfs3(e.to,v,na,(B+(ll) e.cost*A)%M);
		}
	}
}
void solve(int v)
{
	dfs(v,-1);
	int ct=center(v,-1,nd[v]).second;
	mp.clear();
	int t=10%M;
	for(int i=0;i<vec[ct].size();i++)
	{
		edge e=vec[ct][i];
		if(!use[e.to])
		{
			dfs2(e.to,ct,bt,e.cost);
			dfs3(e.to,ct,t,e.cost);
		}
	}
	ans+=mp[0];
	//puts("");
	mp.clear();
	pl=0;
	for(int i=((int) vec[ct].size())-1;i>=0;i--)
	{
		edge e=vec[ct][i];
		if(!use[e.to])
		{
			dfs2(e.to,ct,bt,e.cost);
			dfs3(e.to,ct,t,e.cost);
		}
	}
	ans+=pl;
	//printf("%d %lld\n",ct,ans);
	use[ct]=true;
	for(int i=0;i<vec[ct].size();i++)
	{
		edge e=vec[ct][i];
		if(!use[e.to]) solve(e.to);
	}
}
int main()
{
	int n;
	scanf("%d %lld",&n,&M);
	em=euler(M);
	bt=mpow(10,em-1,M);
	for(int i=0;i<n-1;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		c%=M;
		vec[a].push_back(edge(b,c));
		vec[b].push_back(edge(a,c));
	}
	ans=0;
	solve(0);
	printf("%lld\n",ans);
	return 0;
}