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

void sol()
{
	int n;
	cin >> n;
	VI a(n + 1, 0), vis(n + 1, 0);
	for(int i = 0; i < n; i++)
		cin >> a[i], vis[a[i]]++;
	vector<VI> stk(n + 1, VI(0));	
	for(int i = n - 1; i >= 0; i--)
	{
		int x = a[i];
		stk[x].pb(i);
	}
	int las = n, bf = 0;
	VI ans;
	while(las > 0)
	{
		int ps = 0;
		while(ps <= n && vis[ps])
			++ps;
		if(ps != 0)
		{
			ans.pb(ps);
			int mx = -1;
			for(int j = 0; j < ps; j++)
				mx = max(mx, stk[j].back());
			for(int i = bf; i <= mx; i++)
			{
				--vis[a[i]];
				--las;
				stk[a[i]].pop_back();
			}
			bf = mx + 1;
		}
		else
		{
			for(int i = 0; i < las; i++)
				ans.pb(0);
			las = 0;
		}
	}
	cout << ans.size() << '\n';
	trav(v, ans)
		cout << v << ' ';
	cout << '\n';
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