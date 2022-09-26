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

vector<pair<ii,int> > ans;

void add_ans(int u, int v, int e)
{
	ans.pb({{u,v},e});	
}

vi adj[1111];
int s[11111];

void prep(int u, int p)
{
	s[u]=1;
	for(int v:adj[u])
	{
		if(v==p) continue;
		prep(v,u);
		s[u]+=s[v];
	}
}

int centroid(int u, int r, int p)
{
	for(int v:adj[u])
	{
		if(v==p) continue;
		if(s[v]*2>s[r])
		{
			return centroid(v,r,u);
		}
	}
	return u;
}

int ss[11111];
int cursum;
int incre;

void dfs(int u, int p, int presum=0)
{
	add_ans(u,p,cursum-presum);
	presum=cursum;
	cursum+=incre;
	for(int v:adj[u])
	{
		if(v==p) continue;
		dfs(v,u,presum);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	if(n==1)
	{
		return 0;
	}
	for(int i=0;i<n-1;i++)
	{
		int u,v; cin>>u>>v;
		u--; v--; adj[u].pb(v); adj[v].pb(u);
	}
	prep(0,-1);
	int r = centroid(0,0,-1);
	prep(r,-1);
	vi subs;
	for(int v:adj[r])
	{
		if(s[v]*3>=n)
		{
			subs.pb(v); ss[v]=1; break;
		}
	}
	if(subs.empty())
	{
		int cursum=0;
		for(int v:adj[r])
		{
			cursum+=s[v]; subs.pb(v); ss[v]=1;
			if(cursum*3>=n) break;
		}
	}
	int S = 0;
	for(int i=0;i<subs.size();i++) S+=s[subs[i]];
	int rem = n-S;
	cursum=1; incre=1;
	for(int v:adj[r])
	{
		if(!ss[v])
		{
			dfs(v,r);
		}
	}
	cursum=rem; incre=rem;
	for(int v:adj[r])
	{
		if(ss[v])
		{
			dfs(v,r);
		}
	}
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i].fi.fi+1<<' '<<ans[i].fi.se+1<<' '<<ans[i].se<<'\n';
	}
}