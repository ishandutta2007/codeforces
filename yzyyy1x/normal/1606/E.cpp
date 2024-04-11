#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define sc second
#define pb push_back
#define ll long long
#define trav(v, x) for(auto v:x)
#define VI vector<int>
#define VLL vector<ll>
//define double long double
#define all(x) (x).begin(),(x).end()
using namespace std;
const double eps = 1e-10;//1e-12
const int N = 510;
const ll mod = 998244353;//1e9 + 7;

int n, m;
ll dp[2][N + N][N + N], C[N][N], ppow[N][N];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	dp[0][0][0] = 1;
	C[0][0] = 1;
	for(int i = 1; i <= 500; i++)
	{
		C[i][0] = 1;
		for(int j = 1; j <= i; j++)
		{
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
		}
	}
	for(int i = 1; i <= 500; i++)
	{
		ppow[i][0] = 1;
		for(int j = 1; j <= 500; j++)
		{
			ppow[i][j] = ppow[i][j - 1] * i % mod;
		}
	}
	ll ans = 0;
	for(int i = 1; i <= m + 10; i++)
	{
		int nw = (i & 1);
		int bf = (nw ^ 1);
		memset(dp[nw], 0, sizeof dp[nw]);
		int mnn = 1e9;
		for(int j = 0; j <= n - 2; j++)
		{
			for(int dam = 0; dam <= m; dam++)
			{
				if(!dp[bf][j][dam])
					continue;
//				if(i > m)
//					cerr << i << ' ' << j << ' ' << dam << ' ' << dp[bf][j][dam] << '\n';
				int ndam = dam + (n - j - 1);
				for(int die = 0; die + j <= n; die++)
				{
					dp[nw][j + die][ndam] = (dp[nw][j + die][ndam] + dp[bf][j][dam] * C[n - j][die] % mod * ppow[min(n - j - 1, m - dam)][die])% mod;
					if(dp[nw][j + die][ndam])
						mnn = min(mnn, ndam);
				}
			}
		}
//		cerr << i << ' ' << mnn << '\n';
//		if(i == 1)
//			cerr << dp[1][0][2] << '\n';
		for(int dam = 0; dam <= m + n; dam++)
		{
			dp[nw][n - 1][dam] = 0;
//			if(dp[nw][n][dam])cerr << i << ' ' << n << ' ' << dam << ' ' << dp[nw][n][dam] << '\n';
			ans = (ans + dp[nw][n][dam]) % mod;
		}
	}
	cout << ans << '\n';
}