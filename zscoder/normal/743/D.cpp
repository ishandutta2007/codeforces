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

vi adj[200001];
ll a[200001];
ll dp[200001];
ll mx[200001];
int noc[200001];
ll sub[200001];

void dfs(int u, int p)
{
	sub[u] = a[u];
	mx[u] = -ll(1e16);
	dp[u] = -ll(1e16);
	ll mx1,mx2;
	mx1=mx2=mx[u];
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if(v==p) continue;
		noc[u]++;
		dfs(v, u);
		mx[u] = max(mx[u], mx[v]);
		dp[u] = max(dp[u], dp[v]);
		if(mx[v]>mx1)
		{
			mx2=mx1;
			mx1=mx[v];
		}
		else if(mx[v]>mx2)
		{
			mx2=mx[v];
		}
		sub[u] += sub[v];
	}
	dp[u] = max(dp[u], mx1+mx2);
	mx[u] = max(mx[u], sub[u]);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i = 0; i < n; i++) cin>>a[i];
	for(int i = 0; i < n - 1; i++)
	{
		int u, v; cin>>u>>v;
		u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	dfs(0,-1);
	for(int i = 0; i < n; i++)
	{
		if(noc[i]>1)
		{
			cout<<dp[0];
			return 0;
		}
	}
	cout<<"Impossible";
}