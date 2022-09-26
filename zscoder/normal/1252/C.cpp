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

struct NumberTheory
{
	vector<ll> primes;
	vector<bool> prime;
	vector<ll> totient;
	vector<ll> sumdiv;
	vector<ll> mobius;
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
	void SieveMob(ll n)
	{
		mobius.resize(n+1,0);
		mobius[1] = 1;
		for (int i = 2; i <= n; ++i) {
			if (prime[i]) {
				mobius[i] = -1;				//i is prime
			}
			for (int j = 0; j < primes.size () && i * primes[j] <= n; ++j) {
				if (i % primes[j] == 0) {
					mobius[i * primes[j]] = 0;//prime[j] divides i
					break;
				} else {
					mobius[i * primes[j]] = mobius[i] * -1;	//prime[j] does not divide i
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

struct Lehmer {
	static const int MAXX = 510;
	static const int MAXY = 100010;
	static const int MAXN = 10000010;  //MAXN*MAXN 
	static const int MAXP = 1000010;
	int np;
	bool fl[MAXN];
	int sp[MAXN];
	long long int pr[MAXP];
	int cn[MAXN];
	long long f[MAXX][MAXY];
 
	int size(){  //for pr
		return np;
	}
	long long int& operator[](int id){
		return pr[id];
	}
 
	Lehmer() {
		memset(fl, 0, sizeof(fl));
		for (int i = 2; i < MAXN; i += 2) {
			sp[i] = 2;
			fl[i] = 1;
		}
		for (int i = 3; i < MAXN; i += 2) if (!fl[i]) {
			sp[i] = i;
			for (int j = i; j < MAXN; j += i){
				if (!fl[j]){
					fl[j] = 1;
					sp[j] = i;
				}
			}
		}
		np = 0;
		for (int i = 2; i < MAXN; i++) {
			if (sp[i] == i) {
				pr[np++] = i;
			}
			cn[i] = np;
		}
		for (int i = 0; i < MAXX; i++){
			for (int j = 0; j < MAXY; j++){
				if (!i) f[i][j] = j;
				else f[i][j] = f[i - 1][j] - f[i - 1][j / pr[i - 1]];
			}
		}
	}
private:
	inline long long LegendreSum(long long m, int n) {
		if (!n) return m;
		if (pr[n - 1] >= m) return 1;
		if (m < MAXY && n < MAXX) return f[n][m];
		return LegendreSum(m, n - 1) - LegendreSum(m / pr[n - 1], n - 1);
	}
public:
	inline long long count_primes(long long m) {
		if (m < MAXN) return cn[m];
		int x = sqrt(0.9 + m), y = cbrt(0.9 + m);
		int a = cn[y];
		long long res = LegendreSum(m, a) + a - 1;
		for (int i = a; pr[i] <= x; i++) res = res - count_primes(m / pr[i]) + count_primes(pr[i]) - 1;
		return res;
	}
} pr;
NumberTheory nt;

unordered_map<ll,ll> ma;

ll primecount(ll small)
{
	if(small>=ll(12345677))
	{
		return (ma[small]=pr.count_primes(small));
	}
	if(ma.count(small)) return ma[small];
	return (ma[small]=lower_bound(nt.primes.begin(),nt.primes.end(),small+1)-nt.primes.begin());
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n; cin>>n;
	ll q=1;
	while((q+1)*(q+1)*(q+1)<=n) q++;
	//pq
	nt.Sieve(12345678);
	ll ans = primecount(q);
	int id=0;
	for(ll p:nt.primes)
	{
		if(p*p>=n) break;
		ll pc = primecount(n/p)-1;
		//primes[id]*
		ans+=max(0LL,pc-id);
		id++;
	}
	cout<<ans<<'\n';
}