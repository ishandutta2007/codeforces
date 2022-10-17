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
//const ll inf = 1e18;
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
	int n, m;
	cin >> n >> m;
	int t;
	t = n / 2;
	while(t - (n - t) < m)
	{
		++t;
	}
	VI a(n), b(n);
	for(int i = 0; i < n; i++)
		cin >> a[i], b[i] = a[i];
	sort(all(b));
	int mn = 1e9, l, r;
	for(int i = 0; i < n; i++)
	{
		if(i + t - 1 >= n)
			break;
		if(b[i + t - 1] - b[i] < mn)
		{
			mn = b[i + t - 1] - b[i];
			l = b[i];
			r = b[i + t - 1];
		}
	}
	cout << l << ' ' << r << '\n';
	vector<pii> ans;
	for(int i = 0, j; i < n; i++)
	{
		if(m == 1)
		{
			--m;
			ans.pb(pii(i, n - 1));
			break;
		}
		if(a[i] >= l && a[i] <= r)
		{
			ans.pb(pii(i, i));
			--m;
			continue;
		}
		else
		{
			int num = 0;
			j = i;
			while(j < n && num <= 0)
			{
				if(a[j] >= l && a[j] <= r)
					num++;
				else num--;
				++j;
			}
			--j;
			//cerr << "??" << num << ' ' << i << ' ' << j << '\n';
			ans.pb(pii(i, j));
			--m;
			i = j;
		}
	}
	assert(m == 0);
	trav(v, ans)
		cout << v.fi + 1 << ' ' << v.sc + 1 << '\n';
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