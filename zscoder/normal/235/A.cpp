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
	ll n; cin >> n;
	if(n==1){cout<<1; return 0;}
	if(n==2){cout<<2; return 0;}
	if(n==3){cout<<6; return 0;}
	if(n&1)
	{
		cout<<n*(n-1)*(n-2); return 0;
	}
	else
	{
		ll ans = max(n*(n-1)*(n-2)/2, (n-1)*(n-2)*(n-3));
		if(n%3!=0) ans = max(ans, n*(n-1)*(n-3));
		cout<<ans;
	}
}