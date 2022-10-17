#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define sc second
#define pb push_back
#define ll long long
#define VI vector<int>
#define trav(v,x) for(auto v:x)
using namespace std;
const int N = 1e6 + 100;

int n;
int a[N];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--)
	{
		int n, ans = 2;
		char c;
		cin >> n >> c;
		string s;
		cin >> s;
		VI hav;
		hav.clear();
		for(int i = 0; i < n; i++)
		{
			if(s[i] != c)
				hav.pb(i + 1);
		}
		if(hav.empty())
		{
			cout << 0 << '\n';
			continue;
		}
		{
			VI vis(n + 1, 0);
			trav(v, hav)
			{
				for(int j = 1; j * j <= v; j++)
				{
					if(v % j == 0)
						vis[j] = vis[v / j] = 1;
				}
			}
			int flg = 0;
			for(int i = 1; i <= n; i++)
			{
				if(!vis[i])
				{
					flg = i;
					break;
				}
			}
			if(flg)
			{
				cout << 1 << '\n';
				cout << flg << '\n';
				continue;
			}
		}
		cout << 2 << '\n';
		cout << n - 1 << ' ' << n << '\n';
	}
	return 0;
}