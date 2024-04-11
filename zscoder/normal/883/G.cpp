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

vector<ii> adj[311111];

bool vis[300001];
char ans[311111];

void dfs(int u)
{
	vis[u]=1;
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i].fi; int idx=adj[u][i].se;
		if(!vis[v])
		{
			if(abs(idx)>100000000) dfs(v);
			else
			{
				if(ans[abs(idx)]!='%')
				{
					if(idx>=0&&ans[idx]=='-') continue;
					if(idx<0&&ans[-idx]=='+') continue;
					dfs(v);
				}
				if(idx>=0) ans[idx]='+';
				else ans[-idx]='-';
				dfs(v);
			}
		}
	}
}

void dfs2(int u)
{
	vis[u]=1;
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i].fi; int idx=adj[u][i].se;
		if(!vis[v])
		{
			if(abs(idx)>100000000) dfs2(v);
			else
			{
				if(ans[abs(idx)]!='%')
				{
					if(idx>=0&&ans[idx]=='-') continue;
					if(idx<0&&ans[-idx]=='+') continue;
					dfs2(v);
				}
				if(idx>=0) ans[idx]='-';
				else ans[-idx]='+';
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,s; cin>>n>>m>>s; s--;
	int cnt=0;
	for(int i=0;i<m;i++)
	{
		int t,u,v;
		cin>>t>>u>>v;
		u--; v--;
		if(t==1)
		{
			adj[u].pb(mp(v,-int(1e9)));
		}
		else
		{
			cnt++;
			adj[u].pb(mp(v,cnt));
			adj[v].pb(mp(u,-cnt));
		}
	}
	for(int i=1;i<=cnt;i++) ans[i]='%';
	dfs(s);
	int ct=0;
	for(int i=0;i<n;i++)
	{
		if(vis[i])
		{
			ct++;
		}
	}
	for(int i=1;i<=cnt;i++) 
	{
		if(ans[i]=='%') ans[i]='+';
	}
	cout<<ct<<'\n';
	for(int i=1;i<=cnt;i++)
	{
		cout<<ans[i];
	}
	cout<<'\n';
	
	memset(vis,0,sizeof(vis));
	
	for(int i=1;i<=cnt;i++) ans[i]='%';
	dfs2(s);
	for(int i=1;i<=cnt;i++) 
	{
		if(ans[i]=='%') ans[i]='+';
	}
	ct=0;
	for(int i=0;i<n;i++)
	{
		if(vis[i])
		{
			ct++;
		}
	}
	cout<<ct<<'\n';
	for(int i=1;i<=cnt;i++)
	{
		cout<<ans[i];
	}
	cout<<'\n';
}