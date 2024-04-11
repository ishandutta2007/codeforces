#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define sc second
#define pb push_back
#define ll long long
#define trav(v,x) for(auto v:x)
using namespace std;
const int N = 1e6 + 100;

int n;
int a[N];

int fa[N], sz[N];
bool vis[N];
int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void link(int x, int y)
{
	x = find(x);
	y = find(y);
	if(x == y)
		return;
	sz[x] += sz[y];
	fa[y] = x;
	return;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--)
	{
		int n, m;
		cin >> n >> m;
		for(int i = 1; i <= n + n; i++)
		{
			fa[i] = i;
			sz[i] = 0;
			if(i > n)
				sz[i] = 1;
			vis[i] = 0;
		}
		for(int i = 1; i <= m; i++)
		{
			int x, y;
			string s;
			cin >> x >> y >> s;
			if(s == "imposter")
			{
				link(x, y + n);
				link(y, x + n);
			}
			else
			{
				link(x, y);
				link(x + n, y + n);
			}
		}
		bool flg = 1;
		ll ans = 0;
		for(int i = 1; i <= n; i++)
		{
			int x1, x2;
			x1 = find(i);
			x2 = find(i + n);
			if(x1 == x2)
			{
				flg = 0;
				break;
			}
			if(!vis[x1] && !vis[x2])
			{
				ans += max(sz[x1], sz[x2]);
				vis[x1] = vis[x2] = 1;
			}
		}
		if(flg)
			cout << ans << '\n';
		else
			cout << -1 << '\n';
	}
	return 0;
}