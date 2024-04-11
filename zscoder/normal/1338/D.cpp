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

int dp[111111][3];
int ans=0;
vi adj[111111];

void dfs(int u, int p=-1)
{
	int ch = adj[u].size()-(p!=-1);
	dp[u][2]=0;
	dp[u][0]=ch;
	dp[u][1]=1;
	vi vec;
	vi vec2;
	for(int v:adj[u])
	{
		if(v==p) continue;
		dfs(v,u);
		vec.pb(max(dp[v][0],dp[v][2]));
		vec2.pb(max(dp[v][0],max(dp[v][1],dp[v][2])));
		dp[u][2]=max(dp[u][2],max(dp[v][0],max(dp[v][1],dp[v][2]))); //nothing
		dp[u][1]=max(dp[u][1],1+max(dp[v][2],dp[v][0]));
		dp[u][0]=max(dp[u][0],ch-1+max(dp[v][2],max(dp[v][1],dp[v][0])));
	}
	
	sort(vec2.rbegin(),vec2.rend());
	sort(vec.rbegin(),vec.rend());
	if(vec.size()>=2)
	{
		ans=max(ans,vec[0]+vec[1]+1); //blue top
		ans=max(ans,vec2[0]+vec2[1]+ch-2+(p!=-1)); //red top
	}
	
	for(int i=0;i<3;i++) ans=max(ans,dp[u][i]);
}

int main()
{	
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	dfs(0,-1);	
	cout<<ans<<'\n';
}