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

const int N = 2e6 + 100;
const int inf = 1e9;
//const ll inf = 1e18;
const ll mod = 998244353;//1e9 + 7;

int n, m;
string s;
int a[N];
bool vis[N];
ll add[N], res[N], add2[N], add3[N];

void sol()
{
	cin >> n >> m;
	cin >> s;
	for(int i = 0; i < n * m; i++)
		a[i] = s[i] - '0';
	for(int i = 0; i <= n * m + 10; i++)
		vis[i] = 0, add[i] = 0, res[i] = 0, add2[i] = 0, add3[i] = 0;
	int bf = -1;
	for(int i = 0; i < n * m; i++)
	{
		if(a[i])
		{
			if(!vis[i % m])
			{
				vis[i % m] = 1;
				add[i]++;
			}
			if(bf == -1)
				add2[i]++;
			else
			{
				if(i - bf >= m)
					add2[i]++;
				else
				{
					if(bf + m <= n * m)
						add3[bf + m]++;
					if(i + m <= n * m)
						add3[i + m]--;
				}
			}
			bf = i;
		}
	}
	for(int i = 0; i < n * m; i++)
	{
		if(i >= m)
			add3[i] += add3[i - m];
		add2[i] += add3[i];
	}
	for(int i = 0; i < n * m; i++)
	{
		if(i)
			add[i] += add[i - 1], add2[i] += add2[i - 1];
		cout << add[i] + add2[i] << " \n"[i == n * m - 1];
	}
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