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

set<ii> adj[222222];
vi ans;
int cnt[333333];
int req[333333];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>cnt[i];
	}
	for(int i=0;i<m;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		adj[u].insert({v,i});
		adj[v].insert({u,i});
	}
	set<ii> S;
	for(int i=0;i<n;i++)
	{
		req[i] = max(0, int(adj[i].size())-cnt[i]);
		S.insert({req[i],i});
	}
	while(int(ans.size())<m)
	{
		int u = (*S.begin()).se;
		if(req[u]>0)
		{
			cout<<"DEAD\n"; return 0;
		}
		S.erase({req[u],u});
		vector<ii> edges;
		for(ii e:adj[u])
		{
			edges.pb(e);
			int v=e.fi; int id=e.se;
			ans.pb(id);
			if(req[v]>0)
			{
				S.erase({req[v],v});
				req[v]--;
				S.insert({req[v],v});
			}
		}
		adj[u].clear();
		for(ii x:edges)
		{
			int v=x.fi; int id=x.se;
			adj[v].erase({u,id});
		}
	}
	reverse(ans.begin(),ans.end());	
	cout<<"ALIVE\n";
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]+1;
		if(i+1<ans.size()) cout<<' ';
	}
	cout<<'\n';
}