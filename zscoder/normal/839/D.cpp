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
typedef pair<int,int> ii;
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

const int MOD = 1e9 + 7;
int a[211111];

ll s[1111111];
ll pow2[1111111];
ll ct[1111111];
ll cnt[1111111];
ll ans[1111111];
int mob[1111111];
NumberTheory nt;
int mobius(int x)
{
	int xx=x;
	if(mob[x]!=-2) 
	{
		return mob[x];
	}
	int c=1;
	for(int i=0;nt.primes[i]*nt.primes[i]<=x;i++)
	{
		if(x%nt.primes[i]==0)
		{
			x/=nt.primes[i];
			if(x%nt.primes[i]==0) return (mob[xx]=0);
			if(c==1) c=-1;
			else c=1;
		}
	}
	if(x>1)
	{
		if(c==1) c=-1;
		else c=1;
	}
	//if(x==2) cerr<<x<<' '<<c<<'\n';
	return (mob[xx]=c);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	nt.Sieve(1000001);
	int n; cin>>n;
	for(int i=0;i<n;i++) 
	{
		cin>>a[i];
		ct[a[i]]++;
	}
	for(int i=1;i<=1000000;i++)
	{
		for(int j=i;j<=1000000;j+=i)
		{
			cnt[i]+=ct[j];
		}
	}
	pow2[0]=1;
	for(int i=1;i<=1000000;i++)
	{
		pow2[i]=(pow2[i-1]+pow2[i-1]);
		while(pow2[i]>=MOD) pow2[i]-=MOD;
	}
	for(int i=2;i<=1000000;i++)
	{
		if(cnt[i]==0) continue;
		s[i] = ((ll(cnt[i])*ll(pow2[cnt[i]-1]))%MOD)%MOD;
		s[i]%=MOD;
		if(s[i]<0) s[i]+=MOD;
		//cerr<<i<<' '<<s[i]<<'\n';
	}
	ll ans=0;
	for(int i=1;i<=1000000;i++) mob[i]=-2;
	for(int i=2;i<=1000000;i++)
	{
		ll res=0;
		for(int j=1;j*i<=1000000;j++)
		{
			//if(s[i*j]!=0) cerr<<i<<' '<<j<<' '<<mobius(j)<<' '<<s[i*j]<<'\n';
			res+=(mobius(j)*s[i*j])%MOD;
			while(res>=MOD) res-=MOD;
		}
		//if(res!=0) cerr<<i<<' '<<res<<'\n';
		res=(res*i)%MOD;
		if(res<0) res+=MOD;
		ans+=res;
		while(ans>=MOD) ans-=MOD;
	}
	cout<<ans<<'\n';
}