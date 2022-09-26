#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
//#define mp make_pair
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

#define rep(i,n) for(ll (i)=0;(i)<(ll)(n);++(i))
#define reu(i,l,u) for(ll (i)=(ll)(l);(i)<(ll)(u);++(i))
#define each(it,o) for(auto it= (o).begin(); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define inrep ll t;cin>>t; while(t--)
#define sz(x) ll(x.size())
using namespace std;
 
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
typedef vector<pii > vpii;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll > vpll;
typedef vector<string> vs;

vpii factors;

struct Binos {
    ll MOD; ll P; ll E;
    const ll MAXN=100002;
    ll modPow ( ll b, ll e ) {
        ll r=1;
        while ( e ) {
            if ( e&1 ) r=r*b%MOD;
            b=b*b%MOD;
            e>>=1;
        }
        return r;
    }
    ll modInv ( ll x ) {
        return modPow ( x, (MOD/P)*(P-1)-1 );
    }
 
    vi facs ;
    vi invfacs;
 
    void initfacs() 
    {
        facs[0]=facs[1]=1;
        reu ( i,2,MAXN ) 
        {
			ll cur=i;
			while(cur%P==0) cur/=P;
			facs[i]= ( ll ) cur*facs[i-1]%MOD;
		}
        invfacs[MAXN-1]=modInv ( facs[MAXN-1] );
        for ( ll i=MAXN-1; i>=1; i-- ) 
        {
			ll cur=i;
			while(cur%P==0) cur/=P;
			invfacs[i-1]= ( ll ) cur*invfacs[i]%MOD;
		}
    }
 
    void init(ll m, ll e, ll MD) 
    {
		P=m;E=e;MOD=MD;facs.resize( MAXN );invfacs.resize( MAXN );
        initfacs();
    }
    ll bino ( ll n, ll k ) {
		//cerr<<(facs[n]*invfacs[n])%MOD<<'\n';
        return ( ll ) facs[n]*invfacs[n-k]%MOD*invfacs[k]%MOD;
    }
};



ll m; 
pair<ll,pii> xgcd ( ll a,ll b ) {
 
    ll r1=a,r2=b;
    ll s1=1,s2=0,t1=0,t2=1;
    while ( r2 ) {
        ll q=r1/r2;
        r1=r1%r2;
        swap ( r1,r2 );
        s1-=s2*q;
        t1-=t2*q;
        swap ( s1,s2 );
        swap ( t1,t2 );
    }
 
    return mp ( r1,mp ( s1,t1 ) );
 
}
ll modInv ( ll x, ll mod ) {
    auto r=xgcd ( x,mod );
    assert ( r.first==1 );
    if ( r.second.first<0 ) r.second.first+=mod;
    assert ( r.second.first>=0 );
    return r.second.first;
 
}
 
pii crt ( const vpii &vals ) {
    ll x=0,N=1;
    for ( pii p: vals ) N*=p.second;
    for ( pii p: vals ) {
        ll n=N/p.second;
        x+= ( ll ) p.first*n*modInv ( n,p.second ) %N;
        x%=N;
    }
    return mp ( x%N,N );
}
 
ll crt ( ll a, ll b, ll n1, ll n2 ) {
    auto res=xgcd ( n1,n2 );
    assert ( res.first==1 );
    ll m1,m2;
    tie ( m1,m2 ) =res.second;
    if ( m1<0 ) m1+=n2;
    if ( m2<0 ) m2+=n1;
    return ( ( ll ) a*m2*n2+ ( ll ) b*m1*n1 ) % ( n1*n2 );
}
vector<vi> gcds ( const vi &v1 ) {
    ll n=sz ( v1 );
    vector<vi> g ( n, vi ( n ) );
    rep ( i,n ) rep ( j,n ) g[i][j]=__gcd ( v1[i],v1[j] );
    return g;
}
void testCRT() {
    rep ( xx,10000 ) {
        ll n1=rand() %1000+2;
        ll n2=rand() %1000+2;
        ll g=__gcd ( n1,n2 );
//         cout<<n1<<" "<<n2<<" "<<g<<endl;
        n2/=g;
        n1/=g;
//         cout<<n1<<" "<<n2<< " "<<__gcd(n1,n2)<<endl;
        ll a1=rand() %n1,a2=rand() %n2;
        ll r=crt ( a1,a2,n1,n2 );
//          cout<<mp ( a1,a2 ) <<" "<<mp ( n1,n2 ) <<" "<<r<<" "<<mp ( r%n1, r%n2 ) <<endl;
        assert ( r%n1==a1 &&r%n2==a2 );
    }
    rep ( xx,1000 ) {
        ll f=rand() %5+1;
        vpii facs ( f );
        ll prod=1;
        rep ( i,f ) {
            facs[i].second=rand() %1000+2;
            rep ( j,i ) {
                ll g=__gcd ( facs[j].second, facs[i].second );
                facs[i].second/=g;
                facs[j].second/=g;
            }
 
 
        }
        rep ( i,f )  prod*=facs[i].second;
        if ( prod>INF ) continue;
        rep ( i,f ) {
            facs[i].first=rand() %facs[i].second;
        }
 
        vi vals ( f );
        rep ( i,f ) vals[i]=facs[i].second;
        pii p=crt ( facs );
        assert ( p.second=prod );
        rep ( i,f ) {
            assert ( p.first%facs[i].second==facs[i].first );
        }
 
 
    }
}
 
