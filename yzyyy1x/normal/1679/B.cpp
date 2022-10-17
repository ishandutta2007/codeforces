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
int a[N], b[N];

void sol()
{
	int qq;
	cin >> n >> qq;
	ll sum = 0;
	for(int i = 1; i <= n; i++)
		cin >> a[i], sum += a[i], b[i] = 0;
	int las = -1, vv = 0;
	for(int t = 1; t <= qq; t++)
	{
		int op;
		cin >> op;
		if(op == 1)
		{
			int x, y;
			cin >> x >> y;
			if(b[x] < las)
				a[x] = vv;
			sum += y - a[x];
			a[x] = y;
			b[x] = t;
		}
		else
		{
			int y;
			cin >> y;
			las = t;
			vv = y;
			sum = 1LL * y * n;
		}
		cout << sum << '\n';
	}
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