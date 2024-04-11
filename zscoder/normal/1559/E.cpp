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
typedef vector<int> vi;
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

vector<int> fact;
vector<int> ifact;
vector<int> inv;
vector<int> pow2;
const int MOD = 998244353;
int add(int a, int b)
{
	a+=b;
	while(a>=MOD) a-=MOD;
	return a;
}
void radd(int &a, int b)
{
	a=add(a,b); 
}
int mult(int a, int b)
{
	return (a*1LL*b)%MOD;
}
void rmult(int &a, int b)
{
	a=mult(a,b);
}
int modpow(int a, int b)
{
	int r=1;
	while(b)
	{
		if(b&1) r=mult(r,a);
		a=mult(a,a);
		b>>=1;
	}
	return r;
}
int choose(int a, int b)
{
	if(a<b) return 0;
	if(b==0) return 1;
	if(a==b) return 1;
	return mult(fact[a],mult(ifact[b],ifact[a-b]));
}
int inverse(int a)
{
	return modpow(a,MOD-2);
}
void init(int _n)
{
	fact.clear(); ifact.clear(); inv.clear(); pow2.clear();
	fact.resize(_n+1);
	ifact.resize(_n+1);
	inv.resize(_n+1);
	pow2.resize(_n+1);
	pow2[0]=1;
	ifact[0]=1;
	fact[0]=1;
	for(int i=1;i<=_n;i++)
	{
		pow2[i]=add(pow2[i-1],pow2[i-1]);
		fact[i]=mult(fact[i-1],i);
		//ifact[i]=mult(ifact[i-1],inv[i]);
	}
	ifact[_n] = inverse(fact[_n]);
	for(int i=_n-1;i>=1;i--)
	{
		ifact[i] = mult(ifact[i + 1], i + 1);
	}
	for(int i=1;i<=_n;i++)
	{
		inv[i] = mult(fact[i-1],ifact[i]);
	}
}
	
int ans[111111];
int dp[55][111111];
int S[55][111111];

int getp(int id, int l, int r)
{
	l=max(l,0);
	if(l>r) return 0;
	if(l==0) return S[id][r];
	else return add(S[id][r],MOD-S[id][l-1]);
}

int solve(vector<ii> &a, int m)
{
	int n=a.size();
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			dp[i][j]=S[i][j]=0;
		}
	}
	dp[0][0]=1;
	for(int i=0;i<=m;i++)
	{
		S[0][i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		int l=a[i-1].fi; int r=a[i-1].se;
		for(int j=0;j<=m;j++)
		{
			if(j<l) continue;
			//[j-r,j-l] is the previous sum
			radd(dp[i][j],getp(i-1,j-r,j-l));
		}
		S[i][0]=dp[i][0];
		for(int j=1;j<=m;j++)
		{
			S[i][j]=add(S[i][j-1],dp[i][j]);
		}
	}
	return S[n][m];
}

void solve()
{
	int n,m; cin>>n>>m;
	vector<ii> vec;
	for(int i=0;i<n;i++)
	{
		int l,r; cin>>l>>r;
		vec.pb({l,r});
	}
	for(int gd=1;gd<=m;gd++)
	{
		//solve assuming divisible by m
		ans[gd]=0;
		vector<ii> nw;
		bool pos=1;
		for(int i=0;i<n;i++)
		{
			int l=vec[i].fi; int r=vec[i].se;
			nw.pb(mp((l+gd-1)/gd,r/gd));
			if(nw[i].fi>nw[i].se) pos=0;
		}
		if(!pos) continue;
		//cerr<<"HERE "<<gd<<endl;
		ans[gd]=solve(nw,m/gd);
		//cerr<<gd<<' '<<ans[gd]<<'\n';
	}
	int res=0;
	for(int i=1;i<=m;i++)
	{
		if(nt.mobius[i]==0) continue;
		if(nt.mobius[i]==1) radd(res,ans[i]);
		else radd(res,MOD-ans[i]);
	}
	cout<<res<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	nt.Sieve(123456);
	nt.SieveMob(123456);
	//cerr<<nt.mobius[1]<<' '<<nt.mobius[2]<<' '<<nt.mobius[4]<<'\n';
	int t=1;
	while(t--) solve();
}