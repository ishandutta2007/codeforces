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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const int MOD = 1e9 + 7;

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

ll inv(ll a)
{
	return modpow(a, MOD - 2);
}

ll fact[300001];
ll ifact[300001];

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

ll dp[2001][21];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, k, s; cin>>n>>m>>k>>s;
	vector<ii> vec;
	fact[0] = 1; ifact[0] = 1;
	for(ll i = 1; i <= 300000; i++)
	{
		fact[i] = (fact[i-1]*i)%MOD;
		ifact[i] = mult(ifact[i-1], inv(i));
	}
	vec.pb(mp(n, m));
	for(int i = 0; i < k; i++)
	{
		int u, v; cin>>u>>v;
		vec.pb(mp(u, v));
	}
	sort(vec.begin(),vec.end());
	ll denom = calc(1, 1, n, m);
	ll num = 0;
	ll tmp = denom;
	for(int i = 0; i < vec.size(); i++)
	{
		dp[i][0] = calc(1, 1, vec[i].fi, vec[i].se);
	}
	for(int j = 0; j < vec.size(); j++)
	{
		for(int i = 0; i < j; i++)
		{
			if(vec[i].fi <= vec[j].fi && vec[i].se <= vec[j].se)
			{
				dp[j][0] = subtract(dp[j][0], mult(dp[i][0], calc(vec[i].fi, vec[i].se, vec[j].fi, vec[j].se)));
			}
		}
	}
	for(int i = 1; i <= 19; i++)
	{
		for(int j = 0; j < vec.size(); j++)
		{
			dp[j][i] = calc(1, 1, vec[j].fi, vec[j].se);
			for(int k = 0; k < j; k++)
			{
				if(vec[k].fi <= vec[j].fi && vec[k].se <= vec[j].se)
				{
					dp[j][i] = subtract(dp[j][i], mult(dp[k][i], calc(vec[k].fi, vec[k].se, vec[j].fi, vec[j].se)));
				}
			}	
			for(int k = 0; k < i; k++)
			{
				dp[j][i] = subtract(dp[j][i], dp[j][k]);
			}
		}
	}
	for(int i = 0; i < 20; i++)
	{
		num = add(num, mult(dp[int(vec.size()) - 1][i], s));
		//cerr<<dp[int(vec.size()) - 1][i]<<' '<<s<<'\n';
		tmp = subtract(tmp, dp[int(vec.size()) - 1][i]);
		s=(s+1)/2;
	}
	num = add(num, tmp);
	//cerr<<num<<' '<<denom<<'\n';
	cout << (inv(denom)*num)%MOD;
}