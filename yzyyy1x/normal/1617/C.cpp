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

int hav[N];

void sol()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
		hav[i] = 0;
	VI can;
	int res = n;
	for(int i = 1; i <= n; i++)
	{
		int x = a[i];
		if(x >= 1 && x <= n)
		{
			if(!hav[x])
			{
				hav[x] = 1;
				res--;
			}
			else can.pb((x - 1) / 2);
		}
		else can.pb((x - 1) / 2);
	}
	sort(all(can));
	int nw = n;
	while(nw >= 1)
	{
		while(nw >= 1 && hav[nw])
			--nw;
		if(nw == 0)
			break;
		if(can.back() < nw)
			return (void)(cout << -1 << '\n');
		can.pop_back();
		hav[nw] = 1;
	}
	cout << res << '\n';
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