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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef float ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ld a[111111];
vi adj[111111];
vi heavyadj[111111];
const int C = 450;
int L[111111];

bool light(int x)
{
	return L[x];
}

ld dp[111111];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++) {cin>>a[i]; a[i]=1-a[i];}
	ld sum=0;
	for(int i=0;i<n;i++) sum+=a[i];
	ld sum2=0;
	vi heavy; vector<ii> e;
	for(int i=0;i<n-1;i++)
	{
		int u,v; cin>>u>>v; e.pb(mp(u,v)); adj[u].pb(v); adj[v].pb(u);
	}
	for(int i=0;i<n;i++) L[i]=(adj[i].size()<=C);
	for(int i=0;i<n-1;i++)
	{
		int u=e[i].fi; int v=e[i].se;
		if(!(light(u)^light(v))) sum2+=a[u]*a[v];
		else
		{
			if(light(u)) swap(u,v);
			dp[u]+=a[v];
		}
	}
	for(int i=0;i<n;i++)
	{
		if(!light(i)) heavy.pb(i);
	}
	for(int v:heavy)
	{
		for(int x:adj[v])
		{
			if(!light(x)) heavyadj[v].pb(x);
		}
	}
	int q; cin>>q;
	for(int i=0;i<q;i++)
	{
		int u; ld x; cin>>u>>x; x=1-x;
		sum-=a[u]; sum+=x;
		if(light(u))
		{
			for(int v:adj[u])
			{
				if(light(v))
				{
					sum2+=(x-a[u])*a[v];
				}
				else
				{
					dp[v]+=x-a[u];
				}
			}
		}
		else
		{
			for(int v:heavyadj[u])
			{
				sum2+=(x-a[u])*a[v];
			}
		}
		a[u]=x;
		ld S=sum2;
		for(int v:heavy)
		{
			S+=dp[v]*a[v];
		}
		cout<<fixed<<setprecision(9)<<sum-S<<'\n';
	}
}