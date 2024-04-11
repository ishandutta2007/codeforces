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

map<ii, int> ma;
int n, m, k;

ii xrefl(ii pt)
{
	pt.fi = -pt.fi;
	pt.fi%=n; pt.se%=m;
	if(pt.fi<0) pt.fi+=n;
	if(pt.se<0) pt.se+=m;
	return pt;
}

ii yrefl(ii pt)
{
	pt.se = -pt.se;
	pt.fi%=n; pt.se%=m;
	if(pt.fi<0) pt.fi+=n;
	if(pt.se<0) pt.se+=m;
	return pt;
}

vector<ll> ans;
const ll INF = ll(1e18);

ll lcm(ll a, ll b)
{
	return (a*b)/__gcd(a, b);
}

ll exgcd(ll a, ll b, ll &x, ll &y)
{
	if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
 
    ll x1, y1; // To store results of recursive call
    ll gcd = exgcd(b%a, a, x1, y1);
    x = y1 - (b/a) * x1;
    y = x1;
    return gcd;
}

struct NumberTheory
{
	vector<ll> primes;
	vector<bool> prime;
	vector<ll> totient;
	vector<ll> sumdiv;
	vector<ll> bigdiv;
	void Sieve(ll n)
	{
		prime.assign(n+1, 1);
		prime[1] = false;
		for(ll i = 2; i <= n; i++)
		{
			if(prime[i])
			{
				primes.pb(i);
				for(ll j = i*2; j <= n; j += i)
				{
					prime[j] = false;
				}
			}
		}
	}
	
	ll phi(ll x)
	{
		map<ll,ll> pf;
		ll num = 1; ll num2 = x;
		for(ll i = 0; primes[i]*primes[i] <= x; i++)
		{
			if(x%primes[i]==0)
			{
				num2/=primes[i];
				num*=(primes[i]-1);
			}
			while(x%primes[i]==0)
			{
				x/=primes[i];
				pf[primes[i]]++;
			}
		}
		if(x>1)
		{
			pf[x]++; num2/=x; num*=(x-1);
		}
		x = 1;
		num*=num2;
		return num;
	}
	
	bool isprime(ll x)
	{
		for(ll i = 0; primes[i]*primes[i] <= x; i++)
		{
			if(x%primes[i]==0) return false;
		}
		return true;
	}

	void SievePhi(ll n)
	{
		totient.resize(n+1);
		for (int i = 1; i <= n; ++i) totient[i] = i;
		for (int i = 2; i <= n; ++i)
		{
			if (totient[i] == i)
			{
				for (int j = i; j <= n; j += i)
				{
					totient[j] -= totient[j] / i;
				}
			}
		}
	}
	
	void SieveSumDiv(ll n)
	{
		sumdiv.resize(n+1);
		for(int i = 1; i <= n; ++i)
		{
			for(int j = i; j <= n; j += i)
			{
				sumdiv[j] += i;
			}
		}
	}
	
	ll getPhi(ll n)
	{
		return totient[n];
	}
	
	ll getSumDiv(ll n)
	{
		return sumdiv[n];
	}
	
	ll modpow(ll a, ll b, ll mod)
	{
		ll r = 1;
		if(b < 0) b += mod*100000LL;
		while(b)
		{
			if(b&1) r = (r*a)%mod;
			a = (a*a)%mod;
			b>>=1;
		}
		return r;
	}
	
	ll inv(ll a, ll mod)
	{
		return modpow(a, mod - 2, mod);
	}
	
	ll invgeneral(ll a, ll mod)
	{
		ll ph = phi(mod);
		ph--;
		return modpow(a, ph, mod);
	}
};

NumberTheory nt;
ll g;
ll solve(ll x, ll y)
{
	//cerr << "XY : " << x << ' '<< y << '\n';
	ll l = n*2; ll r = m*2;
	if(abs(x-y)%g==0)
	{
		ll tmp = y-x;
		ll k;
		tmp/=g;
		l/=g; r/=g;
		tmp+=(r*100000000LL);
		tmp%=r;
		
		ll tmp2 = nt.invgeneral(l, r);
		//cerr<<tmp<<' '<<tmp2<<'\n';
		k = (tmp*tmp2)%r;
		return (k*(l*g)+x);
	}
	else
	{
		return INF;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	//n = 4; m = 3;
	//cout << xrefl(mp(3,3)).fi << ' ' << xrefl(mp(3,3)).se << endl;
	cin >> n >> m >> k; vector<ii> vec; vec.resize(k);
	g = __gcd(n*2,m*2);
	nt.Sieve(100001);
	for(int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		vec[i] = mp(x, y);
	}
	ans.resize(k);
	for(int i = 0; i < k; i++)
	{
		int x = vec[i].fi; int y = vec[i].se;
		ans[i] = INF;
		//cerr << solve(x,y) << '\n';
		//cerr << solve(2*n-x,y) << '\n';
		//cerr << solve(x,2*m-y) << '\n';
		//cerr << solve(2*n-x, 2*m-y) << '\n';
		ans[i] = min(solve(x, y), min(solve(2*n - x, y), min(solve(x, 2*m - y), solve(2*n - x, 2*m - y))));
	}
	for(int i = 0; i < k; i++)
	{
		if(ans[i] >= INF) ans[i] = -1;
		cout << ans[i] << '\n';
	}
}