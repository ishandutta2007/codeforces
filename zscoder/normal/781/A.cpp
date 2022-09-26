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
int col[200001];

void dfs(int u, int p)
{
	int cur = 1;
	for(int i=0;i<adj[u].size();i++)
	{
		int v = adj[u][i];
		if(v==p) continue;
		while(cur==col[u]||(p!=-1&&cur==col[p]))
		{
			cur++;
		}
		col[v]=cur;
		cur++;
	}
	for(int i=0;i<adj[u].size();i++)
	{
		int v = adj[u][i];
		if(v==p) continue;
		dfs(v,u);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int u, v; cin>>u>>v;
		u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	col[0] = 1;
	dfs(0,-1);
	int maxcol=0;
	for(int i=0;i<n;i++) maxcol=max(maxcol,col[i]);
	cout<<maxcol<<'\n';
	for(int i=0;i<n;i++)
	{
		cout<<col[i]<<' ';
	}
}