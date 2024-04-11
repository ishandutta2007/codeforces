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
const int N = 100010;
vi adj[N];
int subsize[N];
bool visited[N];
int treesize;
char ans[N];

void dfs(int u, int par)
{
	subsize[u] = 1;
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if(visited[v]) continue;
		if(v == par) continue;
		dfs(v, u);
		subsize[u] += subsize[v];
	}	
	if(par == -1) treesize = subsize[u];
}

int centroid(int u, int par)
{
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if(visited[v]) continue;
		if(v == par) continue;
		if(subsize[v]*2 > treesize) return centroid(v, u);
	}
	return u;
}

void solve(int x, char c)
{
	ans[x] = c;
	for(int i = 0; i < adj[x].size(); i++)
	{
		if(ans[adj[x][i]] == '$') solve(adj[x][i], c);
	}
}

void compsolve(int u, char c)
{
	dfs(u, -1);
	int cent = centroid(u, -1);
	solve(cent, c);
	visited[cent] = true;
	for(int i = 0; i < adj[cent].size(); i++)
	{
		int v = adj[cent][i];
		if(!visited[v]) compsolve(v, c+1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++) ans[i] = '$';
	for(int i = 0; i < n - 1; i++)
	{
		int u, v; cin >> u >> v; u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	compsolve(0, 'A');
	for(int i = 0; i < n; i++) cout << ans[i] << ' ';
}