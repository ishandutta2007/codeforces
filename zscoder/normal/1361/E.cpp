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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int x)
{
	return uniform_int_distribution<int>(0, x-1)(rng);
}

vi adj[112222];
int in[111111];
bool vis[111111];
vi T[112222];
int out[111111];	
int h[111111];
int timer=0;
vi backedge[111111];
int par[222222];

bool cmp(int u, int v)
{
	return (h[u]<h[v]);
}

void dfs(int u, bool build=0)
{
	vis[u]=1;
	in[u]=++timer;
	for(int v:adj[u])
	{
		if(vis[v]) continue;
		h[v]=h[u]+1;
		if(build) T[u].pb(v); 
		par[v]=u;
		dfs(v,build);
	}
	out[u]=++timer;
}

bool good(int r, vector<ii> &E)
{
	timer=0;
	dfs(r);
	for(ii x:E)
	{
		int u=x.fi; int v=x.se;
		if(par[v]==u) continue;
		if(!(in[v]<=in[u]&&out[u]<=out[v])) return false;
	}	
	return true;
}

bool isgood[222222];
vi minedge[222222];

void protop(int u)
{
	for(int v:backedge[u])
	{
		if(h[v]<h[u]) minedge[u].pb(v);
	}
	for(int v:T[u])
	{
		//cerr<<"EDGE "<<u<<' '<<v<<'\n';
		protop(v);
		//cerr<<u<<' '<<v<<' '<<curbackedge<<' '<<minedge[v]<<'\n';
		for(int w:minedge[v])
		{
			if(h[w]<h[u]) minedge[u].pb(w);
		}
	}
	sort(minedge[u].begin(),minedge[u].end(),cmp);
	while(minedge[u].size()>2)
	{
		minedge[u].pop_back();
	}
}

void gooddfs(int u)
{
	for(int v:T[u])
	{
		assert(!minedge[v].empty());
		if(minedge[v].size()<=1&&isgood[minedge[v][0]]) isgood[v]=1;
		gooddfs(v);
	}
}

void solve()
{
	int n,m; cin>>n>>m;
	vector<ii> E;
	for(int i=0;i<m;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		adj[u].pb(v); E.pb({u,v});
	}
	int rt = rnd(n);
	for(int cc=0;cc<80;cc++)
	{
		for(int i=0;i<n;i++) 
		{
			par[i]=-1; vis[i]=0;
		}
		if(good(rt,E)) break;
		if(cc==78)
		{
			for(int i=0;i<n;i++) adj[i].clear();
			cout<<-1<<'\n'; return ;
		}
		rt = rnd(n);
	}
	for(int i=0;i<n;i++) vis[i]=0;
	timer=0; h[rt]=0;
	//cerr<<"RT: "<<rt<<'\n';
	dfs(rt,1);
	for(int i=0;i<n;i++) 
	{
		backedge[i].clear(); minedge[i].clear();
	}
	for(ii x:E)
	{
		int u=x.fi; int v=x.se;
		if(par[v]==u) continue;
		backedge[u].pb(v);
	}
	/*
	for(int i=0;i<n;i++)
	{
		cerr<<rt<<' '<<i<<' '<<backedge[i]<<'\n';
	}
	*/
	for(int i=0;i<n;i++)
	{
		sort(backedge[i].begin(),backedge[i].end(),cmp);
		while(backedge[i].size()>2) backedge[i].pop_back();
	}
	for(int i=0;i<n;i++) isgood[i]=0;
	isgood[rt]=1;
	protop(rt);
	/*
	for(int i=0;i<n;i++)
	{
		cerr<<rt<<' '<<i<<' '<<minedge[i]<<'\n';
	}
	*/
	gooddfs(rt);
	vi good;
	for(int i=0;i<n;i++)
	{
		if(isgood[i]) good.pb(i);
	}
	if(good.size()*5<n) cout<<-1<<'\n';
	else
	{
		for(int i=0;i<good.size();i++)
		{
			cout<<good[i]+1;
			if(i+1<good.size()) cout<<' ';
		}
		cout<<'\n';
	}
	for(int i=0;i<n;i++)
	{
		adj[i].clear(); T[i].clear();
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}