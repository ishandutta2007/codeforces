#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int MOD = 1e9 + 7;
int a[2001];
vi adj[2001];
ll dp[2001];
bool visited[2001];
int d, n; 

void dfs(int u, int root)
{
	visited[u] = true;
	dp[u] = 1;
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if(visited[v]) continue;
		if(a[v] < a[root] || a[v] - a[root] > d) continue;
		if(a[v] == a[root] && v > root) continue;
		dfs(v, root);
		dp[u] = (dp[u] * (dp[v]+1))%MOD;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);	
	cin>>d>>n;
	for(int i = 0; i < n; i++) cin>>a[i];
	for(int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin>>u>>v;
		u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	ll ans = 0;
	for(int i = 0; i < n; i++)
	{
		memset(visited, false, sizeof(visited));
		dfs(i, i);
		ans = (ans + dp[i])%MOD;
	}
	cout << ans << '\n';
	return 0;
}