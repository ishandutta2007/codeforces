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

int n;
ll a[N], sum[N];;

void sol()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	ll coef = 0;
	for(int i = 2; i <= n; i++)
		coef += a[1] + a[i];
	if(coef > 0)
	{
		cout << "INF" << '\n';
		return;
	}
	coef = 0;
	for(int i = 1; i < n; i++)
		coef += a[i] + a[n];
	if(coef < 0)
	{
		cout << "INF" << '\n';
		return;
	}
	ll ans = -2e18;
	coef = 0;
	for(ll i = 1; i < n; i++)
	{
		ll lp = -a[i + 1], rp = -a[i];
		ll b = sum[i] * a[n] + (sum[n - 1] - sum[i]) * a[1];
		ll k = (sum[n - 1] - a[1]) + a[1] * (n - i) + i * a[n];
		ans = max(ans, max(k * lp, k * rp) + b);
	}
	cout<< ans << '\n';
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