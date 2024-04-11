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
	ll n;
	cin >> n;
	ll ans = 6;
	ans = ans * qpow(4, (1LL << n) - 2) % mod;
	cout << ans << '\n';
	return 0;
}