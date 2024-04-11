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
//const ll inf = 1e18;
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
	int n, m;
	cin >> n >> m;
	VLL a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	ll d;
	for(int i = 0; i < m; i++)
	{
		if(i == 0)
			cin >> d;
		else
		{
			ll x;
			cin >> x;
			d = __gcd(d, x);
		}
	}
	VLL ans(2, 0);
	for(int t = 0; t < d; t++)
	{
		VLL dp(2, 0);
		dp[1] = -1e18;
		for(int i = t; i < n; i += d)
		{
			VLL dq(2);
			dq[0] = max(dp[0] + a[i], dp[1] - a[i]);
			dq[1] = max(dp[0] - a[i], dp[1] + a[i]);
			swap(dp, dq);
		}
		ans[0] += dp[0];
		ans[1] += dp[1];
	}
	cout << max(ans[0], ans[1]) << '\n';
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