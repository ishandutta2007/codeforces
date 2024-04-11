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

const int N = 2e6 + 100;
const int inf = 1e9;
//const ll inf = 1e18;
const ll mod = 998244353;//1e9 + 7;

int n, m;
string s;
int a[N];
bool vis[N];
ll add[N], res[N], add2[N], add3[N];

void sol()
{
	ll k;
	cin >> n >> k;
	bool flg = 1;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] != -1 && a[i] >= i)
		{
			flg = 0;
		}
		if(i > n - k && a[i] > 0)
		{
			flg = 0;
		}
	}
	if(!flg)
	{
		cout << 0 << '\n';
		return;
	}
	ll ans = 1LL;
	for(int i = 1; i <= k; i++)
		ans = ans * i % mod;
	for(int i = 1; i <= n - k; i++)
	{
		if(a[i] == -1)
		{
			ans = ans * (k + i) % mod;
		}
		else if(a[i] == 0)
		{
			ans = ans * (k + 1) % mod;
		}
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
/*
0 0 0 3 4
0 0 1 3 4
0 1 0 3 4
0 0 2 3 4 
0 1 1 3 4
0 1 2 3 4

*/