#pragma comment(linker,"/STACK:102400000,102400000")
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <list>
#include <bitset>
#include <vector>
#include <cassert>
using namespace std;

#define I64d_OJ

#ifdef I64d_OJ
#define LL __int64
#endif // I64d_OJ
#ifndef I64d_OJ
#define LL long long
#endif // I64d_OJ


typedef unsigned LL ULL;
typedef unsigned uint;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<LL,LL> pLL;
typedef vector<int> vi;

inline LL read()
{
    LL x=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-')f=-f;ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1
#define ls id<<1
#define rs id<<1|1
#define MID(a,b) (((LL)(a)+(LL)(b))>>1)
#define maxx(a,b) ((a)<(b)?(b):(a))
#define minx(a,b) ((a)<(b)?(a):(b))
#define absx(a) ((a)<0?-(a):(a))
#define MK(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define lowbit(x) ((x)&-(x))

template< typename T >
inline void swapt(T &a,T &b) {T c=a;a=b;b=c;}
template< typename T >
inline void Max(T &a, T b) {if(a<b) a=b;}
template< typename T >
inline void Min(T &a, T b) {if(b<a) a=b;}
template< typename T >
inline T maxt(T a,T b) {if(a<b) return b; else return a;}
template< typename T >
inline T mint(T a,T b) {if(a<b) return a; else return b;}

LL gcd(LL a,LL b) {if(!b) return a; else return gcd(b,a%b);}

const double pi=(double) acos(-1.0);
const double eps=(double) 1e-8;
const int INF=(int) 0x3f3f3f3f;
const LL  LINF=(ULL)(-1) >> 2;
const int SINF=(uint) ~0U>>1;
const double DINF=(double) 1e50;
const int MOD=(int) 1e9+7;
const int maxn=(int) 1000000+20;
const int maxm=(int) 500000+20;

//------------------------------------

int hs[65536<<4];
int a[maxn];
int n,m,k;
LL ans[maxn];

int bk_size;
struct BK
{
    int bn,l,r;
    int id;
    BK() {}
    BK(int _l,int _r,int _id):l(_l),r(_r),id(_id) {bn=_l/bk_size;}
    bool operator < (const BK &t) const
    {
        if(bn==t.bn) return r<t.r;
        else return bn<t.bn;
    }
}B[maxn];

void make()
{
    LL cnt=0;
    int l=0,r=-1;
    for(int i=0;i<m;i++)
    {
        int x=B[i].l, y=B[i].r;
        while(r<y)
        {
            r++;
            cnt+=hs[a[r]^k];
            hs[a[r]]++;
        }
        while(l>x)
        {
            l--;
            cnt+=hs[a[l]^k];
            hs[a[l]]++;
        }
        while(r>y)
        {
            hs[a[r]]--;
            cnt-=hs[a[r]^k];
            r--;
        }
        while(l<x)
        {
            hs[a[l]]--;
            cnt-=hs[a[l]^k];
            l++;
        }
        ans[B[i].id]=cnt;
    }
}

inline void init()
{
    bk_size=sqrt(1.0*n);
    memset(hs,0,sizeof(hs));
}

void work()
{
    n=read(), m=read(), k=read();
    init();
    for(int i=1;i<=n;i++) a[i]=read(), a[i]^=a[i-1];
//    for(int i=1;i<=n;i++) printf("%d ",a[i]);
//    printf("\n");
    for(int i=0;i<m;i++)
    {
        int x=read(), y=read();
        B[i]=BK(x-1,y,i);
    }
    sort(B,B+m);
    make();
    for(int i=0;i<m;i++)
        printf("%I64d\n",ans[i]);

}


//------------------------------------

//#define yukihana0416
int main()
{
#ifdef yukihana0416
freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif // yukihana0416
    work();
    return 0;
}