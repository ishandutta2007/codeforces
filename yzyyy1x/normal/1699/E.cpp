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

const int N = 5050;
const int inf = 1e9;
//const ll inf = 1e18;
const ll mod = 1e9 + 7;
const int M = 5e6 + 100;

bool np[M];
int pri[M];
int pnum = 0;

int n, m;

void sol()
{
	cin >> n >> m;
	vector<int> hav(m + 1, 0), dp(m + 1, m), need(m + 1, 0);
	int mn = inf;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		hav[x] = 1;
		mn = min(mn, x);
	}
	int mx = m, ans = inf;
	for(int i = m; i >= 1; i--)
	{
		dp[i] = i;
		if(hav[i])
			need[i]++;
		for(int j = 1; j * i <= m; j++)
		{
			if(hav[i * j])
				need[dp[i * j]]--;
			dp[i * j] = min(dp[i * j], dp[j]);
			if(hav[i * j])
				need[dp[i * j]]++;
		}
		while(mx > i && !need[mx])
			--mx;
		//if(i <= 7)cerr << i << ' ' << mn << ' ' << mx << '\n';
		if(i <= mn)
			ans = min(ans, mx - i);
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