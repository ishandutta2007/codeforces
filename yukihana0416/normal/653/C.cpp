#pragma comment(linker,"/STACK:102400000,102400000")
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <assert.h>
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

const double pi=(double) acos(-1.0);
const double eps=(double) 1e-10;
const int INF=(int) 0x3f3f3f3f;
const LL  LINF=(ULL)(-1) >> 2;
const int SINF=(uint) ~0U>>1;
const double DINF=(double) 1e50;
const int MOD=(int) 1e9+7;
const int maxn=(int) 2e5+15;
const int maxm=(int) 124750+15;

LL gcd(LL x,LL y) {LL t; while(y) t=x%y,x=y,y=t; return absx(x);}
inline int sig(double x) {return x<-eps?-1:x>eps;}

//--------------start------------------

int n;
int a[maxn];
bool tag[maxn];

bool check(int pos)
{
    if(pos&1) return a[pos-1]>a[pos] && a[pos]<a[pos+1];
    else return a[pos-1]<a[pos] && a[pos]>a[pos+1];
}

void work()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
    }

    a[0]=INF; a[n+1] = n%2==0 ? 0 : INF ;
    for(int i=1;i<=n;i++) tag[i]=!check(i);

    int cnt=0;
    for(int i=1;i<=n;i++) cnt+=tag[i];

    if(cnt>6)
    {
        puts("0");
        return ;
    }

    int pp[8],cc=0;
    for(int i=1;i<=n;i++) if(tag[i])
    {
        pp[cc++]=i;
    }
    int ans=0;

    int spj[16],sc=0;
    for(int i=0;i<cc;i++)
    {
        if(pp[i]!=1) spj[sc++]=pp[i]-1;
        if(pp[i]!=n) spj[sc++]=pp[i]+1;
    }
    sort(spj,spj+sc);
    sc=unique(spj,spj+sc)-spj;

    for(int i=1;i<=n;i++)
    {
        if(tag[i]) continue;
        for(int j=0;j<cc;j++)
        {
            swap(a[i],a[pp[j]]);
            int ok=check(i);
            for(int k=0;k<cc;k++)
                ok&=check(pp[k]);

            for(int k=0;k<sc;k++)
                ok&=check(spj[k]);

            if(ok) ans++;

            swap(a[i],a[pp[j]]);
        }
    }
    for(int i=0;i<cc;i++)
        for(int j=0;j<i;j++)
        {
            swap(a[pp[i]],a[pp[j]]);
            int ok=1;
            for(int k=0;k<cc;k++)
                ok&=check(pp[k]);

            for(int k=0;k<sc;k++)
                ok&=check(spj[k]);

            if(ok) ans++;
            swap(a[pp[i]],a[pp[j]]);
        }
    cout <<ans <<endl;
}


//--------------end------------------

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