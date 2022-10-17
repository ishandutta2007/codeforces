#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define sc second
#define pb push_back
#define ll long long
#define trav(v, x) for(auto v:x)
#define VI vector<int>
#define VLL vector<ll>
//define double long double
#define all(x) (x).begin(),(x).end()
using namespace std;
const double eps = 1e-10;//1e-12
const int N = 2e5 + 100;
const ll mod = 998244353;//1e9 + 7;

VI adj[N];

int sum[N], a[N], n, m;
bool flg, hav[N];

map<int, int>vis;

void dfs(int x, int fa)
{
	sum[x] = a[x];
	trav(v, adj[x])
	{
		if(v == fa)
			continue;
		dfs(v, x);
		sum[x] ^= sum[v];
	}
	if(fa != 0)
		vis[sum[x]]++;
}

void ddfs(int x, int fa)
{	
	if(sum[x] == sum[1])
		hav[x] |= 1;
	int num = 0;
	trav(v, adj[x])
	{
		if(v == fa)
			continue;
		ddfs(v, x);
		if(hav[v])num++, hav[x] = 1;
	}
	if(num >= 2)
		flg = 1;
	if(sum[x] == 0 && hav[x])
		flg = 1;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--)
	{
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
			cin >> a[i], adj[i].clear();
		for(int i = 1; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			adj[x].pb(y);
			adj[y].pb(x);
		}
		vis.clear();
		dfs(1, 0);
		//cerr << sum[1] <<  ' ' << sum[2] << '\n';
		if(sum[1] == 0)
		{
			cout << "YES" << '\n';
			continue;
		}
		if(m >= 3)
		{
			flg = 0;
			for(int i = 1; i <= n; i++)
				hav[i] = 0;
			//cerr << sum[1] << '\n';
			ddfs(1, 0);
			if(flg)
			{
				cout << "YES" << '\n';
				continue;
			}
		}
		cout << "NO" <<'\n';
	}
}