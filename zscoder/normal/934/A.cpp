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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	vector<ll> a,b; 
	for(int i=0;i<n;i++)
	{
		ll x; cin>>x;
		a.pb(x);
	}
	for(int i=0;i<m;i++)
	{
		ll x; cin>>x;
		b.pb(x);
	}
	ll ans=ll(2e18); //minimize this
	for(int i=0;i<n;i++)
	{
		//hide i
		ll mx=-ll(2e18);
		for(int j=0;j<n;j++)
		{
			if(j==i) continue;
			for(int k=0;k<m;k++)
			{
				mx=max(mx,a[j]*b[k]);
			}
		}
		ans=min(ans,mx);
	}
	cout<<ans<<'\n';
}