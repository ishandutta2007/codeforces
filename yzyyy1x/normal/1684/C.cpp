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

void sol()
{
	cin >> n >> m;
	vector<VI> a(n, VI(m, 0));
	int x = -1, y = -1;
	bool flg = 1;
	for(int i = 0; i < n; i++)
	{
		VI b(m, 0);
		for(int j = 0; j < m; j++)
			cin >> a[i][j], b[j] = a[i][j];
		sort(all(b));
		VI dif;
		for(int j = 0; j < m; j++)
		{
			if(a[i][j] != b[j])
				dif.pb(j);
		}
		if(dif.empty())
			continue;
		if(dif.size() >= 3)
		{
			flg = 0;	
		}
		sort(all(dif));
		if(x == -1 && y == -1)
		{
			x = dif[0];
			y = dif[1];
		}
		if(x != dif[0] || y != dif[1])
		{
			flg = 0;
		}
	}
	if(flg && x == -1 && y == -1)
	{
		cout << 1 << ' '<<1 << '\n';
		return;
	}
	for(int i = 0; i < n; i++)
	{
		if(a[i][x] < a[i][y])
			flg = 0;
	}
	if(!flg)
	{
		cout << -1 << '\n';
		return;
	}
	cout << x + 1 << ' ' << y + 1<< '\n';
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