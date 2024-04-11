#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fill(a,v) memset(a, v, sizeof a)
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll lINF = ll(1e18);
/*A
bool open[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int s, x;
	fill(open, false);
	for(int i = 0; i < n; i++)
	{
		cin >> s;
		for(int j = 0; j < s; j++)
		{
			cin >> x;
			open[x-1] = true;
		}
	}
	for(int i = 0; i < m; i++)
	{
		if(open[i] == false)
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}*/

vvi graph;
ll dp[100001];
ll deg[100001];
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int x, y;
	vi empty;
	for(int i = 0; i < n; i++)
	{
		graph.pb(empty);
	}
	for(int i = 0; i < m; i++)
	{
		cin >> x >> y;
		x--;
		y--;
		graph[max(x, y)].pb(min(x, y));
		deg[x]++;
		deg[y]++;
	}
	ll maximum = 0;
	ll maxlength = 1;
	fill(dp, 1);
	for(int i = 0; i < n; i++)
	{
		maxlength = 1;
		for(int j = 0; j < graph[i].size(); j++)
		{
			maxlength = max(maxlength, dp[graph[i][j]] + 1);
		}
		dp[i] = maxlength;
		//cout << dp[i] << endl;
		maximum = max(maximum, maxlength*deg[i]);
	}
	cout << maximum << endl;
	return 0;
}


/*C
int main()
{
	ios_base::sync_with_stdio(false);
	
	return 0;
}
*/

/*D
int main()
{
	ios_base::sync_with_stdio(false);
	
	return 0;
}
*/

/*E
int main()
{
	ios_base::sync_with_stdio(false);
	
	return 0;
}
*/