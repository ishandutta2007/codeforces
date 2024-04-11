#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

vector<ii> adj[100001];
vi ans;
int dp[100001];
bool visited[100001];
bool color[100001];

void dfs(int u)
{
	visited[u] = true;
	if(color[u]) dp[u]++;
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i].fi;
		if(!visited[v]) 
		{
			dfs(v); dp[u] += dp[v];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n - 1; i++)
	{
		int x, y, w;
		cin>>x>>y>>w;
		adj[x].pb(ii(y, w));
		adj[y].pb(ii(x, w));
		if(w == 2) {color[x] = 1; color[y] = 1;}
	}
	dfs(1);
	for(int i = 1; i <= n; i++)
	{
		if(dp[i] == 1) ans.pb(i);
	}
	cout << ans.size() << '\n';
	for(int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}