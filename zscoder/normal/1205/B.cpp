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
typedef vector<ll> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vi adj[222];
int d[222];
int par[222];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	vi a;
	for(int i=0;i<n;i++)
	{
		ll x; cin>>x;
		if(x==0) continue;
		a.pb(x);
	}
	if(a.empty())
	{
		cout<<-1<<'\n'; return 0;
	}
	if(a.size()>200)
	{
		cout<<3<<'\n'; return 0;
	}
	n=a.size();
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if((a[i]&a[j])!=0)
			{
				adj[i].pb(j); adj[j].pb(i);
			}
		}
	}
	int ans=int(1e9);
	for(int i=0;i<n;i++)
	{
		queue<int> q;
		for(int j=0;j<n;j++) 
		{
			par[j]=-1; d[j]=int(1e9);
		}
		q.push(i); d[i]=0;
		while(!q.empty())
		{
			int u=q.front(); q.pop();
			for(int v:adj[u])
			{
				if(d[v]>int(1e8))
				{
					d[v]=d[u]+1;
					if(d[v]==1) par[v]=v;
					else par[v]=par[u];
					q.push(v);
				}
			}
		}
		for(int j=0;j<n;j++)
		{
			for(int v:adj[j])
			{
				if(i==j||i==v) continue;
				if(par[j]==par[v]) continue;
				ans=min(ans,d[v]+d[j]+1);
			}
		}
	}
	if(ans>int(1e8)) ans=-1;
	cout<<ans<<'\n';
}