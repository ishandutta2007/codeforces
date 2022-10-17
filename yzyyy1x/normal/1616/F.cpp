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
const int N = 310;
const ll inf = 1e18;
const ll mod = 998244353;//1e9 + 7;

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

int n, m;
int link[N][N], id[N][N];
int ans[N];

int a[N * N][N];
int row = 0;

void gauss(int n, int m)
{
	int bg = 1;
	for(int i = 1; i < m; i++)
	{
		int ps = bg;
		while(a[ps][i] == 0 && ps <= n)
			++ps;
		if(ps > n)
			continue;
		if(ps != bg)
			for(int j = 1; j <= m; j++)
				swap(a[ps][j], a[bg][j]);
		int coef = a[bg][i];
		for(int j = i; j <= m; j++)
			a[bg][j] = (a[bg][j] * coef) % 3;
		for(int j = 1; j <= n; j++)
		{
			if(j == bg)
				continue;
			coef = a[j][i];
			for(int k = i; k <= m; k++)
				a[j][k] = (a[j][k] - a[bg][k] * coef + 9) % 3;
		}
		++bg;
	}
}

void sol()
{
	cin >> n >> m;
	memset(link, 0, sizeof link);
	memset(id, 0, sizeof id);
	row = 0;
	memset(a, 0, sizeof a);
	for(int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		link[x][y] = link[y][x] = z;
		id[x][y] = id[y][x] = i;
		ans[i] = z;
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			if(!link[i][j])
				continue;
			for(int k = j + 1; k <= n; k++)
			{
				if(!link[i][k] || !link[j][k])
					continue;
				++row;
				if(link[i][j] == -1)
					a[row][id[i][j]] = 1;
				else
					a[row][m + 1] += 3 - link[i][j];
				if(link[i][k] == -1)
					a[row][id[i][k]] = 1;
				else
					a[row][m + 1] += 3 - link[i][k];
				if(link[j][k] == -1)
					a[row][id[j][k]] = 1;
				else 
					a[row][m + 1] += 3 - link[j][k];
				a[row][m + 1] %= 3;
			}
		}
	}
	gauss(row, m + 1);
	for(int i = row; i >= 1; i--)
	{
		int ps = -1;
		for(int j = 1; j <= m; j++)
		{
			if(a[i][j])
			{
				ps = j;
				break;
			}
		}
		if(ps == -1 && a[i][m + 1] != 0)
		{
			cout << -1 << '\n';
			return;
		}
		if(ps == -1)
			continue;
		ans[ps] = a[i][m + 1];
		for(int j = i - 1; j >= 1; j--)
			a[j][m + 1] = (a[j][m + 1] - ans[ps] * a[j][ps] + 9) % 3, a[j][ps] = 0;
	}
	for(int i = 1; i <= m; i++)
	{
		if(ans[i] == -1 || ans[i] == 0)
			ans[i] = 3;
		cout << ans[i] << ' ';
	}
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