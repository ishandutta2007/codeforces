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

ll n, m;
ll a[N], mx[N], mn[N];

ll f[N][3];

void sol()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i], a[i] += a[i - 1];
	cin >> m;
	for(int i = 1; i <= n; i++)
		a[i] -= m * i;
	memset(f, -63, sizeof f);
	f[1][0] = 0;
	f[1][1] = 1;
	f[1][2] = -inf;
	for(int i = 2; i <= n; i++)
	{
		f[i][0] = max({f[i - 1][0], f[i - 1][1], f[i - 1][2]});
		f[i][1] = f[i - 1][0] + 1;
		if(a[i] >= a[i - 2])
			f[i][2] = f[i - 1][1] + 1;
		if(i >= 3 && a[i] >= a[i - 2] && a[i] >= a[i - 3])
			f[i][2] = max(f[i][2], f[i - 1][2] + 1);
	}
	cout << max({f[n][0], f[n][1], f[n][2]}) << '\n';;
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