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

ll f[13][12][12];


int lim, cnt0, cnt1, p[14];
bool vis[14];

void dfs0(int x)
{
	if(x > lim)
	{
		int nw = 0, mx = 1;
		while(nw < mx)
		{
			++nw;
			mx = max(mx, p[nw]);
		}
		if(mx != lim)
			return;
		f[lim][cnt1][cnt0]++;
		return;
	}
	int still = 0;
	for(int i = 1; i <= lim; i++)
	{
		if(vis[i])
			continue;
		if(cnt1 + still > 11)
			break;
		vis[i] = 1, p[x] = i;
		if(x > 1 && p[x] < p[x - 1])
			++cnt0;
		cnt1 += still;
		dfs0(x + 1);
		if(x > 1 && p[x] < p[x - 1])
			--cnt0;
		cnt1 -= still;
		vis[i] = 0;
		still++;
	}
}

ll dp[15][60][12][12];
void init()
{
	int p[14];
	for(int num = 2; num <= 12; num++)
	{
		memset(vis, 0, sizeof vis);
		lim = num;
		cnt0 = 0, cnt1 = 0, dfs0(1);
	}
//	for(int i = 1; i <= 11; i++)
//	{
//		for(int j = 1; j <= 11; j++)
//		{
//			if(f[3][i][j])
//				cerr << "!!" << i << ' ' << j << ' ' << f[3][i][j] << '\n';
//		}
//	}
	dp[0][0][0][0] = 1;
	for(int i = 0; i <= 13; i++)
	{
		for(int use = 0; use <= 50; use++)
		for(int j = 0; j < 11; j++)
		{
			for(int k = 0; k < 11; k++)
			{
				if(dp[i][use][j][k])
				{
					for(int num = 2; num <= 12 && use + num <= 50; num++)
					{
						for(int jj = 1; jj + j <= 11; jj++)
						{
							for(int kk = 1; kk + k <= 11; kk++)
							{
								(dp[i + 1][num + use][j + jj][k + kk] += dp[i][use][j][k] * f[num][jj][kk]) %= mod;
							}
						}
					}
				}
			}
		}
	}
}

ll n, k, x;

ll qpow(ll x, ll y = mod - 2)
{
	ll res = 1;
	while(y)
	{
		if(y & 1)
			res = res * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return res;
}

ll calc(ll x, ll y)
{
	if(x < y || y < 0)
		return 0LL;
	ll res = 1;
	ll tmp = 1;
	for(ll i = x, j = 1; j <= y; j++, i--)
	{
		res = res * i % mod;
		tmp = tmp * j % mod; 
	}
	//cerr << "!!" << x << ' ' <<  y << ' ' << res << '\n';
	return res * qpow(tmp) % mod;
}

void sol()
{
	ll res = 0;
	cin >> n >> k >> x;
	for(int i = 1; i <= 12; i++)
	{
		for(int use = 1; use <= 30; use++)
		{	
			if(!dp[i][use][k][x])
				continue;
//			if(dp[i][use][k][x] && calc(n - use + i, i))
//				cerr << "!!" << i << ' ' << use << ' ' << dp[i][use][k][x] << '\n';
			res = (res + dp[i][use][k][x] * calc(n - use + i, i)) % mod;
		}
	}
	cout << res << '\n';
}

signed main()
{
	init();
//	cerr << "GG" << '\n';
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--)
		sol();
}