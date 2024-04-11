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
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int n,k; 
vector<ii> adj[555555];
ll dp[2][555555];

void dfs(int u, int p=-1)
{
	ll ans=0;
	vector<ll> vec;
	for(ii x:adj[u])
	{
		int v=x.fi; int w=x.se;
		if(v==p) continue;
		dfs(v,u);
		ans+=dp[0][v];
		vec.pb(w+dp[1][v]-dp[0][v]);
	}
	sort(vec.rbegin(),vec.rend());
	dp[0][u]=dp[1][u]=ans;
	for(int i=0;i<min(k,int(vec.size()));i++)
	{
		if(vec[i]>=0) dp[0][u]+=vec[i];
	}
	for(int i=0;i<min(k-1,int(vec.size()));i++)
	{
		if(vec[i]>=0) dp[1][u]+=vec[i];
	}
}

void solve()
{
	cin>>n>>k;
	for(int i=0;i<n-1;i++)
	{
		int u,v,w; cin>>u>>v>>w;u--; v--;
		adj[u].pb({v,w}); adj[v].pb({u,w});
	}
	dfs(0,-1);
	cout<<dp[0][0]<<'\n';
	for(int i=0;i<n;i++) adj[i].clear();
	for(int i=0;i<n;i++)
	{
		dp[0][i]=dp[1][i]=0;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q; cin>>q;
	while(q--)
	{
		solve();
	}
}