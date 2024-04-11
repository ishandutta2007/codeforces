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

const int N = 100001;
const int LG = 18;
vector<ii> adj[N];
int rmqtable[(N<<1)][LG];
int level[N<<1];
int euler[N<<1];
int depth[N];
int firstocc[N];
int eulercnt = 0;
bool visited[N];
int ans[N];
int calc[N];

void allclr(int n)
{
	for(int i = 0; i < n; i++)
	{
		visited[i] = false;
		depth[i] = 0;
		firstocc[i] = 0;
	}
	for(int i = 0; i < (n<<1); i++)
	{
		euler[i] = 0;
		level[i] = 0;
	}
	eulercnt = 0;
}

void dfs(int u, int p)
{
	euler[eulercnt] = u; eulercnt++;
	if(p == -1) {depth[u] = 0;}
	else {depth[u] = depth[p] + 1;}
	firstocc[u] = eulercnt-1;
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i].fi;
		if(v == p) continue ;
		dfs(v, u);
		euler[eulercnt] = u; eulercnt++;
	}
}

void filllevel()
{
	for(int i = 0; i < eulercnt; i++)
	{
		level[i] = depth[euler[i]];
	}
	level[eulercnt] = 1e9 + 7;
	for(int j = 0; j < LG; j++)
	{
		for(int i = 0; i < eulercnt; i++)
		{
			rmqtable[i][j] = eulercnt;
			if(i + (1<<j) - 1 < eulercnt)
			{
				if(j == 0)
				{
					rmqtable[i][j] = i;
				}
				else
				{
					if(level[rmqtable[i][j - 1]] < level[rmqtable[i + (1<<(j-1))][j - 1]])
					{
						rmqtable[i][j] = rmqtable[i][j-1];
					}
					else
					{
						rmqtable[i][j] = rmqtable[i + (1<<(j-1))][j - 1];
					}
				}
			}
		}
	}
}

int rmq(int l, int r)
{
	int k = 31 - __builtin_clz(r-l);
	//cout << l << ' ' << r << ' ' << rmqtable[l][k] << ' ' << rmqtable[r - (1<<k) + 1][k] << endl;
	if(level[rmqtable[l][k]] < level[rmqtable[r - (1<<k) + 1][k]])
	{
		return rmqtable[l][k];
	}
	else
	{
		return rmqtable[r - (1<<k) + 1][k];
	}
}

int lca(int u, int v)
{
	if(firstocc[u] > firstocc[v]) swap(u, v);
	//cout << firstocc[u] << ' ' << firstocc[v] << ' ' << rmq(firstocc[u], firstocc[v]) << ' ' << euler[rmq(firstocc[u], firstocc[v])] << endl;
	return euler[rmq(firstocc[u], firstocc[v])];
}

void dfs2(int u, int p, int ed)
{
	//cerr << u << ' ' << p << ' ' << ed << '\n';
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i].fi; int e = adj[u][i].se;
		if(v == p) continue;
		dfs2(v, u, e);
		calc[u] += calc[v];
	}
	if(p != -1) ans[ed] = calc[u];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	allclr(n);
	for(int i = 0; i < n - 1; i++)
	{
		int u, v; cin >> u >> v;
		u--; v--;
		adj[u].pb(ii(v, i)); adj[v].pb(ii(u, i));
	}
	dfs(0, -1); filllevel();
	int m; cin >> m;
	for(int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		u--; v--;
		int lc = lca(u, v);
		calc[u]++; calc[v]++; calc[lc] -= 2;
	}
	dfs2(0, -1, -1);
	for(int i = 0; i < n - 1; i++)
	{
		cout << ans[i] << ' ';
	}
}