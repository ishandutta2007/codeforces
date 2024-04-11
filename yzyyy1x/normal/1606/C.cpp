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

int a[N];
ll cost[N], sum[N];

bool hav[N];

void sol()
{
	ll n, k;
	cin >> n >> k;
	++k;
	memset(hav, 0, sizeof hav);
	for(int i = 1; i <= n ;i++)
		cin >> a[i], hav[a[i]] = 1;
	int mx;
	ll cur = 0;
	for(int i = 0; i <= 100; i++)
	{
		ll each = 0;
		int bg = i;
		ll nw = 1;
		for(int j = bg; j >= 0; j--)
		{
			if(hav[j])
			{
				each = nw;
				break;
			}
			nw = nw * 10;
		}
		cost[i] = each;
		cur += each * 9;
		sum[i] = cur;
		if(cur >= k)
		{
			mx = i;
			break;
		}
	}
	ll hav = 0;
	for(int i = mx; i >= 0; i--)
	{
		ll bf;
		if(i == 0)
			bf = 0;
		else
			bf = sum[i - 1];
		ll need = k - hav;
		//cerr << i << ' ' << bf << ' ' << need << '\n';
		if(need <= bf)
			cout << 0;
		else
		{
			ll tmp = 0;
			int res = 0;
			while(tmp + bf < need)
				tmp += cost[i], res++;
			hav += tmp;
			cout << res;
		}
	}
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