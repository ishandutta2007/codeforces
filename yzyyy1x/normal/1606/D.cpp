#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define sc second
#define pb push_back
#define ll long long
#define trav(v, x) for(auto v:x)
#define VI vector<int>
#define VLL vector<ll>
//define double long double
#define all(x) (x).begin(),(x).end()
using namespace std;
const double eps = 1e-10;//1e-12
const int N = 5e5 + 100;
const ll mod = 998244353;//1e9 + 7;
const int inf = 1e9;

vector<int> a[N];

int n, m;
int mx[3][N], mn[3][N];//1 red, 2 blue
int color[N];
multiset<int>hav[4];

void ccc(int row, int clr)
{
	for(int j = 1; j <= m; j++)
	{
		mx[clr][j] = max(mx[clr][j], a[row][j]);
		mn[clr][j] = min(mn[clr][j], a[row][j]);
	}
	return;
}

bool doit(int col, int bel)//bel = max's color
{
	int mx = -1;
	int mn = inf;
	for(int i = 1; i <= n; i++)
	{
		mx = max(mx, a[i][col]);
		mn = min(mn, a[i][col]);
	}
	int nw = bel;
	for(int i = 1; i <= n; i++)
	{
		if(a[i][col] == mx)
		{
			if(!color[i])
			{
				ccc(i, nw);
				color[i] = nw;
			}
			if(color[i] != nw)
			{
				return 0;
			}
		}
	}
	nw = 3 - bel;
	for(int i = 1; i <= n; i++)
	{
		if(a[i][col] == mn)
		{
			if(!color[i])
			{
				ccc(i, nw);
				color[i] = nw;
			}
			if(color[i] != nw)
			{
				return 0;
			}
		}
	}
	return 1;
}

bool chk()
{
	if(hav[0].empty() || hav[1].empty() || hav[2].empty() || hav[3].empty())
		return 0;
	if((*hav[0].begin()) > (*prev(hav[1].end())) && (*prev(hav[2].end())) < (*hav[3].begin()))
		return 1;
	return 0;
}

void sol()
{
	for(int i = 0; i < 4; i++)
		hav[i].clear();
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		a[i].resize(m + 1);
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
		color[i] = 0;
	}
	for(int j = 1; j <= m; j++)
		mx[1][j] = mx[2][j] = -1, mn[1][j] = mn[2][j] = inf;
	int bd;
	if(!doit(1, 1))
	{
		cout << "NO" << '\n';
		return;
	}
	if(!doit(m, 2))
	{
		cout << "NO" << '\n';
		return;
	}
	bd = 1;
	for(int col = 2; col < m; col++)
	{
		int mn_red = mn[1][col];
		int mx_red = mx[1][col];
		int mn_blue = mn[2][col];
		int mx_blue = mx[2][col];
		if(mx_red < mn_blue)
			continue;
		else if(mn_red > mx_blue)
		{
			//belong to left
			if(bd != col - 1)
			{
				cout << "NO" << '\n';
				return;
			}
			++bd;
		}
		else
		{
			cout << "NO" << '\n';
			return;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		if(!color[i])
		{
			color[i] = 2;
		}
		for(int j = 1; j <= m; j++)
		{
			if(j <= bd)
			{
				if(color[i] == 1)
					hav[0].insert(a[i][j]);
				else
					hav[1].insert(a[i][j]);
			}
			else
			{
				if(color[i] == 1)
					hav[2].insert(a[i][j]);
				else
					hav[3].insert(a[i][j]);
			}
		}
	}
	vector<pii> buk;
	for(int i = 1; i <= n; i++)
	{
		if(color[i] == 2)
			buk.pb(pii(a[i][1], i));
	}
	sort(all(buk));
	reverse(all(buk));
	int ps = 0;
	while(!chk() && ps < buk.size())
	{
		int nxt = ps;
		while(nxt < buk.size() && buk[ps].fi == buk[nxt].fi)
			++nxt;
		--nxt;
		for(int i = ps; i <= nxt; i++)
		{
			int row = buk[i].sc;
			for(int j = 1; j <= m; j++)
			{
				if(j <= bd)
				{
					hav[1].erase(hav[1].find(a[row][j]));
					hav[0].insert(a[row][j]);
				}
				else
				{
					hav[3].erase(hav[3].find(a[row][j]));
					hav[2].insert(a[row][j]);
				}
			}
			color[row] = 1;
		}
		ps = nxt + 1;
	}
	if(!chk())
	{
		cout << "NO" << '\n';
		return;
	}
	cout << "YES" << '\n';
	for(int i = 1; i <= n; i++)
	{
		if(color[i] == 1)
			cout << "R";
		if(color[i] == 2)
			cout << "B";
	}
	cout << ' ' << bd << '\n';
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--)
	{
		sol();
	}
}