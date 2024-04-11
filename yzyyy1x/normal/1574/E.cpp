#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define sc second
#define pb push_back
#define ll long long
#define trav(v, x) for(auto v:x)
#define VI vector<int>
#define VLL vector<ll>
#define all(x) (x).begin(),(x).end()
using namespace std;
const int N = 2e6 + 100;
const ll mod = 998244353;

int n, m, qq;
int col[N][2][2];
int row[N][2][2];
int hav[2][2];

int fix_row = 0, fix_col = 0;
int free_row, free_col;

ll pow2[N];

map<int, int>mark[N];

void upd(int x, int y, int op)
{
	bool flg = 0;
	flg |= (row[x][1][0] && row[x][0][0]);
	flg |= (row[x][1][1] && row[x][0][1]);
	flg |= (row[x][1][0] && row[x][1][1]);
	flg |= (row[x][0][0] && row[x][0][1]);
	if(flg)
		fix_row += op;
	flg = 0;
	flg |= (col[y][1][0] && col[y][0][0]);
	flg |= (col[y][1][1] && col[y][0][1]);
	flg |= (col[y][1][0] && col[y][1][1]);
	flg |= (col[y][0][0] && col[y][0][1]);
	if(flg)
		fix_col += op;
	flg = 0;
	for(int i = 0; i <= 1; i++)
	{
		for(int j = 0; j <= 1; j++)
		{
			if(row[x][i][j])
				flg = 1;
		}
	}
	if(!flg)
		free_row += op;
	flg = 0;
	for(int i = 0; i <= 1; i++)
	{
		for(int j = 0; j <= 1; j++)
		{
			if(col[y][i][j])
				flg = 1;
		}
	}
	if(!flg)
		free_col += op;
}

ll qry()
{
	if(fix_row && fix_col)
		return 0;
//	cerr << "??" << fix_row << ' ' << fix_col << ' ' << free_row << ' ' << free_col << '\n';
//	system("pause");
	ll res = 0;
	if(!fix_row)
		res = (res + pow2[free_row]) % mod;
	if(!fix_col)
		res = (res + pow2[free_col]) % mod;
	if(fix_row || fix_col)
		return res;
	if(!hav[0][0] && !hav[0][1] && !hav[1][0] && !hav[1][1])
	{
		return (res + mod - 2) % mod;
	}
	if(hav[0][0] && hav[0][1])
		return res;
	if(hav[0][0] && hav[1][0])
		return res;
	if(hav[1][0] && hav[1][1])
		return res;
	if(hav[0][1] && hav[1][1])
		return res;
	return (res + mod - 1) % mod;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	pow2[0] = 1;
	for(int i = 1; i < N; i++)
		pow2[i] = pow2[i - 1] * 2 % mod;
	int tt;
	cin >> n >> m >> qq;
	free_row = n;
	free_col = m;
	map<int, int>::iterator ii;
	for(int i = 1; i <= qq; i++)
	{
		int x, y, op;
		cin >> x >> y >> op;
		if(op == -1)
		{
			ii = mark[x].find(y);
			if(ii == mark[x].end())
			{
				cout << qry() << '\n';
				continue;
			}
			upd(x, y, -1);
			int clr = (*ii).second;
			mark[x].erase(ii);
			row[x][y & 1][clr]--;
			col[y][x & 1][clr]--;
			hav[(x + y) & 1][clr]--;
			upd(x, y, 1);
				cout << qry() << '\n';
		}
		else
		{
			upd(x, y, -1);
		//	cerr << "!!" << free_row << ' ' << free_col << '\n';
			ii = mark[x].find(y);
			if(ii != mark[x].end())
			{
				int bf = (*ii).second;
				row[x][y & 1][bf]--;
				col[y][x & 1][bf]--;
				hav[(x + y) & 1][bf]--;
			}
			mark[x][y] = op;
			row[x][y & 1][op]++;
			col[y][x & 1][op]++;
			hav[(x + y) & 1][op]++;
			upd(x, y, 1);
			cout << qry() << '\n';
		}
	}
}