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
		if(x==1) return false;
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
	
	void getpf(vector<ii>& pf, ll n)
	{
		for(ll i = 0; primes[i]*primes[i] <= n; i++)
		{
			int cnt = 0;
			while(n%primes[i]==0)
			{
				n/=primes[i]; cnt++;
			}
			pf.pb(ii(primes[i], cnt));
		}
		if(n>1)
		{
			pf.pb(ii(n, 1));
		}
	}

	//ll op;
	void getDiv(vector<ll>& div, vector<ii>& pf, ll n, int i)
	{
		//op++;
		ll x, k;
		if(i >= pf.size()) return ;
		x = n;
		for(k = 0; k <= pf[i].se; k++)
		{
			if(i==int(pf.size())-1) div.pb(x);
			getDiv(div, pf, x, i + 1);
			x *= pf[i].fi;
		}
	}
};

NumberTheory nt;
int dp[1000001][21];
int pref[1000001][21];
vi vec[1000001];

void calcppf(int n)
{
	int o = n;
	for(int i = 0; nt.primes[i]*nt.primes[i]<=n; i++)
	{
		int cnt =0 ;
		while(n%nt.primes[i]==0) 
		{
			n/=nt.primes[i]; cnt++;
		}
		if(cnt) vec[o].pb(cnt);
	}
	if(n>1) vec[o].pb(1);
}

ll modpow(ll a, ll b)
{
	ll r = 1;
	while(b)
	{
		if(b&1) r=(r*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return r;
}

int solve(ll r, ll n)
{
	if(n==1) return 1;
	if(r==0) return modpow(2,vec[n].size());
	ll ans = 1;
	for(int i = 0 ;i < vec[n].size(); i++)
	{
		ans=(ans*dp[r][vec[n][i]])%MOD;
	}
	return ans;
}

int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	nt.Sieve(1000000);
	for(int i = 2; i <= 1000000; i++) calcppf(i);
	for(int i = 0; i <= 20; i++)
	{
		dp[1][i] = 2*i + 1;
		if(i>0) pref[1][i] = dp[1][i]+pref[1][i-1];
		else pref[1][i]=dp[1][i];
		if(pref[1][i]>=MOD) pref[1][i]-=MOD;
	}
	for(int i = 2; i <= 1000000; i++)
	{
		for(int j = 0; j <= 20; j++)
		{
			dp[i][j]=pref[i-1][j];
			if(dp[i][j]>=MOD) dp[i][j]-=MOD;
			pref[i][j]=dp[i][j];
			if(j>0) pref[i][j]+=pref[i][j-1];
			if(pref[i][j]>=MOD) pref[i][j]-=MOD;
		}
	}	
	int q; scanf("%d",&q);
	while(q--)
	{
		int r, c; scanf("%d %d",&r,&c);
		printf("%d\n", solve(r,c));
	}
}