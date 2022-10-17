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

int n, m;
ll a[N], sum[N], mx[N], nmx[N];

void sol()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	memset(mx, 63, sizeof mx);
	for(int ans = 1; ans <= 500; ans++)
	{
		memset(nmx, 0, sizeof nmx);
		for(int i = 1; i <= n; i++)
		{
			if(i + ans - 1 > n)
				break;
			ll nw = sum[i + ans - 1] - sum[i - 1];
			if(nw < mx[i + ans])
			{
				nmx[i] = nw;
			}
		}
		ll cur = 0;
		for(int i = n; i >= 1; i--)
		{
			cur = max(cur, nmx[i]);
			nmx[i] = cur;
		}
		if(cur == 0)
		{
			cout << ans - 1 << '\n';
			return;
		}
		memcpy(mx, nmx, sizeof nmx);
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