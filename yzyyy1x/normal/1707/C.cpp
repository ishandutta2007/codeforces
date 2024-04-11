#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define sc second
#define pb push_back
#define ll long long
#define trav(v,x) for(auto v:x)
#define all(x) (x).begin(), (x).end()
#define VI vector<int>
#define VLL vector<ll>
#define pll pair<ll, ll>
#define double long double
#define int long long
using namespace std;

#ifdef LOCAL
void debug_out(){cerr << endl;}
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
	cerr << " " << to_string(H);
	debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const int N = 1e6 + 100;
const int inf = 1e9;
//const ll inf = 1e18;
const ll mod = 998244353;//1e9 + 7;

int n, m;
int a[N];

struct Dsu{
	int fa[N];
	int find(int x)
	{return fa[x] == x ? x : fa[x] = find(fa[x]);}
	bool link(int x, int y)
	{
		x = find(x);
		y = find(y);
		if(x == y)
			return false;
		fa[x] = y;
		return true;
	}
	void init()
	{
		for(int i = 1; i <= n; i++)
			fa[i] = i;
	}
}dsu;

vector<int> adj[N];
vector<pii> may;

int jp[N][22], dep[N];
int tim, in[N], ot[N];

void dfs(int x, int fa)
{
	jp[x][0] = fa;
	in[x] = ++tim;
//	cerr << "PP" << x << ' ' << in[x]<< ' ' << fa << '\n';
	for(int j = 1; j < 20; j++)
		jp[x][j] = jp[jp[x][j - 1]][j - 1];
	trav(v, adj[x])
	{
		if(v == fa)
			continue;
		dep[v] = dep[x] + 1, dfs(v, x);
	}
	ot[x] = tim;
}

int jump(int x, int d)
{
	for(int j = 19; j >= 0; j--)
		if(d & (1 << j))x = jp[x][j];
	return x;
}

int fen[N];
void add(int x, int y)
{
	for(; x <= tim; x += x & -x)
		fen[x] += y;
}
void add(int l, int r, int y)
{
	add(l, y);
	add(r + 1, -y);
}
int ask(int x)
{
	int res = 0;
	for(; x; x -= x & -x)
		res += fen[x];
	return res;
}

void sol()
{
	cin >> n >> m;
	dsu.init();
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		if(dsu.link(x, y))
		{
			adj[x].pb(y);
			adj[y].pb(x);
		}
		else
		{
			may.pb(pii(x, y));
		}
	}
	dep[1] = 1, dfs(1, 0);
	trav(v, may)
	{
		int x, y;
		tie(x, y) = v;
		if(dep[x] < dep[y])
			swap(x, y);
		if(in[y] <= in[x] && ot[x] <= ot[y])
		{
			int d = dep[x] - dep[y];
			int t = jump(x, d - 1);
			add(in[t], ot[t], 1);
			add(in[x], ot[x], -1);
		}
		else
		{
		//	cerr << x << ' ' << y << ' ' << lca << '\n';
			add(in[1], ot[1], 1);
			add(in[x], ot[x], -1);
			add(in[y], ot[y], -1);
		}
	}
	for(int i = 1; i <= n; i++)
		cout << (ask(in[i]) == 0 ? 1 : 0);
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
//	int tt;
//	cin >> tt;
//	while(tt--)
		sol();
}