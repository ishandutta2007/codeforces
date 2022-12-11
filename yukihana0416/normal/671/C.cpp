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
typedef map<int,int> mii;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<LL,LL> pll;
typedef vector<int> vi;

template< typename T > inline void read(T &res)
{
    T x=0; bool f=0; char ch=getchar();
    while(ch<48 || ch>57) {if(ch=='-')f=!f; ch=getchar();}
    while(ch>=48 && ch<=57) {x=x*10+ch-48; ch=getchar();}
    res = f ? -x : x ;
}
char __stack[25],__top;
template< typename T > inline void write(T num)
{
    if(num)
    {
        if(num<0) putchar('-'), num=-num;
        __top=0;
        while(num) __stack[++__top]=num%10, num/=10;
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
inline void fadd(LL &x,LL a) {x+=a; if(x>=MOD) x-=MOD;}

//--------------start------------------

int n;
int a[maxn];
LL f[maxn];
vector<int> G[maxn];

LL sum[maxn<<2];
int flag[maxn<<2],mx[maxn<<2],mn[maxn<<2],Len[maxn<<2];

void build(int l,int r,int id)
{
    Len[id]=r-l+1; flag[id]=0;
    if(l==r)
    {
        mx[id]=mn[id]=l;
        sum[id]=l;
        Len[id]=r-l+1;
        return ;
    }
    int mid=MID(l,r);
    build(lson);
    build(rson);
    mx[id]=max(mx[ls],mx[rs]);
    mn[id]=min(mn[ls],mn[rs]);
    sum[id]=sum[ls]+sum[rs];
}

inline void lazy(int id)
{
    int v=flag[id]; flag[id]=0;
    flag[ls]=mx[ls]=mn[ls]=v;
    flag[rs]=mx[rs]=mn[rs]=v;
    sum[ls]=(LL)Len[ls]*v;
    sum[rs]=(LL)Len[rs]*v;
}

void dfs(int val,int l,int r,int id)
{
    if(mn[id]>=val) return ;
    if(mx[id]<=val)
    {
        flag[id]=val;
        mx[id]=mn[id]=val;
        sum[id]=(LL)Len[id]*val;
        return ;
    }
    if(flag[id]) lazy(id);
    int mid=MID(l,r);
    dfs(val,lson);
    dfs(val,rson);
    mx[id]=max(mx[ls],mx[rs]);
    mn[id]=min(mn[ls],mn[rs]);
    sum[id]=sum[ls]+sum[rs];
}

void update(int val,int L,int R,int l,int r,int id)
{
    if(L>R) return ;
    if(L<=l && r<=R)
    {
        dfs(val,l,r,id);
        return ;
    }
    if(flag[id]) lazy(id);
    int mid=MID(l,r);
    if(L<=mid) update(val,L,R,lson);
    if(mid<R) update(val,L,R,rson);
    mx[id]=max(mx[ls],mx[rs]);
    mn[id]=min(mn[ls],mn[rs]);
    sum[id]=sum[ls]+sum[rs];
}

void work()
{
    while(~scanf("%d",&n))
    {
        int m=0;
        for(int i=1;i<=n;i++) read(a[i]), Max(m,a[i]);
//        for(int i=1;i<=m+1;i++) G[i].clear();

        for(int i=1;i<=n;i++)
        {
            int x=a[i];
            for(int j=1;j*j<=x;j++) if(x%j==0)
            {
                G[j].push_back(i);
                if(j!=x/j) G[x/j].push_back(i);
            }
        }

        build(1,n,1);
        for(int i=m+1;i;i--)
        {
            int sz=G[i].size();
            if(sz>=2)
            {
                update(n+1,G[i][1]+1,n,1,n,1);
                update(G[i][sz-1],G[i][0]+1,G[i][1],1,n,1);
                update(G[i][sz-2],1,G[i][0],1,n,1);
            }
            f[i]=(LL)n*(n+1)-sum[1];
        }

        ULL ans=0;
        for(int i=1;i<=m;i++) ans+=(f[i+1]-f[i])*i;

        printf("%I64u\n",ans);
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