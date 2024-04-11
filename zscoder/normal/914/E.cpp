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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef unordered_map<ll,ll>::iterator mit;

vi adj[200111];
bool visited[200111];
int a[200011];
int sub[200011];
ll ans[200011];
ll dp2[200011];
int xr[200011];
vi S[200011];

void prep(int u, int p)
{
	sub[u]=1;dp2[u] = 0;
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if(v==p||visited[v]) continue;
		prep(v,u);
		sub[u]+=sub[v];
	}
}

int centroid(int u, int p, int rt)
{
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if(v==p||visited[v]) continue;
		if(sub[v]*2>=sub[rt])
		{
			return centroid(v,u,rt);
		}
	}
	return u;
}

int tot[(1<<20)+13];
vi children;
void dfs(int u, int p = -1, int child = -1)
{
	if(child>=0) 
	{
		S[child].pb(xr[u]); tot[xr[u]]++;
	}
	for(int v:adj[u])
	{
		if(v==p||visited[v]) continue;
		xr[v] = xr[u]^a[v];
		if(child==-1)
		{
			children.pb(v);
			dfs(v,u,v);
		}
		else
		{
			dfs(v,u,child);
		}
	}
}

void dfs2(int u, int p, int rt)
{
	dp2[u] = tot[a[rt]^xr[u]];
	for(int i=0;i<20;i++)
	{
		dp2[u] += tot[a[rt]^xr[u]^(1<<i)];
	}
	for(int v:adj[u])
	{
		if(v==p||visited[v]) continue;
		dfs2(v,u,rt);
		dp2[u] += dp2[v];
	}
	//cerr<<rt<<' '<<u<<' '<<xr[u]<<' '<<dp2[u]<<'\n';
	ans[u]+=dp2[u];
}

void solve(int rt)
{
	//update all paths that path through rt on all relevant nodes!
	xr[rt]=0;
	children.clear();
	dfs(rt);
	//solve for root first
	ans[rt]++; //no path
	ans[rt]+=tot[a[rt]];
	for(int i=0;i<20;i++) //1 path
	{
		ans[rt]+=tot[a[rt]^(1<<i)];
	}
	ll sum=0;
	for(int u:children) //2 nonempty paths
	{
		for(auto it:S[u])
		{
			tot[it]--;
		}
		for(auto it:S[u])
		{
			for(int i=0;i<20;i++)
			{
				sum+=tot[it^a[rt]^(1<<i)];
			}
			sum+=tot[it^a[rt]];
		}
		tot[0]++;
		dfs2(u,rt,rt);
		tot[0]--;
		for(auto it:S[u])
		{
			tot[it]++;
		}
	}
	for(int u:children) //2 nonempty paths
	{
		while(!S[u].empty()){tot[S[u].back()]--; S[u].pop_back();}
	}			
	sum>>=1;
	ans[rt]+=sum;
}

void solveall(int u)
{
	prep(u,-1);
	int cent = centroid(u,-1,u);
	solve(cent);
	visited[cent]=1;
	//cerr<<"U : "<<u<<" CENT : "<<cent<<'\n';
	for(int v:adj[cent])
	{
		if(!visited[v])
		{
			solveall(v);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int u,v; cin>>u>>v;
		u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	string s; cin>>s;
	for(int i=0;i<n;i++)
	{
		a[i]=(1<<(s[i]-'a'));
	}
	solveall(0);
	for(int i=0;i<n;i++)
	{
		cout<<ans[i];
		if(i+1<n) cout<<' ';
	}
	cout<<'\n';
}