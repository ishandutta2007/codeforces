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
const int LG = 20;

vector<vector<int> > adj;
int n;

void init(int _n)
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
vector<vector<int> > st;

void addedge(int u, int v)
{
	adj[u].pb(v);
	adj[v].pb(u);
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
		int v = adj[u][i];
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
		int v = adj[u][i];
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
		int v = adj[u][i];
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
	st[0][u] = p;
	if(p == -1) h[u] = 0;
	else h[u] = h[p] + 1;
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if(v == p) continue;
		dfspar(v, u);
	}
}

int LOG;

void calcpar()
{
	h.resize(n);
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
			if(st[i-1][j] == -1) st[i][j] = -1;
			else st[i][j] = st[i-1][st[i-1][j]];
		}
	}
}


bool used[1111111];
	
int main()
{
	int n,k; scanf("%d %d",&n,&k); init(n);
	for(int i=0;i<n-1;i++)
	{
		int u,v; scanf("%d %d",&u,&v); u--; v--; u = n - 1 - u; v = n - 1 - v; //cerr<<"ADD "<<u<<' '<<v<<'\n';
		addedge(u,v);
	}
	calcpar();
	used[0]=1; 
	k=n-k;
	k--;
	for(int i=1;i<n;i++)
	{
		if(used[i]) continue;
		int cur = i; int lvl = 0;
		for(int j=LG-1;j>=0;j--)
		{
			if(st[j][cur] == -1) continue;
			if(used[st[j][cur]]) continue;
			lvl^=(1<<j);
			cur=st[j][cur];
		}
		lvl++;
		//cerr<<"LVL "<<k<<' '<<i<<' '<<lvl<<'\n';
		if(lvl<=k)
		{
			k-=lvl; int cr = i;
			used[cr]=1;
			for(int j=0;j<lvl;j++)
			{
				//cerr<<"USE "<<cr<<endl;
				cr = st[0][cr];
				used[cr]=1;
			}
		}
	}
	for(int i=n-1;i>=0;i--)
	{
		if(!used[i])
		{
			printf("%d ",n-i);//<<' ';
		}
	}
	printf("\n");
}