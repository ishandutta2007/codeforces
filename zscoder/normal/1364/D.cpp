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

vi adj[222222];
bool visited[222222];
int h[222222];
int par[222222];
int backedge[222222];

void dfs(int u, int p=-1)
{
	visited[u]=1;
	for(int v:adj[u])
	{
		if(v==p) continue;
		if(visited[v]&&h[u]>h[v])
		{
			if(backedge[u]==-1) backedge[u]=v;
			else if(h[v]>h[backedge[u]])
			{
				backedge[u]=v;
			}
		}
		else if(!visited[v])
		{
			h[v]=h[u]+1;
			par[v]=u;
			dfs(v,u);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(backedge,-1,sizeof(backedge));
	int n,m,k; cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	dfs(0);
	for(int i=0;i<n;i++)
	{
		if(backedge[i]!=-1)
		{
			//cerr<<i<<' '<<h[i]<<' '<<backedge[i]<<'\n';
			if(h[i]-h[backedge[i]]+1<=k)
			{
				cout<<2<<'\n';
				vi cyc;
				int u=backedge[i];
				int v=i;
				while(v!=u)
				{
					cyc.pb(v);
					v=par[v];
				}
				cyc.pb(u);
				cout<<cyc.size()<<'\n';
				for(int x:cyc)
				{
					cout<<x+1<<' ';
				}
				cout<<'\n';
				return 0;
			}
		}
	}
	vi iset; int ex=0;
	for(int i=0;i<n;i++)
	{
		if(h[i]>=k-1)
		{
			ex=1;
			int cur=i;
			while(iset.size()<(k+1)/2)
			{
				iset.pb(cur);cur=par[cur]; cur=par[cur];
			}
			break;
		}
	}
	if(!ex)
	{
		vi A,B;
		for(int i=0;i<n;i++)
		{
			if(h[i]%2==1) A.pb(i);
			else B.pb(i);
		}
		if(A.size()>B.size()) iset=A;
		else iset=B;
	}
	assert(iset.size()>=(k+1)/2);
	cout<<1<<'\n';
	for(int i=0;i<(k+1)/2;i++)
	{
		cout<<iset[i]+1<<' ';
	}
	cout<<'\n';
}