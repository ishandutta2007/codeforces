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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int dp[1001][1001];
int b[1001];
int a[1001];
vi adj[1001];
vi groups[1001];
int cc = 0;
bool visited[1001];
int sum[1001];
int sumb[1001];

void dfs(int u)
{
	visited[u] = true;
	groups[cc].pb(u);
	sum[cc]+=a[u];
	sumb[cc]+=b[u];
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if(!visited[v]) dfs(v);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, w;
	cin>>n>>m>>w;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin>>b[i];
	}
	for(int i = 0; i < m; i++)
	{
		int u, v; cin>>u>>v;
		u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	for(int i = 0; i < n; i++)
	{
		if(!visited[i])
		{
			dfs(i);
			cc++;
		}
	}
	for(int i = 0; i < groups[0].size(); i++)
	{
		if(a[groups[0][i]] <= w) dp[0][a[groups[0][i]]] = max(dp[0][a[groups[0][i]]],b[groups[0][i]]); 
	}
	if(sum[0] <= w)
	{
		dp[0][sum[0]] = max(dp[0][sum[0]], sumb[0]);
	}
	for(int i = 1; i < cc; i++)
	{
		for(int k = 0; k <= w; k++)
		{
			dp[i][k] = dp[i-1][k];
			for(int j = 0; j < groups[i].size(); j++)
			{
				int u = groups[i][j];
				if(k - a[u] >= 0)
				{
					dp[i][k] = max(dp[i][k], dp[i-1][k-a[u]] + b[u]);
				}
			}
			if(k - sum[i] >= 0)
			{
				dp[i][k] = max(dp[i][k], dp[i-1][k-sum[i]] + sumb[i]);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i <= w; i++)
	{
		//cerr<<i<<' '<<dp[cc-1][i]<<'\n';
		ans = max(ans, dp[cc-1][i]);
	}
	cout<<ans;
}