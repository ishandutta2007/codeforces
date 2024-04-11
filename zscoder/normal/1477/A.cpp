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
typedef pair<ld,ld> state;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void solve()
{
	vector<ll> a;
	int n; ll k; cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		ll x; cin>>x; a.pb(x);
	}
	sort(a.begin(),a.end());
	ll gd = a[1]-a[0];
	for(int i=2;i<n;i++) gd=__gcd(gd,a[i]-a[i-1]);
	if(abs(k-a[0])%gd==0) cout<<"YES\n";
	else cout<<"NO\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}