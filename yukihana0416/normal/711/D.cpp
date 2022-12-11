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

template< typename T >
inline void read(T &res)
{
    T x=0; bool f=0; char ch=getchar();
    while(ch<48 || ch>57) {if(ch=='-')f=!f; ch=getchar();}
    while(ch>=48 && ch<=57) {x=x*10+ch-48; ch=getchar();}
    res = f ? -x : x ;
}
char __stack[25],__top;
template< typename T >
inline void write(T num)
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

template< typename T >
inline void Max(T &a, T b) {if(a<b) a=b;}
template< typename T >
inline void Min(T &a, T b) {if(b<a) a=b;}
template< typename T >
inline void Swap(T &a,T &b) {T c=a; a=b; b=c;}
template< typename T >
inline T Abs(T a) {if(a<0) return -a; else return a;}

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
bool vis[maxn],vise[maxn];
int dep[maxn];

struct adjs {int to,next,id;} ad[maxn<<1];
int head[maxn],adcnt;
inline void init() {memset(head,-1,sizeof(head)); adcnt=0;}
inline void add_edge(int a,int b,int idx)
{
    ad[adcnt].to=b; ad[adcnt].next=head[a];
    ad[adcnt].id=idx;
    head[a]=adcnt++;
}

int Loop,cnt;
void dfs(int u,int d)
{
    dep[u]=d;
    vis[u]=1;
    cnt++;
    for(int i=head[u];~i;i=ad[i].next)
    {
        int v=ad[i].to;
        int idx=ad[i].id;
        if(vise[idx]) continue;
        if(vis[v])
        {
            Loop=Abs(dep[u]-dep[v])+1;
            continue;
        }
        vise[idx]=1;
        dfs(v,d+1);
    }
}

LL fp(LL a,LL n)
{
    LL res=1;
    while(n)
    {
        if(n&1) res=res*a%MOD;
        a=a*a%MOD; n>>=1;
    }
    return res;
}

void work()
{
    while(~scanf("%d",&n))
    {
        init();
        for(int i=1;i<=n;i++)
        {
            int x; read(x);
            add_edge(i,x,i);
            add_edge(x,i,i);
        }
        memset(vis,0,sizeof(vis));
        memset(vise,0,sizeof(vise));
        LL ans=1;

        for(int i=1;i<=n;i++)
        {
            if(vis[i]) continue;
            Loop=cnt=0;
            dfs(i,0);
            LL temp=((fp(2,Loop)-2)*fp(2,cnt-Loop))%MOD;
            temp=(temp+MOD)%MOD;
//            cout <<i <<" " <<Loop <<" " <<cnt <<" " <<temp <<endl;
            ans=ans*temp%MOD;
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