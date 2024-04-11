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

ii ans[31];
vi adj[31];

bool visited[31];
const int LG = 42;
const ll MID = (1LL<<(LG+8));
ll dx[4] = {1, -1, 0, 0};
ll dy[4] = {0, 0, 1, -1};

void dfs(int u, int h, int dir)
{
	visited[u]=1;
	int dr = 0;
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if(visited[v]) continue;
		while(dr==dir) dr++;
		ans[v] = ans[u];
		ans[v].fi+=dx[dr]*(1LL<<h);
		ans[v].se+=dy[dr]*(1LL<<h);
		dfs(v, h - 1, (dr^1));
		dr++;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; 
	cin>>n;
	for(int i = 0; i < n - 1; i++)
	{
		int u, v; cin>>u>>v;
		u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	for(int i = 0; i < n; i++)
	{
		if(adj[i].size()>4)
		{
			cout<<"NO";
			return 0;
		}
	}
	ans[0]=mp(MID,MID);
	dfs(0, LG, -1);
	cout<<"YES\n";
	for(int i = 0; i < n; i++)
	{
		cout<<ans[i].fi<<' '<<ans[i].se<<'\n';
	}
}