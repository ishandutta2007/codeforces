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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vi adj[222222];
int subsize[222222];
int marked[222222];
vector<ii> vec;
int h[222222];

void prep(int u, int p=-1)
{
	subsize[u]=1;
	for(int v:adj[u])
	{
		if(v==p) continue;
		h[v]=h[u]+1;
		prep(v,u);
		subsize[u]+=subsize[v];
	}
	vec.pb({subsize[u]-h[u],u});
}
ll ans=0;
int dp[222222];

void dfs(int u, int p=-1)
{
	dp[u]=(!marked[u]);
	for(int v:adj[u])
	{
		if(v==p) continue;
		dfs(v,u);
		
		dp[u]+=dp[v];
	}
	if(marked[u]) ans+=dp[u];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k; cin>>n>>k;
	for(int i=0;i<n-1;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	prep(0);
	sort(vec.rbegin(),vec.rend());
	for(int i=0;i<n-k;i++)
	{
		marked[vec[i].se]=1;
	}
	dfs(0,-1);
	cout<<ans<<'\n';
}