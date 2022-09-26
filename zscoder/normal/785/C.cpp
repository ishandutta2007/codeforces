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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
ll n,m; 
ll f(ll x)
{
	return (x*(x-1))/2 + (m+x);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	//for the first m days, it will be full
	if(m>=n)
	{
		cout<<n<<'\n'; return 0;
	}
	//m<=n
	ll lo = 1; ll hi = ll(2.5e9);
	ll ans = 0;
	while(lo<=hi)
	{
		ll mid=(lo+hi)>>1;
		if(f(mid)>=n)
		{
			ans=mid;
			hi=mid-1;
		}
		else lo=mid+1;
	}
	cout<<ans+m<<'\n';
}