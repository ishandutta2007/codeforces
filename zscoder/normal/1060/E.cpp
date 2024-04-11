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
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vi adj[222222];
ll h[222222];
ll sub[222222];

void dfs(int u, int p)
{
	sub[u]=1;
	for(int v:adj[u])
	{
		if(v==p) continue;
		h[v]=h[u]+1;
		dfs(v,u);
		sub[u]+=sub[v];
	}
}

ll ans2[222222];

void dfs2(int u, int p, ll n)
{
	for(int v:adj[u])
	{
		if(v==p) continue;
		ans2[v] = ans2[u] + n - 2LL*sub[v];
		dfs2(v,u,n);
	}
}

ll dp[222222];
ll cnt[2][222222];
ll totodd;

void dfs3(int u, int p)
{
	cnt[0][u]++;
	ll s[2]={0,0};
	for(int v:adj[u])
	{
		if(v==p) continue;
		dfs3(v,u);
		cnt[0][u]+=cnt[1][v];
		cnt[1][u]+=cnt[0][v];
		s[0]+=cnt[0][v]; s[1]+=cnt[1][v];
	}
	totodd+=cnt[1][u];
	ll ans = s[0]*s[1];
	for(int v:adj[u])
	{
		if(v==p) continue;
		ans -= cnt[0][v]*cnt[1][v];
	}
	totodd+=ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int u,v; cin>>u>>v;
		u--; v--; adj[u].pb(v); adj[v].pb(u);
	}
	dfs(0,-1);
	for(int i=0;i<n;i++) ans2[0]+=h[i];
	dfs2(0,-1,n);
	ll res = 0;
	for(int i=0;i<n;i++) 
	{
		res+=ans2[i];
	}
	totodd=0;
	dfs3(0,-1);
	totodd*=2;
	res+=totodd;
	res/=4;
	cout<<res<<'\n';
}