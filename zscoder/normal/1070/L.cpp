#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef bitset<2011> b100;

void solve()
{
	int n,m; cin>>n>>m;
	vector<vi> adj(n);
	vi ans(n,1);
	for(int i=0;i<m;i++)
	{
		int u,v; cin>>u>>v; u--; v--; 
		adj[u].pb(v); adj[v].pb(u);
	}
	bool pos=1;
	for(int i=0;i<n;i++)
	{
		if(adj[i].size()&1){pos=0; break;}
	}
	if(pos)
	{
		cout<<1<<'\n';
		for(int i=0;i<n;i++){cout<<1; if(i+1<n) cout<<' ';}
		cout<<'\n';
		return ;
	}
	vector<b100> a(n);
	for(int i=0;i<n;i++)
	{
		for(int v:adj[i])
		{
			a[i].set(v,1);
		}
		if(adj[i].size()&1) 
		{
			a[i].set(i,1); a[i].set(n,1);
		}
	}
	for(int i=0;i<n;i++)
	{
		if(!a[i][i])
		{
			for(int j=i+1;j<n;j++)
			{
				if(a[j][i]) {swap(a[i],a[j]); break;}
			}
		}
		if(!a[i][i]) continue;
		for(int j=i+1;j<n;j++)
		{
			if(a[j][i]) a[j]^=a[i];
		}
	}
	for(int i=n-1;i>=0;i--)
	{
		int cur=a[i][n];
		for(int j=n-1;j>i;j--)
		{
			cur^=(a[i][j]*(ans[j]-1));
		}
		ans[i]=cur+1;
	}
	cout<<2<<'\n';
	for(int i=0;i<n;i++)
	{
		cout<<ans[i];
		if(i+1<n) cout<<' ';
	}
	cout<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}