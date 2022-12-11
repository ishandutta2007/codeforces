#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <assert.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <bitset>
#include <vector>
using namespace std;

#define LL __int64

#define fi first
#define se second
#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1
#define ls id<<1
#define rs id<<1|1
#define MID(a,b) (((a)+(b))>>1)
#define maxx(a,b) ((a)<(b)?(b):(a))
#define minx(a,b) ((a)<(b)?(a):(b))
#define absx(a) ((a)<0?-(a):(a))
#define mk(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define itr iterator
#define lowbit(x) ((x)&-(x))

typedef unsigned LL ULL;
typedef unsigned uint;
typedef map<int,int> mii;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<LL,LL> pLL;

template< typename T > inline void read(T &x) {
    static bool fr_f; static char fr_ch;
    fr_f=0; x=0; fr_ch=getchar();
    while(fr_ch<'0' || fr_ch>'9') {if(fr_ch=='-') fr_f=1; fr_ch=getchar();}
    while(fr_ch>='0' && fr_ch<='9') {x=(x<<1)+(x<<3)+fr_ch-'0'; fr_ch=getchar();}
    if(fr_f) x=-x;
}

template< typename T > inline void Max(T &a, T b) {if(a<b) a=b;}
template< typename T > inline void Min(T &a, T b) {if(b<a) a=b;}
template< typename T > inline T Abs(T a) {if(a<0) return -a; else return a;}

const double pi   =    acos(-1.0) ;
const int MOD     = (int)1e9+7 ;
const int INF     = (int)0x3f3f3f3f ;
const LL  LINF    = (LL)INF<<32|INF ;
const int SINF    = (uint)(-1)>>1 ;
const LL  SLINF   = (ULL)(-1)>>1 ;
const double DINF = 1e50 ;
const double eps  = 1e-8 ;
const int maxn    = (int) 2e5+20 ;
const int maxm    = (int) 25000+20 ;
const int maxk    = (int) 1000+20 ;

inline int sig(double x) {return x<-eps?-1:x>eps;}
inline LL fp(LL a,LL n,LL p) {LL res=1; for(;n;n>>=1,a=a*a%p) if(n&1) res=res*a%p; return res;}
template<typename T>inline T gcd(T a,T b) {for(T c;b;c=a%b,a=b,b=c); return a;}

//--------------------start--------------------

const double pai=pi;
struct cpx{
    double r,i;
    cpx (double r=0.0,double i=0.0):r(r),i(i){}
    cpx operator+(const cpx &t)const {return cpx(r+t.r,i+t.i);}
    cpx operator-(const cpx &t)const {return cpx(r-t.r,i-t.i);}
    cpx operator*(const cpx &t)const {return cpx(r*t.r-i*t.i,r*t.i+i*t.r);}
};
void FFT(cpx y[],int n,int rev){
    for (int i=1,j,k,t;i<n;i++){
        for (j=0,k=n>>1,t=i;k;k>>=1,t>>=1) j=j<<1|t&1;
        if (i<j) swap(y[i],y[j]);
    }
    for (int s=2,ds=1;s<=n;ds=s,s<<=1){
        cpx wn(cos(rev*2*pai/s),sin(rev*2*pai/s)),w(1,0),t;
        for (int k=0;k<ds;k++,w=w*wn)
            for (int i=k;i<n;i+=s) y[i+ds]=y[i]-(t=w*y[i+ds]),y[i]=y[i]+t;
    }
    if (rev==-1) for (int i=0;i<n;i++) y[i].r/=n;
}

int Sn,Tn,k;
char S[maxn],T[maxn];
bool Fs[maxn],Ft[maxn];

int sum[maxn];
inline int Sum(int x)
{
    if(x<0) return 0;
    if(x>=Sn) return sum[Sn-1];
    return sum[x];
}

int ans[maxn<<2];

cpx A[maxn<<2],B[maxn<<2];

int flen;
inline void calc()
{
    reverse(Ft,Ft+Tn);

    for(int i=0;i<flen;i++) A[i]=cpx(), B[i]=cpx();

    for(int i=0;i<Sn;i++) A[i].r=Fs[i];
    for(int i=0;i<Tn;i++) B[i].r=Ft[i];

    FFT(A,flen,1); FFT(B,flen,1);
    for(int i=0;i<flen;i++) A[i]=A[i]*B[i];
    FFT(A,flen,-1);

    for(int i=0;i<flen;i++) ans[i]+=(int)(A[i].r+0.5);
}

void work()
{
    read(Sn), read(Tn), read(k);
    gets(S), gets(T);

    for(flen=1;flen<=(Sn+Tn);flen<<=1);

//    for(int i=0;i<flen;i++) ans[i]=0;

    for(int p=0;p<4;p++)
    {
        char c;
        if(p==0) c='A';
        else if(p==1) c='T';
        else if(p==2) c='C';
        else c='G';

        for(int i=0;i<Tn;i++) Ft[i]=(c==T[i]);
        for(int i=0;i<Sn;i++) sum[i]=(c==S[i])+Sum(i-1);
        for(int i=0;i<Sn;i++) Fs[i]=Sum(i+k)-Sum(i-k-1);

        calc();
    }

    int last=0;
    for(int i=Tn-1;i<Tn+Sn-1;i++) last+=ans[i]==Tn;

    printf("%d\n",last);
}

//---------------------end---------------------

int main()
{
#ifdef yukihana0416
freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif // yukihana0416
    work();
    return 0;
}