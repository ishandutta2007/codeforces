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
	int n,k; cin>>n>>k;
	vi vec;
	for(int i=0;i<n;i++)
	{
		ll x; cin>>x; vec.pb(x);
	}
	sort(vec.rbegin(),vec.rend());
	vi a;
	for(int i=0;i<k;i++)
	{
		int x; cin>>x;
		a.pb(x);
	}
	sort(a.begin(),a.end());
	int ptr=0;
	ll ans=0;
	for(int i=0;i<k;i++)
	{
		ans+=vec[i];
		if(a[i]==1) ans+=vec[i];
	}
	ptr=k;
	for(int i=0;i<k;i++)
	{
		int cnt = a[i];
		if(cnt==1) continue;
		for(int j=1;j<cnt-1;j++) ptr++;
		ans+=vec[ptr]; ptr++;
	}
	cout<<ans<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}