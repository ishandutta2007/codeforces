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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

vector<pair<int,int> > adj[111];
int dp[111][111][27][2];

int solve(int u, int v, int x, int player)
{
	if(dp[u][v][x][player]>=0) return dp[u][v][x][player];
	if(player==1)
	{
		for(ii a:adj[u])
		{
			int to = a.fi; int c = a.se;
			if(c<x) continue;
			if(solve(to, v, c, player^1) == player) return (dp[u][v][x][player] = player);
		}
		return (dp[u][v][x][player] = player^1);
	}
	else
	{
		for(ii a:adj[v])
		{
			int to = a.fi; int c = a.se;
			if(c<x) continue;
			if(solve(u, to, c, player^1) == player) return (dp[u][v][x][player] = player);
		}
		return (dp[u][v][x][player] = player^1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v; cin>>u>>v; u--; v--; char c; cin>>c;
		adj[u].pb(mp(v,c-'a'));
	}
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int res = solve(i,j,0,1);
			if(res==1) cout<<"A";
			else cout<<"B";
		}
		cout<<'\n';
	}
}