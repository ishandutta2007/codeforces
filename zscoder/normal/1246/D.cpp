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

int par[111111];
set<int> adj[111111];
vi moves;
vi vec;
vi parlist;
int h[111111];

void prep(int u)
{
	for(int v:adj[u])
	{
		h[v]=h[u]+1;
		prep(v);
	}
}

void solve(int u)
{
	if(adj[u].empty()) return ;
	assert(parlist.back()==u);
	if(adj[u].size()<=1)
	{
		parlist.pop_back();
		solve((*adj[u].begin())); return ;
	}
	int v = parlist[int(parlist.size())-2];
	moves.pb(v);
	int w = v;
	for(int x:adj[u])
	{
		if(x!=v)
		{
			w=x; break;
		}
	}
	adj[u].erase(v);
	adj[w].insert(v);
	par[v]=w;
	parlist.pop_back();
	parlist.pb(w); parlist.pb(u);
	solve(u);
}

void dfs(int u)
{
	vec.pb(u);
	if(adj[u].empty()) return ;
	assert(adj[u].size()==1);
	dfs((*adj[u].begin()));
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n; par[0]=-1;
	for(int i=0;i<n-1;i++)
	{
		int p; cin>>p; par[i+1]=p;
		adj[p].insert(i+1);
	}
	prep(0);
	int mx=0; int mxn=0;
	for(int i=0;i<n;i++)
	{
		if(h[i]>=mx)
		{
			mx=h[i]; mxn=i;
		}
	}
	while(mxn!=-1)
	{
		parlist.pb(mxn); mxn=par[mxn];
	}
	solve(0);
	dfs(0);
	for(int x:vec)
	{
		cout<<x<<' ';
	}
	cout<<'\n';
	cout<<moves.size()<<'\n';
	reverse(moves.begin(),moves.end());
	for(int i=0;i<moves.size();i++)
	{
		cout<<moves[i];
		if(i+1<moves.size()) cout<<' ';
	}
	cout<<'\n';
}