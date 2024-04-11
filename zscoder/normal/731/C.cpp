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

int c[200001];
vi adj[200001];
vi concomp[200001];
int cc = 0;
bool visited[200001];

void dfs(int u)
{
	concomp[cc].pb(c[u]);
	visited[u] = true;
	for(int i = 0; i < adj[u].size(); i++)
	{
		if(!visited[adj[u][i]]) dfs(adj[u][i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,k; cin>>n>>m>>k;
	for(int i = 0; i < n; i++)
	{
		cin >> c[i];
	}	
	for(int i = 0; i < m; i++)
	{
		int u, v; cin>>u>>v;
		u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	for(int i = 0; i < n; i++)
	{
		if(!visited[i])
		{
			dfs(i);
			cc++;
		}
	}
	int ans = 0;
	for(int i = 0; i < cc; i++)
	{
		map<int,int> ma;
		for(int j = 0; j < concomp[i].size(); j++)
		{
			ma[concomp[i][j]]++;
		}
		int mx = 0; int sum = 0;
		for(mit it = ma.begin(); it != ma.end(); it++)
		{
			sum += it->se;
			mx = max(mx, it->se);
		}
		sum -= mx;
		ans += sum;
	}
	cout << ans;
}