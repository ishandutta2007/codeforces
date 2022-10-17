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
const int N = 1e6 + 100;
const int inf = 1e9;
//const ll inf = 1e18
const ll mod = 998244353;//1e9 + 7

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


int n;
int a[N], b[N];

void out_a()
{
	for(int i = 1; i <= n; i++)
		cout << a[i] << ' ';
	cout << '\n';
}

void out_b()
{
	for(int i = 1; i <= n; i++)
			cout << b[i] << ' ';
	cout << '\n';
}

void gao(int ps)
{
	for(int i = 1; i <= n; i++)
		a[i] = -a[i];
	for(int i = ps; i <= n; i++)
		a[i] += 2;
}

int num[2][2];

struct sta{
	vector<int> x;
	int d;
	friend bool operator <(const sta &x, const sta &y)
	{
		return x.d > y.d;
	};
};

void sol()
{
	string s;
	cin >> n;
	cin >> s;
	s = '#' + s;
	for(int i = 1; i <= n; i++)
	{
		if(s[i] == '1')
			a[i] = 1;
		else a[i] = 0;
	}
	memset(num, 0, sizeof num);
	cin >> s;
	s = '#' + s;
	for(int i = 1; i <= n; i++)
	{
		if(s[i] == '1')
			b[i] = 1;
		else b[i] = 0;
		num[a[i]][b[i]]++;
	}
	sta nw, nxt;
	nw.x.resize(4);
	nxt.x.resize(4);
	for(int i = 0; i <= 1; i++)
		for(int j = 0; j <= 1; j++)
			nw.x[i * 2 + j] = num[i][j];
	if(nw.x[2] == nw.x[1] && nw.x[1] == 0)
		return (void)(cout << 0 << '\n');
	nw.d = 0;
	priority_queue<sta>pq;
	map<VI, int> dis;
	dis[nw.x] = 0;
	pq.push(nw);
	while(!pq.empty())
	{
		nw = pq.top();
		pq.pop();
		if(dis.find(nw.x) == dis.end() || nw.d > dis[nw.x])
			continue;
		
		swap(nw.x[0], nw.x[2]);
		swap(nw.x[1], nw.x[3]);
		if(nw.x[0])
		{
			nxt = nw;
			++nxt.x[2];
			--nxt.x[0];
			nxt.d = nw.d + 1;
			if(nxt.x[1] == 0 && nxt.x[2] == 0)
			{
				cout << nxt.d << '\n';
				return;
			}
			if(dis.find(nxt.x) == dis.end() || dis[nxt.x] > nxt.d)
			{
				dis[nxt.x] = nxt.d;
				pq.push(nxt);
			}
		}
		if(nw.x[1])
		{
			nxt = nw;
			++nxt.x[3];
			--nxt.x[1];
			nxt.d = nw.d + 1;
			if(nxt.x[1] == 0 && nxt.x[2] == 0)
			{
				cout << nxt.d << '\n';
				return;
			}
			if(dis.find(nxt.x) == dis.end() || dis[nxt.x] > nxt.d)
			{
				dis[nxt.x] = nxt.d;
				pq.push(nxt);
			}
		}
	}
	cout << -1 << '\n';
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
/*
1
9
100010111
101101100
*/