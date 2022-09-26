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

ll a[111111];
ll ans[111111];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	vector<ll> D;
	for(int i=0;i+1<n;i++) D.pb(a[i+1]-a[i]);
	sort(D.rbegin(),D.rend());
	int q; cin>>q;
	vector<ii> vec;
	for(int i=0;i<q;i++)
	{
		ll l,r; cin>>l>>r;
		ans[i]=a[n-1]+r-(a[0]+l)+1;
		vec.pb(mp(r-l+1,i));
	}
	sort(vec.rbegin(),vec.rend());
	int ptr=-1;ll sum=0;
	for(int i=0;i<q;i++)
	{
		ll L = vec[i].fi; int id=vec[i].se;
		while(ptr+1<D.size()&&D[ptr+1]>L)
		{
			ptr++; sum+=D[ptr];
		}
		//cerr<<id<<' '<<sum<<' '<<L*ll(ptr+1)<<'\n';
		ans[id]+=L*ll(ptr+1);
		ans[id]-=sum;
	}
	for(int i=0;i<q;i++)
	{
		cout<<ans[i];
		if(i+1<q) cout<<' ';
	}
	cout<<'\n';
}