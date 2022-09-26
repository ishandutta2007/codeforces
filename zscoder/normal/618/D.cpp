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

vi adj[200001];
bool mark[200001];
ll cnt = 0;

void dfs(int u, int p)
{
	int cnt1 = 0;
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if(v == p) continue;
		dfs(v, u);
		if(mark[v]) cnt1++;
	}
	cnt += min(2, cnt1);
	if(cnt1 < 2) mark[u] = true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, x, y;
	cin >> n >> x >> y;
	for(int i = 0; i < n - 1; i++)
	{
		int u, v; cin >> u >> v;
		u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	if(x > y)
	{
		bool star = false;
		for(int i = 0; i < n; i++)
		{
			if(adj[i].size() == n - 1)
			{
				star = true;
				break;
			}
		}
		if(star) cout << y*(n - 2) + x << '\n';
		else cout << y*(n - 1) << '\n';
		return 0;
	}
	dfs(0, -1);
	cout << cnt*x + (n - 1 - cnt)*y;
	return 0;
}