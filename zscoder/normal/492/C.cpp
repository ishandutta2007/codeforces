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

ll a[100001];
deque<ii> vec;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,r,avg; cin>>n>>r>>avg;
	ll sum = ll(avg)*n;
	for(int i = 0; i < n; i++)
	{
		ll b;
		cin >> a[i] >> b;
		sum -= a[i];
		if(r - a[i] > 0) vec.pb(mp(b, r - a[i]));
	}
	if(!vec.empty()) sort(vec.begin(), vec.end());
	if(sum <= 0) {cout<<0; return 0;}
	ll ans = 0;
	while(!vec.empty())
	{
		ll a = vec.front().se; ll b = vec.front().fi;
		if(sum >= a)
		{
			sum -= a;
			ans += a*b;
		}
		else
		{
			ans += sum*b;
			sum = 0;
			break;
		}
		vec.pop_front();
	}
	cout << ans;
}