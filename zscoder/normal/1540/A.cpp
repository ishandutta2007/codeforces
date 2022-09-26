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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

void solve()
{
	int n; cin>>n;
	vector<ll> a;
	for(int i=0;i<n;i++)
	{
		ll x; cin>>x; a.pb(x);
	}
	sort(a.begin(),a.end());
	ll ans=0;
	ans=a[n-1];
	for(int i=0;i<n;i++)
	{
		int l = i;
		int r = n-1-l;
		ans+=r*1LL*a[i];
		ans-=l*1LL*a[i];
	}
	cout<<ans<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}