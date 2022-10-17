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
const ll inf = 1e18;
const ll mod = 998244353;//1e9 + 7;

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

void sol()
{
	ll n;
	cin >> n;
	if(n & 1)
	{
		cout << 2 << '\n';
	}
	else
	{
		ll x = n, y = 1;
		while(x % 2 == 0)
			x >>= 1, y <<= 1;
		if(x > 1 && (x + 1) / 2LL <= n / x)
		{
			cout << x << '\n';
		}
		else
		{
			if(x == 1)
				cout << -1 << '\n';
			else
			{
				cout << y * 2 << '\n';
			}
		}
	}
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