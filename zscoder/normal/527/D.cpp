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

bool cmp(ii a, ii b)
{
	if(a.se!=b.se) return a.se<b.se;
	else return a.fi<b.fi;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<ii> vec;
	vec.resize(n);
	for(int i = 0; i < n; i++)
	{
		ll x, y; cin >> x >> y;
		vec[i] = ii(x - y, x + y);
	}
	sort(vec.begin(), vec.end(), cmp);
	int ans = 1; int la = 0;
	for(int i = 1; i < n; i++)
	{
		if(vec[i].fi >= vec[la].se)
		{
			la = i;
			ans++;
		}
	}
	cout << ans;
}