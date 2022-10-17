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

int n;
pii a[N];
int p[N];
int sz;
bool vis[N];

void dfs(int x)
{
	vis[x] = 1;
	++sz;
	if(vis[p[x]])
		return;
	dfs(p[x]);
}

void sol()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i].fi;
	for(int i = 1; i <= n; i++)
		cin >> a[i].sc;
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
		p[i] = a[i].sc;
	for(int i = 1; i <= n; i++)
		vis[i] = 0;
	vector<int> buk[2];
	for(int i = 1; i <= n; i++)
	{
		if(vis[i])
			continue;
		sz = 0;
		dfs(i);
		buk[sz & 1].pb(sz);
	}
	int l = 1, r = n;
	ll ans = 0;
	trav(v, buk[0])
	{
		VI cur;
		for(int i = 0; i < v / 2; i++)
			cur.pb(l++), cur.pb(r--);
		for(int i = 0; i < v; i++)
			ans += abs(cur[i] - cur[(i - 1 + v) % v]);
	}
	vector<vector<int>> bb;
	trav(v, buk[1])
	{
		VI cur;
		for(int i = 0; i < v / 2; i++)
			cur.pb(l++), cur.pb(r--);
		bb.pb(cur);
	}
	trav(cur, bb)
	{
		cur.pb(l++);
		for(int i = 0; i < cur.size(); i++)
			ans += abs(cur[i] - cur[(i - 1 + cur.size()) % cur.size()]);
	}
	cout << ans << '\n';
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--)
		sol();
}