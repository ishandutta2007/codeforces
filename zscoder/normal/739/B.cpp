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

struct PBDS
{
	tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> t;
	int timer;
	
	PBDS(){timer = 0;}
	void insert(ll x)
	{
		t.insert(mp(x, timer));
		timer++;
	}
	
	int lower(ll x)
	{
		if(t.empty()) return 0;
		return t.order_of_key(mp(x, -1));
	}
	
	void del(ll x) //make sure x exists
	{
		ii tmp = (*t.find_by_order(lower(x)));
		t.erase(tmp);
	}
	
	int higher(ll x)
	{
		if(t.empty()) return 0;
		int tmp = lower(x);
		return (int(t.size()) - tmp);
	}
};

const int maxn = 201011;
PBDS *vec[maxn];
PBDS buffer[maxn];
PBDS *cc = buffer;
int ans[maxn];
ll a[maxn];
int par[maxn];
ll add[maxn];
vector<ii> adj[maxn];
int sz[maxn];
ll h[maxn];

void calcsiz(int v, int p)
{
	//cerr<<v<<' '<<p<<'\n';
	sz[v] = 1;
	for(int i = 0; i < adj[v].size(); i++)
	{
		h[adj[v][i].fi] = h[v] + adj[v][i].se;
		calcsiz(adj[v][i].fi, v);
		sz[v] += sz[adj[v][i].fi];
	}
}

void dfs(int v, int p)
{
	vec[v] = cc++;
    int mx = -1, bigChild = -1;
    ll ww = -1;
    for(int i = 0; i < adj[v].size(); i++)
    {
		int u = adj[v][i].fi; ll w = adj[v][i].se;
	   if(u != p && sz[u] > mx)
	   {
		   mx = sz[u]; bigChild = u;
		   ww = w;
	   }
    }
   for(int i = 0; i < adj[v].size(); i++)
   {
	int u = adj[v][i].fi; 
       if(u != bigChild)
       {
           dfs(u, v);
       }
   }
  // cerr<<"BIGCHILD : "<<v<<' '<<bigChild<<'\n';
    if(bigChild != -1)
    {	
        dfs(bigChild, v);
        vec[v] = vec[bigChild];
       // add[v] = add[bigChild] - ww;
       // vec[v]->insert((a[bigChild] - ww) - add[v]);
       vec[v] -> insert(h[bigChild] - a[bigChild]);
    }
   // cerr<<"ADD : "<<v<<' '<<add[v]<<'\n';
    //cnt[ col[v] ]++;
    for(int i = 0; i < adj[v].size(); i++)
    {
		int u = adj[v][i].fi;
       if(u != bigChild)
		{
           while(!(vec[u]->t.empty()))
           {
               //cnt[ col[x] ]++;
               //vec[v] -> insert(it->fi);
               ll x = (*vec[u]->t.find_by_order(0)).fi;
               //cerr<<x<<'\n';
               /*
               vec[v]->insert(x+add[u]-add[v]);
               vec[u]->t.erase(vec[u]->t.begin());
               */
               vec[v]->insert(x);
               vec[u]->t.erase(vec[u]->t.begin());
           }
           //vec[v]->insert((a[u]-w)-add[v]);
           vec[v]->insert(h[u]-a[u]);
        }
    }
   ans[v] = vec[v]->lower(h[v]+1);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("alyona.in", "r", stdin);
	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	//cerr<<vec[0]->t.size()<<'\n';
	for(int i = 1; i < n; i++)
	{
		ll w;
		cin>>par[i]>>w;
		par[i]--;
		adj[par[i]].pb(mp(i,w));
	}
	calcsiz(0, -1);
	dfs(0, -1);
	for(int i = 0; i < n; i++)
	{
		cout<<ans[i]<<' ';
	}
}