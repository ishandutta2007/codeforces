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
const int inf = 1e9;
//const ll inf = 1e18;

ll n, m, k, mod;

bool vi[110][110][110];
ll dp[110][110][110], fac[210], C[210][210];

ll f(ll n, ll m, ll k)
{
	if(vi[n][m][k])
		return dp[n][m][k];
	//cerr << "GG" << n << ' ' << m << ' ' << k << '\n';
	vi[n][m][k] = 1;
	if(n == 0 && k == 0)
		return dp[n][m][k] = 1;
	if(m <= 0 && k == 0)
		return dp[n][m][k] = fac[n];
	if(m <= 0)
		return dp[n][m][k] = 0;
	ll res = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= k && j < i; j++)
		{
			if(j == k && m == 1)
				continue;
			int jj = k - j - (m == 1);
			if(jj > n - i)
				continue;
			res = (res + f(i - 1, m - 1, j) * f(n - i, m - 1, jj) % mod * C[n - 1][i - 1]) % mod;
		}
	}
	return dp[n][m][k] = res;
}
void sol()
{
	cin >> n >> m >> k >> mod;
	fac[0] = 1;
	for(int i = 1; i <= 200; i++)
		fac[i] = fac[i - 1] * i % mod;
	C[0][0] = 1;
	for(int i = 1; i <= 200; i++)
	{
		C[i][0] = 1;
		for(int j = 1; j <= 200; j++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
	}
	cout << f(n, m, k) << '\n';
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
//	int tt;
//	cin >> tt;
//	while(tt--)
		sol();
}