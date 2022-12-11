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
const int maxn=(int) 1e6+15;
const int maxm=(int) 3000+15;

LL gcd(LL x,LL y) {LL t; while(y) t=x%y,x=y,y=t; return absx(x);}
inline int sig(double x) {return x<-eps?-1:x>eps;}

//--------------start------------------

int n,m,tot;
int fa[maxn],sz[maxn];
int *a[maxn];
map<int,int> mp;
int buf[maxn],bnt;
pii pp[maxn];
int r[maxn],c[maxn];
int num[maxn];

int FA(int x)
{
    if(x==fa[x]) return x;
    return fa[x]=FA(fa[x]);
}

int uni(int x,int y)
{
    int fx=FA(x), fy=FA(y);
    if(sz[fx]<sz[fy]) swapt(fx,fy);
    fa[fy]=fx;
    sz[fx]+=sz[fy];
}

void work()
{
    n=read(), m=read();
    tot=0;

    for(int i=0;i<n;i++)
    {
        a[i]=(int *) malloc(sizeof(int)*m);
        for(int j=0;j<m;j++)
        {
            a[i][j]=read();
            fa[tot]=tot; sz[tot]=1;
            pp[tot]=MK(a[i][j],i*m+j);
            tot++;
        }
    }


    for(int i=0;i<n;i++)
    {
        mp.clear();
        for(int j=0;j<m;j++)
        {
            if(mp.find(a[i][j])!=mp.end())
            {
                uni(i*m+j,mp[a[i][j]]);
            }
            mp[a[i][j]]=i*m+j;
        }
    }

    for(int j=0;j<m;j++)
    {
        mp.clear();
        for(int i=0;i<n;i++)
        {
            if(mp.find(a[i][j])!=mp.end())
            {
                uni(i*m+j,mp[a[i][j]]);
            }
            mp[a[i][j]]=i*m+j;
        }
    }

    sort(pp,pp+tot);
    bnt=0;
    for(int i=0;i<tot;i++)
    {
        int tmp=pp[i].se;
        int mx=maxt(r[tmp/m],c[tmp%m])+1;
        int ff=FA(tmp);
        Max(num[ff],mx);

        buf[bnt++]=tmp;
        if(i==tot-1 || pp[i].fi!=pp[i+1].fi)
        {
            for(int j=0;j<bnt;j++)
            {
                tmp=buf[j];
                ff=FA(tmp);
                r[tmp/m]=num[ff];
                c[tmp%m]=num[ff];
            }
            bnt=0;
        }
    }

    for(int i=0;i<n;i++)
    {
        bool flag=0;
        for(int j=0;j<m;j++)
        {
            if(flag) putchar(' ');
            else flag=1;
            printf("%d",num[FA(i*m+j)]);
        }
        putchar('\n');
    }
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