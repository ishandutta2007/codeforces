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
const ll inf = 1e18;
const ll mod = 998244353;//1e9 + 7;

int n, m;
ll a[N], b[N], sa[N], sb[N], dt[N];
vector<pii> hav[N];
bool vis[N], use[N];

int nxt[N];

int find(int x)
{return nxt[x] == x ? x : nxt[x] = find(nxt[x]);}

void gao(int x)
{
	vis[x] = 1;
	nxt[x] = find(x + 1);
}

void sol()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sa[i] = sa[i - 1] + a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> b[i];
		sb[i] = sb[i - 1] + b[i];
		dt[i] = sb[i] - sa[i];
	}
	queue<pii> que;
	for(int i = 0; i <= n + 1; i++)
		hav[i].clear();
	for(int i = 0; i <= n + 1; i++)
	{
		vis[i] = 0;
		nxt[i] = i;
	}
	for(int i = 0; i <= n; i++)
	{
		if(dt[i] == 0)
			gao(i);
	}
	for(int i = 1; i <= m; i++)
	{
		int l, r;
		cin >> l >> r;
		--l;
		if(dt[l] == 0 && dt[r] == 0)
			que.push(pii(l, r));
		else
		{
			hav[l].pb(pii(r, i));
			hav[r].pb(pii(l, i));
			use[i] = 0;
		}
	}
	while(!que.empty())
	{
		int l, r;
		tie(l, r) = que.front();
		que.pop();
		for(int i = find(l); i <= r; i = find(i))
		{
			gao(i);
			trav(v, hav[i])
			{
				if(use[v.sc] || !vis[v.fi])
					continue;
				use[v.sc] = 1;
				que.push(pii(min(v.fi, i), max(v.fi, i)));
			}
		}
	}
	for(int i = 0; i <= n; i++)
	{
		if(!vis[i])
		{
			cout << "NO" << '\n';
			return;
		}
	}
	cout << "YES" << '\n';
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