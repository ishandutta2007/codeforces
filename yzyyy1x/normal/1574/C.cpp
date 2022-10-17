#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define sc second
#define pb push_back
#define ll long long
#define trav(v,x) for(auto v:x)
using namespace std;
const int N = 1e6 + 100;

int n;
ll a[N];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i<= n; i++)
		cin >> a[i];
	ll sum = 0;
	for(int i = 1;i <= n; i++)
		sum += a[i];
	sort(a + 1, a + n + 1);
	int qq;
	cin >> qq;
	while(qq--)
	{
		ll x, y;
		cin >> x >> y;
		ll ans = 2e18;
		// 0 or upd sum only
		int ps = lower_bound(a + 1, a + n + 1, x) - a;
		if(ps <= n)
		{
			ll val = sum - a[ps];
			if(val >= y)
			{
				cout << 0 << '\n';
				continue;
			}
			else
				ans = min(ans, y - val);
		}
		// upd one
		if(sum >= y)
		{
			ll tmp = sum - y;
			int ps = lower_bound(a + 1, a + n + 1, tmp) - a;
			if(ps > n || a[ps] > tmp)
				--ps;
			if(ps != 0)
			{
				ans = min(ans, max(0LL, x - a[ps]));
			}
		}
		// can upd both
		ps = lower_bound(a + 1, a + n + 1, x) - a;
		if(ps > n || a[ps] > x)ps--;
		if(ps >= 1)
		{
			ll tmp = x - a[ps];
			ll val = sum - a[ps];
			ans = min(ans, tmp + max(0LL, y - val));
		}
		cout << ans << '\n';
	}
	return 0;
}