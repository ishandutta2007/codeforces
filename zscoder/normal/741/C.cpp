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

int a[200001];
bool d[200001];
vector<ii> query;
bool visited[200001];
vi adj[200001];

void dfs(int u)
{
	visited[u]=1;
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if(!visited[v])
		{
			a[v]=a[u]^1;
			dfs(v);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		int u, v; cin >> u >> v;
		u--; v--;
		query.pb(mp(u,v));
		adj[u].pb(v); adj[v].pb(u);
		adj[2*i].pb(2*i+1); adj[2*i+1].pb(2*i);
	}
	for(int i = 0; i < n*2; i++)
	{
		if(!visited[i]) dfs(i);
	}
	for(int i = 0; i < n; i++)
	{
		int l = query[i].fi; int r = query[i].se;
		if(a[l]==0) a[l]=2;
		if(a[r]==0) a[r]=2;
		cout<<a[l]<<' '<<a[r]<<'\n';
	}
}