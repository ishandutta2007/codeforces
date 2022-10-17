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
const ll mod = 998244353;//1e9 + 7;

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

void sol()
{
	int n;
	cin >> n;
	map<int, int> cnt;
	VI cur(n);
	for(int i = 0; i < n; i++)
	{
		cin >> cur[i];
		cnt[cur[i]]++;
	}
	trav(v, cnt)
	{
		if(v.sc & 1)
		{
			cout << -1 << '\n';
			return;
		}
	}
	int bf = 0;
	vector<int> cut;
	vector<pii> ins;
	while(cur.size() > 0)
	{
		int bg = cur[0];
		int sz = cur.size(), ps;
		for(int i = 1; i < sz; i++)
		{
			if(cur[i] == bg)
			{
				ps = i;
				break;
			}
		}
		VI nxt;
		for(int i = 1; i < ps; i++)
		{
			ins.pb(pii(bf + ps + i, cur[i]));
		}
		cut.pb(bf + ps * 2);
		bf += ps * 2;
		for(int i = ps - 1; i > 0; i--)
			nxt.pb(cur[i]);
		for(int i = ps + 1; i < sz; i++)
			nxt.pb(cur[i]);
		cur = nxt;
		//cerr << "!!!" << cur.size() << '\n';
	}
	cout << ins.size() << '\n';
	trav(v, ins)
		cout << v.fi << ' ' << v.sc << '\n';
	cout << cut.size() << '\n';
	int bef = 0;
	trav(v, cut)
		cout << v - bef << ' ', bef = v;
	cout << '\n';
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