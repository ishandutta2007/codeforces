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
typedef map<ll,ll>::iterator mit;


int getid(int x, int y)
{
	return x*2+y;
}

vi adj[211111];
bool vis[211111];
int par[211111];
bool cycle;
bool onstack[211111];

void dfs(int u)
{
	vis[u]=1; onstack[u]=1;
	for(int v:adj[u])
	{
		if(vis[v]&&onstack[v])
		{
			cycle=1;
		}
		if(!vis[v]) 
		{
			par[v]=u; dfs(v);
		}
	}
	onstack[u]=0;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(par,-1,sizeof(par));
	int n, m; cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		int k; cin>>k;
		for(int j=0;j<k;j++)
		{
			int v; cin>>v;
			v--;
			for(int z=0;z<2;z++)
			{
				adj[getid(i,z)].pb(getid(v, z^1));
			}
		}
	}
	int s; cin>>s;
	s--;
	dfs(getid(s,0));
	for(int i=0;i<n;i++)
	{
		if(vis[getid(i,1)]&&adj[getid(i,1)].empty())
		{
			cout<<"Win\n";
			vi vec;
			int cur=getid(i,1);
			while(cur!=-1)
			{
				vec.pb(cur/2);
				cur=par[cur];
			}
			for(int i=int(vec.size())-1;i>=0;i--)
			{
				cout<<vec[i]+1;
				if(i>0) cout<<' ';
			}
			cout<<'\n';
			return 0;
		}
	}
	if(!cycle)
	{
		cout<<"Lose\n";
	}
	else
	{
		cout<<"Draw\n";
	}
}