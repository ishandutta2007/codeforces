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

ll ans[333333];
vector<pair<ll,int> > vec;
ll x[333333];
ll y[333333];
ll X[333333];
ll Y[333333];

ll sumX(int l, int r)
{
	if(l>r) return 0;
	if(l==0) return X[r];
	else return X[r]-X[l-1];
}

ll sumY(int l, int r)
{
	if(l>r) return 0;
	if(l==0) return Y[r];
	else return Y[r]-Y[l-1];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
		vec.pb(mp(x[i]-y[i],i));
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<n;i++)
	{
		X[i]=x[vec[i].se]; Y[i]=y[vec[i].se];
		if(i>0) 
		{
			X[i]+=X[i-1]; Y[i]+=Y[i-1];
		}
	}
	for(ll i=0;i<n;i++)
	{
		int id = vec[i].se;
		if(i>0)
		{
			ans[id] += ll(i)*y[id] + sumX(0,i-1);
		}
		ans[id] += ll(n-1-i)*x[id] + sumY(i+1,n-1);
	}
	/*
	for(int i=0;i<n;i++)
	{
		cerr<<"ANS : "<<i<<' '<<ans[i]<<'\n';
	}
	*/
	for(int i=0;i<m;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		ans[u]-=min(x[u]+y[v],x[v]+y[u]);
		ans[v]-=min(x[u]+y[v],x[v]+y[u]);
	}
	for(int i=0;i<n;i++)
	{
		cout<<ans[i];
		if(i+1<n) cout<<' ';
	}
	cout<<'\n';
}