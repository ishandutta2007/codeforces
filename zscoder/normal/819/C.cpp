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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

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
	ll getDiv(vector<ii>& pf, ll n, int i, ll mx)
	{
		//op++;
		ll ans=0;
		ll x, k;
		if(i >= int(pf.size())) return 0;
		x = n;
		for(k = 0; k <= pf[i].se; k++)
		{
			if(x>mx) break;
			if(i==int(pf.size())-1) 
			{
				ans++;
			}
			ans+= getDiv(pf, x, i + 1,mx);
			x *= pf[i].fi;
		}
		return ans;
	}
};
NumberTheory nt;


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	nt.Sieve(1000111);
	int t; cin>>t;
	while(t--)
	{
		ll n[3];
		ll m[3];
		ll s[3];
		map<int,int> ma1;
		for(int i=0;i<3;i++) 
		{
			cin>>n[i];
			vector<ii> pf;
			nt.getpf(pf,n[i]);
			for(int j=0;j<pf.size();j++)
			{
				ma1[pf[j].fi]+=pf[j].se;
			}
		}
		for(int i=0;i<3;i++) cin>>m[i];
		map<int,int> ma;
		for(int i=0;i<3;i++) 
		{
			cin>>s[i];
			vector<ii> pf;
			nt.getpf(pf,s[i]);
			for(int j=0;j<pf.size();j++)
			{
				ma[pf[j].fi]+=pf[j].se;
			}
		}
		ma[2]++;
		vector<ii> tmp;
		for(auto it = ma.begin();it!=ma.end();it++)
		{
			tmp.pb(mp(it->fi,it->se));
		}
		ll ans = nt.getDiv(tmp,1,0,n[0]*n[1]*n[2]);
		vector<ll> rest;
		for(auto it = ma1.begin(); it!=ma1.end();it++)
		{
			ll p = it->fi;
			if(it->se>ma[p])
			{
				ll tmp=1;
				for(int i=0;i<ma[p]+1;i++) tmp*=p;
				rest.pb(tmp);
			}
		}
		//cerr<<ans<<'\n';
		//inclusion exclusion
		ll M= m[0]*m[1]*m[2];
		ll tot =M;
		//cerr<<tot<<'\n';
		int rsiz=rest.size();
		for(int i = 1; i < (1<<rsiz); i++)
		{
			ll P=1;
			for(int j = 0; j < rsiz; j++)
			{
				if(i&(1<<j))
				{
					P*=rest[j];
				}
			}
			if((__builtin_popcount(i))&1) tot-=M/P;
			else tot+=M/P;
		}
		ans+=tot;
		cout<<ans<<'\n';
	}
}