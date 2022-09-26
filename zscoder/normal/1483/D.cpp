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
typedef pair<ld,ld> state;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll d[602][602];
const ll INF = ll(2e18);
ll a[602][602];
vector<ii> adj[606];
ll dp[602];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	for(int i=0;i<n;i++)	
	{
		for(int j=0;j<n;j++) d[i][j]=INF;
		d[i][i]=0;
	}
	for(int i=0;i<m;i++)
	{
		int u,v; ll w;
		cin>>u>>v>>w;
		u--; v--;
		d[u][v]=d[v][u]=w;
		adj[u].pb({v,w}); adj[v].pb({u,w});
	}
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	int q; cin>>q;
	for(int i=0;i<q;i++)
	{
		int u,v; ll w; cin>>u>>v>>w;
		u--; v--;
		a[u][v]=a[v][u]=w;
	}
	set<ii> S;
	for(int e2=0;e2<n;e2++)
	{
		for(int u=0;u<n;u++)
		{
			dp[u]=INF;
		}
		for(int u=0;u<n;u++)
		{
			for(int v=0;v<n;v++)
			{
				if(a[u][v]>0) dp[u]=min(dp[u],d[e2][v]-a[u][v]);
			}
		}
		for(auto e:adj[e2])
		{
			int e1=e.fi; ll w=e.se;
			bool pos=0;
			for(int u=0;u<n;u++)
			{
				//cerr<<"EDGE "<<e2<<"-"<<e1<<" with "<<u<<" gives "<<d[u][e1]+w+dp[u]<<'\n';
				if(d[u][e1]+w+dp[u]<=0){pos=1; break;}
			}
			if(pos) 
			{
				//cerr<<"YES "<<min(e1,e2)<<' '<<max(e1,e2)<<'\n';
				S.insert({min(e1,e2),max(e1,e2)});
			}
		}
	}
	cout<<S.size()<<'\n';
}