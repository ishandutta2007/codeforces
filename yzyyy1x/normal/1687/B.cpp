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

int n, m;

bool cur[N];
pii a[N];

int ask()
{
	cout << "? ";
	for(int i = 1; i <= m; i++)
		cout << cur[i];
	cout << endl << '\n';
	int res;
	cin >> res;
	return res;
}

void sol()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		cur[i] = 1;
		int nw = ask();
		cur[i] = 0;
		a[i] = pii(nw, i);
	}
	sort(a + 1, a + m + 1);
	int ans = 0;
	for(int i = 1; i <= m; i++)
	{
		int nxt;
		int id = a[i].sc;
		int val = a[i].fi;
		cur[id] = 1;
		nxt = ask();
		if(nxt - ans == val)
		{
			ans = nxt;
		}
		else
		{
			cur[id] = 0;
			continue;
		}
	}
	cout << "! " << ans << endl;
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