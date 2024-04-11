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
#include <iomanip>
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
#define lowbit(x) ((x)&-(x))

typedef unsigned LL ULL;
typedef unsigned uint;
typedef map<int,int> mii;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<LL,LL> pll;
typedef vector<int> vi;

template< typename T >
inline void read(T &res)
{
    T x=0; bool f=0; char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-')f=!f; ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    res = f ? -x : x ;
}

template< typename T >
inline void Max(T &a, T b) {if(a<b) a=b;}
template< typename T >
inline void Min(T &a, T b) {if(b<a) a=b;}
template< typename T >
inline void Swap(T &a,T &b) {T c=a; a=b; b=c;}

const double pi=(double) acos(-1.0);
const int MOD=(int) 1e9+7;
const int INF=(int) 0x3f3f3f3f;
const LL  LINF=(LL) INF<<32|INF;
const int SINF=(uint) ~0>>1;
const LL  SLINF=(ULL) (-1)>>1;
const double DINF=(double) 1e50;
const double eps=(double) 1e-8;
const int maxn=(int) 5000+20;
const int maxm=(int) 1000000+15;

inline int sig(double x) {return x<-eps?-1:x>eps;}
inline void fadd(LL &x,LL a) {x+=a; if(x>=MOD) x-=MOD;}

//--------------start------------------

int n,s,e;
int x[maxn],a[maxn],b[maxn],c[maxn],d[maxn];
map<pii,LL> dp[2];
map<pii,LL> :: iterator Mit,Tit;

inline void update(map<pii,LL> &d,int in,int out,LL val)
{
    Tit=d.find(mk(in,out));
    if(Tit==d.end())
    {
        d[mk(in,out)]=val;
    }
    else
    {
        if(Tit->se>val) d[mk(in,out)]=val;
    }
}

void work()
{
    while(~scanf("%d",&n))
    {
        read(s), read(e);
        for(int i=1;i<=n;i++) read(x[i]);
        for(int i=1;i<=n;i++) read(a[i]);
        for(int i=1;i<=n;i++) read(b[i]);
        for(int i=1;i<=n;i++) read(c[i]);
        for(int i=1;i<=n;i++) read(d[i]);

        dp[0].clear();
        dp[0][mk(0,0)]=0;
        bool now=0;

        int in,out;
        LL val;
        for(int i=1;i<=n;i++)
        {
            for(Mit=dp[now].begin();Mit!=dp[now].end();Mit++)
            {
                in=Mit->fi.fi, out=Mit->fi.se, val=Mit->se;
                if(i==n)
                {
                    if(i==s)
                    {
                        if(in) update(dp[!now],in-1,out,val+c[i]+x[i]);
                        update(dp[!now],in,out+1,val+d[i]-x[i]);
                    }
                    else if(i==e)
                    {
                        if(out) update(dp[!now],in,out-1,val+a[i]+x[i]);
                        update(dp[!now],in+1,out,val+b[i]-x[i]);
                    }
                    else
                    {
                        update(dp[!now],in+1,out+1,val+b[i]+d[i]-x[i]-x[i]);
                        if(in) update(dp[!now],in,out,val+c[i]+b[i]);
                        if(out) update(dp[!now],in,out,val+a[i]+d[i]);
                        if(in && out) update(dp[!now],in-1,out-1,val+a[i]+c[i]+x[i]+x[i]);
                    }
                }
                else
                {
                    if(i==s)
                    {
                        if(in>=2 || (in==1 && out!=0)) update(dp[!now],in-1,out,val+c[i]+x[i]);
                        update(dp[!now],in,out+1,val+d[i]-x[i]);
                    }
                    else if(i==e)
                    {
                        if(out>=2 || (out==1 && in!=0)) update(dp[!now],in,out-1,val+a[i]+x[i]);
                        update(dp[!now],in+1,out,val+b[i]-x[i]);
                    }
                    else
                    {
                        update(dp[!now],in+1,out+1,val+b[i]+d[i]-x[i]-x[i]);
                        if(in) update(dp[!now],in,out,val+c[i]+b[i]);
                        if(out) update(dp[!now],in,out,val+a[i]+d[i]);
                        if(in && out && (in>=2 || out>=2)) update(dp[!now],in-1,out-1,val+a[i]+c[i]+x[i]+x[i]);
                    }
                }
            }
            dp[now].clear();
            now=!now;
        }
        printf("%I64d\n",dp[now][mk(0,0)]);
    }
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