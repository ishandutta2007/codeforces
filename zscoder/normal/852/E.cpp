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
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

const int MOD=1e9+7;

ll dp[111111];

ll add(ll a, ll b)
{
	a+=b;
	while(a>=MOD) a-=MOD;
	return a;
}

ll mult(ll a, ll b)
{
	return (a*b)%MOD;
}

ll modpow(ll a, ll b)
{
	ll r=1;
	while(b)
	{
		if(b&1) r=mult(r,a);
		a=mult(a,a);
		b>>=1;
	}
	return r;
}

vi adj[111111];
int dp2[111111];

void prep(int u, int p)
{
	dp2[u]=1;
	int ch=0;
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if(v==p) continue;
		ch++;
		prep(v,u);
		dp2[u] += dp2[v] - 1;
	}
	if(ch>0) dp2[u]++;
}

void dfs(int u, int p = -1, int pass = 1)
{
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if(v==p) continue;
		dp[u] += dp2[v] - 1;
	}
	dp[u] += pass - 1;
	dp[u] += 2;
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v=adj[u][i];
		if(v==p) continue;
		dp[u] -= (dp2[v] - 1);
		if(adj[u].size()==1) dfs(v,u,1);
		else dfs(v,u,dp[u]);
		dp[u] += (dp2[v] - 1);
	}
	//cerr<<u<<' '<<dp2[u]<<' '<<dp[u]<<'\n';
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
	if(n==1)
	{
		cout<<1<<'\n';
		return 0;
	}
	/*
	ll res=0;
	for(int i=0;i<n;i++)
	{
		prep(i,-1);
		res=add(res,modpow(2,dp2[i]-1));
		for(int j=0;j<n;j++) dp[j]=dp2[j]=0;
	}
	cout<<res<<'\n';
	*/
	prep(0,-1);
	dfs(0);
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		ans=add(ans,modpow(2,dp[i]-1));
	}
	cout<<ans<<'\n';
}