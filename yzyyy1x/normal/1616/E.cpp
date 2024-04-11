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

int fir[200], nxt[N];

int fen[N];

int ask(int x)
{
	int res = 0;
	for(; x; x -= x & -x)
		res += fen[x];
	return res;
}

void add(int x)
{
	for(; x <= n; x += x & -x)
		fen[x]++;
}

void sol()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		fen[i] = 0;
	string s, t, ss;
	cin >> s >> t;
 	ss = s;
 	sort(all(ss));
 	if(ss >= t)
 		return (void)(cout << -1 << '\n');
 	if(s < t)
 		return (void)(cout << 0 << '\n');
 	s = '#' + s;
 	t = '#' + t;
 	memset(fir, -1, sizeof fir);
 	for(int i = n; i >= 1; i--)
 	{
 		int c = s[i] - 'a';
 		nxt[i] = fir[c];
 		fir[c] = i;
 	}
 	VI ans;
 	ll cur = 0, res = inf;;
 	for(int i = 1; i <= n; i++)
 	{
 		int tc = t[i] - 'a';
 		int mn = -1;
 		for(int c = 0; c < 26; c++)
 		{
 			if(fir[c] != -1)
 			{
 				mn = c;
 				break;
 			}
 		}
 		if(mn < tc)
 		{
 			for(int c = mn; c < tc; c++)
 			{
 				if(fir[c] == -1)
 					continue;
 				if(fir[c] < fir[mn])
 					mn = c;
 			}
 			int ps = fir[mn];
 			int tmp = ps - 1 - ask(ps);
 			res = min(res, cur + tmp); 
 		}
 		if(fir[tc] == -1)
 			break;
 		mn = tc;
 		int ps = fir[mn];
		int tmp = ps - 1 - ask(ps);
 		add(ps + 1);
 		cur += tmp;
 		fir[mn] = nxt[fir[mn]];
 		//cerr << i << ' ' << cur << '\n';
 	}
 	cout<< res << '\n';
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