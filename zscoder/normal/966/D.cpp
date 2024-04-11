#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

set<int> adj[311111];
bool ischild[311111];
set<int> adj2[311111];
bool vis[311111];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m; vector<ii> edges;
	for(int i=0;i<m;i++)
	{
		int u,v; cin>>u>>v; edges.pb(mp(u,v));
		adj[u].insert(v); adj[v].insert(u);
	}
	if(adj[1].find(n)!=adj[1].end())
	{
		cout<<1<<'\n';
		cout<<1<<' '<<n<<'\n';
		return 0;
	}
	vi child; 
	for(int v:adj[1])
	{
		child.pb(v); ischild[v]=1;
		if(adj[v].find(n)!=adj[v].end())
		{
			cout<<2<<'\n';
			cout<<1<<' '<<v<<' '<<n<<'\n';
			return 0;
		}
	}
	for(int v:child)
	{
		for(int x:adj[v])
		{
			if(adj[x].find(n)!=adj[x].end())
			{
				cout<<3<<'\n';
				cout<<1<<' '<<v<<' '<<x<<' '<<n<<'\n';
				return 0;
			}
		}
	}
	for(int v:child)
	{
		for(int x:adj[v])
		{
			if(x==1) continue;
			if(adj[x].find(1)==adj[x].end())
			{
				cout<<4<<'\n';
				cout<<1<<' '<<v<<' '<<x<<' '<<1<<' '<<n<<'\n';
				return 0;
			}
		}
	}
	for(ii x:edges)
	{
		if(ischild[x.fi]&&ischild[x.se])
		{
			adj2[x.fi].insert(x.se);
			adj2[x.se].insert(x.fi);
		}
	}
	for(int v:child)
	{
		if(!vis[v])
		{
			vis[v]=1;
			vi childs;
			for(int x:adj2[v])
			{
				for(int i=0;i<childs.size();i++)
				{
					if(adj2[childs[i]].find(x)==adj2[childs[i]].end())
					{
						cout<<5<<'\n';
						cout<<1<<' '<<childs[i]<<' '<<v<<' '<<x<<' '<<childs[i]<<' '<<n<<'\n';
						return 0;
					}
				}
				vis[x]=1;
				childs.pb(x);
			}
			for(int x:childs)
			{
				for(int y:adj2[x])
				{
					if(y!=v&&adj2[v].find(y)==adj2[v].end())
					{
						cout<<5<<'\n';
						cout<<1<<' '<<v<<' '<<x<<' '<<y<<' '<<v<<' '<<n<<'\n';
						return 0;
					}
				}
			}
		}
	}
	cout<<-1<<'\n';
}