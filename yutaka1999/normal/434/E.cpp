#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#define SIZE 100005

using namespace std;
typedef pair <int,int> P;
typedef long long int ll;

vector <int> vec[SIZE];
int nd[SIZE];
bool use[SIZE];
ll cnt[SIZE];
ll ans[SIZE];
ll back[SIZE];
ll vl[SIZE];
ll dep1[SIZE];
ll dep2[SIZE];
map <ll,int> mp;
ll MOD;

ll mpow(ll m,ll t)
{
	if(t==0) return 1LL;
	ll ret=mpow(m,t/2);
	ret=ret*ret%MOD;
	if(t%2==1) ret=ret*m%MOD;
	return ret;
}
ll getinv(ll X)
{
	return mpow(X,MOD-2);
}
void dfs(int v,int p)
{
	nd[v]=1;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p&&!use[to])
		{
			dfs(to,v);
			nd[v]+=nd[to];
		}
	}
}
P center(int v,int p,int all)
{
	P ret=P(all,v);
	int mx=all-nd[v];
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p&&!use[to])
		{
			ret=min(ret,center(to,v,all));
			mx=max(mx,nd[to]);
		}
	}
	ret=min(ret,P(mx,v));
	return ret;
}
void dfs1(int v,int p,ll dep,ll k,ll t,ll goal)
{
	dep+=(ll) vl[v]*(ll) t%MOD;
	if(dep>=MOD) dep-=MOD;
	ans[v]+=mp[(MOD-dep+goal)%MOD];
	dep1[v]=(MOD-dep+goal)%MOD;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p&&!use[to])
		{
			dfs1(to,v,dep,k,t*k%MOD,goal*k%MOD);
		}
	}
}
void dfs2(int v,int p,ll dep,ll k,ll t)
{
	dep+=(ll) vl[v]*(ll) t%MOD;
	if(dep>=MOD) dep-=MOD;
	mp[dep]++;
	dep2[v]=dep;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p&&!use[to])
		{
			dfs2(to,v,dep,k,t*k%MOD);
		}
	}
}
void dfs3(int v,int p)
{
	back[v]+=mp[dep2[v]];
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p&&!use[to])
		{
			dfs3(to,v);
		}
	}
}
void dfs4(int v,int p)
{
	mp[dep1[v]]++;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p&&!use[to])
		{
			dfs4(to,v);
		}
	}
}
void solve(int v,ll k,ll goal)
{
	dfs(v,-1);
	int ct=center(v,-1,nd[v]).second;
	use[ct]=true;
	mp.clear();
	mp[vl[ct]]++;
	ll inv=getinv(k);
	for(int i=0;i<vec[ct].size();i++)
	{
		int to=vec[ct][i];
		if(!use[to])
		{
			dfs1(to,ct,0,inv,inv,goal*inv%MOD);
			dfs2(to,ct,vl[ct],k,k);
		}
	}
	ans[ct]+=mp[goal];
	mp.clear();
	for(int i=0;i<vec[ct].size();i++)
	{
		int to=vec[ct][vec[ct].size()-i-1];
		if(!use[to])
		{
			dfs1(to,ct,0,inv,inv,goal*inv%MOD);
			dfs2(to,ct,vl[ct],k,k);
		}
	}
	mp.clear();
	mp[goal]++;
	for(int i=0;i<vec[ct].size();i++)
	{
		int to=vec[ct][i];
		if(!use[to])
		{
			dfs3(to,ct);
			dfs4(to,ct);
		}
	}
	back[ct]+=mp[vl[ct]];
	mp.clear();
	for(int i=0;i<vec[ct].size();i++)
	{
		int to=vec[ct][vec[ct].size()-i-1];
		if(!use[to])
		{
			dfs3(to,ct);
			dfs4(to,ct);
		}
	}
	for(int i=0;i<vec[ct].size();i++)
	{
		int to=vec[ct][i];
		if(!use[to])
		{
			solve(to,k,goal);
		}
	}
}
int main()
{
	int n;
	ll goal,k;
	scanf("%d %lld %lld %lld",&n,&MOD,&k,&goal);
	for(int i=0;i<n;i++) scanf("%lld",&vl[i]);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--,b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	solve(0,k,goal);
	//for(int i=0;i<n;i++) printf("%lld ",ans[i]);puts("");
	//for(int i=0;i<n;i++) printf("%lld ",back[i]);puts("");
	ll ret=0;
	for(int i=0;i<n;i++)
	{
		ret+=(ll) back[i]*(ll) ans[i];
		ret+=(ll) (n-ans[i])*(ll) (n-ans[i]);
		ret-=(ll) back[i]*(ll) (n-back[i]);
	}
	printf("%lld\n",ret);
	return 0;
}