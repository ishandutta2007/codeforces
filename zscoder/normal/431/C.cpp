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

int dp[101][101][101];
int k;

int add(int a, int b)
{
	return (a+b)%MOD;
}

int solve(int n, int s, int d)
{
	if(s <= 0) return 0;
	if(d < 0) return 0;
	if(n == 1 && d >= s) return 1;
	else if(n == 1) return 0;
	if(dp[n][s][d] != -1) return dp[n][s][d];
	int ans = 0;
	for(int i = 1; i <= d; i++)
	{
		ans = add(ans, solve(n - 1, s - i, d));
	}
	dp[n][s][d] = ans;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, d; cin >> n >> k >> d;
	memset(dp, -1, sizeof(dp));
	int ans = 0;
	for(int j = 1; j <= n; j++)
	{
		ans = add(ans, ((solve(j, n, k) - solve(j, n, d - 1))%MOD + MOD)%MOD);
	}
	cout << ans;
}