#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long double ld;
const int MOD = 1e9 + 7;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

vi adj[100001];
int color[100001];
int counter;
bool cycle;
int ans;

void dfs(int u)
{
	color[u] = counter;
	int v;
	int exist = 0;
	for(int i = 0; i < adj[u].size(); i++)
	{
		v = adj[u][i];
		if(color[v] == 0)
		{
			dfs(v);
		}
		else
		{
			exist++;
		}
	}
	if(exist > 1)
	{
		cycle = true;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m;
	int u, v;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for(int i = 1; i <= n; i++)
	{
		if(color[i] == 0)
		{
			counter++;
			cycle = false;
			dfs(i);
			if(!cycle)
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}