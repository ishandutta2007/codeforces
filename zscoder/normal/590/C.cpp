#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char a[1001][1001];
int dist[3][1001][1001];
int n, m;

bool valid(int x, int y)
{
	if(x>=0&&x<n&&y>=0&&y<m&&a[x][y]!='#') return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < m; k++)
			{
				dist[i][j][k] = 1000000000;
			}
		}
	}
	for(int c = '1'; c <= '3'; c++)
	{
		deque<ii> dq;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				if(a[i][j] == c)
				{
					dist[c-'1'][i][j] = 0;
					dq.pb(mp(i, j));
				}
			}
		}
		while(!dq.empty())
		{
			int x = dq.front().fi; int y = dq.front().se; dq.pop_front();
			for(int i = 0; i < 4; i++)
			{
				int x2 = x+dx[i]; int y2 = y+dy[i];
				if(valid(x2, y2))
				{
					int d = dist[c-'1'][x][y] + (a[x2][y2]=='.');
					if(d < dist[c-'1'][x2][y2])
					{
						dist[c-'1'][x2][y2] = d;
						if(a[x2][y2] == '.')
						{
							dq.pb(mp(x2, y2));
						}
						else
						{
							dq.push_front(mp(x2, y2));
						}
					}
				}
			}
		}
	}
	ll ans = ll(1e18);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			ll d = dist[0][i][j] + ll(dist[1][i][j]) + dist[2][i][j] - (a[i][j]=='.')*2;
			ans = min(ans, d);
		}
	}
	if(ans > 10000000) ans = -1;
	cout << ans;
}