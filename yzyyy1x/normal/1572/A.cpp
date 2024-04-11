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

VI adj[N];
int deg[N];

void sol()
{
	cin >> n;
	for(int i = 0; i <= n; i++)
		deg[i] = 0, adj[i].clear();
	for(int i = 1; i <= n; i++)
	{
		int m;
		cin >> m;
		for(int j = 1; j <= m; j++)
		{
			int x;
			cin >> x;
			adj[x].pb(i);
			++deg[i];
		}
	}
	int cur = 0, num = 0;
	set<int> may;
	for(int i = 1; i <= n; i++)
	{
		if(!deg[i])
			may.insert(i);
	}
	int ans = 1;
	while(!may.empty())
	{
		auto ii = may.lower_bound(cur);
		if(ii == may.end())
		{
			++ans;
			cur = 0;
			continue;
		}
		int x = (*ii);
		may.erase(ii);
		++num;
		trav(v, adj[x])
		{
			--deg[v];
			if(deg[v] == 0)
				may.insert(v);
		}
		cur = x;
	}
	cout << (num == n ? ans : -1) << '\n';
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--)
		sol();
	return 0;
}