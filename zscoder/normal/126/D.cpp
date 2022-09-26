#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

//Problem : Find number of sets of DISTINCT fibonacci numbers that sum up to n with at most k elements

const int K = 101;
const int N = 99;
const int MOD = 1e9 + 7;
const ll MAX = 1e18;

ll dp[2][3][3];
bool used[N];
ll fib[N];

ll add(ll a, ll b)
{
	ll r = (a + b)%MOD;
	r = (r + MOD)%MOD;
	return r;
}

void precom()
{
	fib[0] = 1; fib[1] = 1;
	for(int i = 2; i < N; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
		if(fib[i] > MAX) fib[i] = MAX + 1234567;
	}
	memset(dp, 0, sizeof(dp));
	memset(used, 0, sizeof(used));
}

ll solve(ll n, ll m)
{
	precom();
	int bestfib = 0;
	for(int i = N - 1; i >= 1; i--)
	{
		if(n >= fib[i])
		{
			bestfib = max(bestfib, i);
			n -= fib[i];
			used[i] = 1;
		}
	}
	m = min(ll(bestfib), m);
	dp[1][1][0] = 1; dp[1][0][0] = 1;
	for(int j = 0; j <= 2; j++)
	{
		for(int k = 0; k <= 2; k++)
		{
			{
				if(j == 0)
				{
					if(k <= 2) dp[0][j][k] = dp[1][k][0];
				}
				else
				{
					if( k + 2*(j - 1) <= 2) dp[0][j][k] = dp[1][k + 2*(j - 1)][0];
					//2 cannot be split into 2 1s because we require distinct
				}
				//cerr << 2 << ' ' << j << ' ' << k << ' ' << l << ' ' << dp[0][j][k][l] << '\n';
			}
		}
	}
	for(int i = 3; i <= bestfib; i++)
	{
		int cur = i%2; int prev = (cur^1);
		for(int j = 0; j <= 2; j++)
		{
			for(int k = 0; k <= 2; k++)
			{
			
				{
					if(j == 0)
					{
						if(k <= 2) dp[cur][j][k] = dp[prev][k][used[i - 2]];
					}
					else
					{
						if(j - 1 + k <= 2 && j - 1 + used[i - 2] <= 2) dp[cur][j][k] = dp[prev][j - 1 + k][j - 1 + used[i - 2]];
						if(k + j <= 2 && j + used[i - 2] <= 2) dp[cur][j][k] = add(dp[cur][j][k], dp[prev][j + k][j + used[i - 2]]);
					}
					//cerr << i << ' ' << j << ' ' << k << ' ' << l << ' ' << dp[cur][j][k][l] << '\n';
				}
			}
		}
	}
	ll ans = dp[bestfib%2][1][0];
	ans = (ans + MOD)%MOD;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll t; cin >> t;
	while(t--)
	{
		ll n, m; cin >> n; m = 100;
		cout << solve(n, m) << '\n';
	}
	/*
	for(int i = 0; i <= m; i++)
	{
		for(int j = 0; j <= m; j++)
		{
			if(i + j <= m) dp[1][i][0][j] = 1;
		}
	}
	*/
	/*
	for(int j = 0; j <= m; j++)
	{
		for(int k = 0; k <= m; k++)
		{
			for(int l = 0; l <= m; l++)
			{
				if(j == 0)
				{
					dp[0][j][k][l] = dp[1][k][0][l];
				}
				else
				{
					if(l + 1 <= m) dp[0][j][k][l] = dp[0][j - 1][k][l + 1];
					if(k + 2*j <= m) dp[0][j][k][l] = add(dp[0][j][k][l], dp[1][k + 2*j][0][l]);
				}
				//cerr << 2 << ' ' << j << ' ' << k << ' ' << l << ' ' << dp[0][j][k][l] << '\n';
			}
		}
	}
	*/	
	/*
	for(int i = 3; i <= bestfib; i++)
	{
		int cur = i%2; int prev = (cur^1);
		for(int j = 0; j <= m; j++)
		{
			for(int k = 0; k <= m; k++)
			{
				for(int l = 0; l <= m; l++)
				{
					if(j == 0)
					{
						dp[cur][j][k][l] = dp[prev][k][used[i - 2]][l];
					}
					else
					{
						if(l + 1 <= m) dp[cur][j][k][l] = dp[cur][j - 1][k][l + 1];
						if(k + j <= m) dp[cur][j][k][l] = add(dp[cur][j][k][l], dp[prev][j + k][j + used[i - 2]][l]);
					}
					//cerr << i << ' ' << j << ' ' << k << ' ' << l << ' ' << dp[cur][j][k][l] << '\n';
				}
			}
		}
	}
	*/
	//cout << ans << '\n';
}