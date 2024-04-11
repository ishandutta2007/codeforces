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
typedef pair<int,ii> iii;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll a[3]; cin>>a[0]>>a[1]>>a[2];
	ll ans = ll(3e18);
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			ll tmp[3];
			tmp[0] = 0; tmp[1] = 0; tmp[2] = 0;
			for(int k = i; k < 3; k++)
			{
				tmp[k]++;
			}
			for(int k = 0; k <= j; k++)
			{
				tmp[k]++;
			}
			ll x = a[0] - tmp[0];
			ll y = a[1] - tmp[1];
			ll z = a[2] - tmp[2];
			ll m = max(x,max(y,z));
			ll ans2 = m*3+tmp[0]+tmp[1]+tmp[2] - a[0] - a[1] - a[2];
			//cerr<<x<<' '<<y<<' '<<z<<'\n';
			ans = min(ans, ans2);
		}
	}
	for(int i = 0; i < 3; i++)
	{
		for(int j = i; j < 3; j++)
		{
			ll tmp[3];
			tmp[0] = 0; tmp[1] = 0; tmp[2] = 0;
			for(int k = i; k <= j; k++)
			{
				tmp[k]++;
			}
			if(a[0]<=tmp[0]&&a[1]<=tmp[1]&&a[2]<=tmp[2])
			{
				ans = min(ans, tmp[0]-a[0]+tmp[1]-a[1]+tmp[2]-a[2]);
			}
		}
	}
	cout << ans;
}