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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void solve()
{
	int n; cin>>n;
	vi a;
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		ll x; cin>>x; a.pb(x);
		if(i%2==0) ans+=x;
	}
	ll mx=0;
	for(int i=0;i<2;i++)
	{
		int st=i;
		vector<ll> arr;
		while(st+1<n)
		{
			arr.pb(a[st+1]-a[st]);
			st+=2;
		}
		if(i==1)
		{
			for(int i=0;i<arr.size();i++) arr[i]*=-1;
		}
		ll sum = 0;
		for (int r = 0; r < arr.size(); ++r) 
		{
			sum += arr[r];
			mx = max(mx, sum);
			sum = max(sum, 0LL);
		}
	}
	ans+=mx;
	cout<<ans<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}