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

ll f[18][N];

void Add(ll &x,ll y)
{x=(x+y)%mod;}

void Sub(ll &x,ll y)
{x=(x-y+mod)%mod;}

void Mul(ll &x,ll y)
{x=x*y%mod;}

ll qpow(ll x,ll y)
{
	ll res=1;
	while(y)
	{
		if(y&1)res=res*x%mod;
		x=x*x%mod,y>>=1;
	}
	return res;
}

const int len = 1 << 17;

void Or(ll *a,bool inv)
{
	for(int l=2,md=1;l<=len;l<<=1,md<<=1)
		for(int i=0;i<len;i+=l)
			for(int j=0;j<md;j++)
				inv?Sub(a[i+j+md],a[i+j]):Add(a[i+j+md],a[i+j]);
}


void sol()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	ll tot = 0;
	for(int i = 0; i < n; i++)
		a[i] = s[i] == '?' ? -1 : s[i] - 'a', tot += (a[i] == -1);
	for(ll num = 1; num <= 17; num++)
	{
		for(int i = 0; i < n; i++)
		{
			ll s = 0, res = 1, las = tot;
			for(int j = 0; i - j >= 0 && i + j < n; j++)
			{
				if(j == 0)
				{
					if(a[i] == -1)
						Mul(res, num);
					las -= (a[i] == -1);
				}
				else
				{
					if(a[i - j] != -1 && a[i + j] != -1 && a[i - j] != a[i + j])
						break;
					if(a[i - j] != -1 && a[i + j] == -1)
						s |= (1 << a[i - j]);
					if(a[i + j] != -1 && a[i - j] == -1)
						s |= (1 << a[i + j]);
					if(a[i - j] == -1 && a[i + j] == -1)
						Mul(res, num);
					las -= (a[i - j] == -1);
					las -= (a[i + j] == -1);
				}
				Add(f[num][s], res * qpow(num, las));
			}
			s = 0, res = 1, las = tot;
			for(int j = 0; i - j >= 0 && i + j + 1 < n; j++)
			{
				if(a[i - j] != -1 && a[i + j + 1] != -1 && a[i - j] != a[i + j + 1])
					break;
				if(a[i - j] != -1 && a[i + j + 1] == -1)
					s |= (1 << a[i - j]);
				if(a[i + j + 1] != -1 && a[i - j] == -1)
					s |= (1 << a[i + j + 1]);
				if(a[i - j] == -1 && a[i + j + 1] == -1)
					Mul(res, num);
				las -= (a[i - j] == -1);
				las -= (a[i + j + 1] == -1);
				Add(f[num][s], res * qpow(num, las));
			}
		}
	}
	for(int i = 1; i <= 17; i++)
		Or(f[i], 0);
	int qq;
	cin >> qq;
	while(qq--)
	{
		string s;
		cin >> s;
		int S = 0;
		for(int i = 0; i < s.length(); i++)
			S |= (1 << (s[i] - 'a'));
		cout << f[s.length()][S] << '\n';
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