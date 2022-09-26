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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

int a[111];

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
			if(cnt>0) pf.pb(ii(primes[i], cnt));
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

map<int,int> dp;

map<int,set<int> > S;
const int LG = 30;

int solve(int bit)
{
	if(dp.find(bit)!=dp.end()) return dp[bit];
	//cerr<<bit<<endl;
	vi vec;
	for(int i=0;i<LG;i++)
	{
		if(bit&(1<<i)) vec.pb(i);
	}
	if(vec.empty())
	{
		return (dp[bit]=0);
	}
	vi X;
	for(int i=1;i<=vec.back();i++)
	{
		int nw=0;
		for(int j=0;j<vec.size();j++)
		{
			if(vec[j]>=i)
			{
				if(vec[j]-i>0) nw|=(1<<(vec[j]-i));
			}
			else
			{
				nw|=(1<<vec[j]);
			}
		}
		X.pb(solve(nw));
	}
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());
	for(int i=0;i<X.size();i++)
	{
		if(X[i]!=i) return (dp[bit]=i);
	}
	return (dp[bit]=int(X.size()));
}

NumberTheory nt;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cerr<<solve((1<<30) - 1)<<endl;
	int n; cin>>n;
	nt.Sieve(100001);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		vector<ii> V;
		nt.getpf(V,a[i]);
		for(int j=0;j<V.size();j++)
		{
			S[V[j].fi].insert(V[j].se);
		}
	}
	int xr=0;
	for(auto it = S.begin(); it != S.end(); it++)
	{
		int bit = 0;
		for(auto it2=(it->se).begin(); it2!=(it->se).end(); it2++)
		{
			bit^=(1<<(*it2));
		}
		xr^=solve(bit);
	}
	if(xr==0)
	{
		cout<<"Arpa\n";
	}
	else
	{
		cout<<"Mojtaba\n";
	}
}