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

vector<int> fact;
vector<int> ifact;
vector<int> inv;
vector<int> pow2;
const int MOD = 998244353;
int add(int a, int b)
{
	a+=b;
	while(a>=MOD) a-=MOD;
	return a;
}
int mult(int a, int b)
{
	return (a*1LL*b)%MOD;
}
int modpow(int a, int b)
{
	int r=1;
	while(b)
	{
		if(b&1) r=mult(r,a);
		a=mult(a,a);
		b>>=1;
	}
	return r;
}
int choose(int a, int b)
{
	if(a<b) return 0;
	if(b==0) return 1;
	if(a==b) return 1;
	return mult(fact[a],mult(ifact[b],ifact[a-b]));
}
int inverse(int a)
{
	return modpow(a,MOD-2);
}
void init(int _n)
{
	fact.clear(); ifact.clear(); inv.clear(); pow2.clear();
	fact.resize(_n+1);
	ifact.resize(_n+1);
	inv.resize(_n+1);
	pow2.resize(_n+1);
	pow2[0]=1;
	ifact[0]=1;
	fact[0]=1;
	for(int i=1;i<=_n;i++)
	{
		pow2[i]=add(pow2[i-1],pow2[i-1]);
		fact[i]=mult(fact[i-1],i);
		//ifact[i]=mult(ifact[i-1],inv[i]);
	}
	ifact[_n] = inverse(fact[_n]);
	for(int i=_n-1;i>=1;i--)
	{
		ifact[i] = mult(ifact[i + 1], i + 1);
	}
	for(int i=1;i<=_n;i++)
	{
		inv[i] = mult(fact[i-1],ifact[i]);
	}
}

struct Tree
{
	struct data
	{
		ll w;
	};
	
	struct node
	{
		int p; //parent
		ll w; //modify for different problems
	};
	
	struct edge
	{
		int v; data dat;
	};
	
	vector<vector<edge> > adj;
	int n;
	
	Tree(int _n)
	{
		adj.resize(_n);
		n = _n;
	}
	
	vi level;
	vi depth;
	vi h;
	vi euler;
	vi firstocc;
	vector<vi> rmqtable;
	vi subsize;
	vi start; vi en;
	vector<vector<node> > st;
	
	void addedge(int u, int v)
	{
		edge tmp; tmp.v = v;
		adj[u].pb(tmp);
		tmp.v = u;
		adj[v].pb(tmp);
	}
	
	void reset(int _n)
	{
		adj.clear();
		level.clear();
		depth.clear();
		euler.clear();
		rmqtable.clear();
		subsize.clear();
		start.clear();
		en.clear();
		st.clear();
		firstocc.clear();
		adj.resize(_n);
		n = _n;
	}
	
	void dfssub(int u, int p)
	{
		subsize[u] = 1;
		for(int i = 0; i < adj[u].size(); i++)
		{
			int v = adj[u][i].v;
			if(v == p) continue;
			dfssub(v, u);
			subsize[u] += subsize[v];
		}
	}
	
	void calcsub()
	{
		subsize.resize(n);
		dfssub(0, -1);
	}
	
	int timer;
	
	void dfsstartend(int u, int p)
	{
		start[u] = ++timer;
		if(p == -1) h[u] = 0;
		else h[u] = h[p] + 1;
		for(int i = 0; i < adj[u].size(); i++)
		{
			int v = adj[u][i].v;
			if(v == p) continue;
			dfsstartend(v, u);
		}
		en[u] = ++timer;
	}
	
	void calcstartend()
	{
		timer = 0;
		start.resize(n); en.resize(n); h.resize(n);
		dfsstartend(0, -1);
	}
	
	int eulercnt;
	
	void dfseuler(int u, int p)
	{
		euler[eulercnt] = u; eulercnt++;
		if(p == -1) {depth[u] = 0;}
		else {depth[u] = depth[p] + 1;}
		firstocc[u] = eulercnt-1;
		for(int i = 0; i < adj[u].size(); i++)
		{
			int v = adj[u][i].v;
			if(v == p) continue ;
			dfseuler(v, u);
			euler[eulercnt] = u; eulercnt++;
		}
	}
	
	void calceuler()
	{
		eulercnt = 0;
		level.assign(2*n+1, 0);
		euler.assign(2*n+1, 0);
		depth.assign(n, 0);
		firstocc.resize(n);
		dfseuler(0, -1);
	}

	void filllevel()
	{
		int LG = 0;
		while((1<<LG) <= n*2) LG++;
		rmqtable.resize(LG);
		for(int i = 0; i < LG; i++) rmqtable[i].resize(eulercnt);
		for(int i = 0; i < eulercnt; i++)
		{
			level[i] = depth[euler[i]];
		}
		level[eulercnt] = 1000000000;
		for(int j = 0; j < LG; j++)
		{
			for(int i = 0; i < eulercnt; i++)
			{
				rmqtable[j][i] = eulercnt;
				if(i + (1<<j) - 1 < eulercnt)
				{
					if(j == 0)
					{
						rmqtable[j][i] = i;
					}
					else
					{
						if(level[rmqtable[j - 1][i]] < level[rmqtable[j-1][i + (1<<(j-1))]])
						{
							rmqtable[j][i] = rmqtable[j-1][i];
						}
						else
						{
							rmqtable[j][i] = rmqtable[j-1][i + (1<<(j-1))];
						}
					}
				}
			}
		}
	}

	int rmq(int l, int r)
	{
		int k = 31 - __builtin_clz(r-l);
		//cout << l << ' ' << r << ' ' << rmqtable[l][k] << ' ' << rmqtable[r - (1<<k) + 1][k] << endl;
		if(level[rmqtable[k][l]] < level[rmqtable[k][r - (1<<k) + 1]])
		{
			return rmqtable[k][l];
		}
		else
		{
			return rmqtable[k][r - (1<<k) + 1];
		}
	}

