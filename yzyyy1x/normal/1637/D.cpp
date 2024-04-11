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

ll a[N], b[N];
ll sum[2][N];

void sol()
{
	int n;
	cin >> n;
	ll ans = 0;
	for(int i = 1; i <= n; i++)
		cin >> a[i], sum[0][i] = sum[0][i - 1] + a[i];
	for(int i = 1; i <= n; i++)
		cin >> b[i], sum[1][i] = sum[1][i - 1] + b[i];
	VLL dp(n * 101, inf);
	dp[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		VLL dq(n * 101, inf);
		for(int j = 0; j <= 100 * (i - 1); j++)
		{
			ll x = j;
			ll y = sum[0][i - 1] + sum[1][i - 1] - j;
			dq[x + a[i]] = min(dq[x + a[i]], dp[j] + a[i] * x + b[i] * y);
			dq[x + b[i]] = min(dq[x + b[i]], dp[j] + b[i] * x + a[i] * y);
		}
		swap(dp, dq);
	}
	ans = inf;
	for(int i = 0; i <= 100 * n; i++)
		ans = min(ans, dp[i]);
	ans *= 2;
	for(int i = 1; i <= n; i++)
		ans += (1LL * a[i] * a[i] + 1LL * b[i] * b[i]) * (n - 1);
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