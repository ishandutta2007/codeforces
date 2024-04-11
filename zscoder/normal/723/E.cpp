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

vi c[40001];
vi e[40001];
bool visited[40001];
int x[40001]; int y[40001];

void dfs(int u)
{
	visited[u] = true;
	for(int i = 0; i < e[u].size(); i++)
	{
		int v = e[u][i];
		if(visited[v]) continue;
		if(x[v] == x[u] || y[v] == y[u]) swap(x[v], y[v]);
		dfs(v);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--)
	{
		int n, m; cin>>n>>m;
		memset(visited, 0, sizeof(visited));
		for(int i = 1; i <= n; i++)
		{
			c[i].clear();
		}
		for(int i = 0; i < m; i++)
		{
			e[i].clear();
			int u, v; cin >> u >> v;
			c[u].pb(i); c[v].pb(i);
			x[i] = u; y[i] = v;
		}
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			if(c[i].size()%2==0) ans++;
			for(int j = 0; j + 1 < c[i].size(); j+=2)
			{
				e[c[i][j]].pb(c[i][j+1]);
				e[c[i][j+1]].pb(c[i][j]);
			}
		}
		for(int i = 0; i < m; i++)
		{
			if(!visited[i])
			{
				dfs(i);
			}
		}
		cout << ans << '\n';
		for(int i = 0; i < m; i++)
		{
			cout << x[i] << ' ' << y[i] << '\n';
		}
	}
}