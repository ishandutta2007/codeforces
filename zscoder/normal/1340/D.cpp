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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vi adj[222222];
int dp[222222];

void dfs(int u, int p=-1)
{
	vi vec;
	for(int v:adj[u])
	{
		if(v==p) continue;
		dfs(v,u);
		vec.pb(dp[v]);
	}
	sort(vec.rbegin(),vec.rend());
	for(int i=0;i<vec.size();i++)
	{
		dp[u]=max(dp[u],vec[i]+i+1);
	}
}

vector<ii> ans;
int mxdeg;

void push(int u, int t)
{
	ans.pb({u,t});
}

void solve(int u, int p, int curt)
{
	push(u,curt);
	int reser=curt-1;
	int ch=0;
	for(int v:adj[u])
	{
		if(v==p) continue;
		ch++;
	} 
	for(int v:adj[u])
	{
		if(v==p) continue;
		if(curt>=mxdeg)
		{
			curt=reser-ch;
			while(curt==reser) curt++;
			push(u,curt);
		}
		solve(v,u,curt+1);
		push(u,curt+1);
		curt++;
		ch--;
	}
	if(p!=-1&&curt!=reser)
	{
		push(u,reser);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	mxdeg=0;
	for(int i=0;i<n;i++) mxdeg=max(mxdeg,int(adj[i].size()));
	solve(0,-1,0);
	cout<<ans.size()<<'\n';
	for(ii x:ans)
	{
		cout<<x.fi+1<<' '<<x.se<<'\n';
	}
}