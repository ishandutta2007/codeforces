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

vector<ll> dp[751];
ll a[751];
const ll INF = ll(1e16);
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin>>n>>m;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	for(int i = 0; i <= n; i++) dp[i].resize(n+1);
	dp[n][0] = 0;
	for(int i = n - 1; i >= 0; i--)
	{
		for(int j = 0; j <= n - i; j++)
		{
			dp[i][j] = -INF;
			if(j>0) dp[i][j] = dp[i+1][j-1];
			dp[i][j] = max(dp[i][j], min(0LL, dp[i+1][j] + a[i]));
		}
	}
	for(int i = 0; i < m; i++)
	{
		ll x; cin >> x;
		cout << lower_bound(dp[0].begin(),dp[0].end(),-x) - dp[0].begin() << '\n';
	}
}