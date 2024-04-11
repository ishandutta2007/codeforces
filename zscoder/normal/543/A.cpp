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
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int MOD;
int a[501];

int add(int a, int b)
{
	return (a+b)%MOD;
}

int mult(int a, int b)
{
	return int(ll(a)*ll(b)%MOD);
}

int dp[2][501][501];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, b, MOD;
	cin>>n>>m>>b>>MOD;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for(int i = 0; i <= m; i++)
	{
		if(a[0]*i <= b) dp[0][i][a[0]*i] = 1;
	}
	for(int i = 1; i < n; i++)
	{
		int cur = (i&1); int prev = (cur^1);
		for(int j = 0; j <= m; j++)
		{
			for(int k = 0; k <= b; k++)
			{
				//cerr << i << ' ' << j << ' ' << k << endl;
				if(j == 0)
				{
					if(k == 0) dp[cur][j][k] = 1;
					else dp[cur][j][k] = 0;
				}
				else
				{
					dp[cur][j][k] = dp[prev][j][k];
					//cerr << i << ' ' << j - 1 << ' ' << k - a[i] << endl;
					//cerr << dp[1][0][0] << endl;
					//if(k >= a[i]) cerr << dp[i][j][k] << ' ' << dp[i][j-1][k-a[i]] << endl;
					if(k >= a[i]) dp[cur][j][k] = (dp[cur][j-1][k-a[i]]+dp[cur][j][k])%MOD;
				}
				//cerr << i << ' ' << j << ' ' << k << endl;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i <= b; i++)
	{
		ans = (ans+dp[(n-1)&1][m][i])%MOD;
	}
	cout << ans;
}