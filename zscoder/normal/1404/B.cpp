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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vi adj[111111];
int h[111111];

void dfs(int u, int p)
{
	for(int v:adj[u])
	{
		if(v==p) continue;
		h[v]=h[u]+1;
		dfs(v,u);
	}
}

void solve()
{
	int n,a,b,da,db; cin>>n>>a>>b>>da>>db;
	a--; b--;
	for(int i=0;i<n-1;i++)
	{
		int u,v; cin>>u>>v; u--; v--; adj[u].pb(v); adj[v].pb(u);
	}
	h[a]=0;
	dfs(a,-1);
	int mx=0; int mxrt=a;
	for(int i=0;i<n;i++)
	{
		if(h[i]>mx){mx=h[i]; mxrt=i;}
	}
	bool ans=0;
	if(da>=h[b]) ans=1;
	h[mxrt]=0;
	dfs(mxrt,-1);
	mx=0;
	for(int i=0;i<n;i++)
	{
		if(h[i]>mx){mx=h[i]; mxrt=i;}
	}
	if(min(db,mx)<=2*da) ans=1;
	for(int i=0;i<n;i++) adj[i].clear();
	cout<<(ans?"Alice":"Bob")<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}