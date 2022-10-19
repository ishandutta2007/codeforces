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
int a[N], suf[N], pref[N];

void sol()
{
	int n;
	cin >> n;
	n *= 2;
	string s;
	cin >> s;
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '(')
			a[i + 1] = 1;
		else a[i + 1] = -1;
	}
	bool flg = 1;
	for(int i = 1; i <= n; i++)
	{
		pref[i] = a[i];
		if(i > 1)
			pref[i] += pref[i - 1];
		if(pref[i] < 0)
			flg = 0;
	}
	for(int i = n; i >= 1; i--)
	{
		suf[i] = a[i];
		if(i < n)
			suf[i] += suf[i + 1];
	}
	if(flg)
	{
		cout << 0 << '\n';
		return;
	}
	int rm = n;
	while(pref[rm] >= 0)
		--rm;
	int lm = 1;
	while(pref[lm] >= 0)
		++lm;
	int mxv = inf;
	suf[n + 1] = 0;
	pref[0] = 0;
	for(int l = n, r = n; l >= 1; l--)
	{
		if(l >= rm && suf[l + 1] <= suf[r + 1])
			r = l;
		mxv = min(mxv, suf[l]);
		if(l <= lm)
		{
			if(pref[l - 1] + mxv - suf[r + 1] >= 0)
			{
				//cerr << suf[r + 1] << ' ' << mxv << '\n';
				cout << 1 << '\n';
				cout << l << ' ' << r << '\n';
				return;
			}
		}
	}
	cout << 2 << '\n';
	int ps = 0;
	for(int i = 1; i <= n; i++)
		if(pref[i] >= pref[ps])ps = i;
	cout << 1 << ' ' << ps << '\n' << ps + 1 << ' ' << n << '\n';
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