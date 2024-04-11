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
//#define int long long
using namespace std;
const int N = 1e6 + 100;
const int inf = 1e9;
//const ll inf = 1e18
const ll mod = 998244353;//1e9 + 7

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


int n, m;
int a[N], ans[N], val[N], fr[N], to[N], type[N];
bool vis[N];

vector<pii> adj[N], aadj[N], adj2[N];
bool ok = 1;

void dfs(int x)
{
//	cerr << x << ' ' << val[x] << '\n';
	vis[x] = 1;
	trav(v, adj2[x])
	{
		if(vis[v.fi])
		{
			if(val[v.fi] != (val[x] ^ v.sc))
				ok = 0; 
			continue;
		}
		val[v.fi] = val[x] ^ v.sc;
		dfs(v.fi);
	}
}

void ddfs(int x, int fa)
{
	trav(v, adj[x])
	{
		if(v.fi == fa)
			continue;
		ddfs(v.fi, x);
	}
	trav(v, aadj[x])
	{
		if(v.fi == fa)
			continue;
		ans[v.sc] = val[x] ^ val[v.fi];
		ddfs(v.fi, x);
	}
}

int bel[N], dep[N], tot;

void Dfs(int x, int ff)
{
	trav(v, adj[x])
	{
		if(v.fi == ff)
			continue;
		bel[v.fi] = bel[x];
		dep[v.fi] = dep[x] ^ __builtin_parity(v.sc);
		Dfs(v.fi, x);
	}
	trav(v, aadj[x])
	{
		if(v.fi == ff)
			continue;
		bel[v.fi] = ++tot;
		dep[v.fi] = 0;
//		adj2[bel[x]].pb(pii(bel[v.fi], v.sc));
//		adj2[bel[v.fi]].pb(pii(bel[x], v.sc));
		Dfs(v.fi, x);
	}
}

int cas = 0, ttt;

void sol()
{
	cin >> n >> m;
	tot = 0;
	for(int i = 1; i <= n; i++)
		adj[i].clear(), aadj[i].clear(), adj2[i].clear(), vis[i] = 0, val[i] = 0, bel[i] = 0;
	for(int i = 1; i < n; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		fr[i] = x;
		to[i] = y;
		if(z != -1)
		{
			adj[x].pb(pii(y, z));
			adj[y].pb(pii(x, z));
			ans[i] = z;
		}
		else
		{
			aadj[x].pb(pii(y, i));
			aadj[y].pb(pii(x, i));
			ans[i] = -1;
		}
	}
	bel[1] = ++tot;
	dep[1] = 0;
	Dfs(1, 0);
	int x, y, z;
	ok = 1;
	while(m--)
	{
		cin >> x >> y >> z;
		if(bel[x] == bel[y] && (__builtin_parity(dep[x] ^ dep[y]) != z))
			ok = 0;
		else
		{
			int nw = z;
			if(dep[x] != dep[y])
				nw ^= 1;
			adj2[bel[x]].pb(pii(bel[y], nw));
			adj2[bel[y]].pb(pii(bel[x], nw));
		//	cerr << x << ' ' << bel[x] << ' ' << y << ' ' << bel[y] << ' ' << nw << '\n';
		}
	}
	for(int i = 1; i <= tot; i++)
	{
		if(!vis[i])
		{
			val[i] = 0;
			dfs(i);
		}
	}
	if(!ok)
	{
		cout << "NO" << '\n';
		return;
	}
	cout << "YES" << '\n';
	for(int i = 1; i < n; i++)
	{
		if(ans[i] == -1)
		{
			int nw = dep[fr[i]] ^ dep[to[i]];
			if(val[bel[fr[i]]] != val[bel[to[i]]])
				nw ^= 1;
			ans[i] = nw;
		}
		cout << fr[i] << ' ' << to[i] << ' ' << ans[i] << '\n';
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin >> tt;
	ttt = tt;
	while(tt--)
		sol();
}
/*
1
5 10
4 5 -1
1 4 -1
3 4 1
1 2 -1
3 2 1
5 1 1
4 1 1
1 3 0
4 3 1
5 4 0
4 5 0
5 4 0
5 1 1
4 5 0
*/