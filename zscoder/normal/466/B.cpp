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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, a, b; cin >> n >> a >> b;
	n*=6LL;
	if(a*b >= n)
	{
		cout << a*b << '\n' << a << ' ' << b;
		return 0;
	}
	ll ansa = a; ll ansb = b; ll area = ll(1e18);
	for(ll i = a; i <= 100000; i++)
	{
		ll x = i; ll y = max(b,(n+x-1)/x);
		if(x*y < area)
		{
			area = x*y;
			ansa = x; ansb = y;
		}
	}
	for(ll i = b; i <= 100000; i++)
	{
		ll y = i; ll x = max(a,(n+y-1)/y);
		if(x*y < area)
		{
			area = x*y;
			ansa = x; ansb = y;
		}
	}
	cout << area << '\n' << ansa << ' ' << ansb;
}