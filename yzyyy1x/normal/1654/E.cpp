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
int a[N];

const int mv = (int)4e7;
int cnt[(int)9e7];
int ans = 0;

void doit(int d)
{
	for(int i = 1; i <= n; i++)
	{
		int nw = d * i - a[i] + mv;
		++cnt[nw];
		ans = max(ans, cnt[nw]);
	}
	for(int i = 1; i <= n; i++)
	{
		int nw = d * i - a[i] + mv;
		--cnt[nw];
	}
}

void sol()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int B = 350;
	for(int d = -B; d <= B; d++)
	{
		doit(d);
	}
	for(int i = 1; i <= n; i++)
	{
		int l = max(1, i - B);
		int r = min(n, i + B);
		for(int j = l; j <= r; j++)
		{
			if(j == i)
			{
				continue;
			}
			int nw = a[i] - a[j];
			if(abs(nw) % abs(i - j))
				continue;
			nw /= (i - j);
			++cnt[nw + 200000];
			ans = max(ans, cnt[nw + 200000] + 1);
		}
		for(int j = l; j <= r; j++)
		{
			if(j == i)
			{
				continue;
			}
			int nw = a[i] - a[j];
			if(abs(nw) % abs(i - j))
				continue;
			nw /= (i - j);
			--cnt[nw + 200000];
		}
	}
	cout << n - ans << '\n';
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