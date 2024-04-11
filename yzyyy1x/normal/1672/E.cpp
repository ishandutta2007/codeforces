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
const ll inf = 1e18;
const ll mod = 998244353;//1e9 + 7;

int a[N], b[N];

int nxt[N], bf[N];

int ask(int x)
{
	cout << "? " << x << endl;
	int res;
	cin >> res;
	return res;
}

void out(int x)
{
	cout << "! " << x << endl;
	return;
}

void sol()
{
	int n;
	cin >> n;
	int s = 0;
	int l = 1, r = 5e6, res;
	while(l <= r)
	{
		int mid = (l + r) >> 1;
		if(ask(mid) == 1)
			res = mid, r = mid - 1;
		else l = mid + 1;
	}
	s = res - (n - 1);
	int mn = res;
	for(int num = 2; num <= n; num++)
	{
		int upper = (s + (n - 1)) / num;
		int lower = (s + (n - num) + num - 1) / num;
		if(lower == upper)
		{
			int nw = ask(lower);
			if(!nw)
				continue;
			if(nw * lower <= mn)
			{
				mn = nw * lower;
			}
		}
	}
	out(mn);
}

signed main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	int tt;
//	cin >> tt;
//	while(tt--)
		sol();
}