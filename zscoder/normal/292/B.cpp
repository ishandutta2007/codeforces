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

vector<int> adj[333333];


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	if(m>n)
	{
		cout<<"unknown topology\n"; return 0;
	}
	if(m==n-1)
	{
		for(int i=0;i<n;i++)
		{
			if(int(adj[i].size())==n-1)
			{
				cout<<"star topology\n"; return 0;
			}
		}
	}
	if(m==n)
	{
		for(int i=0;i<n;i++)
		{
			if(adj[i].size()!=2)
			{
				cout<<"unknown topology\n"; return 0;
			}
		}
		cout<<"ring topology\n"; return 0;
	}
	if(m==n-1)
	{
		int ans=0;
		for(int i=0;i<n;i++)
		{
			if(adj[i].size()>2)
			{
				cout<<"unknown topology\n"; return 0;
			}
			if(adj[i].size()==1) ans++;
		}
		if(ans==2) cout<<"bus topology\n"; 
		else cout<<"unknown topology\n";
		return 0;
	}
	cout<<"unknown topology\n"; return 0;
}