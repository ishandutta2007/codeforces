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
	vector<string> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	bool flg = 0;
	auto is_par = [&](string s)
	{
		int len = s.length();
		for(int i = 0; i < len; i++)
			if(s[i] != s[len - i - 1])return 0;
		return 1;
	};
	for(int i = 0; i < n; i++)
	{
		if(is_par(a[i]))
			flg = 1;
	}
	map<string, bool> vis;
	for(int i = 0; i < n; i++)
	{
		string rs = a[i];
		reverse(all(rs));
		if(vis.find(rs) != vis.end())
			flg = 1;
		vis[a[i]] = 1;
	}
	map<string, bool>three, two;
	for(int i = 0; i < n; i++)
	{
		if(a[i].length() == 1)
			continue;
		string s = a[i];
		if(s.length() == 2)
		{
			string rs;
			rs = s;
			reverse(all(rs));
			if(three[rs])
				flg = 1;
			two[s] = 1;
		}
		else
		{
			string t;
			t = s.substr(1, 2);
			reverse(all(t));
			if(two[t])
				flg = 1;
			t = s.substr(0, 2);
			three[t] = 1;
		}
	}
	
	if(flg)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
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
2
3
abc
gc
ba
3
gc
abc
ba
*/