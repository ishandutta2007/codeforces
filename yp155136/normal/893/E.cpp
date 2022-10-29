#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <stack>
using namespace std;

#define LL   long long
#define ld   long double
#define pii  pair<int,int>
#define pLL  pair<LL,LL>
#define vint vector<int>
#define vLL  vector<LL>

#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define MP make_pair
#define PB push_back

#define Si(x) scanf("%d",&(x));
#define Sii(x,y) scanf("%d %d",&(x),&(y));
#define Siii(x,y,z) scanf("%d %d %d",&(x),&(y),&(z));
#define Siiii(x,y,z,w) scanf("%d %d %d %d",&(x),&(y),&(z),&(w));
#define Siiiii(x,y,z,w,a) scanf("%d %d %d %d %d",&(x),&(y),&(z),&(w),&(a));
#define Siiiiii(x,y,z,w,a,b) scanf("%d %d %d %d %d %d",&(x),&(y),&(z),&(w),&(a),&(b));
#define SL(x) scanf("%lld",&(x));
#define SLL(x,y) scanf("%lld %lld",&(x),&(y));
#define SLLL(x,y,z) scanf("%lld %lld %lld",&(x),&(y),&(z));
#define SLLLL(x,y,z,w) scanf("%lld %lld %lld %lld",&(x),&(y),&(z),&(w));
#define SLLLLL(x,y,z,w,a) scanf("%lld %lld %lld %lld %lld",&(x),&(y),&(z),&(w),&(a));
#define SLLLLLL(x,y,z,w,a,b) scanf("%lld %lld %lld %lld %lld %lld",&(x),&(y),&(z),&(w),&(a),&(b));

#define Pi(x) printf("%d\n",(x));
#define Pii(x,y) printf("%d %d\n",(x),(y));
#define Piii(x,y,z) printf("%d %d %d\n",(x),(y),(z));
#define Piiii(x,y,z,w) printf("%d %d %d %d\n",(x),(y),(z),(w));
#define Piiiii(a,b,c,d,e) printf("%d %d %d %d %d\n",(a),(b),(c),(d),(e));
#define Piiiiii(a,b,c,d,e,f) printf("%d %d %d %d %d %d\n",(a),(b),(c),(d),(e),(f));
#define PL(x) printf("%lld\n",(x)*1LL);
#define PLL(x,y) printf("%lld %lld\n",(x)*1LL,(y)*1LL);
#define PLLL(x,y,z) printf("%lld %lld %lld\n",(x)*1LL,(y)*1LL,(z)*1LL);
#define PLLLL(x,y,z,w) printf("%lld %lld %lld %lld\n",(x)*1LL,(y)*1LL,(z)*1LL,(w)*1LL);
#define PLLLLL(a,b,c,d,e) printf("%lld %lld %lld %lld %lld\n",(a),(b),(c),(d),(e));
#define PLLLLLL(a,b,c,d,e,f) printf("%lld %lld %lld %lld %lld %lld\n",(a),(b),(c),(d),(e),(f));

#define Pi1(x) printf("%d",  (x));
#define PiL(x) printf("%lld",(x));
#define Pspace putchar(' ');
#define Pendl  puts("");

#define MEM0(x) memset( (x), 0, sizeof( (x) ) )
#define MEM1(x) memset( (x),-1, sizeof( (x) ) )
#define REP1(i,n)  for (int i = 1; (n) >= i ; ++i)
#define REP0(i,n)  for (int i = 0; (n) >  i ; ++i)
#define REP(L,R,k) for (int i = (L); (R) >= i; i+= (k) )

int myRnd(int L,int R) {
    return abs(( (rand()<<15)|rand() ) ) % (R-L+1) + L;
}

const LL mod = 1e9+7;

LL pow(LL a,LL n,LL mod=mod) {
    if (n==0) return 1;
    else if (n==1) return a%mod;
    LL ret=pow(a,n/2);
    ret*=ret;
    ret %= mod;
    if (n&1) ret*=a;
    return ret%mod;
}

//const LL mod = 1e9 + 7;
const int N = 1000100 + 6;

LL f[N];
LL rev_f[N];

LL C(int n,int m) {
    //cout<<"n = "<<n<<" , m = "<<m<<endl;
    if (m==0 || n==m) return 1;
    if (m>n) return 0;
    return f[n]*rev_f[m]%mod * rev_f[n-m]%mod;
}

LL H(int n,int m) {
    //cout<<"n = "<<n<<" , m = "<<m<<endl;
    return C(n+m-1,m);
}

#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <set>
#include <queue>
using namespace std;

#define SZ(x) ((int)(x).size())
const int MAX_N = 1e6 +6;
int prime[MAX_N];

void build() {
	prime[0] = prime[1] = 1;
	for (int i=2;MAX_N>i;i++) {
		if (prime[i] == 0) {
			prime[i]=i;
			for (long long j=i*1LL*i;MAX_N>j;j+=i) {
				prime[j] = i;
			}
		}
	}
}

vector<pii> get_prime_divisor(int x) {
	vector<pii> ret;
	while (x!=1) {
		pii tmp;
		tmp.first = prime[x];
		int cnt=0;
		int pp=prime[x];
		while (x%pp==0) {
			x/=pp;
			cnt++;
		}
		tmp.second = cnt;
		ret.emplace_back(tmp);
	}
	return ret;
}

int main () {
    build();
    srand(time(NULL));
    int n,k;
    f[0] = 1;
    rev_f[0] = 1;
    REP1(i,N)
    {
        f[i] = f[i-1]*i;
        f[i] %= mod;
        rev_f[i] = pow(f[i],mod-2,mod);
        //cout<<rev_f[i]*f[i]%mod<<endl;
    }
    int q;
    Si(q);
    REP0(qq,q)
    {
        int x,y;
        Sii(x,y);
        vector<pii> v=get_prime_divisor(x);
        LL ans=1;
        for (pii p:v) {
            ans *= H(y,p.second);
            ans %= mod;
            //cout<<p.second<<endl;
        }
        LL _=0;
        //cout<<ans<<endl;
        int n=y;
        PL(ans*pow(2,n-1,mod)%mod);
    }
}