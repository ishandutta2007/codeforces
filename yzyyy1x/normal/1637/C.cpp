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
	int n;
	cin >> n;
	VI a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	ll ans = 0;
	ll las = 0;
	bool flg = 0;
	int odd = 0, even = 0, num = 0;
	for(int i = 1; i + 1 < n; i++)
	{
		if(a[i] > 1)
		{
			if(a[i] & 1)
				odd++;
			else even++;
		}
	}
	if(even)
		flg = 1;
	if(odd && n > 3)
		flg = 1;
	for(int i = 1; i + 1 < n; i++)
	{
		if(a[i] % 2 == 0)
		{
			ans += a[i] / 2;
		}
		else
		{
			ans += (a[i] + 1) / 2;
		}
	}
	if(!flg)
		ans = -1;
	cout << ans << '\n';
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