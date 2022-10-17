#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define sc second
#define pb push_back
#define ll long long
#define VI vector<int>
#define all(x) (x).begin(),(x).end()
#define trav(v,x) for(auto v:x)
using namespace std;
const int N = 2e3 + 100;

int a[N];

VI adj[N];

int n, dfn[N + N], tim = 0;

void dfs(int x, int fa)
{
	dfn[++tim] = x;
	trav(v, adj[x])
	{
		if(v == fa)
			continue;
		dfs(v, x);
		dfn[++tim] = x;
	}
}

int ask(int l, int r)
{
	VI bin;
	bin.clear();
	for(int i = l; i <= r; i++)
		bin.pb(dfn[i]);
	sort(all(bin));
	bin.erase(unique(all(bin)), bin.end());
	cout << "? " << bin.size() << ' ';
	trav(v, bin)
	{
		cout << v << ' ';
	}
	cout << '\n';
	fflush(stdout);
	int x;
	cin >> x;
	return x;
}

signed main()
{
	cin >> n;
	for(int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs(1, 0);
	
	int val = ask(1, tim);
	
	int l = 1, r = tim;
	
	// 1 2 is ok
	// 1 3
	
	while(l + 1 < r)
	{
		int mid = (l + r) / 2;
		int nw = ask(l, mid);
		if(nw == val)
		{
			r = mid;
		}
		else
		{
			l = mid;
		}
	}
	cout << "!" << ' ' << dfn[l] << ' ' << dfn[r] << '\n';
	return 0;
}