ll facprimep ( ll x, ll p ) {
    ll  cnt = 0;
    ll pp = p;
    while ( pp <= x ) {
        cnt += x / pp;
        pp *= p;
    }
    return cnt;
}

Binos B[21];//[21];

ll nCkPPnp ( ll n,ll  k,ll id ) {
	ll p=factors[id].fi; ll e=factors[id].se;
	/*
    ll pp=1;
    rep ( i,e ) pp*=p;
    ll r=n-k;
    vi facs = {1};
    ll acc = 1;
    reu ( i,1,pp ) {
        if ( i%p ) acc=acc*i%pp;
        facs.push_back ( acc );
    }
   ll t=1,b=1; ll neg=0, digs=0;
    while ( n ) {
        if ( acc != 1&& digs >= e ) {
            neg ^= n & 1;
            neg ^= r & 1;
            neg ^= k & 1;
        }
        t = ( t * facs[n % pp] ) % pp;
        b = ( b * facs[r % pp] ) % pp;
        b = ( b * facs[k % pp] ) % pp;
        n /= p;
        r /= p;
        k /= p;
        digs ++;
    }
    ll  res = ( t * modInv ( b, pp ) ) % pp;
    if ( p != 2 || e < 3 )
        if ( neg )
            res = pp - res;
    return res;
	*/
	//ll pp=1;
  //  rep ( i,e ) pp*=p;
	//Binos binom(p,e,pp);
	//cerr<<p<<' '<<e<<' '<<pp<<' '<<n<<' '<<k<<' '<<binom.bino(n,k)<<'\n';
	return B[id].bino(n,k);
}
 
