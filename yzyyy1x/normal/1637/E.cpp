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
const ll inf = 1e18;
const ll mod = 998244353;//1e9 + 7;

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


pii a[N];
int num;
map<int, bool> cant[N];
const int B = 200;
set<pii> st[B + 10];

void sol()
{
	for(int i = 0; i <= B; i++)
		st[i].clear();
	int n, m;
	cin >> n >> m;
	map<int, int> vis, id;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		vis[x]++;
	}
	num = 0;
	trav(v, vis)
	{
		a[++num] = v;
		id[v.fi] = num;
	}
	for(int i = 0; i <= num; i++)
		cant[i].clear();
	for(int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		x = id[x];
		y = id[y];
		cant[x][y] = cant[y][x] = 1;
	}
	ll ans = 0;
	vector<int> may;
	for(int i = 1; i <= num; i++)
	{
		trav(j, may)
		{
			if(cant[i][j])
				continue;
			ans = max(ans, 1LL * (a[i].fi + a[j].fi) * (a[i].sc + a[j].sc));
		}
		for(int j = 1; j <= B; j++)
		{
			if(st[j].empty())
				continue;
			auto ii = prev(st[j].end());
			while(1)
			{
				if(!cant[(*ii).second][i])
				{
					ans = max(ans, 1LL * ((*ii).first + a[i].fi) * (a[i].sc + j));
					break;
				}
				if(ii == st[j].begin())
					break;
				ii = prev(ii);
			}
		}
		if(a[i].sc <= B)
			st[a[i].sc].insert(pii(a[i].fi, i));
		else may.pb(i);
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