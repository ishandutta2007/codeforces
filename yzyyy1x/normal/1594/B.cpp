#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define sc second
#define pb push_back
#define ll long long
#define trav(v,x) for(auto v:x)
using namespace std;
const int N = 1e6 + 100;
const ll mod = 1e9 + 7;

int n;
int a[N];

ll qpow(ll x, ll y)
{
	ll res = 1;
	while(y)
	{
		if(y & 1)
			res = res * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return res;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--)
	{
		ll n, k;
		cin >> n >> k;
		for(int i = 0; k; i++)
		{
			if((1LL << i) < k)
				k -= (1LL << i);
			else
			{
				ll ans = 0;
				ans = (ans + qpow(n, i)) % mod;
				--k;
				for(int j = i - 1; j >= 0 && k; j--)
				{
					ll hav = (1LL << j);
					if(k < hav)continue;
					ans = (ans + qpow(n, j)) % mod;
					k -= (1LL << j);
				}
				cout << ans << '\n';
				break;
			}
		}
	}
	return 0;
}