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
int col[222222];

void dfs(int u, int c)
{
	col[u]=c;
	for(int v:adj[u])
	{
		if(col[v]<0)
		{
			dfs(v,c^1);
		}
		else
		{
			if(col[v]!=(c^1)) {cout<<-1<<'\n'; exit(0);}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	memset(col,-1,sizeof(col));
	for(int i=0;i<n;i++)
	{
		if(col[i]<0) dfs(i,0);
	}
	vi a[2];
	for(int i=0;i<n;i++) a[col[i]].pb(i);
	cout<<a[0].size()<<'\n';
	for(int v:a[0])
	{
		cout<<v+1<<' ';
	}
	cout<<'\n';
	cout<<a[1].size()<<'\n';
	for(int v:a[1])
	{
		cout<<v+1<<' ';
	}
	cout<<'\n';
}