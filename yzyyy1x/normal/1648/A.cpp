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

int n, m;
vector<pii> col[N];

void sol()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			int x;
			cin >> x;
			col[x].pb(pii(i, j));
		}
	}
	int lim = 2e5;
	ll ans = 0;
	for(int i = 0; i <= lim; i++)
	{
		if(col[i].empty())
			continue;
		vector<pii> buk = col[i];
		ll sum = 0, num = 0;
		sort(all(buk));
		trav(v, buk)
			ans += v.fi * num - sum, ++num, sum += v.fi;
		sort(all(buk), [&](pii x, pii y)
		{
			return x.sc < y.sc;
		});
		sum = num = 0;
		trav(v, buk)
			ans += v.sc * num - sum, ++num, sum += v.sc;
	}
	cout << ans << '\n';
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