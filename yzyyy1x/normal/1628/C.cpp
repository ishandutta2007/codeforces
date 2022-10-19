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
//const ll inf = 1e18;
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

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};


void sol()
{
	int n;
	cin >> n;
	vector<VI> mp(n, VI(n)), a(n, VI(n));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> mp[i][j];
	ll ans = 0;
	for(int val = (1 << 30); val >= 1; val >>= 1)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(mp[i][j] & val)
					a[i][j] = 1;
				else a[i][j] = 0;
			}
		}
		int num = 0;
		auto doit = [&](int i, int j)
		{
			for(int d = 0; d < 4; d++)
			{
				int ni = i + dx[d];
				int nj = j + dy[d];
				if(ni >= 0 && ni < n && nj >= 0 && nj < n)
				{
					a[ni][nj] ^= 1;
				}
			}
			return;
		};
		for(int i = 0; i < n - 1; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(a[i][j])
					num ^= 1, doit(i + 1, j);
			}
//			if(a[i][n - 1] && i + 1 < n)
//				num ^= 1, doit(i + 1, n - 1);
		}
		if(num == 1)
			ans |= val;
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