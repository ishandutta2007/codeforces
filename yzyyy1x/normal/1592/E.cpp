#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define sc second
#define pb push_back
#define ll long long
#define trav(v,x) for(auto v:x)
#define VI vector<int>
using namespace std;
const int N = 5e6 + 100;
const int inf = 1e8;

const int m = 1048575;

int n;
int a[N], sum[N], ss[N];

int vis[2][N];

VI bin;

void clr()
{
	trav(v, bin)
		vis[0][v] = vis[1][v] = 0;
	bin.clear();
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	int ans = 0, tmp = 0, ttmp = (1 << 20) - 1;
	for(int p = 19; p >= 0; p--)
	{
		clr();
		tmp |= (1 << p);
		for(int i = 1; i <= n; i++)
			ss[i] = (sum[i] & tmp);	
		for(int l = n; l >= 1; l--)
		{
			if((1 << p) & a[l])
			{
				int nw = vis[1 ^ (l & 1)][ss[l - 1]];
				if(nw >= l)
					ans = max(ans, nw - l + 1);
				vis[(l & 1)][ss[l]] = max(vis[(l & 1)][ss[l]], l);
				bin.pb(ss[l]);
			}
			else clr();
		}
	}
	cout << ans << '\n';
	return 0;
}
//101
//110