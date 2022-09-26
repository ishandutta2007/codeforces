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
typedef vector<ll> vi;
typedef long double ld;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;
typedef vector<ll>::iterator vit;

vector<ii> pt;
ll yval[100001];

ll srt (ll cval)
{
	ll lo = 0, hi = 15e8;
	while (lo < hi)
	{
		ll mid = (lo + hi) / 2;
		if (mid * mid >= cval)
			hi = mid;
		else
			lo = mid + 1;
	}
	return lo;
}

ll solve (int start, int end)
{
	if (start == end)
		return 2e18;
	int mid = (start + end) / 2;
	
	ll val = min (solve (start, mid), solve (mid + 1, end));
	ll csum = srt (val);
	
	pt.clear();
	for (int i = max ((ll) start, mid - csum); i <= min ((ll) end, mid + csum); i++)
		pt.push_back (make_pair (yval[i], i));
	
	sort (pt.begin(), pt.end());
	for (int i = 0; i < pt.size(); i++)
	{
		for (int j = i - 1; j >= 0 && i - j < 10; j--)
		{
			val = min (val, (pt[j].first - pt[i].first) * (pt[j].first - pt[i].first) + (pt[j].second - pt[i].second) * (pt[j].second - pt[i].second));
		}
		for (int j = i + 1; j < pt.size() && j - i < 10; j++)
		{
			val = min (val, (pt[j].first - pt[i].first) * (pt[j].first - pt[i].first) + (pt[j].second - pt[i].second) * (pt[j].second - pt[i].second));
		}
	}
	return val;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n; pt.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> yval[i];
		if(i>0) yval[i]+=yval[i-1];
	}
	cout << solve(0,n-1);
}