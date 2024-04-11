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

vi adj[522222];
int a[522222];
int vis[522222];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	vector<ii> vec;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		vec.pb({a[i],i});
	}
	vi ans;
	sort(vec.begin(),vec.end());
	for(int i=0;i<vec.size();i++)
	{
		int id=vec[i].fi; int u=vec[i].se;
		set<int> S;
		for(int v:adj[u])
		{
			if(vis[v])
			{
				S.insert(a[v]);
			}
		}
		for(int j=1;j<id;j++)
		{
			if(S.find(j)==S.end())
			{
				cout<<-1<<'\n'; return 0;
			}
		}
		if(S.find(id)!=S.end()){cout<<-1<<'\n'; return 0;}
		vis[u]=1;
		ans.pb(u);
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]+1;
		if(i+1<n) cout<<' ';
	}
	cout<<'\n';
}