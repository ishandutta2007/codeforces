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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void solve()
{
	int n; cin>>n;
	vector<ll> vec;
	ll sum=0; ll xr=0;
	for(int i=0;i<n;i++)
	{
		ll x; cin>>x; vec.pb(x);
		sum+=x;
		xr^=x;
	}
	vec.pb(xr);vec.pb(xr+sum);
	ll sum2=0; ll xr2=0;
	for(int i=0;i<vec.size();i++)
	{
		sum2+=vec[i]; xr2^=vec[i];
	}
	assert(sum2==xr2*2);
	cout<<2<<'\n';
	cout<<xr<<' '<<xr+sum<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--)
	{
		solve();
	}
}