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
#define int long long
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
const int inf = 1e9;
//const ll inf = 1e18;
const ll mod = 998244353;//1e9 + 7;

ll a[N];

void sol()
{
	int n;
	ll x;
	cin >> n;
	cin >> x;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	if(n == 1)
	{
		cout << max(a[1], x) - 1 << '\n';
		return;
	}
	ll mn = inf;
	ll mx = -inf;
	for(int i = 1; i <= n; i++)
		mn = min(mn, a[i]), mx = max(mx, a[i]);
	ll res = 0;
	for(int i = 1; i < n; i++)
		res += abs(a[i + 1] - a[i]);
	if(mn > 1)
	{
		//1 to mn - 1
		ll tmp = min(a[1], a[n]) - 1;
		for(int i = 1; i < n; i++)
		{
			tmp = min(tmp, min(a[i], a[i + 1]) * 2 - 2);
		}
		res += tmp;
	}
	if(mx < x)
	{
		ll tmp = x - max(a[1], a[n]);
		for(int i = 1; i < n; i++)
		{
			tmp = min(tmp, 2 * x - max(a[i], a[i + 1]) * 2);
		}
		res += tmp;
	}
	cout << res << '\n';
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