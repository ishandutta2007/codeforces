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

const int N = 5050;
const int inf = 1e9;
//const ll inf = 1e18;
const ll mod = 1e9 + 7;

int n;
int a[N], ps[N];

int need[N][N];
int cnt[N];

//

void sol()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		memset(cnt, 0, sizeof cnt);
		int mx = 0;
		for(int j = i; j <= n; j++)
		{
			++cnt[a[j]];
			mx = max(mx, cnt[a[j]]);
			if(mx * 2 > j - i + 1 || (j - i + 1) & 1)
				need[i][j] = 1;
			else need[i][j] = 0;
		}
	}
	int ans = 0;
	for(int val = 1; val <= n; val++)
	{
		VI buk;
		buk.pb(0);
		for(int i = 1; i <= n; i++)
		{
			if(a[i] == val)
				buk.pb(i);
		}
		buk.pb(n + 1);
		VI dp(buk.size(), 0);
		for(int j = 1; j < buk.size(); j++)
		{
			int mx = -inf;
			for(int k = 0; k < j; k++)
			{
				if(need[buk[k] + 1][buk[j] - 1] == 0)
					mx = max(mx, dp[k] + 1);
			}
			dp[j] = mx;
		}
		ans = max(ans, dp[buk.size() - 1] - 1);
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