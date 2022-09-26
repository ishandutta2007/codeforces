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

ll a[111111];
vi adj[111111];

void solve()
{
	ll sum=0;
	int n; cin>>n;
	for(int i=0;i<n;i++) 
	{
		cin>>a[i]; sum+=a[i];
	}
	for(int i=0;i<n-1;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	vector<ll> incre;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j+1<adj[i].size();j++) incre.pb(a[i]);
	}
	sort(incre.rbegin(),incre.rend());
	for(int i=0;i<n-1;i++)
	{
		cout<<sum;
		if(i+1<n-1) cout<<' ';
		if(i<incre.size()) sum+=incre[i];
	}
	cout<<'\n';
	for(int i=0;i<n;i++) adj[i].clear();
	
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t; while(t--) solve();
}