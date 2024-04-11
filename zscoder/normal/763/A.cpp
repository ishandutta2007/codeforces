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

int cnt[100001];
vi adj[100001];
int a[100001];
int color[100001];
int ans;
bool good[100001];
void dfs(int u, int p)
{
	color[u]=0;
	good[u]=1;
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if(v==p) continue;
		dfs(v,u);
		if(color[v]==-1) //subtree not same color
		{
			color[u] = -1;
			good[u] = 0;
		}
		else if(color[u]==0)
		{
			color[u] = color[v];
		}
		else if(color[u]!=color[v])
		{
			color[u] = -1;
		}
	}
	if(color[u]==0)
	{
		color[u]=a[u];
	}
	else if(color[u]!=a[u])
	{
		color[u]=-1;
	}
	//cerr<<u<<' '<<color[u]<<' '<<good[u]<<'\n';
}
int tot;
int n; 
pair<int,int> dfs2(int u, int p)
{
	int cnt = 0;
	int sub = 1;
	if(a[u]==a[0]) cnt++;
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if(v!=p)
		{
			ii tmp = dfs2(v,u);
			sub+=tmp.se;
			cnt+=tmp.fi;
		}
	}
	if(!good[u]) return mp(cnt,sub);
	if(n-sub==tot-cnt)
	{
		ans=u;
	}
	return mp(cnt,sub);
}
	
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	for(int i = 0; i < n - 1; i++)
	{
		int u, v; cin>>u>>v; u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
		if(a[i]==a[0]) tot++;
	}
	dfs(0,-1);
	if(good[0])
	{
		cout<<"YES\n1";
		return 0;
	}
	ans=-1;
	dfs2(0,-1);
	if(ans==-1)
	{
		cout<<"NO";
	}
	else
	{
		cout<<"YES\n"<<ans+1<<'\n';
	}
}