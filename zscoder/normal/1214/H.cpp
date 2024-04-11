#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vi adj[333333];
int dp[333333];
int par[333333];
int mxh=0;
int vis[222222];

void dfs(int u, int p=-1)
{
	par[u]=p;
	mxh=max(mxh,dp[u]);
	for(int v:adj[u])
	{
		if(v==p||vis[v]) continue;
		dp[v]=dp[u]+1;
		dfs(v,u);
	}
}

int c[222222];
int n,k; 
void dfs2(int u, int col, int dir, int p=-1)
{
	c[u]=col;
	for(int v:adj[u])
	{
		if(v==p||vis[v]) continue;
		dfs2(v,(col+k+dir)%k,dir,u);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>k;
	for(int i=0;i<n-1;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	dfs(0,-1);
	int mx=-1; int mxp = -1;
	for(int i=0;i<n;i++)
	{
		if(dp[i]>mx)
		{
			mx=dp[i]; mxp=i;
		}
	}
	memset(dp,0,sizeof(dp));
	int l=mxp;
	dfs(mxp,-1);
	mx=mxp=-1;
	for(int i=0;i<n;i++)
	{
		if(dp[i]>mx)
		{
			mx=dp[i]; mxp=i;
		}
	}
	int r=mxp;
	if(k==2)
	{
		cout<<"Yes\n";
		for(int i=0;i<n;i++)
		{
			if(dp[i]%2==0) cout<<2;
			else cout<<1;
			if(i+1<n) cout<<' ';
		}
		cout<<'\n'; return 0;
	}
	//go from l to r
	vi chain;
	chain.pb(r);
	while(chain.back()!=l)
	{
		chain.pb(par[chain.back()]);
	}
	reverse(chain.begin(),chain.end());
	int cur=0;
	for(int v:chain)
	{
		c[v]=cur;
		cur++;
		if(cur>=k) cur-=k;
	}
	memset(dp,0,sizeof(dp));
	for(int x:chain) vis[x]=1;
	for(int i=1;i+1<chain.size();i++)
	{
		int u = chain[i];
		int L = i+1;
		int R = chain.size()-i;
		mxh=0;
		dfs(u,-1);
		if(mxh==0) continue;
		cerr<<mxh<<' '<<L<<' '<<R<<'\n';
		if(mxh+R>=k&&mxh+L>=k)
		{
			cout<<"No\n"; return 0;
		}
		if(L>=R)
		{
			//mxh+R<k
			dfs2(chain[i],c[chain[i]],1,-1);
		}
		else
		{
			dfs2(chain[i],c[chain[i]],-1,-1);
		}
	}
	cout<<"Yes\n";
	for(int i=0;i<n;i++)
	{
		cout<<c[i]+1;
		if(i+1<n) cout<<' ';
	}
	cout<<'\n';
}