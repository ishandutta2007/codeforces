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

int n, m;
int a[510][510], cnt[2][510][510], f[510], g[510];

void sol()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		for(int j = 1; j <= m; j++)
			a[i][j] = (s[j - 1] == '1');
	}
	for(int j = 1; j <= m; j++)
	{
		for(int i = 1; i <= n; i++)
		{
			cnt[0][i][j] = cnt[0][i - 1][j] + (a[i][j] == 0);
			cnt[1][i][j] = cnt[1][i - 1][j] + (a[i][j] == 1);
		}
	}
	int res = inf;
	for(int up = 1; up <= n; up++)
	{
		for(int dw = up; dw <= n; dw++)
		{
			if(dw - up < 4)
				continue;
			for(int i = 1; i <= m; i++)
			{
				f[i] = cnt[0][dw - 1][i] - cnt[0][up][i];
				g[i] = cnt[1][dw - 1][i] - cnt[1][up][i] + (a[up][i] == 0) + (a[dw][i] == 0);
			}
			int mn = inf;
			for(int l = m; l >= 1; l--)
			{
				if(m - l >= 3)
				{
					mn += g[l + 1];
					mn = min(mn, f[l + 3] + g[l + 1] + g[l + 2]);
					res = min(res, f[l] + mn);
				}
			}
		}
	}
	cout << res << '\n';
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