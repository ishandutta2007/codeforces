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
#define mk(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define lowbit(x) ((x)&-(x))

typedef unsigned LL ULL;
typedef unsigned uint;
typedef pair<int,int> pii;
typedef vector<int> vi;

template< typename T > inline void read(T &x) {
    bool f=0; char ch=getchar(); x=0;
    while(ch<48 || 57<ch) {if(ch=='-')f=!f; ch=getchar();}
    while(47<ch && ch<58) {x=x*10+ch-48; ch=getchar();}
    if(f) x=-x;
}
char __stack[25],__top;
template< typename T > inline void write(T x) {
    if(x) {
        if(x<0) putchar('-'), x=-x;
        __top=0;
        while(x) __stack[++__top]=x%10, x/=10;
        while(__top) putchar(48+__stack[__top--]);
    }
    else putchar(48);
}

template< typename T > inline void Max(T &a, T b) {if(a<b) a=b;}
template< typename T > inline void Min(T &a, T b) {if(b<a) a=b;}
template< typename T > inline void Swap(T &a,T &b) {T c=a; a=b; b=c;}
template< typename T > inline T Abs(T a) {if(a<0) return -a; else return a;}

const double pi=(double) acos(-1.0);
const int MOD=(int) 1e9+7;
const int INF=(int) 0x3f3f3f3f;
const LL  LINF=(LL) INF<<32|INF;
const int SINF=(uint) ~0>>1;
const LL  SLINF=(ULL) (-1)>>1;
const double DINF=(double) 1e50;
const double eps=(double) 1e-8;
const int maxn=(int) 2e5+20;
const int maxm=(int) 2e5+20;

inline int sig(double x) {return x<-eps?-1:x>eps;}

//--------------start------------------

int n,m,k;
vi f[maxn<<1],g[maxn<<1];
int dx[maxn<<1],dy[maxn<<1];
int visf[maxn<<1],visg[maxn<<1];
LL ans[maxn<<1];

void work()
{
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        for(int i=0; i<=n+m; i++)
        {
            f[i].clear();
            visf[i]=0;
        }
        for(int i=0; i<=n+m; i++)
        {
            g[i].clear();
            visg[i]=0;
        }
        for(int i=1; i<=k; i++)
        {
            ans[i]=LINF;
            scanf("%d%d",&dx[i],&dy[i]);
            f[dx[i]+dy[i]].push_back(i);
            g[dy[i]-dx[i]+n].push_back(i);
        }
        int pos=0+n,x=0,y=0,flag=-1;
        LL tim=0;
        while(1)
        {
            if(flag==-1) pos=y-x+n;
            else pos=x+y;
            if(flag==-1)
            {
                if(visg[pos]) break;
                visg[pos]=1;
                for(int i=0; i<g[pos].size(); i++)
                {
                    int id=g[pos][i];
                    ans[id]=min(ans[id],tim+abs(dx[id]-x));
                }
                if(x==0)
                {
                    if((m-y)>n) x=n,y=y+n, tim+=n;
                    else x=x+(m-y), tim+=(m-y), y=m;
                }
                else if(x==n)
                {
                    if(y>n) x=0,y=y-n, tim+=n;
                    else x=x-y, tim+=y, y=0;
                }
                else if(y==0)
                {
                    if((n-x)>m) x=x+m, y=m, tim+=m;
                    else y=y+(n-x), tim+=(n-x), x=n;
                }
                else if(y==m)
                {
                    if(x<m) y=y-x, tim+=x, x=0;
                    else y=0, x=x-m, tim+=m;
                }
                flag=-flag;
            }
            else
            {
                if(visf[pos]) break;
                visf[pos]=1;
                for(int i=0; i<f[pos].size(); i++)
                {
                    int id=f[pos][i];
                    ans[id]=min(ans[id],tim+abs(dx[id]-x));
                }
                if(x==0)
                {
                    if(y>n) x=n,y=y-n, tim+=n;
                    else x=x+y, tim+=y, y=0;
                }
                else if(x==n)
                {
                    if((m-y)>n) x=0,y=y+n, tim+=n;
                    else x=x-(m-y), tim+=(m-y), y=m;
                }
                else if(y==0)
                {
                    if(x<m) y=y+x, tim+=x, x=0;
                    else y=m, x=x-m, tim+=m;
                }
                else if(y==m)
                {
                    if((n-x)>m) x=x+m, y=0, tim+=m;
                    else y=y-(n-x), tim+=(n-x), x=n;
                }
                flag=-flag;
            }
            if(x==n&&y==m) break;
            if(x==0&&y==m) break;
            if(x==n&&y==0) break;
            if(x==0&&y==0) break;
        }
        for(int i=1; i<=k; i++)
        {
            if(ans[i]==LINF) ans[i]=-1;
            printf("%I64d\n",ans[i]);
        }
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