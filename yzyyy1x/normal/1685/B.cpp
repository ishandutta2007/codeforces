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

string s;
int n, a, b, c, d, val[N];

void sol()
{
	cin >> a >> b >> c >> d;
	cin >> s;
	n = s.length();
	VI num(2, 0);
	for(int i = 0; i < n; i++)
	{
		val[i + 1] = (s[i] == 'A' ? 0 : 1);
		num[val[i + 1]]++;
	}
	if(num[0] != a + c + d || num[1] != b + c + d)
	{
		cout << "NO" << '\n';
		return;
	}
	VI cnt[3], sum(3, 0);
	for(int i = 1; i <= n; i++)
	{
		if(val[i] == val[i + 1] || i == n)
			continue;
		int j = i + 1;
		while(j <= n && val[j] != val[j - 1])
			++j;
		--j;
		if(val[i] == 0 && val[j] == 1)
			cnt[0].pb((j - i + 1) / 2), sum[0] += (j - i + 1) / 2;
		else if(val[i] == val[j])
			cnt[1].pb((j - i + 1) / 2), sum[1] += (j - i + 1) / 2;
		else
			cnt[2].pb((j - i + 1) / 2), sum[2] += (j - i + 1) / 2;
		i = j;
	}
	if(c <= sum[0] && d <= sum[2])
	{
		cout << "YES" << '\n';
		return;
	}
	if(c > sum[0] && d > sum[2])
	{
		c -= sum[0];
		d -= sum[2];
		if(c + d <= sum[1])
			cout << "YES" << '\n';
		else cout << "NO" << '\n';
		return;
	}
	if(d > sum[2])
	{
		swap(c, d);
		swap(sum[0], sum[2]);
		swap(cnt[0], cnt[2]);
	}
	c -= sum[0] + sum[1];
	if(c <= 0)
	{
		cout << "YES" << '\n';
		return;
	}
	sort(all(cnt[2]));
	reverse(all(cnt[2]));
	trav(v, cnt[2])
	{
		if(c <= 0)
			d -= v;
		else
		{
			--v;
			int tmp = min(c, v);
			c -= tmp;
			v -= tmp;
			d -= v;
		}
	}
	if(c <= 0 && d <= 0)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
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