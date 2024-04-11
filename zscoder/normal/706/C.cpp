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

const ll INF = ll(1e18);
const int MOD = 1e9 + 7;

ll c[100001];
ll dp[100001][2];
string s[100001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> c[i];
	}
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	dp[0][0] = 0; dp[0][1] = c[0];
	for(int i = 1; i < n; i++)
	{
		string tmp = s[i];
		reverse(tmp.begin(), tmp.end());
		string tmp2 = s[i - 1];
		reverse(tmp2.begin(), tmp2.end());
		dp[i][0] = INF; dp[i][1] = INF;
		if(s[i - 1] <= s[i])
		{
			dp[i][0] = min(dp[i][0], dp[i - 1][0]);
		}
		if(tmp2 <= s[i])
		{
			dp[i][0] = min(dp[i][0], dp[i-1][1]);
		}
		if(s[i - 1] <= tmp)
		{
			dp[i][1] = min(dp[i][1], dp[i - 1][0] + c[i]);
		}
		if(tmp2 <= tmp)
		{
			dp[i][1] = min(dp[i][1], dp[i - 1][1] + c[i]);
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			if(dp[i][j] >= INF) dp[i][j] = -1;
		}
	}
	if(dp[n - 1][0] == -1 && dp[n - 1][1] == -1) 
	{
		cout << -1;
		return 0;
	}
	else if(dp[n - 1][0] == -1)
	{
		cout << dp[n-1][1];
		return 0;
	}
	else if(dp[n-1][1] == -1)
	{
		cout << dp[n-1][0];
		return 0;
	}
	else
	{
		cout << min(dp[n-1][0], dp[n-1][1]);
		return 0;
	}
	return 0;
}