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
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int a[1111111];
string ty[1111111];
vi adj[1111111];
int dp[1111111][2];

void prep(int u, int p=-1)
{
	string tmp = ty[u];
	if(tmp=="IN")
	{
		dp[u][0]=a[u]; return ;
	}
	else if(tmp=="NOT")
	{
		prep(adj[u][0],u);
		dp[u][0]=!dp[adj[u][0]][0];
	}
	else
	{
		prep(adj[u][0],u); prep(adj[u][1],u);
		if(tmp=="XOR") dp[u][0]=(dp[adj[u][0]][0])^(dp[adj[u][1]][0]);
		else if(tmp=="OR") dp[u][0]=(dp[adj[u][0]][0])|(dp[adj[u][1]][0]);
		else dp[u][0]=(dp[adj[u][0]][0])&(dp[adj[u][1]][0]);
	}
	//cerr<<u<<' '<<dp[u][0]<<'\n';
}
void dfs(int u, int p=-1)
{
	string tmp = ty[u];
	if(u==0)
	{
		dp[u][1]=dp[u][0]^1;
	}
	else
	{
		int nw=0;
		string pp = ty[p];
		//cerr<<"UP: "<<u<<' '<<p<<' '<<pp<<'\n';
		if(pp!="NOT")
		{
			for(int v:adj[p])
			{
				if(v==u) continue;
				nw=v;
			}
		}
		if(pp=="NOT")
		{
			int newpar=!(dp[u][0]^1);
			if(newpar==dp[p][0]) dp[u][1]=dp[0][0];
			else dp[u][1]=dp[p][1];
		}
		else if(pp=="XOR")
		{
			int newpar=(dp[u][0]^1)^(dp[nw][0]);
			if(newpar==dp[p][0]) dp[u][1]=dp[0][0];
			else dp[u][1]=dp[p][1];
		}
		else if(pp=="OR")
		{
			int newpar=(dp[u][0]^1)|(dp[nw][0]);
			if(newpar==dp[p][0]) dp[u][1]=dp[0][0];
			else dp[u][1]=dp[p][1];
		}
		else
		{
			int newpar=(dp[u][0]^1)&(dp[nw][0]);
			if(newpar==dp[p][0]) dp[u][1]=dp[0][0];
			else dp[u][1]=dp[p][1];
		}
	}
	//cerr<<"U1: "<<u<<' '<<dp[u][1]<<'\n';
	if(tmp=="IN")
	{
		return ;
	}
	else if(tmp=="NOT")
	{
		dfs(adj[u][0],u);
	}
	else
	{
		dfs(adj[u][0],u); dfs(adj[u][1],u);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		string s; int u,v; 
		cin>>s;
		ty[i]=s;
		if(s=="IN")
		{
			cin>>a[i];
		}
		else if(s=="NOT")
		{
			cin>>u; u--; adj[i].pb(u);
		}
		else
		{
			cin>>u>>v; u--; v--; adj[i].pb(u); adj[i].pb(v);
		}
	}
	prep(0);
	dfs(0);
	for(int i=0;i<n;i++)
	{
		if(ty[i]=="IN")
		{
			cout<<dp[i][1];
		}
	}
	cout<<'\n';
}