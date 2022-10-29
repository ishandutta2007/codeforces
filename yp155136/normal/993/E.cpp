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
#include <iomanip>
#include <bitset>
using namespace std;

typedef long long      LL;
typedef double    ld;
typedef pair<int,int>  pii;
typedef pair<LL,LL>    pLL;
typedef vector<int>    vint;
typedef vector<LL>     vLL;
typedef vector<pii>    vpii;
typedef vector<pLL>    vpLL;

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

#define IOS ios::sync_with_stdio(0); cin.tie(0);

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

const int N = 2e5 + 6;
const int INF = 0x3f3f3f3f;
const int mod = 1000000000 + 7;

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 262144;
typedef complex<ld> cplx;
const ld PI = acos(-1);
const cplx I(0,1);
cplx omega[MAXN+1];
void pre_fft() {
	for (int i=0;i<=MAXN;i++) {
		omega[i] = exp(i*2*PI/MAXN*I);
	}
}

void fft(int n,cplx a[],bool inv=false) {
	int basic=MAXN/n;
	int theta=basic;
	for (int m=n;m>=2;m>>=1) {
		int mh=m>>1;
		for (int i=0;i<mh;i++) {
			cplx w=omega[inv?MAXN-(i*theta%MAXN):i*theta%MAXN];
			for (int j=i;j<n;j+=m) {
				int k=j+mh;
				cplx x=a[j]-a[k];
				a[j] += a[k];
				a[k] = w*x;
			}
		}
		theta = (theta*2)%MAXN;
	}
	int i=0;
	for (int j=1;j<n-1;++j) {
		for (int k=n>>1;k>(i^=k);k>>=1) ;
		if (j<i) swap(a[i],a[j]);
	}
	if (inv) {
		for (int i=0;i<n;i++) a[i]/=n;
	}
}

cplx a[MAXN],b[MAXN],c[MAXN];

//how to use :
/*
pre_fft();
fft(n,a);
pre_fft();
fft(n,b);
for (int i=0;n>i;i++) {
	c[i] = a[i]*b[i];
}
pre_fft();
fft(n,c,1);
*/

int aa[N];

LL ans[N];

LL aaa[N],bbb[N];

void dc(int L,int R)
{
    //cout << "L = " << L << " , R = " << R << endl;
    if (L > R) return;
    int mid = (L+R)>>1;
    int n = R-L+1;
    n = (n+5)/2;
    int nn = 1;
    while (nn < n) nn*=2;
    nn*=2;
    //cout << "nn = " << nn << " , L = " << L << " , R = " << R << endl;
    //cout << "nn = " << nn << endl;
    nn = min(nn,MAXN);
    for (int i=0;nn>i;i++)
    {
        a[i] = b[i] = cplx(0,0);
    }
    int now=0;
    for (int i=mid;i>=L;i--)
    {
        now += (aa[i]);
        a[now] += cplx(1,0);
    }
    now = 0;
    for (int i=mid;R>=i;i++)
    {
        now += aa[i];
        b[now] += cplx(1,0);
    }
    //cout << "ready fft " << endl;
    fft(nn,a);
    fft(nn,b);
    for (int i=0;nn>i;i++) {
        c[i] = a[i]*b[i];
    }
    fft(nn,c,1);
    for (int i=0;nn>i;i++)
    {
        //cout << "i = " << i << " , mid = " << mid << " , C = " << LL(c[i].real() + 1e-5) << endl;
        if (aa[mid])
        {
            if (i == 0) continue;
            ans[i-1] += LL(c[i].real()+1e-5);
            continue;
        }
        ans[i] += LL(c[i].real()+1e-5);

    }
    dc(L,mid-1);
    dc(mid+1,R);
}

int main () {
    srand(time(NULL));
    pre_fft();
    int n,x;
    Sii(n,x);
    REP1(i,n)
    {
        int y;
        Si(y);
        if (y < x) aa[i] = 1;
    }
    dc(1,n);
    for (int i=0;n>=i;i++)
    {
        if (i) printf(" ");
        printf("%lld",ans[i]);
    }
    puts("");
}