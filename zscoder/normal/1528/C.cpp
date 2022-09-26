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
typedef pair<ld,ld> state;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int dp[333333];
vi adj[333333];
vi adj2[333333];
int s[333333];
int e[333333];
int timer;
int head[333333];


void prep2(int u, int p=-1)
{
	s[u]=++timer;
	for(int v:adj2[u])
	{
		prep2(v,u);
	}
	e[u]=++timer;
}

bool insub(int u, int v) //is v in sub of u
{
	return (s[u]<=s[v]&&e[v]<=e[u]);
}

set<ii> S;

ii ins(ii v)
{
	if(S.empty()){S.insert(v); return {-1,-1};}
	int l=v.fi; int r=v.se;
	auto it = S.lower_bound({l,-1}); 
	if(it==S.begin()){S.insert(v); return {-1,-1};}
	it--;
	if(it->se>=r)
	{
		ii retval = (*it);
		S.erase(it); S.insert(v); return retval;
	}
	else
	{
		S.insert(v); return {-1,-1};
	}
}

void dfs(int u, int p=-1)
{
	/*
	if(p==-1) 
	{
		dp[u]=1; head[u]=-1;
	}
	else
	{
		if(!insub(p,u)) head[u]=p;
		else head[u]=head[p];
		if(head[u]<0) dp[u]=1;
		else dp[u]=dp[head[u]]+1;
	}
	cerr<<"TIMER: "<<u<<' '<<s[u]<<' '<<e[u]<<'\n';
	cerr<<u<<' '<<dp[u]<<' '<<head[u]<<'\n';
	*/
	ii addback = ins({s[u],e[u]});
	dp[u]=S.size();
	for(int v:adj[u])
	{
		dfs(v,u);
	}
	S.erase({s[u],e[u]});
	if(addback.fi>=0) S.insert(addback);
}

void solve()
{
	int n; cin>>n;
	timer=0;
	for(int i=1;i<n;i++)
	{
		int u; cin>>u; u--; adj[u].pb(i);
	}
	for(int i=1;i<n;i++)
	{
		int u; cin>>u; u--; adj2[u].pb(i);
	}
	prep2(0);
	S.clear();
	dfs(0);
	int ans=0;
	for(int i=0;i<n;i++) ans=max(ans,dp[i]);
	cout<<ans<<'\n';
	for(int i=0;i<n;i++) 
	{
		adj2[i].clear(); adj[i].clear(); head[i]=-1;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(head,-1,sizeof(head));
	int t; cin>>t;
	while(t--) solve();
}