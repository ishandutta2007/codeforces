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
bool link[11][11];
bool ifok[4000][11];
int nxt[4000][11];

void sol()
{
	cin >> n;
	cin >> m;
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		link[x][y] = link[y][x] = 1;
	}
	for(int sta = 0; sta < (1 << 10); sta++)
	{
		for(int i = 0; i <= 9; i++)
		{
			ifok[sta][i] = 1;
			for(int j = i + 1; j <= 9; j++)
			{
				if((sta & (1 << j)) && link[i][j])
				{
					ifok[sta][i] = 0;	
				}
			}
			if(ifok[sta][i])
			{
				int to = (1 << i);
				for(int j = 0; j <= 9; j++)
				{
					if((sta & (1 << j)) && link[i][j])
					{
						to |= (1 << j);
					}
				}
				nxt[sta][i] = to;
			}
		}
	}
	VLL dp(1 << 10, 0), dq(1 << 10, 0);
	for(int i = 0; i <= 9; i++)
		dp[1 << i] = 1;
	for(int i = 2; i <= n; i++)
	{
		fill(all(dq), 0);
		for(int sta = 0; sta < (1 << 10); sta++)
		{
			for(int nw = 0; nw <= 9; nw++)
			{
				if(ifok[sta][nw])
				{
					(dq[nxt[sta][nw]] += dp[sta]) %= mod;
				}
			}
		}
		swap(dp, dq);
	}
	ll res = 0;
	for(int i = 0; i < (1 << 10); i++)
		(res += dp[i]) %= mod;
	cout << res << '\n';
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