#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int group[555555];
int cc[555555];
vi adj[555555];
int col[555555];
int bad[555555];

void dfs(int u, int ccno, int c=0)
{
	cc[u]=ccno; col[u]=c;
	for(int v:adj[u])
	{
		if(group[v]!=group[u]) continue; //we only go to same group
		if(cc[v]!=-1) 
		{
			if(col[v]==col[u]) //same color means not bipartite le
			{
				bad[group[v]]=1; //mark the group as bad
			}
			continue;
		}
		dfs(v,ccno,c^1);
	}
}

ll nc2(ll x)
{
	return (x*(x-1))/2;
}

map<ii,vector<ii> > E;

vi dsu[555555];
int par[555555];
int coloring[555555];

int rt(int u)
{
	if(par[u]<0) return u;
	return rt(par[u]);
}

void merge(int u, int v, int fl=0) //f1 = 1 means need flip
{
	u=rt(u); v=rt(v);
	if(u==v) return ;
	if(par[u]>par[v]) swap(u,v);
	//par[u] is greater
	for(int x:dsu[v])
	{
		dsu[u].pb(x);
		coloring[x]^=fl;
	}
	par[u]+=par[v]; par[v]=u;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,k; cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		cin>>group[i]; group[i]--;
	}
	vector<ii> edges;
	for(int i=0;i<m;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		adj[u].pb(v); adj[v].pb(u);
		if(group[u]!=group[v])
		{
			E[mp(min(group[u],group[v]),max(group[u],group[v]))].pb({u,v});
		}
	}
	memset(cc,-1,sizeof(cc));
	int cccnt=0;
	for(int i=0;i<n;i++)
	{
		if(cc[i]!=-1) continue;
		dfs(i,cccnt,0);
		cccnt++;
	}
	ll goodgroups=k;
	for(int i=0;i<k;i++)
	{
		if(bad[i]) goodgroups--;
	}
	ll ans = nc2(goodgroups);
	memset(par,-1,sizeof(par));
	for(int i=0;i<n;i++) dsu[i].pb(i);
	for(auto gpair: E)
	{
		//is this pair fked?
		int g1 = gpair.fi.fi;
		int g2 = gpair.fi.se;
		if(bad[g1]||bad[g2]) continue; //dont care anymore
		//we care now
		vector<ii> edges = gpair.se;
		//map<ii,int> ma;
		int pos=1;
		vi kao;
		for(ii e:edges)
		{
			int u=e.fi; int v=e.se;
			int c1 = cc[u]; int c2 = cc[v]; kao.pb(c1); kao.pb(c2);
			if(c1>c2) swap(c1,c2);
			/*
			int cpair = (col[u]^col[v]);
			if(ma.count({c1,c2})&&ma[{c1,c2}]!=cpair)
			{
				pos=0; break;
			}
			ma[{c1,c2}]=cpair;
			*/
			int cpair = (col[u]^coloring[cc[u]]^col[v]^coloring[cc[v]]); //check whether current colors match or not, 0 if match
			if(rt(c1)==rt(c2))
			{
				if(cpair==0){pos=0; break;} //fail liao
			}
			else
			{
				//correct the color if cpair = 0
				merge(c1,c2,cpair^1);
			}
		}
		for(int x:kao)
		{
			par[x]=-1; dsu[x].clear(); dsu[x].pb(x); coloring[x]=0;
		}
		if(!pos) ans--;
	}
	cout<<ans<<'\n';
}