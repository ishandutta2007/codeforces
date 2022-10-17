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

int n;
ll a[N], b[N];

void sol()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	if(n == 1)
	{
		cout << (a[1] == 0 ? "Yes" : "No") << '\n';
		return;
	}
	while(n > 0 && a[n] == 0)
		--n;
	for(int i = n; i >= 1; i--)
	{
		if(a[i] > 0 || i > 1 && a[i] == 0)
		{
			cout << "No" << '\n';
			return;
		}
		a[i - 1] += a[i];
	}
	if(a[1] != 0)
		cout << "No" << '\n';
	else
		cout << "Yes" << '\n';
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