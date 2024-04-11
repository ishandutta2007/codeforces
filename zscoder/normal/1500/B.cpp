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
typedef pair<ld,ld> state;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll lcm(ll a, ll b)
{
	return (a/__gcd(a,b))*b;
}

int a[501111];
int b[501111];
ii F[1011111];


ll inv(ll a, ll m)
{
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;
 
    if (m == 1)
        return 0;
 
    // Apply extended Euclid Algorithm
    while (a > 1) {
        // q is quotient
        q = a / m;
 
        t = m;
 
        // m is remainder now, process same as
        // euclid's algo
        m = a % m, a = t;
 
        t = x0;
 
        x0 = x1 - q * x0;
 
        x1 = t;
    }
 
    // Make x1 positive
    if (x1 < 0)
        x1 += m0;
 
    return x1;
}
 
// k is size of num[] and rem[]. Returns the smallest
// number x such that:
// x % num[0] = rem[0],
// x % num[1] = rem[1],
// ..................
// x % num[k-2] = rem[k-1]
// Assumption: Numbers in num[] are pairwise coprime
// (gcd for every pair is 1)
ll findMinX(ll num[], ll rem[], ll k)
{
    // Compute product of all numbers
    ll prod = 1;
    for (ll i = 0; i < k; i++)
        prod *= num[i];
 
    // Initialize result
    ll result = 0;
 
    // Apply above formula
    for (ll i = 0; i < k; i++) {
        ll pp = prod / num[i];
       // cerr<<pp<<' '<<num[i]<<'\n';
      // cerr<<"QUERY: "<<pp<<' '<<num[i]<<endl;
        result += rem[i] * inv(pp, num[i]) * pp;
    }
	//cerr<<"OK"<<endl;
    return result % prod;
}

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

NumberTheory nt;
vector<ii> v[2];
map<ll,ll> ma[2];
map<ll,ll> M;

ll comp(ll x, ll y, ll n, ll m)
{
	//z = x (mod n), z = y (mod m)
	//cerr<<x<<' '<<y<<' '<<n<<' '<<m<<'\n';
	/*
	ll newm = m/__gcd(n,m);
	y%=newm;
	m=newm;
	*/
	/*
	ll num[2] = {n,m};
	ll rem[2] = {x,y};
	return findMinX(num,rem,2);
	*/
	ll num[M.size()] = {};
	ll rem[M.size()] = {};
	int id=0;
	for(auto X:M)
	{
		ll p = X.fi; ll pw = X.se;
		ll cur=1;
		for(int i=0;i<pw;i++)
		{
			cur*=p;
		}
		ll r = 0;
		if(ma[0][p]==pw)
		{
			r = x%cur;
		}
		else
		{
			r = y%cur;
		}
		rem[id] = r;
		num[id++] = cur;
	}
	ll res = findMinX(num,rem,M.size());
	if(res%n==x&&res%m==y) return res;
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	nt.Sieve(1000001);
	ll n,m,k; cin>>n>>m>>k;
	
	nt.getpf(v[0],n); nt.getpf(v[1],m);
	for(int i=0;i<2;i++)
	{
		for(auto X:v[i])
		{
			ma[i][X.fi]=X.se;
			M[X.fi]=max(M[X.fi],X.se);
		}
	}
	for(int i=0;i<n;i++) 
	{
		cin>>a[i];
		a[i]--;
		F[a[i]].fi=i+1;
	}
	for(int i=0;i<m;i++) 
	{
		cin>>b[i];
		b[i]--;
		F[b[i]].se=i+1;
	}
	vector<ll> sad;
	for(int i=0;i<=2*max(n,m);i++)
	{
		//cerr<<F[i].fi<<' '<<F[i].se<<'\n';
		if(F[i].fi>0&&F[i].se>0)
		{
			F[i].fi--; F[i].se--;
			//cerr<<"COMP: "<<F[i].fi<<' '<<F[i].se<<'\n';
			ll r = comp(F[i].fi,F[i].se,n,m);
			//cerr<<"R = "<<r<<'\n';
			if(r>=0) sad.pb(r);
		}
	}
	sort(sad.begin(),sad.end());
	sad.erase(unique(sad.begin(),sad.end()),sad.end());
	//for(auto s:sad) cerr<<s<<' ';
	//cerr<<'\n';
	ll period = lcm(n,m);
	ll goodguys = period - sad.size();
	k--;
	ll times = k/goodguys;
	k%=goodguys;
	ll nw = k;
	sad.pb(ll(1e18));
	for(auto X:sad)
	{
		if(k>=X)
		{
			nw++; k++;
		}
		else break;
	}
	cout<<times*period + nw + 1<<'\n';
}