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

template< typename T > inline void read(T &res) {
    T x=0; bool f=0; char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-')f=!f; ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    res = f ? -x : x ;
}

template< typename T > inline void Max(T &a, T b) {if(a<b) a=b;}
template< typename T > inline void Min(T &a, T b) {if(b<a) a=b;}
template< typename T > inline T Abs(T a) {if(a<0) a=-a; return a;}

const double pi=(double) acos(-1.0);
const int MOD=(int) 1e9+7;
const int INF=(int) 0x3f3f3f3f;
const LL  LINF=(LL) INF<<32|INF;
const int SINF=(uint) ~0>>1;
const LL  SLINF=(ULL) (-1)>>1;
const double DINF=(double) 1e50;
const double eps=(double) 1e-8;
const int maxn=(int) 2e5+20;
const int maxm=(int) 5e5+15;

inline int sig(double x) {return x<-eps?-1:x>eps;}

//--------------start------------------

int n;
int d[maxn],c[maxn];
pii p[maxn];

int gao(int x,int &res)
{
    for(int i=1;i<=n;i++)
    {
        if(d[i]==1 && x<1900) return 1;
        if(d[i]==2 && x>=1900) return -1;
        x+=c[i];
    }
    res=x;
    return 0;
}

void work()
{
    read(n);
    for(int i=1;i<=n;i++) read(c[i]), read(d[i]);


    int L=-INF, R=INF, mid, ans=-INF, temp, ck;
    while(L<=R)
    {
        mid=MID(L,R);
        ck=gao(mid,temp);

        if(ck==0)
        {
            Max(ans,temp);
            L=mid+1;
        }
        else if(ck==1)
        {
            L=mid+1;
        }
        else
        {
            R=mid-1;
        }
    }


    if(ans==-INF) puts("Impossible");
    else if(ans>=INF/2) puts("Infinity");
    else printf("%d\n",ans);
}

//--------------end--------------------

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