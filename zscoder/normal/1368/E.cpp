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

vi adj[222222];
int dp[222222];
vi radj[222222];

void solve()
{
	int n,m; cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		adj[u].pb(v); radj[v].pb(u);
	}
	for(int i=0;i<n;i++) dp[i]=0;
	vi vec;
	for(int i=0;i<n;i++)
	{
		for(int z:radj[i])
		{
			if(dp[z]!=-1) dp[i]=max(dp[z]+1,dp[i]);
		}
		if(dp[i]>=2) 
		{
			vec.pb(i); dp[i]=-1;
		}
	}
	cout<<vec.size()<<'\n';
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i]+1;
		if(i+1<vec.size()) cout<<' ';
	}
	cout<<'\n';
	for(int i=0;i<n;i++) 
	{
		radj[i].clear(); adj[i].clear();
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--)
	{
		solve();
	}
}