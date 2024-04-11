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
	int n; ll x; cin>>n>>x;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		char c; cin>>c;
		ll y; cin>>y;
		if(c=='+') x+=y;
		else
		{
			if(x>=y) x-=y;
			else ans++;
		}
	}
	cout<<x<<' '<<ans<<'\n';
}