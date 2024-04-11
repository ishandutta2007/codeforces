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

const int MOD = 1e9 + 7;
ll dp[2][3001];
int a[3001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, h;
	cin >> n >> h;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	memset(dp,0,sizeof(dp));
	if(a[1] == h || a[1] == h - 1) dp[1][0] = 1;
	if(a[1] == h - 1) dp[1][1] = 1;
	for(int i = 2; i <= n; i++)
	{
		int cur = (i&1); int prev = (cur^1);
		for(int j = 0; j <= n; j++)
		{
			dp[cur][j] = 0;
		}
		for(int j = 0; j <= n; j++)
		{
			//cerr << i - 1 << ' ' << j << ' ' << dp[prev][j] << '\n';
			if(a[i] == h - j)
			{
				dp[cur][j] = (dp[prev][j])%MOD;
				if(j>0) dp[cur][j]=(dp[cur][j]+dp[prev][j-1]*j)%MOD;
			}
			else if(a[i] == h - j - 1)
			{
				dp[cur][j] = (dp[prev][j]+dp[prev][j+1])%MOD;
				if(j>0) dp[cur][j]=(dp[cur][j]+dp[prev][j]*j)%MOD;
			}
			//cerr << i << ' ' << j << ' ' << dp[cur][j] << '\n';
		}
	}
	cout << dp[n&1][0];
}