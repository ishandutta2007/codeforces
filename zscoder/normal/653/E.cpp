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

set<ii> edges;

void yes(){cout << "possible";}
void no(){cout << "impossible";}

bool valid(int u, int v)
{
	if(u > v) swap(u, v);
	if(edges.find(mp(u, v)) == edges.end()) return true;
	else return false;
}

set<int> unvisited;

void dfs(int u)
{
	vi adj;
	for(sit it = unvisited.begin(); it != unvisited.end(); it++)
	{
		if(valid(u, (*it)))
		{
			adj.pb((*it));
		}
	}
	for(int i = 0; i < adj.size(); i++)
	{
		unvisited.erase(adj[i]);
	}
	for(int i = 0; i < adj.size(); i++)
	{
		dfs(adj[i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, k; cin >> n >> m >> k;
	int deg = n - 1;
	for(int i = 2; i <= n; i++) unvisited.insert(i);
	for(int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		edges.insert(mp(min(u, v), max(u, v)));
		if(min(u, v) == 1) deg--;
	}
	if(deg < k) 
	{
		no(); return 0;
	}
	int cc = 0; //# of connected components
	for(int i = 2; i <= n; i++)
	{
		if(valid(1, i) && unvisited.find(i) != unvisited.end())
		{
			unvisited.erase(i);
			dfs(i);
			cc++;
		}
	}
	if(!unvisited.empty())
	{
		no(); return 0;
	}
	if(cc <= k)
	{
		yes(); return 0;
	}
	else
	{
		no(); return 0;
	}
	return 0;
}