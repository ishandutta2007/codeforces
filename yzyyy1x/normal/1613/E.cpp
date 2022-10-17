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

const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

int n, m;
string a[N];
vector<int> deg[N];
vector<int> ans[N];
vector<bool> vis[N];

struct node{
	int x, y;
	node(){};
	node(int x, int y):x(x), y(y){};
};

void sol()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] = '#' + a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		ans[i].resize(m + 1);
		vis[i].resize(m + 1);
		deg[i].resize(m + 1);
		for(int j = 1; j <= m; j++)
		{
			deg[i][j] = 0;
			ans[i][j] = 0;
			vis[i][j] = 0;
			if(a[i][j] == '.')
			{
				for(int d = 0; d < 4; d++)
				{
					int ni = i + dx[d];
					int nj = j + dy[d];
					if(ni > n || ni < 1 || nj > m || nj < 1)	
						continue;
					if(a[ni][nj] == '.' || a[ni][nj] == 'L')
						++deg[i][j];
				}
			}
		}
	}
	node nw;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(a[i][j] == 'L')
			{
				nw = node(i, j);
			}
		}
	}
	queue<node> q;
	q.push(nw);
	auto chk = [&](int i, int j)
	{
		ans[i][j] = 0;
		for(int d = 0; d < 4; d++)
		{
			int ni = i + dx[d];
			int nj = j + dy[d];
			if(ni > n || ni < 1 || nj > m || nj < 1)	
				continue;
			if(a[ni][nj] == '.' && vis[ni][nj] || a[ni][nj] == 'L')
				++ans[i][j];
		}
		if(deg[i][j] - ans[i][j] <= 1)
			return 1;
		return 0;
	};
	vis[nw.x][nw.y] = 1;
	while(!q.empty())
	{
		nw = q.front();
		q.pop();
		//cerr << nw.x << ' ' << nw.y << ' ' << nw.d << '\n';
		int i = nw.x;
		int j = nw.y;
		for(int d = 0; d < 4; d++)
		{
			int ni = i + dx[d];
			int nj = j + dy[d];
			if(ni > n || ni < 1 || nj > m || nj < 1)	
				continue;
			if(a[ni][nj] == '.' && !vis[ni][nj] && chk(ni, nj))
				q.push(node(ni, nj)), vis[ni][nj] = 1;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(vis[i][j] && a[i][j] != 'L')
				cout << '+';
			else
				cout << a[i][j];
		}
		cout << '\n';
	}
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