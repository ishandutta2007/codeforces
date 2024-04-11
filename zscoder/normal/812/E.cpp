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
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

int par[100001];
int a[100001];
vi adj[100001];

vi odd;
vi even;

int dfs(int u, int p)
{
	int h=0;
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		h = dfs(v,u)+1;
	}
	if(h&1) odd.pb(a[u]);
	else even.pb(a[u]);
	return (h&1);
}

map<int,int> ma;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=1;i<n;i++) 
	{
		cin>>par[i];
		par[i]--;
		adj[par[i]].pb(i);
	}
	par[0]=-1;
	dfs(0,-1);
	ll ans=0;
	int xr=0;
	for(int i=0;i<even.size();i++)
	{
		xr^=even[i];
	}
	for(int i=0;i<odd.size();i++) ma[odd[i]]++;
	if(xr==0)
	{
		ans+=ll(even.size())*ll(even.size() - 1);
		ans+=ll(odd.size())*ll(odd.size() - 1);
		ans>>=1;
	}
	for(int i=0;i<even.size();i++)
	{
		int tmp = (xr^even[i]);
		ans+=ma[tmp];
	}
	cout<<ans<<'\n';
}