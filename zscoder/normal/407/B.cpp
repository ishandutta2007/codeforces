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

int p[1111];
ll dp[1111];
const int MOD = 1e9 + 7;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> p[i];
	}
	dp[1] = 2;
	for(int i = 2; i <= n; i++)
	{
		dp[i] = 1;
		for(int j = p[i]; j < i; j++)
		{
			dp[i] = (dp[i] + dp[j])%MOD;
		}
		dp[i] = (dp[i]+1)%MOD;
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++)
	{
		ans = (ans+dp[i])%MOD;
	}
	cout<<ans;
}