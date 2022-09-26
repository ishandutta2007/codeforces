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

int dp[10000001][2];
const int MOD = 1e9 + 7;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	dp[1][0] = 0;
	dp[1][1] = 3;
	for(int i = 2; i <= n; i++)
	{
		dp[i][0] = dp[i-1][1];
		dp[i][1] = (dp[i-1][1]+dp[i-1][1]+dp[i-1][0]*3LL)%MOD;
	}
	cout<<dp[n][0];
}