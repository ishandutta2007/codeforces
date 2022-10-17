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

int n, m;
int a[N], b[N];

void sol()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];	
	sort(a + 1, a + n + 1);
	if(n & 1)
	{
		cout << "NO" << '\n';
		return;
	}
	int ps = 1;
	for(int i = 1; i <= n; i += 2)
	{
		b[i] = a[ps++];
	}
	for(int i = 2; i <= n; i += 2)
		b[i] = a[ps++];
	for(int i = 1; i <= n; i++)
	{
		if(i == 1)
		{
			if(b[1] >= b[2] || b[1] >= b[n])
			{
				cout << "NO" << '\n';
				return;
			}
		}
		else if(i == n)
		{
			if(b[n] <= b[1] || b[n] <= b[n - 1])
			{
				cout << "NO" << '\n';
				return;
			}
		}
		else if(i & 1)
		{
			if(b[i] >= b[i - 1] || b[i] >= b[i + 1])
			{
				cout << "NO" << '\n';
				return;
			}
		}
		else
		{
			if(b[i] <= b[i - 1] || b[i] <= b[i + 1])
			{
				cout << "NO" << '\n';
				return;
			}
		}
	}
	cout << "YES" << '\n';
	for(int i = 1; i <= n; i++)
		cout << b[i] << ' ';
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