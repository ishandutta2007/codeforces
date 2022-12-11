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
#include <list>
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
    bool f=0; char ch=getchar(); x=0;
    while(ch<'0' || ch>'9') {if(ch=='-') f=1; ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    if(f) x=-x;
}

template< typename T > inline void Max(T &a, T b) {if(a<b) a=b;}
template< typename T > inline void Min(T &a, T b) {if(b<a) a=b;}
template< typename T > inline T Abs(T a) {if(a<0) return -a; else return a;}

const double pi=(double) acos(-1.0);
const int MOD=(int) 1e7+9;
const int INF=(int) 0x3f3f3f3f;
const LL  LINF=(LL) INF<<32|INF;
const int SINF=(uint) ~0>>1;
const LL  SLINF=(ULL) (-1)>>1;
const double DINF=(double) 1e50;
const double eps=(double) 1e-8;
const int maxn=(int) 1e5+10;
const int maxm=(int) 2e4+10;
const int maxk=(int) 5e2+10;

inline int sig(double x) {return x<-eps?-1:x>eps;}

//--------------start------------------

void work()
{
    int n;
    int x,y,X,Y;
    read(n);
    read(x), read(y), read(X), read(Y);
    double mn=0.0, mx=DINF;
    bool flag=0;
    for(int i=0;i<n;i++)
    {
        int p,q,v,w;
        read(p), read(q), read(v), read(w);
        double mn1=0.0, mn2=0.0, mx1=DINF, mx2=DINF;

        if(v==0 && w==0)
        {
            if(x<p && p<X && y<q && q<Y) ;
            else flag=1;
        }

        if(v==0)
        {
            if(x<p && p<X) ;
            else flag=1;
        }
        else
        {
            mn1=(double)(x-p)/v;
            mx1=(double)(X-p)/v;
            if(mn1>mx1) swap(mn1,mx1);

            if(mn1<0) mn1=0;
            if(mx1<0) flag=1;
        }

        if(w==0)
        {
            if(y<q && q<Y) ;
            else flag=1;
        }
        else
        {
            mn2=(double)(y-q)/w;
            mx2=(double)(Y-q)/w;
            if(mn2>mx2) swap(mn2,mx2);

            if(mn2<0) mn2=0;
            if(mx2<0) flag=1;
        }

        Max(mn,mn1);
        Max(mn,mn2);

        Min(mx,mx1);
        Min(mx,mx2);
    }
    if(mn>=mx) flag=1;
    if(flag) puts("-1");
    else printf("%.12lf\n",mn);
}

//--------------end--------------------

int main()
{
#ifdef yukihana0416
freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif // yukihana0416
    work();
    return 0;
}