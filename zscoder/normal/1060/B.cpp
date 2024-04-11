#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int sod(ll x)
{
	ll ans=0;
	while(x)
	{
		ans+=x%10;
		x/=10;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n; cin>>n;
	ll t = 1;
	while(t*10-1<=n) t*=10;
	cout<<sod(t-1)+sod(n-(t-1))<<'\n';
}