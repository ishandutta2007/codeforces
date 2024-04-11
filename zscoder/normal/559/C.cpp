#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const int MOD = 1e9 + 7;
ll fact[999999];
ll ifact[999999];

ll modpow(ll a, ll b)
{
	ll r = 1;
	while(b)
	{
		if(b&1) r = (r*a)%MOD;
		a = (a*a)%MOD;
		b>>=1;
	}
	return r;
}

ll inv(ll x)
{
	return modpow(x, MOD - 2);
}

ll mult(ll a, ll b)
{
	return (a*b)%MOD;
}

ll add(ll a, ll b)
{
	return (a+b)%MOD;
}

ll subtract(ll a, ll b)
{
	return (add(a, -b)+MOD)%MOD;
}

ll calc(ll x1, ll y1, ll x2, ll y2)
{
	//if(!(x2>=x1&&y2>=y1)){exit(0);}
	if(x2<x1||y2<y1) return 0;
	ll x = x2 - x1;
	ll y = y2 - y1;
	return mult(fact[x+y], mult(ifact[x], ifact[y]));
}
ii vec[111111];
ll dp[100001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("countways.in", "r", stdin);
	fact[0] = 1; ifact[0] = 1;
	for(ll i = 1; i <= 999999; i++)
	{
		fact[i] = mult(fact[i-1], i);
		ifact[i] = mult(ifact[i-1], inv(i));
	}
	int t = 1;
	while(t--)
	{
		ll n, m, k; cin >> n >> m >> k;
		
		for(int i = 0; i < k; i++)
		{
			ll x, y;
			cin >> x >> y;
			vec[i] = ii(x, y);
		}
		vec[k] = ii(n, m);
		sort(vec, vec + k + 1);
		//dp.resize(k+1);
		for(int i = 0; i < k + 1; i++)
		{
			//if(!(vec[i].fi>=1&&vec[i].se>=1)) return 0;
			ll x = calc(1, 1, vec[i].fi, vec[i].se);
			dp[i] = x;
			//dp.pb(calc(1, 1, vec[i].fi, vec[i].se));
		}
		
		for(int j = 0; j < k + 1; j++)
		{
			for(int i = 0; i < j; i++)
			{
				if(vec[i].fi <= vec[j].fi && vec[i].se <= vec[j].se)
				{
					dp[j] = subtract(dp[j], mult(dp[i], calc(vec[i].fi, vec[i].se, vec[j].fi, vec[j].se)));
				}
			}
		}
		cout << dp[k] << '\n';
		
	}
	//cout<<"3\n1";
}