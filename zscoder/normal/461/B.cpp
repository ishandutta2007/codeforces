#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

int par[100001];
int color[100001];
vi adj[100001];
ll dp[100001][2];

const int MOD = 1e9+7;

void dfs(int u)
{
	dp[u][color[u]] = 1;
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if(par[v] == u)
		{
			dfs(v);
			ll tmp0 = (dp[u][0]*dp[v][0] + dp[u][0]*dp[v][1])%MOD;
			ll tmp1 = (dp[u][0]*dp[v][1] + dp[u][1]*dp[v][1] + dp[u][1]*dp[v][0])%MOD;
			dp[u][0] = tmp0;
			dp[u][1] = tmp1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n - 1; i++)
	{
		cin >> par[i];
		adj[i].pb(par[i]);
		adj[par[i]].pb(i);
	}
	for(int i = 0; i < n; i++) cin >> color[i];
	dfs(0);
	cout << dp[0][1] << '\n';
	return 0;
}