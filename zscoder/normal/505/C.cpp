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

int cnt[30001];
int dp[30001][520];
int d;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n >> d;
	for(int i = 0; i < n; i++)
	{
		int x; cin >> x; cnt[x]++;
	}
	memset(dp,-1,sizeof(dp));
	int ans = 0;
	dp[d][250] = cnt[d];
	ans = max(ans, cnt[d]);
	for(int i = d + 1; i <= 30000; i++)
	{
		int shift = 250;
		for(int j = 0; j <= 500; j++)
		{
			int jump = j - shift + d;
			if(jump <= 0) continue;
			if(i - jump > 0)
			{
				//if(i <= 30) cerr << i << ' ' << jump << '\n';
				if(dp[i-jump][jump-1-d+shift] != -1)
				{
					dp[i][j] = max(dp[i][j], dp[i-jump][jump-1-d+shift]+cnt[i]);
				}
				if(dp[i-jump][jump-d+shift] != -1)
				{
					dp[i][j] = max(dp[i][j], dp[i-jump][jump-d+shift]+cnt[i]);
				}
				if(dp[i-jump][jump+1-d+shift] != -1)
				{
					dp[i][j] = max(dp[i][j], dp[i-jump][jump+1-d+shift]+cnt[i]);
				}
			}
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
}