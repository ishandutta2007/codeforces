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

vector<int> adj[1111];
ll a[2222];
bool rem[2222];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	ll ans=0;
	for(int i=0;i<m;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		adj[u].pb(v); adj[v].pb(u);
		ans+=min(a[u],a[v]);
	}
	cout<<ans<<'\n';
	/*
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		vector<ii> V;
		for(int j=0;j<n;j++)
		{
			if(rem[j]) continue;
			ll sum=0;
			for(int v:adj[j])
			{
				if(rem[v]) continue;
				sum+=a[v];
			}
			V.pb({sum,j});
		}
		sort(V.begin(),V.end());
		ans+=V[0].fi;
		int id=V[0].se;
		rem[id]=1;
		cerr<<V[0].fi<<' '<<V[0].se<<'\n';
	}
	cout<<ans<<'\n';
	*/
}