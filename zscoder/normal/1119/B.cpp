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

ll a[1111];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; ll h; cin>>n>>h;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int lo=0; int hi=n-1;
	int ans=-1;
	while(lo<=hi)
	{
		int mid=(lo+hi)>>1;
		vi vec;
		for(int i=0;i<=mid;i++)
		{
			vec.pb(a[i]);
		}
		sort(vec.rbegin(),vec.rend());
		ll sum=0;
		if(int(vec.size())&1) vec.pb(0);
		for(int i=0;i<vec.size();i+=2)
		{
			sum+=max(vec[i],vec[i+1]);
		}
		if(sum<=h)
		{
			ans=mid; lo=mid+1;
		}
		else hi=mid-1;
	}
	cout<<ans+1<<'\n';
}