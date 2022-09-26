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

vi adj[222222];
int leaves;
int bundles;
int f[222222];

void dfs(int u, int p)
{
	for(int v:adj[u])
	{
		if(v==p) continue;
		dfs(v,u);
	}
	int cnt=0;
	for(int v:adj[u])
	{
		if(v==p) continue;
		if(!f[v])
		{
			cnt++;
		}
	}
	if(u==0) return ;
	if(cnt==0)
	{
		//this is leaf boy
	}
	else
	{
		//form a new bundle
		bundles++;
		leaves+=cnt;
		f[u]=1; //used le
	}
}

void solve()
{
	int n; cin>>n;
	for(int i=0;i<n;i++) adj[i].clear();
	for(int i=0;i<n-1;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	leaves=0;
	bundles=0;
	for(int i=0;i<n;i++) f[i]=0;
	dfs(0,-1);
	int bad=0;
	for(int v:adj[0])
	{
		if(f[v]==0)
		{
			leaves++; bad=1;
		}
	}
	if(bad==0)
	{
		cout<<leaves-bundles+1<<'\n';
	}
	else
	{
		cout<<leaves-bundles<<'\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}