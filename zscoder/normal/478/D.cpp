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

ll add(ll a, ll b)
{
	return (a+b)%MOD;
}

int dp[2][200001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll r, g; cin >> r >> g;
	dp[1][1] = 1; dp[1][0] = 1;
	for(int i = 2; i <= 900; i++)
	{
		int cur = (i&1); int prev = (cur^1);
		for(int j = 0; j <= r; j++)
		{
			if((ll(i)*ll(i+1))/2 - j > g) continue;
			dp[cur][j] = dp[prev][j];
			if(j >= i) dp[cur][j] = (dp[cur][j] + dp[prev][j-i])%MOD;
		}
	}
	ll ra = r; ll ga = g;
	int h = 0;
	ll sum = r + g;
	while(sum >= h + 1)
	{
		sum -= (h+1);
		h++;
	}
	ll ans = 0;
	r = ra; g = ga;
	//cerr << h << '\n';
	for(int i = 0; i <= r; i++)
	{
		if((ll(h)*ll(h+1))/2 - i > g) continue;
		ans = add(ans, dp[h&1][i]);
	}
	cout << ans;
}