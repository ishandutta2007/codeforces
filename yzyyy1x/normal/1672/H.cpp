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

const int N = 2e5 + 100;
const ll inf = 1e18;
const ll mod = 998244353;//1e9 + 7;

int n, qq;
int a[N];

int lp[N], rp[N], type[N], fir[N], las[N];
int sum[N][4];


void sol()
{
	cin >> n >> qq;
	string s;
	cin >> s;
	for(int i = 1; i <= n; i++)
		a[i] = s[i - 1] - '0';
	memset(fir, 63, sizeof fir);
	for(int i = 1; i <= n; i++)
	{
		int j = i;
		while(j <= n && (j == i || a[j] != a[j - 1]))
			++j;
		--j;
		for(int k = i; k <= j; k++)
			lp[k] = i, rp[k] = j;
		memcpy(sum[j], sum[i - 1], sizeof sum[i - 1]);
		if(a[i] == 1 && a[j] == 1)
			sum[j][0]++, type[i] = type[j] = 0;
		if(a[i] == 0 && a[j] == 0)
			sum[j][1]++, type[i] = type[j] = 1;
		if(a[i] == 1 && a[j] == 0)
			sum[j][2]++, type[i] = type[j] = 2, fir[i] = i, las[j] = j;
		if(a[i] == 0 && a[j] == 1)
			sum[j][3]++, type[i] = type[j] = 3, fir[i] = i, las[j] = j;
		i = j;
	}
	for(int i = 1; i <= n; i++)
	{
		if(i != rp[i])
			continue;
		las[i] = max(las[i], las[lp[i] - 1]);
	}
	for(int i = n; i >= 1; i--)
	{
		if(i != lp[i])
			continue;
		fir[i] = min(fir[i], fir[rp[i] + 1]);
	}
	while(qq--)
	{
		int l, r;
		cin >> l >> r;
		l = lp[l];
		r = rp[r];
		int cnt[4];
		for(int i = 0; i < 4; i++)
			cnt[i] = sum[r][i] - sum[l - 1][i];
		int res = accumulate(cnt, cnt + 4, 0);
		res -= min(cnt[0], cnt[1]);
		if(cnt[2] != cnt[3] || cnt[2] == 0)
			res -= min(cnt[2], cnt[3]);
		else
		{
			if(a[l] == 0 && cnt[0] >= cnt[1] || a[l] == 1 && cnt[0] <= cnt[1])
			{
				res -= cnt[2] - 1;
			}
			else res -= cnt[2];
		}
		cout << res << '\n';
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