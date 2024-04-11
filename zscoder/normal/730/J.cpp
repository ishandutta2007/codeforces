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

int a[101];
int b[101];
int dp[2][101][10001];
int INF = 1000000000;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	int total = 0;
	vector<ii> bot;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		total += a[i];
	}
	vi vec;
	for(int i = 0; i < n; i++)
	{
		cin >> b[i];
		vec.pb(b[i]);
		bot.pb(mp(a[i],b[i]));
	}
	sort(vec.begin(),vec.end());
	reverse(vec.begin(),vec.end());
	int prefsum = 0;
	int kk, t;
	t = 0;
	for(int i = 0; i < n; i++)
	{
		prefsum += vec[i];
		if(total <= prefsum)
		{
			kk = i + 1;
			break;
		}
	}
	for(int j = 0; j < 101; j++)
	{
		for(int k = 0; k < 10001; k++)
		{
			dp[0][j][k] = -1;
		}
	}
	dp[0][0][0] = 0;
	for(int i = 1; i <= n; i++)
	{
		int cur = (i&1); int prev = (cur^1);
		for(int j = 0; j < 101; j++)
		{
			for(int k = 0; k < 10001; k++)
			{
				dp[cur][j][k] = -1;
			}
		}
		for(int j = 0; j <= i; j++)
		{
			for(int k = 0; k <= 10000; k++)
			{
				dp[cur][j][k] = dp[prev][j][k];
				if(j > 0 && k >= b[i-1])
				{
					if(dp[prev][j-1][k-b[i-1]] == -1) continue;
					dp[cur][j][k] = max(dp[cur][j][k], dp[prev][j-1][k-b[i-1]] + a[i-1]);
				}
			}
		}
	}
	for(int tot = total; tot <= 10000; tot++)
	{
		//cerr<<n<<' '<<kk<<' '<<tot<<' '<<dp[n&1][kk][tot]<<'\n';
		t = max(t, dp[(n&1)][kk][tot]);
	}
	t = total - t;
	cout << kk << ' ' << t << '\n';
}