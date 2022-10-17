//#define LOCAL
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
const int N = 4e6 + 100;
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

int n, a[N];

int tot = 0;
VI adj[N];
int imp[N];
unordered_map<int, int>id;
bool link[N];

int cal_id(int x)
{
	if(id.find(x) == id.end())
		++tot, id[x] = tot;
	return id[x];
}

void doit(int x, int ps)
{
	int nw;
	nw = cal_id(x);
	imp[nw] = ps;
	while(x)
	{
		int nxt, nxt_id;
		int tmp = 1;
		while(tmp < x)
			tmp <<= 1;
		nxt = tmp - x;
		nxt_id = cal_id(nxt);
		if(!link[nw])
			adj[nxt_id].pb(nw), link[nw] = 1;
//		cerr << x << ' ' << nxt << '\n';
		swap(x, nxt);
		swap(nw, nxt_id);
	}
}

int mx[N];
int mx_val = -1;
pii ans;

void upd(int val, int x, int y)
{
	if(val > mx_val)
		mx_val = val, ans = pii(x, y);
}

int dep[N];

void dfs(int x)
{
	mx[x] = -1;
	if(imp[x])
		mx[x] = x;
	trav(v, adj[x])
	{
		dep[v] = dep[x] + 1, dfs(v);
		if(mx[v] != -1)
		{
			if(mx[x] != -1)
				upd(dep[mx[x]] + dep[mx[v]] - 2 * dep[x], mx[x], mx[v]);
			if(mx[x] == -1 || dep[mx[x]] < dep[mx[v]])
				mx[x] = mx[v];
		}
	}
}

void sol()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		doit(a[i], i);
	}
	dep[id[0]] = 0, dfs(id[0]);
	cout << imp[ans.fi] << ' ' << imp[ans.sc] << ' ' << mx_val << '\n';
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