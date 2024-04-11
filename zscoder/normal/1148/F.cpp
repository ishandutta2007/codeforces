#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ii a[333333];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); 
	int n; cin>>n;
	ll s=0;
	for(int i=0;i<n;i++)
	{
		ll x,y; cin>>x>>y; a[i]=mp(x,y); s+=x;
	}
	if(s<0)
	{
		for(int i=0;i<n;i++) a[i].fi*=-1;
	}
	ll ans=0;
	for(int i=62;i>=0;i--)
	{
		ll sum=0;
		for(int j=0;j<n;j++)
		{
			if((a[j].se&((1LL<<(i+1))-1))==(1LL<<i))
			{
				sum+=a[j].fi;
			}
		}
		if(sum>0)
		{
			ans^=(1LL<<i);
			for(int j=0;j<n;j++)
			{
				if(a[j].se&(1LL<<i)) a[j].fi*=-1;
			}
		}
	}
	cout<<ans<<'\n';
}