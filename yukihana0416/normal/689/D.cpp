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

const double pi=(double) acos(-1.0);
const int MOD=(int) 1e9+7;
const int INF=(int) 0x3f3f3f3f;
const LL  LINF=(LL) INF<<32|INF;
const int SINF=(uint) ~0>>1;
const LL  SLINF=(ULL) (-1)>>1;
const double DINF=(double) 1e50;
const double eps=(double) 1e-8;
const int maxn=(int) 2e5+20;
const int maxm=(int) 1e6+15;

inline int sig(double x) {return x<-eps?-1:x>eps;}
inline void fadd(LL &x,LL a) {x+=a; if(x>=MOD) x-=MOD;}

//--------------start------------------

int n;
int a[maxn],b[maxn];
int t1[maxn<<2],t2[maxn<<2];

void build(int l,int r,int id)
{
    if(l==r)
    {
        t1[id]=a[l];
        t2[id]=b[l];
        return ;
    }
    int mid=MID(l,r);
    build(lson);
    build(rson);
    t1[id]=max(t1[ls],t1[rs]);
    t2[id]=min(t2[ls],t2[rs]);
}

void query(int L,int R,int l,int r,int id,int &mn,int &mx)
{
    if(L<=l && r<=R)
    {
        Max(mx,t1[id]);
        Min(mn,t2[id]);
        return ;
    }
    int mid=MID(l,r);
    if(L<=mid) query(L,R,lson,mn,mx);
    if(mid<R) query(L,R,rson,mn,mx);
}

void work()
{
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++) read(a[i]);
        for(int i=1;i<=n;i++) read(b[i]);
        build(1,n,1);
        LL ans=0;
        for(int i=1;i<=n;i++)
        {
            int ll,rr; ll=rr=-1;
            int l=1,r=i;
            while(l<=r)
            {
                int mid=MID(l,r);
                int mn=INF,mx=-INF;
                query(mid,i,1,n,1,mn,mx);
                if(mx==mn)
                {
                    ll=mid;
                    r=mid-1;
                }
                else if(mx>mn) l=mid+1;
                else if(mx<mn) r=mid-1;
            }
            l=1; r=i;
            while(l<=r)
            {
                int mid=MID(l,r);
                int mn=INF, mx=-INF;
                query(mid,i,1,n,1,mn,mx);
                if(mx==mn)
                {
                    rr=mid;
                    l=mid+1;
                }
                else if(mx>mn) l=mid+1;
                else if(mx<mn) r=mid-1;
            }
//            if(i==4) cout <<rr <<" " <<ll <<endl;
//            if(i==5) cout <<rr <<" " <<ll <<endl;
            if(ll!=-1)
            {
                ans+=rr-ll+1;
            }
        }
        printf("%I64d\n",ans);
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