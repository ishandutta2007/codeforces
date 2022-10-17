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

const int N = 1e6 + 100;
const ll inf = 1e18;
const ll mod = 998244353;//1e9 + 7;

int n, m;
int a[N];
ll sum[N];

void sol()
{
	cin >> n >> m;
	ll res = 0;
	for(int i = 1; i <= n; i++)
		cin >> a[i], sum[i] = sum[i - 1] + a[i];
	res = -inf;
	if(m < n)
	{
		int k = m;
		for(int i = 1; i + k - 1 <= n; i++)
			res = max(res, sum[i + k - 1] - sum[i - 1]);
		cout << res + 1LL * (m - 1) * m / 2LL << '\n';
	}
	else
	{
		res = sum[n] + 1LL * (m - 1) * n;
		ll tmp = 1LL * (n - 1) * n / 2LL;
		cout << res - tmp << '\n';
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