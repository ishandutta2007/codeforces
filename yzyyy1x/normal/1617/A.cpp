//#define LOCAL
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
//const ll inf = 1e18
const ll mod = 998244353;//1e9 + 7

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


int n;
int a[N];
int num[40];

void out(int x)
{
	for(int i = 1; i <= num[x]; i++)
		cout << (char)('a' + x);
}

void sol()
{
	string s, t;
	cin >> s >> t;
	memset(num, 0, sizeof num);
	int n = s.length();
	for(int i = 0; i < n; i++)
		num[s[i] - 'a']++;
	if(t == "abc" && num[0] && num[1] && num[2])
	{
		out(0);
		out(2);
		out(1);
	}
	else
	{
		out(0);
		out(1);
		out(2);
	}
	for(int i = 3; i <= 25; i++)
		out(i);
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