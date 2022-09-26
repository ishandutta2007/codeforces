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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	vector<ll> a,b;
	for(int i=0;i<n;i++)
	{
		ll x; cin>>x; a.pb(x);
	}	
	for(int i=0;i<m;i++)
	{
		ll y; cin>>y; b.pb(y);
	}
	ll gd = 0;
	for(int i=0;i+1<n;i++)
	{
		gd=__gcd(abs(a[i+1]-a[i]),gd);
	}
	for(int i=0;i<m;i++)
	{
		cout<<__gcd(b[i]+a[0],gd)<<' ';
	}
	cout<<'\n';
}