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
int a[N];

bool ifok;
bool dp[N];
vector<int> adj[N];
vector<pii> ans[2];

void dfs1(int x, int fa)
{
	int c[2] = {0, 0}, s = 0;
	trav(v, adj[x])
	{
		if(v == fa)
			continue;
		dfs1(v, x);
		++s;
		++c[dp[v]];
	}
	if(!ifok)
		return;
	if(s == 0)
	{
		dp[x] = 0;
		return;
	}
	if(x == 1)
	{
		if(s & 1)
		{
			if(!(c[0] - c[1] == 1))
				ifok = 0;
		}
		else
		{
			if(!(c[0] == c[1]))
				ifok = 0;
		}
	}
	else
	{
		if(s & 1)
		{
			if(c[0] - c[1] == 1)
				dp[x] = 1;
			else if(c[1] - c[0] == 1)
				dp[x] = 0;
			else
				ifok = 0;
		}
		else
		{
			if(c[0] == c[1])
				dp[x] = 0;
			else if(c[0] - c[1] == 2)
				dp[x] = 1;
			else
				ifok = 0;
		}
	}
}

void del(int x, int fa)
{
	VI type[2];
	int c[2] = {0, 0}, s = 0;
	trav(v, adj[x])
	{
		if(v == fa)
			continue;
		del(v, x);
		++s;
		++c[dp[v]];
		type[dp[v]].pb(v);
	}
	if(s == 0)
		return;
	if(x == 1)
	{
		if(s & 1)
		{
			for(int i = 0; i < c[1]; i++)
			{
				ans[0].pb(pii(1, type[0][i]));
				ans[0].pb(pii(1, type[1][i]));
			}
			ans[0].pb(pii(1, type[0][c[0] - 1]));
		}
		else
		{
			for(int i = 0; i < c[1]; i++)
			{
				ans[0].pb(pii(1, type[1][i]));
				ans[0].pb(pii(1, type[0][i]));
			}
		}
	}
	else
	{
		if(s & 1)
		{
			if(c[0] - c[1] == 1)
			{
				ans[1].pb(pii(x, type[0][c[0] - 1]));
				for(int i = 0; i < c[1]; i++)
				{
					ans[1].pb(pii(x, type[1][i]));
					ans[1].pb(pii(x, type[0][i]));
				}
			}
			else if(c[1] - c[0] == 1)
			{
				for(int i = 0; i < c[0]; i++)
				{
					ans[0].pb(pii(x, type[1][i]));
					ans[0].pb(pii(x, type[0][i]));
				}
				ans[0].pb(pii(x, type[1][c[1] - 1]));
			}
		}
		else
		{
			if(c[0] == c[1])
			{
				for(int i = 0; i < c[0]; i++)
				{
					ans[0].pb(pii(x, type[0][i]));
					ans[0].pb(pii(x, type[1][i]));
				}
			}
			else if(c[0] - c[1] == 2)
			{
				ans[0].pb(pii(x, type[0][c[0] - 1]));
				ans[1].pb(pii(x, type[0][c[0] - 2]));
				for(int i = 0; i < c[1]; i++)
				{
					ans[1].pb(pii(x, type[1][i]));
					ans[1].pb(pii(x, type[0][i]));
				}
			}
		}
	}
}

void sol()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		adj[i].clear();
	for(int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	ifok = 1;
	dfs1(1, 0);
	if(!ifok)
	{
		cout << "NO" << '\n';
		return;
	}
	ans[0].clear(), ans[1].clear();
	cout << "YES" << '\n';
	del(1, 0);
	trav(v, ans[0])
		cout << v.fi << ' ' << v.sc << '\n';
	reverse(all(ans[1]));
	trav(v, ans[1])
		cout << v.fi << ' ' << v.sc << '\n';
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