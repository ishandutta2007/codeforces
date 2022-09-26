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
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

vi solo;

struct DSU
{
	int S;
	
	struct node
	{
		int p; ll sum;
	};
	vector<node> dsu;
	
	DSU(int n)
	{
		S = n;
		for(int i = 0; i < n; i++)
		{
			node tmp;
			tmp.p = i; tmp.sum = 0;
			dsu.pb(tmp);
		}
	}
	
	void reset(int n)
	{
		dsu.clear();
		S = n;
		for(int i = 0; i < n; i++)
		{
			node tmp;
			tmp.p = i; tmp.sum = 0;
			dsu.pb(tmp);
		}
	}
	
	int rt(int u)
	{
		if(dsu[u].p == u) return u;
		dsu[u].p = rt(dsu[u].p);
		return dsu[u].p;
	}
	
	void merge(int u, int v)
	{
		u = rt(u); v = rt(v);
		if(u == v) return ;
		if(rand()&1) swap(u, v);
		dsu[v].p = u;
		dsu[u].sum += dsu[v].sum;
	}
	
	bool sameset(int u, int v)
	{
		if(rt(u) == rt(v)) return true;
		return false;
	}
	
	ll getstat(int u)
	{
		return dsu[rt(u)].sum;
	}
};

vi adj[200001];

void dfs(int u,int p)
{
	solo.pb(u);
	bool visitedsth = 0;
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if(v==p) continue;
		dfs(v,u);
		solo.pb(u);
	}
}	
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	srand(13);
	int n,m,k; cin>>n>>m>>k;
	vector<ii> edges;
	for(int i=0;i<m;i++)
	{
		int u, v; cin>>u>>v;
		edges.pb(mp(u,v));
	}
	DSU dsu(n+2);
	for(int i=0;i<edges.size();i++)
	{
		int u=edges[i].fi; int v=edges[i].se;
		if(dsu.sameset(u,v)) continue;
		dsu.merge(u,v);
		adj[u].pb(v); adj[v].pb(u);
	}
	dfs(1,-1);
	int maxi = (2*n-1)/k + 1;
	int cur=0;
	for(int i=0;i<k;i++)
	{
		vi res;
		for(int j=0;j<maxi;j++)
		{
			if(cur<solo.size()) res.pb(solo[cur++]);
			else
			{
				if(j>0) break;
				else
				{
					res.pb(1);
					break;
				}
			}
		}
		cout<<res.size()<<' ';
		for(int j=0;j<res.size();j++) cout<<res[j]<<' ';
		cout<<'\n';
	}
}