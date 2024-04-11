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
int a[N];

void sol()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	vector<int> ans;
	vector<pii> seg;
	for(int i = 1, j; i <= n; i++)
	{
		if(a[i] == 0)
			continue;
		j = i;
		lb:
		while(j <= n && a[j] == 1)
			++j;
		--j;
		if(j < n)
		{
			if((j - i + 1) % 2 == 0)
			{
				for(int k = j - 1; k >= i; k -= 2)
				{
					ans.pb(k);
				}
				i = j;
				continue;
			}
			else
			{
				int nxt = j + 1;
				while(nxt <= n && a[nxt] == 0)
					++nxt;
				if(nxt > n)
				{
					cout << "NO" << '\n';
					return;
				}
				if((nxt - j) % 2 == 0)
				{
					for(int k = j; k < nxt - 2; k += 2)
						ans.pb(k);
					for(int k = nxt - 2; k >= i; k -= 2)
						ans.pb(k);
					i = nxt;
					continue;
				}
				else
				{
					for(int k = j; k < nxt - 2; k += 2)
						ans.pb(k);
					for(int k = j; k <= nxt; k++)
						a[k] = 1;
					j = nxt;
					goto lb;
				}
			}
		}
		else
		{
			if(i > 1 && (j - i + 1) % 2 == 0)
			{
				for(int k = i - 1; k < j; k += 2)
				{
					ans.pb(k);
				}
				i = j;
				continue;
			}
			else
			{
				cout << "NO" << '\n';
				return;
			}
		}
	}
	cout << "YES" << '\n';
	cout << ans.size() << '\n';
	trav(v, ans)
		cout << v << ' ';
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