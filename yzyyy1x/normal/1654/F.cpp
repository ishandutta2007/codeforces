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
const ll inf = 1e18;
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

int n;

void sol()
{
	cin >> n;
	string s;
	cin >> s;
	vector<int> rnk(1 << n), nxt(1 << n);
	for(int x = 0; x < (1 << n); x++)
	{
		rnk[x] = s[x];
	} 
	for(int l = 2; l <= (1 << n); l <<= 1)
	{
		vector<pii> buk;
		for(int x = 0; x < (1 << n); x++)
		{
			int tmp = x ^ (l >> 1);
			buk.pb(pii(x, tmp));
		}
		sort(all(buk), [&](pii x, pii y)
			{
				return rnk[x.fi] == rnk[y.fi] ? rnk[x.sc] < rnk[y.sc] : rnk[x.fi] < rnk[y.fi];
			});
		int tim = 0;
		for(int x = 0; x < (1 << n); x++)
		{
			if(x == 0 || rnk[buk[x].fi] > rnk[buk[x - 1].fi] || rnk[buk[x].sc] > rnk[buk[x - 1].sc])
			{
				++tim;
			} 
			nxt[buk[x].fi] = tim;
		}
		swap(nxt, rnk);
	}
	int ps;
	for(int i = 0; i < (1 << n); i++)
	{
		if(rnk[i] == 1)
		{
			ps = i;
			break;
		}
	}
	for(int i = 0; i < 1 << n; i++)
		cout<< s[i ^ ps];
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