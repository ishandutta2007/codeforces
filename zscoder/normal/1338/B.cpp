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
int h[222222];
int bad;
int leaf[222222];

void dfs(int u, int p=-1)
{
	int child=0;
	for(int v:adj[u])
	{
		if(v==p) continue;
		if(leaf[v]) child++;
		h[v]=h[u]+1;
		dfs(v,u);
	}
	if(child>0) bad+=child-1;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	int r=0;
	for(int i=0;i<n;i++) 
	{
		if(adj[i].size()!=1) r=i;
		else leaf[i]=1;
	}
	bad=0;
	dfs(r,-1);
	int small=1;
	set<int> S;
	for(int i=0;i<n;i++)
	{
		if(leaf[i]) S.insert((h[i]&1));
	}
	if(S.size()>1) small=3;
	cout<<small<<' '<<n-1-bad<<'\n';
}