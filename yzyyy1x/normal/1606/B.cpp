#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define sc second
#define pb push_back
#define ll long long
#define trav(v, x) for(auto v:x)
#define VI vector<int>
#define VLL vector<ll>
//define double long double
#define all(x) (x).begin(),(x).end()
using namespace std;
const double eps = 1e-10;//1e-12
const int N = 2e5 + 100;
const ll mod = 998244353;//1e9 + 7;

void sol()
{
	ll n, k;
	cin >> n >> k;
	if(k == 1)
		cout << n - 1 << '\n';
	else
	{
		ll ans = 0;
		ll nw = 1;
		while(nw < n)
		{
			if(nw <= k)
			{
				nw *= 2;
				++ans;
			}
			else
			{
				ll las = n - nw;
				ans += las / k;
				nw += las / k * k;
				if(las % k)
					++ans, nw += k;
				break;
			}
		}
		cout << ans << '\n';
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--)
	{
		sol();
	}
}