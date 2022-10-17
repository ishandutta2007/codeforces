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

int n, m, a[N];

int ans[N];

void calc(int i, int j)
{
	ll x = a[i], y = a[j];
	if(ans[i] >= 0)
	{
		if(y < 0)
		{
			ans[i] -= y;
			ans[j] += x;
		}
		else
		{
			ans[i] += y;
			ans[j] -= x;
		}
	}
	else
	{
		if(y > 0)
		{
			ans[i] -= y;
			ans[j] += x;
		}
		else
		{
			ans[i] += y;
			ans[j] -= x;
		}
	}
}

void sol()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		ans[i] = 0;
	}
	for(int i = 1; i <= n; i += 2)
	{
		if(i == n)
			break;
		calc(i, i + 1);
	}
	if(n & 1)
		calc(n - 1, n);
	for(int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
	cout << '\n';
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