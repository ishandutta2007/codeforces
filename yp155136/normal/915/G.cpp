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
#include <set>
#include <map>
#include <cassert>
using namespace std;

#define LL   long long
#define ld   long double
#define pii  pair<int,int>
#define pLL  pair<LL,LL>
#define vint vector<int>
#define vLL  vector<LL>
#define vpii vector<pii>

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
#define PLLLLL(a,b,c,d,e) printf("%lld %lld %lld %lld %lld\n",(a)*1LL,(b)*1LL,(c)*1LL,(d)*1LL,(e)*1LL);
#define PLLLLLL(a,b,c,d,e,f) printf("%lld %lld %lld %lld %lld %lld\n",(a)*1LL,(b)*1LL,(c)*1LL,(d)*1LL,(e)*1LL,(f)*1LL);

#define Pi1(x) printf("%d",  (x));
#define PL1(x) printf("%lld",(x));
#define Pspace putchar(' ');
#define Pendl  puts("");

#define MEM0(x) memset( (x), 0, sizeof( (x) ) )
#define MEM1(x) memset( (x),-1, sizeof( (x) ) )
#define REP1(i,n)  for (int i = 1; (n) >= i ; ++i)
#define REP0(i,n)  for (int i = 0; (n) >  i ; ++i)

int myRnd() {
    return abs(  ((rand()<<15) ^ rand()) );
}

int myRnd(int L,int R) {
    return abs(( (rand()<<15)^rand() ) ) % (R-L+1) + L;
}

void Parr(int *arr,int L,int R) {
    for (int i=L;R>=i;i++) {
        printf("%d%c",arr[i]," \n"[i==R]);
    }
}

void Pvec(vint v) {
    for (int i=0;SZ(v)>i;i++) {
        printf("%d%c",v[i]," \n"[i==SZ(v)-1]);
    }
}

void Sarr(int *arr,int L,int R) {
    for (int i=L;R>=i;i++)
    {
        Si(arr[i]);
    }
}

const int N = 2e6 + 6;
const LL mod = 1e9 + 7;

int ppow(int a,int n,int mod)
{
    if (n==0) return 1;
    else if (n==1) return a;
    int ret = 1;
    int tmp = a;
    while (n)
    {
        if (n&1) ret = ret * 1LL * tmp % mod;
        tmp = tmp * 1LL * tmp % mod;
        n >>= 1;
    }
    return ret;
}

int pow_x[N];
int ans[N];
int p[N];
int a[N];
int u[N];
int np;

int cnt[N];

LL val(LL x)
{
    return (x%mod+mod)%mod;
}

void build_a()
{
    for (int i=2;N>i;i++)
    {
        if (a[i] == 0)
        {
            a[i] = i;
            u[i] = 1;
            p[np++] = i;
        }
        for (int j=0;N>i*p[j];j++)
        {
            int tmp = i*p[j];
            a[tmp] = p[j];
            if (a[i] == p[j] || u[i] == 0) u[tmp] = 0;
            else u[tmp] = -u[i];
            if (a[i] == p[j]) break;
        }
    }
}

/*
const int MAX_N = 2e6 +6;
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
*/

vector<pii> get_prime_divisor(int x) {
	vector<pii> ret;
	while (x!=1) {
		pii tmp;
		tmp.first = a[x];
		int cnt=0;
		int pp=a[x];
		while (x%pp==0) {
			x/=pp;
			cnt++;
		}
		tmp.second = cnt;
		ret.emplace_back(tmp);
	}
	return ret;
}

vector<int> get_divisor(int x) {
	vector<pii> prime_divisor=get_prime_divisor(x);
	int sz=SZ(prime_divisor);
	queue<pii> que;
	que.push({1,0});
	vector<int> ret;
	while (!que.empty()) {
		pii p=que.front();
		que.pop();
		if (p.second == sz) {
			ret.emplace_back(p.first);
			continue;
		}
		int t=1;
		for (int i=0;prime_divisor[p.second].second>=i;i++) {
			que.push(make_pair(p.first*t,p.second+1));
			t*=prime_divisor[p.second].first;
		}
	}
	return ret;
}

int main () {
    srand(time(NULL));
    //build();
    build_a();
    int n,k;
    Sii(n,k);
    for (int i=0;N>i;i++)
    {
        pow_x[i] = ppow(i,n,mod);
    }
    LL now = 0;
    ans[1] = 1;
    for (int i=2;k>=i;i++)
    {
        vint ret = get_divisor(i);
        for (int i:ret)
        {
            if(i==1) continue;
            now -= u[i]*pow_x[ cnt[i] ];
            cnt[i]++;
            now += u[i]*pow_x[ cnt[i] ];
            now = val(now);
        }
        ans[i] = val( pow_x[i]-now );
    }
    LL _ = 0;
    REP1(i,k)
    {
        //ans[i] %= mod;
        _ += (ans[i]^i);
        //_ %= mod;
    }
    PL(_%mod);
}