ll nCkPP ( ll n, ll k, ll id) {
	ll p=factors[id].fi; ll pw=factors[id].se;
    if ( k>n ) return 0;
    ll ppp = facprimep ( n,p )-facprimep ( k,p )-facprimep ( n-k,p );
    if ( ppp>=pw ) return 0;
 
    ll  modpow = pw - ppp;
    ll pp=1;
    rep ( i,pw ) pp*=p;
    ll pp2=1;
    rep ( i,modpow ) pp2*=p;
    ll pp3=1;
    rep ( i,ppp ) pp3*=p;
    ll r = nCkPPnp ( n, k, id) % pp2; //check
//     cout<<"res"<<r<< " "<<ppp<<endl;
    return ( ( ll ) pp3* r ) %pp;
}
/*
struct Sieve {
    vi sieve;
    vi primes;
    Sieve ( ll maxn ) :sieve ( maxn,-1 ) {
 
        for ( ll i=2; i<maxn; i++ ) {
            if ( sieve[i]<0 ) {
                ll ind=primes.size();
                primes.push_back ( i );
                sieve[i]=ind;
 
                if ( i*i<maxn ) {
                    for ( ll n=i*i; n<maxn; n+=i )
                        sieve[n]=ind;
                }
            }
        }
    }
    bool isPrime ( ll x ) {
        if ( x<2 ) return 0;
        return x==primes[sieve[x]];
    }
    vi getUniqueIndizes ( ll n ) {
        vi res;
        while ( n>1 ) {
            ll ind=sieve[n];
            ll fac=primes[ind];
            res.push_back ( ind );
 
            while ( n%fac==0 ) n/=fac;
        }
        return res;
    }
    vi getIndizes ( ll n ) {
        vi res;
        while ( n>1 ) {
            res.push_back ( sieve[n] );
            n/=primes[sieve[n]];
        }
        return res;
    }
    vi getUniqueFactors ( ll n ) {
        vi res=getUniqueIndizes ( n );
        rep ( i,res.size() ) res[i]=primes[res[i]];
        return res;
 
    }
    vi getFactors ( ll n ) {
        vi res=getIndizes ( n );
        rep ( i,res.size() ) {
            res[i]=primes[res[i]];
            n/=res[i];
        }
        if ( n>1 ) res.push_back ( n );
        return res;
    }
    vpii getFactors2 ( ll n ) {
        vi f=getFactors ( n );
        vpii res;
        sort ( all ( f ) );
        ll b=-1;
        for ( ll ff:f ) {
            if ( ff==b ) res.back().second++;
            else {
                b=ff;
                res.push_back ( mp ( ff,1 ) );
            }
        }
        return res;
    }
};
*/
//Sieve s ( 2000000 );
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
		for (ll i = 1; i <= n; ++i) totient[i] = i;
		for (ll i = 2; i <= n; ++i)
		{
			if (totient[i] == i)
			{
				for (ll j = i; j <= n; j += i)
				{
					totient[j] -= totient[j] / i;
				}
			}
		}
	}
	
	void SieveSumDiv(ll n)
	{
		sumdiv.resize(n+1);
		for(ll i = 1; i <= n; ++i)
		{
			for(ll j = i; j <= n; j += i)
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
	
	void getpf(vpii &pf, ll n)
	{
		for(ll i = 0; primes[i]*primes[i] <= n; i++)
		{
			ll cnt = 0;
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
	void getDiv(vector<ll>& div, vector<ii>& pf, ll n, ll i)
	{
		//op++;
		ll x, k;
		if(i >= pf.size()) return ;
		x = n;
		for(k = 0; k <= pf[i].se; k++)
		{
			if(i==ll(pf.size())-1) div.pb(x);
			getDiv(div, pf, x, i + 1);
			x *= pf[i].fi;
		}
	}
};
NumberTheory nt;


ll nCk ( ll n, ll k) {
    vpii rems;
    ll id=0;
    for ( pii p: factors ) {
        ll r=nCkPP ( n,k,id++);
        ll mod=1;
        rep ( i,p.second ) mod*=p.first;
        rems.emplace_back ( r,mod );
    }
    return crt ( rems ).first;
}
 
ll nCk ( ll n, ll k, ll m ) {
    if ( m<2 ) return 0;
    if ( k>n ) return 0;
 
    return nCk ( n,k);
}

/*


struct Factor {
    std::vector<ull_t> ps, ks;
    ull_t size() const { return ps.size(); }
    
    Factor(ull_t x) {
        assert (0 < x);
        if (x % 2 == 0) {
            ull_t k = 0;
            do {
                x /= 2;
                k++;
            } while (x % 2 == 0);
            ps.push_back(2);
            ks.push_back(k);
        }
        for (ull_t p = 3; ; p += 2) {
            ull_t q = x / p, r = x % p;
            if (q < p)
                break;
            if (r)
                continue;
            ull_t k = 0;
            do {
                x /= p;
                k++;
            } while (x % p == 0);
            ps.push_back(p);
            ks.push_back(k);
 
        }
        if (x > 1) {
            ps.push_back(x);
            ks.push_back(1);
        }
    }
};

Factor mf(1);
static ull_t revmod(ull_t a, ull_t b)
{
    assert (0 < b);
    ull_t x = a % b, y = b, u = 1, v = 0;
    while (x > 0) {
        ull_t q = y / x, r = y % x;
        ull_t w = q * (ull64_t) u % b;
        w = v >= w ? v - w : v + (b - w);
        y = x; v = u;
        x = r; u = w;
    }
    assert (y == 1);
    return v;
}
 
 
static ull_t binmod1(ull_t a, ull64_t b, ull_t m, const Factor &mf)
{
    const ull_t l = mf.size(); 
    std::vector<ull_t> ks(l, 0);
    std::vector<ull64_t> ts(a, 0);
 
    for (ull_t i = 0; i < a; i++)
        ts[i] = i + 1;
    for (ull_t i = 0; i < l; i++) {
        ull_t p = mf.ps[i], k = 0;
        for (ull_t q = p - 1; q < a; q += p) {
            ull_t x = ts[q];
            while (x % p == 0) {
                x /= p;
                k++;
            }
            ts[q] = x;
        }
        ks[i] = k;
    }
    ull_t ra = 1;
    for (ull_t i = 0; i < a; i++)
        ra = ra * ts[i] % m;
 
    for (ull_t i = 0; i < a; i++)
        ts[i] = b + i + 1;
    for (ull_t i = 0; i < l; i++) {
        ull_t p = mf.ps[i], k = ks[i];
        for (ull_t q = p - 1 - b % p; 0 < k && q < a; q += p) {
            ull64_t x = ts[q];
            while (k > 0 && x % p == 0) {
                x /= p;
                k--;
            }
            ts[q] = x;
        }
        assert (k == 0);
    }
    ull_t rb = 1;
    for (ull_t i = 0; i < a; i++)
        rb = rb * (ts[i] % m) % m;
 
    return revmod(ra, m) * (ull64_t) rb % m;
}
 
static ull_t upow(ull_t x, ull_t n)
{
    ull_t a = 1, b = x;
    for (ull_t k = n; k; k >>= 1) {
        if (k & 1)
            a *= b;
        b *= b;
    } 
    return a;
}
 
static ull64_t factpow(ull64_t n, ull_t p)
{
    ull64_t res = 0;
    while (n >= p) {
        n /= p;
        res += n;
    }
    return res;
}
 
static ull_t binmodpk1(ull64_t a, ull_t p, ull_t pk, const ull_v &ms)
{
    ull_t res = 1;
    for (ull64_t v = a; v; v /= p) {
        ull64_t q = v / pk;
        ull_t r = v % pk;
        res = res * (ull64_t) ms[r] % pk;
        if (q % 2 != 0 && ms[pk - 1] != 1)
            res = pk - res;
    }
    return res;
}
 
static ull_t binmodpk(ull64_t a, ull64_t b, ull_t p, ull_t k)
{
    ull64_t c = a + b;
//    fprllf(stderr, "p=%u, k=%u \n", p, k);
    ull64_t ak = factpow(a, p);
    ull64_t bk = factpow(b, p);
    ull64_t ck = factpow(c, p);
//    fprllf(stderr, "ak=%llu, bk=%llu, ck=%llu \n", ak, bk, ck);
    assert (ck >= ak && ck - ak >= bk);
    ull_t fk = ck - ak - bk, rk = k - fk;
//    fprllf(stderr, "fk=%u, rk=%u \n", fk, rk);
    if (fk >= k)
        return 0;
    ull_t rp = upow(p, rk);
//    fprllf(stderr, "rp=%u \n", rp);
    std::vector<ull_t> ms(rp);
    for (ull_t i = 0; i < rp; i++)
        ms[i] = i;
    for (ull_t i = 0; i < rp; i += p)
        ms[i] = 1;
    for (ull_t i = 1; i < rp; i++)
        ms[i] = ms[i - 1] * (ull64_t) ms[i] % rp;
 
    ull_t ra = binmodpk1(a, p, rp, ms);
    ull_t rb = binmodpk1(b, p, rp, ms);
    ull_t rc = binmodpk1(c, p, rp, ms);
 
    ull_t rd = revmod(ra * (ull64_t) rb % rp, rp);
    ull_t res = rc * (ull64_t) rd % rp;
    return res * upow(p, fk);
}
 
static ull_t binmod(ull64_t a, ull64_t b, ull_t m)
{
    if (b < a)
        std::swap(a, b);
//    fprllf(stderr, "a=%llu, b=%llu \n", a, b);
    
    if (a <= M1) {
        ull64_t c = a + b;
        switch (a) {
        case 0:
            return 1;
        case 1:
            return c % m;
#if 0
        case 2:
            if (c & 1) {
                return (c % m) * (ull64_t) (c / 2 % m) % m;
            } else {
                return (c / 2 % m) * (ull64_t) ((c - 1) % m) % m; 
            }
#endif
        default:
            return binmod1(a, b, m, mf);
        }
    }
    
    ull_t rv = 0, rm = 1;
    for (ull_t i = 0; i < mf.size(); i++) {
        ull_t pi = mf.ps[i], ki = mf.ks[i];
        ull_t im = upow(pi, ki), iv = binmodpk(a, b, pi, ki);
        ull_t ia = rm * revmod(rm, im), ra = rm * im - ia + 1;
        rm *= im;
        rv = (rv * (ull64_t) ra + iv * (ull64_t) ia) % rm;
    }
    
    return rv;
}
*/
ll dp[5001][5001];


ll add(ll a, ll b)
{
	a+=b;
	while(a>=m) a-=m;
	return a;
}

const ll C=0;

ll choose(ll a, ll b)
{
	if(b<0) return 0;
	if(a<b) return 0;
	if(b==0) return 1;
	if(a<=C&&b<=C)
	{
		if(dp[a][b]!=-1) return dp[a][b];
		return (dp[a][b]=add(choose(a-1,b),choose(a-1,b-1)));
	}
	return nCk(a,b,m);
	//return Binomial(a,b,m);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	nt.Sieve(100001);
	ll N; ll l,r; cin>>N>>m>>l>>r;
	nt.getpf(factors,m);
	for(ll i=0;i<factors.size();i++)
	{
		ll pp=1;
		for(ll j=0;j<factors[i].se;j++) pp*=factors[i].fi;
		B[i].init(factors[i].fi,factors[i].se,pp);
	}	
	//mf=Factor(m);
	//cout<<choose(5,3)<<endl;
	memset(dp,-1,sizeof(dp));
	ll ans=0;
	for(ll n=0;n<=N;n++)
	{
		if(n-l<0) continue;
		ans=(ans+((choose(n,(n-l)/2) + m - choose(n,(max(n-r,0LL)+1)/2 - 1))%m * choose(N, n))%m)%m;
		if(ans<0) ans+=m;
		//cerr<<n<<endl;
	}
	cout<<ans<<'\n';
}