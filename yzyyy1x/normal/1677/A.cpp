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

const int N = 5000 + 100;
const int inf = 1e9;
//const ll inf = 1e18;
const ll mod = 998244353;//1e9 + 7;

int n;
int a[N], f[N][N], g[N][N];

void sol()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		f[i][n + 1] = 0;
		for(int j = n; j > i; j--)
		{
			f[i][j] = f[i][j + 1];
			if(a[j] < a[i])
				++f[i][j];
		}
		g[i][0] = 0;
		for(int j = 1; j < i; j++)
		{
			g[i][j] = g[i][j - 1];
			if(a[j] < a[i])
				++g[i][j];
		}
	}
	ll ans = 0;
	for(int b = 1; b <= n; b++)
	{
		for(int c = b + 1; c <= n; c++)
		{
			ll lp, rp;
			lp = g[c][b - 1];
			rp = f[b][c + 1];
			ans += 1LL * lp * rp;
		}
	}
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