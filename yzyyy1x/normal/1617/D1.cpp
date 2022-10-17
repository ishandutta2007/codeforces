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

int sta[N],  id[N][3], ans[N][3], res[N];

int chk(int x, int y, int z)
{
	cout << '?' << ' ' << x << ' ' << y << ' ' << z << endl;
	int res;
	cin >> res;
	return res;
}

void out()
{
	cout << '!' << ' ' ;
	int num = 0;
	for(int i = 1; i <= n * 3; i++)
		if(res[i] == 0)++num;
	cout << num << ' ' ;
	for(int i = 1; i <= n * 3; i++)
		if(res[i] == 0)cout << i << ' ';
	cout << endl;
}

void sol()
{
	cin >> n;
	n /= 3;
	for(int i = 1; i <= 3 * n; i += 3)
	{
		sta[(i + 2) / 3] = chk(i, i + 1, i + 2);
		id[(i + 2) / 3][0] = i;
		id[(i + 2) / 3][1] = i + 1;
		id[(i + 2) / 3][2] = i + 2;
	}
	int bad = 0, good = 0;
	for(int i = 1; i <= n; i++)
	{
		if(sta[i] == 0 && !bad)
			bad = i;
		if(sta[i] == 1 && !good)
			good = i;
	}
	{
		bool flg = 0;
		int y;
		for(int i = 0; i <= 2; i++)
		{
			int nw = chk(id[bad][0], id[bad][1], id[good][i]);
			if(nw == 1)
			{
				flg = 1;
				y = i;
				break;
			}
		}
		if(flg)
		{
			swap(id[bad][0], id[bad][2]);
			swap(id[bad][1], id[good][y]);
			for(int i = 0; i < 3; i++)
				swap(id[1][i], id[bad][i]);
			ans[1][0] = 0, ans[1][1] = 1;
			ans[1][2] = chk(id[1][0], id[1][1], id[1][2]);
		}
		else
		{
			int nw = chk(id[bad][0], id[good][0], id[good][1]);
			if(nw == 1)
			{
				swap(id[bad][1], id[good][0]);
			}
			else swap(id[bad][1], id[good][2]);
			for(int i = 0; i < 3; i++)
				swap(id[1][i], id[bad][i]);
			ans[1][0] = 0, ans[1][1] = 1;
			ans[1][2] = chk(id[1][0], id[1][1], id[1][2]);
		}
	}
	for(int i = 2; i <= n; i++)
	{
		for(int j = 0; j <= 2; j++)
		{
			ans[i][j] = chk(id[1][0], id[1][1], id[i][j]);
		}
	}
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= 2; j++)
			res[id[i][j]] = ans[i][j];
	out();
}

signed main()
{
	int tt;
	cin >> tt;
	while(tt--)
		sol();
}