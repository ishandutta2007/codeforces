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

#define LL long long

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
    while(fr_ch<'0' || '9'<fr_ch) {if(fr_ch=='-') fr_f=1; fr_ch=getchar();}
    while('0'<=fr_ch && fr_ch<='9') {x=(x<<1)+(x<<3)+fr_ch-'0'; fr_ch=getchar();}
    if(fr_f) x=-x;
}

template< typename T > inline void Max (T &a, T b) {if(a<b) a=b;}
template< typename T > inline void Min (T &a, T b) {if(b<a) a=b;}
template< typename T > inline void Swap(T &a, T &b) {T c=a;a=b;b=c;}
template< typename T > inline T Abs(T a) {if(a<0) return -a; else return a;}

const double   pi = acos(-1.0) ;
const int     MOD = (int)1e9+7 ;
const int     INF = (int)0x3f3f3f3f ;
const LL     LINF = (LL)INF<<32|INF ;
const int    SINF = (uint)(-1)>>1 ;
const LL    SLINF = (ULL)(-1)>>1 ;
const double DINF = 1e50 ;
const double  eps = 1e-5 ;
const int    maxn = (int) 3e5+20 ;
const int    maxm = (int) 25000+20 ;
const int    maxk = (int) 1000+20 ;

inline int sig(double x) {return x<-eps?-1:x>eps;}
inline LL fp(LL a,LL n,LL p) {LL res=1; for(;n;n>>=1,a=a*a%p) if(n&1) res=res*a%p; return res;}
template<typename T>inline T gcd(T a,T b) {for(T c;b;c=a%b,a=b,b=c); return a;}

//--------------------start--------------------

LL exgcd(LL a,LL b,LL &x,LL &y)
{
    if(a==0 && b==0) return -1;
    if(b==0) return x=1,y=0,a;
    LL temp=exgcd(b,a%b,y,x);
    return y-=a/b*x,temp;
}

void gao(LL i,LL j,LL p,LL q,LL x,LL y,LL &n)
{
//    LL x,y; exgcd(p,q,x,y);
//    cout <<"ex: " <<x <<" " <<y <<endl;
    x*=(i-j);
    x%=q;
    n=i-x*p;
//    cout <<i <<" " <<x <<" " <<p <<endl;
    n%=p*q;
    if(n<0) n+=p*q;
}

void work()
{
    LL a,b,p,x;
    cin >>a >>b >>p >>x;

    LL tx,ty; exgcd(p-1,p,tx,ty);
    LL inv=fp(a,p-2,p);

    LL res=0;
    for(int i=0;i<p-1;i++)
    {
        LL j;
        if(i==0)
        {
            j=b;
        }
        else
        {
            j=j*inv%p;
        }

        if(i==j)
        {
            if(x>=i) res+=(x-i)/((p-1)*p)+1;
        }
        else
        {
            LL n; gao(i,j,p-1,p,tx,ty,n);
//            cout <<n <<endl;
            if(x>=n)
            {
                res+=(x-n)/((p-1)*p)+1;
            }
        }
    }
    cout <<res <<endl;
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