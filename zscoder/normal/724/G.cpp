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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

vector<ii> adj[100001];
bool visited[100001];
const int MOD = 1e9 + 7;
ll pow2[100001];
ll ans;
ll V[100001];

struct gausselim
{
	ll cnt[61][2];
	int rank;
	ll cyc[61];
	ll tmp;
	void init()
	{
		for(int i = 0; i < 61; i++)
		{
			cyc[i] = cnt[i][0] = cnt[i][1] = 0;
		}
		rank = tmp = 0;
	}
	void addval(ll x)
	{
		for(int i = 0; i < 61; i++)
		{
			cnt[i][(x>>i)&1]++;
		}
	}
	void add(ll x)
	{
		tmp|=x;
		for(int i = 60; i >= 0; i--)
		{
			if(x&(1LL<<i))
			{
				if(cyc[i]==0)
				{
					cyc[i] = x;
					rank++;
					break;
				}
			}
			x = min(x, (x^cyc[i]));
		}	
	}
	void upd()
	{
		for(int i = 0; i < 61; i++)
		{
			if(tmp&(1LL<<i))
			{
				ans = (ans + (ll(((cnt[i][0]+cnt[i][1])*(cnt[i][0]+cnt[i][1]-1))/2LL)%MOD*pow2[i+rank-1])%MOD)%MOD;
			}
			else
			{
				ans = (ans + (ll((cnt[i][0]*cnt[i][1]))%MOD*pow2[i+rank])%MOD)%MOD;
			}
		}
	}
};

gausselim base;

void dfs(int u, int p, ll w)
{
	visited[u] = true;
	base.addval(w); V[u] = w;
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i].fi; ll ww = adj[u][i].se;
		if(v == p) continue;
		if(visited[v])
		{
			base.add((V[u]^V[v])^ww);
			continue ;
		}
		dfs(v, u, (w^ww));
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	pow2[0] = 1;
	for(int i = 1; i <= 100000; i++)
	{
		pow2[i] = (pow2[i-1]*2LL)%MOD;
	}
	for(int i = 0; i < m; i++)
	{
		int u, v; ll w; cin>>u>>v>>w;
		u--; v--;
		adj[u].pb(mp(v,w)); adj[v].pb(mp(u,w));
	}
	for(int i = 0; i < n; i++)
	{
		if(!visited[i])
		{
			base.init();
			dfs(i, -1, 0);
			//cerr<<base.rank<<' '<<base.tmp<<'\n';
			base.upd();
		}
	}
	cout << ans << '\n';
}