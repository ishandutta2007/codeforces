#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define sc second
#define pb push_back
#define ll long long
#define trav(v,x) for(auto v:x)
#define all(x) (x).begin(), (x).end()
#define VI vector<int>
#define VLL vector<ll>
#define pll pair<ll, ll>
#define double long double
//#define int long long
using namespace std;
const int N = 2e6 + 100;
const int inf = 1e9;
//const ll inf = 1e18;
const ll mod = 1e9 + 7;

#ifdef LOCAL
void debug_out(){cerr << endl;}
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
	cerr << " " << to_string(H);
	debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

ll fac[N], pw[N], ifac[N], ipw[N];;

ll qpow(ll x, ll y = mod - 2)
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

void init()
{
	int n = 2e6;
	fac[0] = 1;
	for(int i = 1; i <= n; i++)
		fac[i] = fac[i - 1] * i % mod;
	ifac[n] = qpow(fac[n]);
	for(int i = n - 1; i >= 0; i--)
		ifac[i] = ifac[i + 1] * (i + 1) % mod;
	pw[0] = 1;
	for(int i = 1; i <= n; i++)
		pw[i] = pw[i - 1] * 2 % mod;	
	ipw[0] = 1;
	for(int i = 1; i <= n; i++)
		ipw[i] = ipw[i - 1] * (ll)(5e8 + 4) % mod;
}

ll C(ll x, ll y)
{
	if(x < y)
		return 0;
	if(y < 0)
		return 0;
	return fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}

void sol()
{
	int n, m, k;
	cin >> n >> m >> k;
	ll ban = 0, ans = 0;
	for(int i = 1; i <= m; i++)
	{
		ll val = i * 2 - 1;
		ll coef = C(n - 1, m - i);
		//cerr << val << ' ' << coef << '\n';
		ans = (ans + val * coef) % mod;
	}
	cout << ans * k % mod * ipw[n - 1] % mod << '\n';
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	init();
	int tt;
	cin >> tt;
	while(tt--)
		sol();
}