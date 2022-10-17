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

int n;
string s[11];
int fir[11][53], sec[11][53];

int calc(char c)
{
	if(c >= 'a' && c <= 'z')
		return  c - 'a';
	else
		return c - 'A'+ 26;
}

VI hav[N];
int id[53][3030];
int c_nw;
int num = 0;
int cur = 0;
VI stk;

void dfs(int x)
{
	if(x > n)
	{
		id[c_nw][cur] = ++num;
		hav[num] = stk;
		return;
	}
	if(fir[x][c_nw] == -1)
		return;
	else
		cur = cur << 1, stk.pb(fir[x][c_nw]), dfs(x + 1), cur >>= 1, stk.pop_back();
	if(sec[x][c_nw] == -1)
		return;
	else
		cur = cur << 1 | 1, stk.pb(sec[x][c_nw]), dfs(x + 1), cur >>= 1, stk.pop_back();
}

int ind[N], mxl[N], bf[N];
VI adj[N];

void out(int v)
{
	if(v == -1)
		return;
	out(bf[v]);
	cout << s[1][hav[v][0]];
}

void sol()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> s[i];
	num = 0;
	memset(fir, -1, sizeof fir);
	memset(sec, -1, sizeof sec);
	for(int i = 1; i <= n; i++)
	{
		int m = s[i].length();
		for(int j = 0; j < m; j++)
		{
			int v = calc(s[i][j]);
			if(fir[i][v] == -1)
				fir[i][v] = j;
			else
				sec[i][v] = j;
		}
	}
	for(int c = 0; c < 52; c++)
	{
		c_nw = c;
		dfs(1);
	}
	for(int i = 0; i <= num; i++)
		adj[i].clear(), ind[i] = 0, mxl[i] = 1, bf[i] = -1;
	for(int nw = 1; nw <= num; nw++)
	{
		VI cur = hav[nw];
		for(int c = 0; c < 52; c++)
		{
			bool ifok = 1;
			int nxt = 0;
			for(int i = 1; i <= n; i++)
			{
				int ps = cur[i - 1];
				if(fir[i][c] > ps)
					nxt <<= 1;
				else if(sec[i][c] > ps)
					nxt = nxt << 1 | 1;
				else
				{
					ifok = 0;
					break;
				}
			}
			if(ifok)
			{
				int to = id[c][nxt];
				adj[nw].pb(to);
				++ind[to];
			}
		}
	}
	queue<int> que;
	for(int i = 1; i <= num; i++)
	{
		if(!ind[i])
			mxl[i] = 1, que.push(i);
	}
	while(!que.empty())
	{
		int nw = que.front();
		que.pop();
		trav(v, adj[nw])
		{
			--ind[v];
			if(mxl[nw] + 1 > mxl[v])
				mxl[v] = mxl[nw] + 1, bf[v] = nw;
			if(!ind[v])
			{
				que.push(v);
			}
		}
	}
	//cerr << "OOO" << '\n';
	int ps = -1, mx = 0;
	for(int i = 1; i <= num; i++)
	{
		if(mxl[i] > mx)
			mx = mxl[i], ps = i;
	}
	cout << mx << '\n';
	out(ps);
	cout << '\n';
	for(int i = 0; i <= num; i++)
		hav[i].clear();
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