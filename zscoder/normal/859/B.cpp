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
typedef long double ld; 
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n; cin>>n;
	for(ll i = 2; i <= 2000000; i++)
	{
		ll L = i/2; ll R = (i+1)/2;
		if(L*R>=n)
		{
			cout<<i*2<<'\n';
			return 0;
		}
	}
}