	int lcaeuler(int u, int v)
	{
		if(firstocc[u] > firstocc[v]) swap(u, v);
		//cerr << firstocc[u] << ' ' << firstocc[v] << ' ' << rmq(firstocc[u], firstocc[v]) << ' ' << euler[rmq(firstocc[u], firstocc[v])] << endl;
		return euler[rmq(firstocc[u], firstocc[v])];
	}
	
	bool insub(int u, int v) //is u in the subtree of v?
	{
		if(start[v] <= start[u] && en[u] <= en[v]) return true;
		return false;
	}
	
	void dfspar(int u, int p)
	{
		//cerr << u << ' ' << p << '\n';
		st[0][u].p = p;
		if(p == -1) h[u] = 0;
		else h[u] = h[p] + 1;
		for(int i = 0; i < adj[u].size(); i++)
		{
			int v = adj[u][i].v;
			if(v == p) continue;
			dfspar(v, u);
		}
	}
	
	int LOG;
	
	void calcpar()
	{
		h.resize(n);
		int LG = 0; LOG = 0;
		while((1<<LG) <= n) {LG++; LOG++;}
		st.resize(LG);
		for(int i = 0; i < LG; i++)
		{
			st[i].resize(n);
		}
		dfspar(0, -1);
		//cerr << "HER" << ' ' << LG << endl;
		for(int i = 1; i < LG; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(st[i-1][j].p == -1) st[i][j].p = -1;
				else st[i][j].p = st[i-1][st[i-1][j].p].p;
			}
		}
	}
	
	int getpar(int u, ll k)
	{
		for(int i = LOG - 1; i >= 0; i--)
		{
			if(k&(1<<i))
			{
				u = st[i][u].p;
			}
		}
		return u;
	}
	
	int lca(int u, int v)
	{
		if(h[u] > h[v]) swap(u, v);
		for(int i = LOG - 1; i >= 0; i--)
		{
			if(st[i][v].p != -1 && h[st[i][v].p] >= h[u])
			{
				v = st[i][v].p;
			}
		}
		if(u == v) return u;
		for(int i = LOG - 1; i >= 0; i--)
		{
			if(st[i][v].p != -1 && st[i][v].p != st[i][u].p)
			{
				u = st[i][u].p;
				v = st[i][v].p;
			}
		}
		return st[0][u].p;
	}

	int distance(int u, int v)
	{
		int lc = lca(u, v);
		return (h[u]+h[v]-2*h[lc]);
	}
};

const int C = 560;
int n,q;
vi adj[159111];
int ans[159111];
int sub[159111];
int par[159111];
vi adj2[159111];
Tree T(1);
int child_ancestor(int u, int v) 
{
    int low = 0, high = (int) adj2[u].size() - 1;

    while (low < high) {
        int mid = (low + high) / 2;

        if (T.start[v] < T.en[adj2[u][mid]])
            high = mid;
        else
            low = mid + 1;
    }

    return adj2[u][low];
}

void dfs(int u, int p=-1)
{
	sub[u]=1; par[u]=p;
	for(int v:adj[u])
	{
		if(v==p) continue;
		adj2[u].pb(v);
		dfs(v,u); sub[u]+=sub[v];
	}
}
int invn;
vector<ii> queries;
int explode[159111];
int upd[159111];

void push(int u, int p=-1)
{
	ans[u]=add(ans[u],upd[u]);
	for(int v:adj[u])
	{
		if(v==p) continue;
		upd[v]=add(upd[v],upd[u]);
		push(v,u);
	}
}

void recomp()
{
	set<int> S;
	for(ii x:queries) S.insert(x.fi);
	for(int u:S)
	{
		int d=explode[u];
		for(int v:adj[u])
		{
			if(v==par[u])
			{
				int subsize=n-sub[u];
				upd[0]=add(upd[0],MOD-mult(d,mult(subsize,invn)));
				upd[u]=add(upd[u],mult(d,mult(subsize,invn)));
			}
			else
			{
				upd[v]=add(upd[v],MOD-mult(d,mult(sub[v],invn)));
			}
		}
	}
	push(0,-1);
	for(int i=0;i<n;i++) 
	{
		explode[i]=upd[i]=0;
	}
	queries.clear();
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>q; T.reset(n);
	for(int i=0;i<n-1;i++)
	{
		int u,v; cin>>u>>v; u--; v--; T.addedge(u,v);
		adj[u].pb(v); adj[v].pb(u);
	}
	T.calcpar();
	dfs(0,-1);
	T.calcstartend();
	int totsum=0;
	invn = inverse(n);
	for(int i=0;i<q;i++)
	{
		int t; cin>>t;
		if(t==1)
		{
			int u,d; cin>>u>>d; u--;
			totsum=add(totsum,d);
			queries.pb({u,d});
			explode[u]=add(explode[u],d);
			if(queries.size()>=C)
			{
				recomp();
			}
		}
		else
		{
			int u; cin>>u; u--;
			int res=add(totsum,ans[u]);
			for(ii x:queries)
			{
				int v=x.fi; int d=x.se;
				if(v==u) continue;
				int subsize=0;
				if(T.insub(u,v)) //u in sub of v
				{
					int hu = T.h[u];
					int hv = T.h[v];
					int thepar = child_ancestor(v,u);
					subsize=sub[thepar];
				}
				else
				{
					subsize=n-sub[v];
				}
				res=add(res,MOD-mult(d,mult(subsize,invn)));
			}
			cout<<res<<'\n';
		}
	}
}