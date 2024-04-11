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

const int MOD = 1e9+7;

int add(int a, int b)
{
	a+=b;
	while(a>=MOD) a-=MOD;
	return a;
}

int mult(int a, int b)
{
	return (a*1LL*b)%MOD;
}

vi adj[111111];
int dp[111111][11][3];
ll m;
ll k;

void dfs(int u, int p)
{
	vector<int> cur(11,0);
	cur[0] = 1;
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if(v==p) continue;
		dfs(v,u);
		vector<int> nt(11,0);
		for(int j=0;j<11;j++)
		{
			for(int k=0;k<=j;k++)
			{
				nt[j] = add(nt[j], mult(add(dp[v][k][0], dp[v][k][2]), cur[j-k]));
			}
		}
		cur = nt;
	}
	//vector<ll> tmp = cur;
	for(int i=0;i<11;i++)
	{
		dp[u][i][0] = add(dp[u][i][0], mult(m - k, cur[i]));
	}
	cur.clear(); cur.resize(11,0);
	cur[0] = 1;
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if(v==p) continue;
		vector<int> nt(11,0);
		for(int j=0;j<11;j++)
		{
			for(int k=0;k<=j;k++)
			{
				nt[j] = add(nt[j], mult(add(dp[v][k][0],add(dp[v][k][1],dp[v][k][2])), cur[j-k]));
			}
		}
		cur = nt;
	}
	for(int i=0;i<11;i++)
	{
		dp[u][i][2] = add(dp[u][i][2], mult(k - 1, cur[i]));
	}
	cur.clear(); cur.resize(11,0); cur[0]=1;
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if(v==p) continue;
		vector<int> nt(11,0);
		for(int j=0;j<11;j++)
		{
			for(int k=0;k<=j;k++)
			{
				nt[j] = add(nt[j], mult(dp[v][k][2], cur[j-k]));
			}
		}
		cur = nt;
	}
	for(int i=1;i<11;i++)
	{
		dp[u][i][1] = add(dp[u][i][1], cur[i-1]);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin>>n>>m;
	for(int i=0;i<n-1;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	int x;
	cin>>k>>x;
	dfs(0,-1);
	ll ans=0;
	for(int i=0;i<=x;i++)
	{
		for(int j=0;j<3;j++)
		{
			ans=add(ans,dp[0][i][j]);
		}
	}
	cout<<ans<<'\n';
}