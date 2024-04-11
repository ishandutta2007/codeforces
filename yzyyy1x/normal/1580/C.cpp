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
#define int long long
using namespace std;

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

const int N = 1e6 + 100;
const int inf = 1e9;
//const ll inf = 1e18;
const ll mod = 998244353;//1e9 + 7;

int n, m;
int bg[N];
pii train[N], opt[N];

ll res2[N], hav[110][110], nxt[N], bf[N];
ll laz[N];

void sol()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> train[i].fi >> train[i].sc;
	}
	for(int i = 1; i <= m; i++)
	{
		cin >> opt[i].fi >> opt[i].sc;
	}
	for(int i = m; i >= 1; i--)
	{
		if(!bf[opt[i].sc])
			nxt[i] = m + 1;
		else
			nxt[i] = bf[opt[i].sc];
		bf[opt[i].sc] = i;
	}
	for(int i = 1; i <= m; i++)
	{
		int x, y, nw, val;
		tie(val, nw) = opt[i];
		if(val == 2)
			val = -1;
		tie(x, y) = train[nw];
		if(val == 1)
			bg[nw] = i;
		if(x + y <= 100)
		{
			int b = bg[nw] % (x + y);
			int l = (x + b) % (x + y);
			for(int j = 0; j < y; j++)
			{
				hav[x + y][l] += val;
				l = (l + 1) % (x + y);
			}
		}
		else
		{
			if(val == 1)
			{
				for(int j = bg[nw] + x; j < nxt[i]; j += x + y)
					laz[j]++, laz[min(j + y, nxt[i])]--;
			}
		}
		ll res = 0;
		for(int v = 1; v <= 100; v++)
			res += hav[v][i % v];
		laz[i] += laz[i - 1];
		cout << res + laz[i] << '\n';
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
//	int tt;
//	cin >> tt;
//	while(tt--)
		sol();
}