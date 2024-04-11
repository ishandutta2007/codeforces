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
const ll inf = 1e18;
const ll mod = 998244353;//1e9 + 7;

int n;
int a[N], ans[N], cnt[N];
vector<int> hav[N];

void sol()
{
	cin >> n;
	for(int i = 0; i <= n; i++)
		hav[i].clear(), cnt[i] = 0;
	for(int i = 1; i <= n; i++)
		cin >> a[i], ++cnt[a[i]], hav[a[i]].pb(i);
	vector<pii> buk;
	for(int i = 1; i <= n; i++)
	{
		if(cnt[i])
			buk.pb(pii(cnt[i], i));
	}
	sort(all(buk));
	reverse(all(buk));
	while(!buk.empty())
	{
		vector<pii> cur;
		for(int i = buk.size() - 1; i >= 0; i--)
		{
			int val = buk[i].sc;
			int who = hav[val].back();
			--buk[i].fi;
			cur.pb(pii(who, val));
			hav[val].pop_back();
		}
		if(cur.size() == 1)
		{
			ans[cur[0].fi] = cur[0].sc;
		}
		else
		{
			for(int i = 1; i < cur.size(); i++)
			{
				ans[cur[i].fi] = cur[i - 1].sc;
			}
			ans[cur[0].fi] = cur[cur.size() - 1].sc;
		}
		while(buk.back().fi == 0)
			buk.pop_back();
	}
	for(int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
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