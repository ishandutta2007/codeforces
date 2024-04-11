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
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;
typedef vector<ll>::iterator vit;

vector<ii> adj[100001];
int n,k; 
//vector<ii> nw[100001];
ll dp[100001];
ll dp2[100001];
void solve(int u, int p)
{
	vector<ii> vec;
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i].fi; int w=adj[u][i].se;
		if(v==p) continue;
		solve(v,u);
		vec.pb(mp(dp[v]+w,i));
	}
	sort(vec.rbegin(),vec.rend());
	for(int i=0;i<vec.size();i++)
	{
		if(i>=k-1) 
		{
			//nw[u].pb(adj[u][vec[i].se]);
			//nw[adj[u][vec[i].se].fi].pb(mp(u,adj[u][vec[i].se].se));
		}
		else
		{
			//nw[u].pb(mp(adj[u][vec[i].se].fi,0));
			//nw[adj[u][vec[i].se].fi].pb(mp(u,0));
			dp[u]+=vec[i].fi;
		}
	}
	dp2[u]=dp[u];
	for(int i = 0; i < vec.size(); i++)
	{
		int idx = vec[i].se;
		int v = adj[u][idx].fi; int w = adj[u][idx].se;
		//use dp2[v] instead of dp[v]
		if(i>=k-1)
		{
			dp2[u] = max(dp2[u],dp2[v]+w+dp[u]);
		}
		else
		{
			ll val = 0;
			val = dp[u]-dp[v]+dp2[v];
			if(k-1<vec.size()) val+=vec[k-1].fi;
			dp2[u]=max(dp2[u],val);
		}
	}
}
/*
ll dp2[100001];
void dfs(int u, int p)
{
	for(int i=0;i<nw[u].size();i++)
	{
		int v=nw[u][i].fi; int w=nw[u][i].se;
		if(v==p) continue;
		dfs(v,u);
		dp2[u]=max(dp2[u],w+dp2[v]);
	}
}
*/

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n; int k=1;
	for(int i = 0; i < n - 1; i++)
	{
		int u,v,w; cin>>u>>v>>w;
		adj[u].pb(mp(v,w));
		adj[v].pb(mp(u,w));
	}
	solve(0,-1);
	//dfs(0,-1);
	//cout<<dp[0]+dp2[0]<<'\n';
	cout<<dp2[0]<<'\n';
}