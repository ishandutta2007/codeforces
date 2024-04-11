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
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vi adj[222222];
int down[222222];
int up[222222];
int good[222222];
int h[222222];
int par[222222];

void dfsdown(int u, int p=-1)
{
	par[u]=p;
	for(int v:adj[u])
	{
		if(v==p) continue;
		h[v]=h[u]+1;
		dfsdown(v,u);
		down[u]=max(down[u],down[v]+1);
	}
}

void dfsup(int u, int p=-1)
{
	vector<ii> children;
	for(int v:adj[u])
	{
		if(v==p) continue;
		children.pb({down[v]+1,v});
	}
	sort(children.rbegin(),children.rend());
	for(int v:adj[u])
	{
		if(v==p) continue;
		//compute up[v]
		int maxd = 0;
		int ptr = 0;
		while(ptr<children.size()&&children[ptr].se==v) 
		{
			ptr++;
		}
		if(ptr<children.size()) maxd = children[ptr].fi;
		up[v] = 1 + max(up[u], maxd);
		dfsup(v,u);
	}
}

void dpgood(int u, int p, int pathlength)
{
	vector<ii> children;
	for(int v:adj[u])
	{
		if(v==p) continue;
		children.pb({down[v]+1,v});
		dpgood(v,u,pathlength);
	}
	children.pb({up[u],u});
	sort(children.rbegin(),children.rend());
	//cerr<<"F: "<<u<<' '<<pathlength<<' '<<children.size()<<'\n';
	if(children.size()>=3&&children[2].fi>=pathlength) good[u]=1;
}

int onpath[222222];
int goodcnt[222222];
int maxd[222222];
int sub[222222];

void countgood(int u, int p=-1)
{
	sub[u]=good[u];
	for(int v:adj[u])
	{
		if(v==p) continue;
		countgood(v,u);
		sub[u]+=sub[v];
	}
}

void dfspath(int u, int p=-1)
{
	for(int v:adj[u])
	{
		if(v==p) continue;
		if(onpath[v]) continue;
		maxd[u]=max(maxd[u],1+down[v]); //longest down chain from path node
	}
	goodcnt[u] = sub[u];
	for(int v:adj[u])
	{
		if(v==p) continue;
		if(!onpath[v]) continue;
		goodcnt[u]-=sub[v];
		dfspath(v,u);
	}
}

void solve()
{
	int n;
	int a,b; 
	cin>>n>>a>>b; a--; b--;
	for(int i=0;i<n-1;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	dfsdown(a); //rt at a
	dfsup(a);
	dpgood(a,-1,h[b]);
	vi path;
	path.pb(b);
	while(b!=a)
	{
		b=par[b];
		path.pb(b);
	}
	reverse(path.begin(),path.end());
	int m = path.size();
	for(int v:path) onpath[v]=1;
	countgood(a);
	/*
	for(int i=0;i<n;i++)
	{
		cerr<<i<<": "<<down[i]<<' '<<up[i]<<' '<<good[i]<<' '<<sub[i]<<'\n';
	}
	*/
	dfspath(a);
	int l = 0; int r = m-1;
	set<ii> S;
	S.insert({l,0});
	S.insert({r,1});
	set<int> rem[2];
	for(int i=l;i<=r;i++) 
	{
		rem[0].insert(i);
		rem[1].insert(i); //remaining stuff that i can use
	}
	//rem[0] means path is i-(i+1)-...
	rem[0].erase(0);
	rem[1].erase(r);
	bool pos=0;
	while(!S.empty())
	{
		int id = (*S.begin()).fi; int dir = (*S.begin()).se; S.erase(S.begin());
		int u = path[id];
		if(goodcnt[u])
		{
			pos=1; break;
		}
		//relax u
		int lengoin = maxd[u];
		if(lengoin>=m-1) //m-1 is our "D"
		{
			while(!rem[0].empty())
			{
				S.insert({(*rem[0].begin()),0});
				rem[0].erase(rem[0].begin());
			}
			while(!rem[1].empty())
			{
				S.insert({(*rem[1].begin()),1});
				rem[1].erase(rem[1].begin());
			}
			continue;
		}
		int L = m-1;
		if(dir==0)
		{
			int lef = id+L-lengoin;
			int ri = id+L;
			auto it = rem[1].lower_bound(lef);
			vi dellist;
			while(it!=rem[1].end()&&(*it)<=ri)
			{
				dellist.pb((*it));
				it++;
			}
			for(int x:dellist)
			{
				rem[1].erase(x);
				S.insert({x,1});
			}
		}
		else
		{
			int lef = id-L;
			int ri = id-(L-lengoin);
			auto it = rem[0].lower_bound(lef);
			vi dellist;
			while(it!=rem[0].end()&&(*it)<=ri)
			{
				dellist.pb((*it));
				it++;
			}
			for(int x:dellist)
			{
				rem[0].erase(x);
				S.insert({x,0});
			}
		}
	}
	cout<<(pos?"YES":"NO")<<'\n';
	for(int i=0;i<n;i++) 
	{
		par[i]=-1; adj[i].clear();
	}
	for(int i=0;i<n;i++) down[i]=up[i]=good[i]=h[i]=onpath[i]=goodcnt[i]=maxd[i]=0;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}