#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int ans[101][101];
ii resp[101][101];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			resp[i][j] = ii(i, j);
		}
	}
	for(int i = 0; i < q; i++)
	{
		int t, a; cin >> t >> a;
		if(t == 1)
		{
			a--;
			bool stop = false; int cnt = 0;
			for(int x = 0; x < n; x++)
			{
				for(int y = 0; y < m; y++)
				{
					if(resp[x][y].fi == a)
					{
						resp[x][y].se = (resp[x][y].se + m - 1)%m;
						cnt++;
					}
					if(cnt >= m)
					{
						stop = true;
						break;
					}
				}
				if(stop) break;
			}
		}
		else if(t == 2)
		{
			a--;
			bool stop = false; int cnt = 0;
			for(int x = 0; x < n; x++)
			{
				for(int y = 0; y < m; y++)
				{
					if(resp[x][y].se == a)
					{
						resp[x][y].fi = (resp[x][y].fi + n - 1)%n;
						cnt++;
					}
					if(cnt >= n)
					{
						stop = true;
						break;
					}
				}
				if(stop) break;
			}
		}
		else
		{
			int b, c; cin >> b >> c;
			a--; b--;
			bool stop = false;
			for(int x = 0; x < n; x++)
			{
				for(int y = 0; y < m; y++)
				{
					if(resp[x][y].fi == a && resp[x][y].se == b)
					{
						ans[x][y] = c;
						stop = true;
						break;
					}
				}
				if(stop) break;
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}