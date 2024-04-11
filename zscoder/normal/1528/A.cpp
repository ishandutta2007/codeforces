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
typedef pair<ld,ld> state;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vi adj[222222];
vi F[222222];
ll dp[222222][2];

void dfs(int u, int p=-1)
{
	dp[u][0]=dp[u][1]=0;
	for(int v:adj[u])
	{
		if(v==p) continue;
		dfs(v,u);
		for(int i=0;i<2;i++)
		{
			dp[u][i]+=max(abs(F[u][i]-F[v][0])+dp[v][0],abs(F[u][i]-F[v][1])+dp[v][1]);
		}
	}
}

void solve()
{
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		F[i].clear();
		int l,r; cin>>l>>r;
		F[i].pb(l); F[i].pb(r);
	}
	for(int i=0;i<n-1;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	dfs(0);
	cout<<max(dp[0][0],dp[0][1])<<'\n';
	for(int i=0;i<n;i++) adj[i].clear();
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}