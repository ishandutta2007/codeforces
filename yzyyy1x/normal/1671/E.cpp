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

int n, m, a[N], val[N];
string s;

ll dp[N];

void dfs(int x)
{
	if(x * 2 > m)
	{
		dp[x] = 1;
		return;
	}
	dfs(x * 2);
	dfs(x * 2 + 1);
	if(val[x * 2] != val[x * 2 + 1])
		dp[x] = 2LL * dp[x * 2] * dp[x * 2 + 1] % mod;
	else
	{
		dp[x] = dp[x * 2] * dp[x * 2 + 1] % mod;
	}
}

void sol()
{
	cin >> n;
	m = (1 << n) - 1;
	cin >> s;
	for(int i = 1; i <= m; i++)
		a[i] = (s[i - 1] == 'B');
	for(int dep = n; dep >= 1; dep--)
	{
		int l = 1 << (dep - 1), r = (1 << dep) - 1;
		if(dep == n)
		{
			for(int i = l; i <= r; i++)
			{
				val[i] = a[i];
			}
			continue;
		}
		int tot = 0;
		map<tuple<int, int, int>, int> mp;
		for(int i = l; i <= r; i++)
		{
			int vl = val[i * 2], vr = val[i * 2 + 1];
			if(vl > vr)
				swap(vl, vr);
			if(!mp.count(make_tuple(a[i], vl, vr)))
				mp[make_tuple(a[i], vl, vr)] = ++tot;
			val[i] = mp[make_tuple(a[i], vl, vr)];
		}
	}
	dfs(1);
	cout << dp[1] << '\n';
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