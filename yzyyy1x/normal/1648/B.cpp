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

int n, m;

int a[N], sum[N];
bool vis[N];

void sol()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i], vis[a[i]] = 1, sum[a[i]]++;
	for(int i = 1; i <= m; i++)
		sum[i] += sum[i - 1];
	bool flg = 1;
	for(int i = 1; i <= m; i++)
	{
		if(!vis[i])
			continue;
		int mm = m / i;
		for(int j = 1; j <= mm; j++)
		{
			if(vis[j])
				continue;
			int l = j * i;
			int r = (j + 1) * i - 1;
			r = min(r, m);
			if(sum[r] - sum[l - 1] > 0)
			{
				flg = 0;
				break;
			}
		}
	}
	if(!flg)
		cout << "No" << '\n';
	else
		cout << "Yes" << '\n';
	for(int i = 1; i <= n; i++)
		vis[a[i]] = 0;
	for(int i = 0; i <= m; i++)
		sum[i] = 0;	
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