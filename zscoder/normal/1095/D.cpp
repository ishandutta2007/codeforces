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
vi cyc;
map<ii,int> ma;
bool vis[222222];
void dfs(int u)
{
	if(vis[u]) return ;
	cyc.pb(u); vis[u]=1;
	for(int v:adj[u])
	{
		if(vis[v]) continue;
		dfs(v);
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		ma[{u,v}]=i; ma[{v,u}]=i;
		adj[u].pb(v); adj[v].pb(u);
	}
	dfs(0);
	vi ans(n);
	if(ma[{cyc[1],cyc[2]}]==0)
	{
		ans=cyc;
	}
	else
	{
		reverse(cyc.begin(),cyc.end());
		ans=cyc;
	}
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]+1;
		if(i+1<n) cout<<' ';
	}
	cout<<'\n';
}