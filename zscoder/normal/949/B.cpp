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
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

ll f(ll n, ll x)
{
	if(n==1) return 1;
	if(x%2==1)
	{
		return x/2 + 1;
	}
	ll half = (n+1)/2;
	if(n%2==0)
	{
		return f(n/2, x/2) + half;
	}
	else
	{
		if(x>=4) return f(n/2, x/2 - 1) + half; 
		else return f(n/2, n/2) + half;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n; int q; cin>>n>>q;
	while(q--)
	{
		ll x; cin>>x;
		cout<<f(n,x)<<'\n';
	}
}