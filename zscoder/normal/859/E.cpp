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
typedef long double ld; 
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

const int MOD=1e9+7;

ll mult(ll a, ll b)
{
	return (a*b)%MOD;
}

vi adj[200001];
bool good[200001];
bool vis[200001];

struct DSU
{
	int S;
	
	struct node
	{
		int p; ll sum;
	};
	vector<node> dsu;
	
	DSU(int n)
	{
		S = n;
		for(int i = 0; i < n; i++)
		{
			node tmp;
			tmp.p = i; tmp.sum = 1;
			dsu.pb(tmp);
		}
	}
	
	void reset(int n)
	{
		dsu.clear();
		S = n;
		for(int i = 0; i < n; i++)
		{
			node tmp;
			tmp.p = i; tmp.sum = 1;
			dsu.pb(tmp);
		}
	}
	
	int rt(int u)
	{
		if(dsu[u].p == u) return u;
		dsu[u].p = rt(dsu[u].p);
		return dsu[u].p;
	}
	
	void merge(int u, int v)
	{
		u = rt(u); v = rt(v);
		if(u == v) return ;
		if(rand()&1) swap(u, v);
		dsu[v].p = u;
		dsu[u].sum += dsu[v].sum;
	}
	
	bool sameset(int u, int v)
	{
		if(rt(u) == rt(v)) return true;
		return false;
	}
	
	ll getstat(int u)
	{
		return dsu[rt(u)].sum;
	}
};

vi cc[200001];


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	DSU dsu(2*n);
	for(int i=0;i<n;i++)
	{
		int u,v; cin>>u>>v;
		u--; v--;
		adj[u].pb(v);
		good[u]=1;
		dsu.merge(u,v);
	}
	for(int i=0;i<2*n;i++)
	{
		//cerr<<i<<' '<<dsu.rt(i)<<'\n';
		cc[dsu.rt(i)].pb(i);
	}
	ll ans=1;
	for(int i=0;i<2*n;i++)
	{
		bool tr=0;
		int siz=cc[i].size();
		if(cc[i].empty()) continue;
		if(cc[i].size()==1) continue;
		for(int j=0;j<cc[i].size();j++)
		{
			int u=cc[i][j];
			if(!good[u])
			{
				tr=1;
				break;
			}
		}
		if(tr)
		{
			ans=mult(ans,siz);
			continue;
		}
		bool loop=0;
		for(int j=0;j<cc[i].size();j++)
		{
			int u=cc[i][j];
			if(adj[u][0]==u)
			{
				loop=1; break;
			}
		}
		if(!loop) ans=mult(ans,2);
	}
	cout<<ans<<'\n';
}