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

ll mult(ll a, ll b)
{
	return (a*b)%MOD;
}

void add(ll &a, ll b)
{
	a+=b;
	while(a>=MOD) a-=MOD;
}

ll fact[511];
ll a[511];
vector<ll> pf[511];
NumberTheory nt;
map<vector<ll>,int> ma;
int cnt[511];
ll dp[511][511];
ll ncr[511][511];

ll choose(int n, int r)
{
	if(r==0) return 1;
	if(r<0) return 0;
	if(n<r) return 0;
	if(n==r) return 1;
	if(ncr[n][r]!=-1) return ncr[n][r];
	ncr[n][r]=0;
	add(ncr[n][r],choose(n-1,r-1));
	add(ncr[n][r],choose(n-1,r));
	return ncr[n][r];
}

vector<int> A;

bool issquare(int x)
{
	if(floor(sqrt(x))==(double)sqrt(x))
	{
		return true;
	}
	else return false;
}
int n;
ll ori[1111];
void gen()
{
	n = rand()%8+1;
	for(int i=0;i<n;i++)
	{
		a[i] = rand()%6+1;
		ori[i]=a[i];
	}
}

ll solve_naive()
{
	vi p;
	for(int i=0;i<n;i++) p.pb(i);
	ll ans=0;
	do
	{
		bool pos=1;
		for(int i=0;i+1<n;i++)
		{
			if(issquare(a[p[i]]*a[p[i+1]]))
			{
				pos=0; break;
			}
		}
		if(pos) ans++;
	}while(next_permutation(p.begin(),p.end()));
	return ans;
}
const bool DEBUG=0;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	fact[0]=1;
	for(int i=1;i<=510;i++) fact[i]=mult(i,fact[i-1]);
	nt.Sieve(111111);
	memset(ncr,-1,sizeof(ncr));
	for(int cc=1;;cc++)
	{
		if(!DEBUG) cin>>n;
		else gen();
		ll res = 0;
		if(DEBUG) solve_naive();
		memset(dp,0,sizeof(dp));
		ma.clear();
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;i++)
		{
			if(!DEBUG) cin>>a[i];
			vector<ii> PF;
			nt.getpf(PF,a[i]);
			pf[i].clear();
			for(int j=0;j<PF.size();j++)
			{
				if(PF[j].se&1)
				{
					pf[i].pb(PF[j].fi);
				}
			}
			sort(pf[i].begin(),pf[i].end());
			pf[i].erase(unique(pf[i].begin(),pf[i].end()),pf[i].end());
			if(ma.find(pf[i])==ma.end())
			{
				int cur = ma.size();
				ma[pf[i]]=cur;
			}
			a[i]=ma[pf[i]];
			cnt[a[i]]++;
		}
		//cnt[n-1] >= 0 at most
		int mx = 0;
		for(int i=0;i<n;i++)
		{
			//cerr<<i<<' '<<cnt[i]<<'\n';
			if(cnt[i]>0)
			{
				mx=i;
			}
			else break;
		}
		int sum = cnt[0];
		dp[0][cnt[0]-1] = fact[cnt[0]];
		for(int i = 0; i + 1 <= mx; i++)
		{
			for(int j = 0; j < sum; j++)
			{
				//there are sum + 1 blanks and j blanks will subtract runs by 1
				int q = cnt[i+1];
				ll v = dp[i][j];
				if(v!=0)
				{
					//cerr<<i<<' '<<j<<' '<<v<<'\n';
					for(int k = 0; k <= j + q - 1; k++)
					{
						//final value = k
						ll coeff = 0;
						for(int l = 1; l <= q; l++)
						{
							//cerr<<k<<' '<<l<<' '<<q-l+j-k<<' '<<2*l-j-q+k<<' '<<mult(choose(q-1,l-1),mult(choose(j,q-l+j-k),choose(sum+1-j,2*l-j-q+k)))<<'\n';
							add(coeff,mult(choose(q-1,l-1),mult(choose(j,q-l+j-k),choose(sum+1-j,2*l-j-q+k))));
						}
						coeff=mult(coeff,fact[q]);
						add(dp[i+1][k],mult(coeff,v));
						if(dp[i+1][k]<0) dp[i+1][k]+=MOD;
					}
				}
			}
			sum+=cnt[i+1];
		}
		ll ans = dp[mx][0];
		if(ans!=res&&DEBUG)
		{
			freopen("onthebench.out","w",stdout);
			cout<<n<<'\n';
			for(int i=0;i<n;i++)
			{
				cout<<ori[i]<<' ';
			}
			cout<<'\n';
			cerr<<"NAIVE : "<<res<<'\n';
			cerr<<"FAST : "<<ans<<'\n';
			return 0;
		}
		if(!DEBUG) 
		{
			cout<<ans<<'\n';
			return 0;
		}
		else cerr<<"Case #"<<cc<<" complete\n";
	}
}