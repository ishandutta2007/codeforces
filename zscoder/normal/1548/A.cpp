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
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

set<int> adj[222222];

int cmp(int x)
{
	if(adj[x].empty()) return 1;
	//cerr<<x<<": "<<(*prev(adj[x].end()))<<'\n';
	if((*prev(adj[x].end()))<x) return 1;
	return 0;
}

ll ans=0;

void ins(int u, int x)
{
	ans-=cmp(u);
	adj[u].insert(x);
	ans+=cmp(u);
}

void del(int u, int x)
{
	ans-=cmp(u);
	adj[u].erase(x);
	ans+=cmp(u);
}

void addedge(int u, int v)
{
	ins(u,v);
	ins(v,u);
}

void deledge(int u, int v)
{
	del(u,v);
	del(v,u);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	for(int i=0;i<n;i++) 
	{
		ans+=cmp(i);
	}
	for(int i=0;i<m;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		addedge(u,v);
	}
	
	int q; cin>>q;
	while(q--)
	{
		int t; cin>>t;
		if(t==2)
		{
			int u,v; cin>>u>>v; u--; v--;
			deledge(u,v);
		}
		else if(t==1)
		{
			int u,v; cin>>u>>v; u--; v--;
			addedge(u,v);
		}
		else
		{
			cout<<ans<<'\n';
		}
	}
}