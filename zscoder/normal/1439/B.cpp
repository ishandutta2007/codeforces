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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

unordered_set<int> adj[111111];

bool ex_edge(int u, int v)
{
	if(adj[u].find(v)!=adj[u].end()) return true;
	return false;
}

void solve()
{
	int n,m,k; cin>>n>>m>>k;
	set<ii> S;
	for(int i=0;i<m;i++)
	{
		int u,v;cin>>u>>v; u--; v--;
		adj[u].insert(v); adj[v].insert(u);
	}
	for(int i=0;i<n;i++)
	{
		S.insert({int(adj[i].size()),i});
	}
	bool pos=0;
	vi clique;
	int rem_edge = m;
	bool is_first_time=0;
	
	while(!S.empty())
	{
		ii tmp = (*S.begin());
		int siz=tmp.fi; int u=tmp.se;
		if(siz>=k) 
		{
			pos=1;
			break;
		}
		//remove diao u
		if(siz==k-1)
		{
			if(ll(k)*ll(k-1)<=2*rem_edge)
			{
				vi potential_clique;
				for(int v:adj[u]) potential_clique.pb(v);
				potential_clique.pb(u);
				random_shuffle(potential_clique.begin(),potential_clique.end());
				bool cl=1;
				for(int i=0;i<potential_clique.size();i++)
				{
					for(int j=i+1;j<potential_clique.size();j++)
					{
						int x=potential_clique[i]; int y=potential_clique[j];
						if(!ex_edge(x,y)){cl=0; break;}
					}
					if(!cl) break;
				}
				if(cl) {clique=potential_clique; break;}
			}
		}		
		//remove
		rem_edge-=adj[u].size();
		for(int v:adj[u])
		{
			S.erase({int(adj[v].size()),v});
			adj[v].erase(u);
			S.insert({int(adj[v].size()),v});
		}
		S.erase({int(adj[u].size()),u});
		adj[u].clear();
		
	}
	if(!clique.empty())
	{
		cout<<2<<'\n';
		for(int x:clique)
		{
			cout<<x+1<<' ';
		}
		cout<<'\n';
		for(int i=0;i<n;i++) adj[i].clear();
		return ;
	}
	if(pos)
	{
		cout<<1<<' '<<S.size()<<'\n';
		for(auto e:S)
		{
			cout<<e.se+1<<' ';
		}
		cout<<'\n';
		for(int i=0;i<n;i++) adj[i].clear();
		return ;
	}
	cout<<-1<<'\n';
	for(int i=0;i<n;i++) adj[i].clear();
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	srand(2190911);
	int t; cin>>t;
	while(t--) solve();
}