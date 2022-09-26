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

vi adj[222222];
int h[222222];
int s[222222];
int e[222222];
int timer=0;
int mnback[222222];
int sub[222222];
int par[222222];
vi child[222222];

void prep(int u, int p)
{
	s[u]=++timer;
	sub[u]=1;
	for(int v:adj[u])
	{
		if(v==p) continue;
		if(h[v]==-1)
		{
			h[v]=h[u]+1; par[v]=u; child[u].pb(v);
			prep(v,u);
			sub[u]+=sub[v];
		}
		else
		{
			mnback[u]=min(mnback[u],h[v]);
		}
	}
	e[u]=timer;
}

int ded=0;
int targeth=0;
void test(int u, int p)
{
	if(mnback[u]<targeth) ded=1;
	for(int v:child[u])
	{
		test(v,u);
	}
}

void solve()
{
	int n,m,a,b; cin>>n>>m>>a>>b;
	a--; b--;
	for(int i=0;i<n;i++)
	{
		h[i]=-1; mnback[i]=int(1e9); sub[i]=0; par[i]=-1;
	}
	for(int i=0;i<m;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	h[a]=0;
	prep(a,-1);
	targeth=h[b];
	int tp = b;
	while(h[tp]>1) tp=par[tp];
	ll tmp = n - 1 - sub[tp];
	ll tmp2 = 0;
	for(int v:child[b])
	{
		ded=0;
		test(v,-1);
		if(!ded)
		{
			tmp2+=sub[v];
		}
	}
	cout<<tmp*tmp2<<'\n';
	//answer is long long
	for(int i=0;i<n;i++)
	{
		adj[i].clear();child[i].clear();
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}