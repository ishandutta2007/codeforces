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
ll dp[2][3001];
ll a[3001],s[3001];
int par[3001][3001];
ll b[3001];

#define REP(i,b) for(int (i)=(0);(i)<(b);(i)++)
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) 
	{
		cin >> a[i]; a[i] -= i;
	}
	for(int i = 0; i < n; i++) s[i]=a[i];
	sort(s,s+n);
	dp[0][0] = abs(a[0]-s[0]); par[0][0] = 0;
	for(int i = 1; i < n; i++)
	{
		dp[0][i] = abs(a[0] - s[i]);
		par[0][i] = i;
		if(dp[0][i-1] <= dp[0][i])
		{
			dp[0][i] = dp[0][i-1];
			par[0][i] = par[0][i-1];
		}
	}
	for(int i = 1; i < n; i++)
	{
		int cur = (i&1); int prev = (cur^1);
		dp[cur][0] = abs(a[i]-s[0])+dp[prev][0];
		par[i][0] = 0;
		for(int j = 1; j < n; j++)
		{
			dp[cur][j] = abs(a[i] - s[j]) + dp[prev][j];
			par[i][j] = j;
			if(dp[cur][j - 1] <= dp[cur][j])
			{
				dp[cur][j] = dp[cur][j-1];
				par[i][j] = par[i][j-1];
			}
		}
	}
	
	int cur2 = 0; ll mini = INF; int z = (n&1)^1;
	for(int i = 0; i < n; i++)
	{
		if(dp[z][i] < mini)
		{
			mini = dp[z][i];
			cur2 = i;
		}
	}
	cout << mini;
	//cerr << i << ' ' << s[i] << ' ' << tmpans << '\n';
}