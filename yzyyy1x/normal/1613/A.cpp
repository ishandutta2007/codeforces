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

void sol()
{
	ll x1, y1, x2, y2, z1 = 0, z2 = 0;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	ll tmp = x1;
	while(tmp)
		++y1, tmp /= 10, ++z1;
	tmp = x2;
	while(tmp)
		++y2, tmp /= 10, ++z2;
	if(y1 > y2)
		return (void)(cout << ">" << '\n');
	if(y1 < y2)
		return (void)(cout << "<" << '\n');
	if(z1 < z2)
	{
		for(int i = 1; i <= z2 - z1; i++)
			x1 *= 10;
	}
	if(z2 < z1)
	{
		for(int i = 1; i <= z1 - z2; i++)
			x2 *= 10;
	}
	if(x1 == x2)
		return (void)(cout << "=" << '\n');
	if(x1 > x2)
		cout << '>' << '\n';
	else
		cout << '<' << '\n';
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