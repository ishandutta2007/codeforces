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

int color[200001];
vi adj[200001];
vector<int> ans;

void move(int u)
{
	ans.pb(u); color[u]^=1;
}

void dfs(int u, int p)
{
	move(u);
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if(v == p) continue;
		dfs(v, u);
	}
	if(p != -1)
	{
		move(p);
		if(color[u]) return ;
		else
		{
			move(u); move(p);
			return ;
		}
	}
	else
	{
		if(color[u])
		{
			return ;
		}
		else
		{
			move(adj[u][0]);
			move(u);
			move(adj[u][0]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> color[i];
		if(color[i] == -1) color[i] = 0;
	}
	for(int i = 0; i < n - 1; i++)
	{
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	//ans.pb(1);
	color[1]^=1;
	dfs(1, -1);
	for(int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << ' ';
	}
}