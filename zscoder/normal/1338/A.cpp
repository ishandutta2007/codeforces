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

ll a[111111];

ll bits(ll x)
{
	if(x==0) return 0;
	int d=0;
	while(x)
	{
		x>>=1; d++;
	}
	return d;
}

void solve()
{
	int n; cin>>n;
	ll ans=0;
	ll curmx=-ll(1e18);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		ll nw = max(curmx,a[i]);
		ll diff = nw-a[i];
		ans=max(ans,bits(diff));
		curmx=nw;
	}
	cout<<ans<<'\n';	
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}