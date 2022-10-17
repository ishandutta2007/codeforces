//#define LOCAL
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
const int N = 1e6 + 100;
const int inf = 1e9;
//const ll inf = 1e18
const ll mod = 998244353;//1e9 + 7

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


int n;
int a[N];

ll f[N][2];

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

void sol()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		int x = a[i];
		if(x == 0)
		{
			f[0][1] = (f[0][1] * 2 + 1) % mod;
			f[x + 2][0] = f[x + 2][0] * 2 % mod;
		}
		else if(x == 1)
		{
			f[x][1] = (f[x][1] * 2 + f[x - 1][1]) % mod;
			f[1][0] = (f[1][0] * 2 + 1) % mod;
			f[x + 2][0] = f[x + 2][0] * 2 % mod;
		}
		else
		{
			f[x][1] = (f[x][1] * 2 + f[x - 1][1]) % mod;
			f[x][0] = (f[x][0] * 2 + f[x - 2][1]) % mod;
			f[x + 2][0] = f[x + 2][0] * 2 % mod;
		}
	}
	ll ans = 0;
	for(int i = 0; i <= n + 5; i++)
		ans = (ans + f[i][0] + f[i][1]) % mod;
	cout << ans << '\n';
	for(int i = 0; i <= n + 5; i++)
		f[i][0] = f[i][1] = 0;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--)
		sol();
}