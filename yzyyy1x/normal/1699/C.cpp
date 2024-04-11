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
const ll mod = 1e9 + 7;

int n;
int a[N], ps[N];

//

void sol()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i], ps[a[i]] = i;
	ll ans = 1;
	int l = ps[0], r = ps[1], las;
	if(l > r)
	 	swap(l, r);
	las = r - l - 1;
	for(int i = 2; i < n; i++)
	{
		int nw = ps[i];
		if(nw >= l && nw <= r)
			ans = ans * las % mod, --las;
		else
		{
			if(nw < l)
				las += l - nw - 1, l = nw;
			else
				las += nw - r - 1, r = nw; 
		}
	}
	cout << ans << '\n';
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