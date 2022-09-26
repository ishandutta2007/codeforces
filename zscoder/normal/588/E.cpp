#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

const int INF = 1e9 + 7;

void debug()
{
	cout << "Debugg" << endl;
}

struct node
{
	vi vec;
	void set()
	{
		vec.assign(10, INF);
	}
	void insert(int x)
	{
		vec.pb(x);
		sort(vec.begin(), vec.end());
		vec.resize(10);
	}
};

void pnode(node a)
{
	for(int i = 0; i < 10; i++)
	{
		printf("%d ", a.vec[i]);
	}
	printf("\n");
}

node combine(node a, node b)
{
	node ans;
	ans.vec.resize(20);
	//sort(a.vec.begin(), a.vec.end()); sort(b.vec.begin(), b.vec.end());
	////debug()();
	merge(a.vec.begin(), a.vec.end(), b.vec.begin(), b.vec.end(), ans.vec.begin());
	////debug()();
	//sort(ans.vec.begin(), ans.vec.end());
	////debug()();
	//cout << ans.vec.size() << endl;
	ans.vec.resize(10);
	////debug()();
	return ans;
}

const int LG = 17;

node w[100001];
node st[LG][100001]; //always combine with current w before use
vi adj[100001];
int par[LG][100001];
bool visited[100001];
int h[100001];

void dfs(int u)
{
	visited[u] = true;
	//cout << u << endl;
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if(!visited[v])
		{
			h[v] = h[u] + 1;
			par[0][v] = u;
			st[0][v] = w[u];
			//cout << v << ' ' << 0 << ' ' << par[0][v] << '\n';
			//pnode(st[0][v]);
			//debug()();
			for(int j = 1; j < LG; j++)
			{
				//cout << v << ' ' << j << ' ' << par[j - 1][v] << '\n'; //debug()();
				if(par[j-1][v] != -1) par[j][v] = par[j - 1][par[j - 1][v]];
				else par[j][v] = -1;
				//debug()();
				if(par[j-1][v] != -1) st[j][v] = combine(st[j-1][v], st[j-1][par[j-1][v]]); //needs rechecking
				else st[j][v] = st[j-1][v]; //check again
				//pnode(st[j][v]);
				//debug()();
			}
			dfs(v);
		}
	}	
}

int lca(int u, int v)
{
	if(u == v) return u;
	if(h[u] > h[v]) swap(u, v);
	for(int i = LG - 1; i >= 0; i--)
	{
		if(par[i][v] != -1 && h[par[i][v]] >= h[u])
		{
			v = par[i][v];
		}
	}
	if(v == u) return u;
	for(int i = LG - 1; i >= 0; i--)
	{
		if(par[i][v] != -1 && par[i][u] != -1 && par[i][v] != par[i][u])
		{
			v = par[i][v];
			u = par[i][u];
		}
	}
	return par[0][v];
}

node path(int u, int height)
{
	node ans = w[u];
	for(int i = LG - 1; i >= 0; i--)
	{
		if(height&(1<<i))
		{
			ans = combine(ans, st[i][u]);
			u = par[i][u];
		}
	}
	return ans;
}

void output(node &x, int a)
{
	vi ans;
	for(int i = 0; i < 10; i++)
	{
		if(x.vec[i] != INF) ans.pb(x.vec[i]);
	}
	//sort(ans.begin(), ans.end());
	printf("%d ", min(a,int(ans.size())));
	for(int i = 0; i < min(int(ans.size()), a); i++)
	{
		printf("%d ", ans[i]+1);
	}
	printf("\n");
}

int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 0; i < n - 1; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for(int i = 0; i < n; i++)
	{
		w[i].set();
	}
	for(int i = 0; i < m; i++)
	{
		int c;
		scanf("%d", &c);
		c--;
		w[c].insert(i); //remember to + 1 at output
	}
	st[0][0].set(); h[0] = 0; 
	for(int i = 0; i < LG; i++)
	{
		par[i][0] = -1;
	}
	dfs(0);
	for(int i = 0; i < q; i++)
	{
		int u, v, a;
		scanf("%d %d %d", &u, &v, &a);
		u--; v--;
		int lc = lca(u, v);
		int hlc = h[lc]; int hu = h[u]; int hv = h[v];
		//printf("VERTICES : %d %d %d\nHEIGHTS : %d %d %d\n", u, v, lc, hu, hv, hlc);
		node key;
		if(hu == hlc && hlc == hv)
		{
			key = w[u];
		}
		else if(hu == hlc)
		{
			key = path(v, hv - hlc);
		}
		else
		{
			key = path(v, hv - hlc);
			key = combine(key, path(u, hu - hlc - 1));
		}
		output(key, a);
	}
	return 0;
}