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

int p[222222];
ll s[222222];
vi adj[222222];
ll a[222222];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	p[0]=-1;
	for(int i=1;i<n;i++)
	{
		cin>>p[i]; p[i]--; adj[p[i]].pb(i);
	}
	for(int i=0;i<n;i++) cin>>s[i];
	for(int i=0;i<n;i++)
	{
		if(s[i]==-1)
		{
			s[i]=ll(1e17);
			for(int v:adj[i])
			{
				s[i]=min(s[i],s[v]);
			}
			if(adj[i].empty()) s[i]=s[p[i]];
			if(s[i]<s[p[i]]){cout<<-1<<'\n'; return 0;}
		}
	}
	a[0]=s[0];
	for(int i=1;i<n;i++)
	{
		if(s[i]<s[p[i]]){cout<<-1<<'\n'; return 0;}
		a[i]=s[i]-s[p[i]];
	}
	ll sum=0;
	for(int i=0;i<n;i++) sum+=a[i];
	cout<<sum<<'\n';
}