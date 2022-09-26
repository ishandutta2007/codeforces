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
typedef pair<ld,ld> state;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vi out[222222]; //stores the outedges of each vertex
bool vis[222222]; //whether a vertex is visited
vi adj[222222];
vi T[222222]; //adjacency list for the dfs tree
vi backedges[222222]; //backedges from a specific vertex

void dfs(int u, int p=-1) //p = parent in the dfs tree
{
	vis[u]=1;
	for(int v:adj[u])
	{
		if(v==p) continue; //do nothing, because i just came from the parent
		if(vis[v]) //v is visited before
		{
			backedges[u].pb(v); //means there is a backedge u-v
		}
		else
		{
			T[u].pb(v); //u->v is an edge in the dfs tree
			dfs(v,u);
		}
	}
}

void dfs2(int u, int p=-1)
{
	//first, i recursively solve all the children
	for(int v:T[u])
	{
		dfs2(v,u);
	}
	//need to determine the direction of the parent edge
	if(p==-1) return ;
	if(out[u].size()&1) //if vertex u has odd outdegree, i orient u->p
	{
		out[u].pb(p);
	}
	else
	{
		out[p].pb(u);
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
	vi roots;
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			dfs(i);
			roots.pb(i);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int v:backedges[i]) 
		{
			if(i<v) out[i].pb(v);
		}
	}
	for(int r:roots)
	{
		dfs2(r);
	}
	//now, every edge is oriented
	vector<vi> ans;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<out[i].size();j+=2)
		{
			if(j+1<out[i].size())
			{
				ans.pb({out[i][j],i,out[i][j+1]});
			}
		}
	}
	cout<<ans.size()<<'\n';
	for(auto X:ans)
	{
		cout<<X[0]+1<<' '<<X[1]+1<<' '<<X[2]+1<<'\n';
	}
}