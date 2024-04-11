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

const int N = 3050;
const ll inf = 1e18;
const ll mod = 998244353;//1e9 + 7;

int n, dp[N][N];
int a[N], nxt[N];

void sol()
{
	VI buk;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i], buk.pb(a[i]);
	sort(all(buk));
	buk.erase(unique(all(buk)), buk.end());	
	for(int i = 1; i <= n; i++)
		a[i] = lower_bound(all(buk), a[i]) - buk.begin() + 1;
	int cnum = buk.size();
	VI bf(cnum + 1, n + 1);
	for(int i = n; i >= 1; i--)
	{
		nxt[i] = bf[a[i]];
		bf[a[i]] = i;
	}
	for(int i = 1; i <= n; i++)	
		dp[i][i] = 0;
	for(int len = 2; len <= n; len++)
	{
		for(int l = 1; l + len - 1 <= n; l++)
		{
			int r = l + len - 1;
			dp[l][r] = dp[l + 1][r] + 1;
			for(int i = nxt[l]; i <= r; i = nxt[i])
			{
				dp[l][r] = min(dp[l][r], dp[l + 1][i] + dp[i][r]);
			}
		}
	}
	cout << dp[1][n] << '\n';
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(dp, 0, sizeof dp);
	int tt;
	cin >> tt;
	while(tt--)
		sol();
}
/*
1
80
3 2 3 4 1 1 2 1 4 2 4 3 2 1 2 4 1 3 1 3 3 3 4 4 2 2 3 2 2 3 4 4 4 1 1 4 2 4 4 2 3 3 1 1 1 1 1 1 1 4 3 4 4 3 3 1 2 2 3 4 1 4 4 3 3 3 4 1 3 3 2 2 2 2 2 4 1 2 1 2
*/