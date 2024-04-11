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
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<ii> adj[333333];
ll a[333333];
ll dp[333333];
ll ans[333333];

void dfs(int u, int p)
{
	vector<ll> V;
	for(ii x:adj[u])
	{
		int v=x.fi; ll w=x.se;
		if(v==p) continue;
		dfs(v,u);
		dp[u] = max(dp[u], max(0LL, dp[v] + a[v] - w));
		V.pb(max(0LL, dp[v] + a[v] - w));
	}
	sort(V.rbegin(),V.rend());
	ans[u] = a[u];
	for(int i=0;i<min(int(V.size()),2);i++) ans[u]+=V[i];
	//cerr<<u<<' '<<dp[u]<<' '<<ans[u]<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n-1;i++)
	{
		int u,v; ll w;cin>>u>>v>>w;
		u--; v--;
		adj[u].pb(mp(v,w)); adj[v].pb(mp(u,w));
	}
	dfs(0,-1);
	ll as=0;
	for(int i=0;i<n;i++) as=max(as,ans[i]);
	cout<<as<<'\n';
}