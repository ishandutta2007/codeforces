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
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

set<int> adj[222222];
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
DSU dsu(1);

int visited[222222];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	dsu.reset(n);
	for(int i=0;i<m;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		adj[u].insert(v); adj[v].insert(u);
	}
	set<int> alive;
	for(int i=0;i<n;i++) alive.insert(i);
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			queue<int> q;
			q.push(i);
			alive.erase(i);
			while(!q.empty())
			{
				int u=q.front(); q.pop();
				if(visited[u]) continue;
				visited[u]=1;
				vi ee;
				for(int v:alive)
				{
					if(adj[u].find(v)==adj[u].end())
					{
						ee.pb(v); q.push(v); dsu.merge(i,v);
					}
				}
				for(int x:ee) alive.erase(x);
			}
		}
	}
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		cnt+=(dsu.rt(i)==i);
	}
	cout<<cnt-1<<'\n';
}