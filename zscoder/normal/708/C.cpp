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

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

vi adj[400001];
int sub[400001];
int par[400001];
bool ans[400001];
int n;

void dfs(int u, int p)
{
	sub[u] = 1;
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if(v == p) continue ;
		dfs(v, u);
		sub[u] += sub[v];
	}
}

int centroid(int u, int p)
{
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if(v == p) continue ;
		if(sub[v] <= n/2) continue;
		return centroid(v, u);
	}
	return u;
}

void dfs2(int u, int p)
{
	sub[u] = 1;
	//cout << u << ' ' << p << endl;
	if(p != -1)
	{
		if(par[p] == -1)
		{
			par[u] = u;
		}
		else
		{
			par[u] = par[p];
		}
	}
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if(v == p) continue ;
		dfs2(v, u);
		sub[u] += sub[v];
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i = 0; i < n - 1; i++)
	{
		int u, v; cin >> u >> v;
		u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	dfs(0, -1);
	int cent = centroid(0, -1);
	par[cent] = -1;
	dfs2(cent, -1);
	//cout << cent << endl;
	memset(ans, 0, sizeof(ans));
	int best = -1; int secondbest = -1; int bestidx = -1;
	for(int i = 0; i < n; i++)
	{
		//cout << i << ' ' << par[i] << endl;
		if(par[i] == i)
		{
			if(sub[i] >= best)
			{
				if(sub[i] == best)
				{
					if(bestidx == -1) bestidx = i;
					else bestidx = -2;
				}
				else
				{
					bestidx = i;
				}
				secondbest = best;
				best = sub[i];
			}
			else if(sub[i] >= secondbest)
			{
				secondbest = sub[i];
			}
		}
	}
	//cout << best << ' ' << secondbest << ' ' << bestidx << endl;
	for(int i = 0; i < n; i++)
	{
		if(i == cent)
		{
			ans[i] = 1;
			continue;
		}
		int p = par[i];
		int maxsize = 0;
		if(p == bestidx)
		{
			maxsize = max(secondbest, sub[p] - sub[i]);
		}
		else
		{
			maxsize = best;
		}
		int siz = n - sub[i] - maxsize;
		//cout << i << ' ' << p << ' ' << siz << ' ' << maxsize << endl;
		if(siz <= n/2) ans[i] = 1;
		else ans[i] = 0;
	}
	for(int i = 0; i < n; i++)
	{
		cout << ans[i] << ' ';
	}
}