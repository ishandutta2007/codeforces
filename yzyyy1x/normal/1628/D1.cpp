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
const ll mod = 1e9 + 7;

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
	int n, m, k;
	cin >> n >> m >> k; 
	vector<VLL> dp(n + 1, VLL(m + 1, 0));
	ll inv2 = 5e8 + 4;
	for(int i = 1; i <= n; i++)
	{
		dp[i][0] = 0;
		for(int j = 1; j < i && j <= m; j++)
		{
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) * inv2 % mod;
		}
		if(i <= m)
			dp[i][i] = i;
	}
	cout << dp[n][m] * k % mod << '\n';
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