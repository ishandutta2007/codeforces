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

ll s[201];
ll e[201];
vector<ii> interval;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> s[i] >> e[i];
	}
	interval.pb(mp(0, 0));
	interval.pb(mp(ll(1e18),ll(1e18)));
	for(int i = 0; i < n; i++)
	{
		ll l = s[i]; ll r = s[i] + e[i] - 1;
		bool pos = true;
		for(int j = 0; j < int(interval.size()) - 1; j++)
		{
			if(interval[j].se < l || interval[j].fi > r)
			{
				
			}
			else
			{
				pos = false;
			}
		}
		if(pos)
		{
			interval.pb(mp(l,r));
			cout<<l<<' '<<r<<'\n';
		}
		else
		{
			for(int j = 0; j < int(interval.size()) - 1; j++)
			{
				ll L = interval[j].se + 1;
				ll R = interval[j+1].fi - 1;
				if(R - L + 1 >= e[i])
				{
					l = L;
					r = L + e[i] - 1;
					interval.pb(mp(l,r));
					cout<<l<<' '<<r<<'\n';
					break;
				}
			}
		}
		sort(interval.begin(),interval.end());
	}
}