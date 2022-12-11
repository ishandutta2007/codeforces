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

const double pi=(double) acos(-1.0);
const double eps=(double) 1e-8;
const int INF=(int) 0x3f3f3f3f;
const LL  LINF=(ULL)(-1) >> 2;
const int SINF=(uint) ~0U>>1;
const double DINF=(double) 1e50;
const int MOD=(int) 1e9+7;
const int maxn=(int) 200000+15;
const int maxm=(int) 2000000+15;

LL gcd(LL x,LL y) {LL t; while(y) t=x%y,x=y,y=t; return absx(x);}
inline int sig(double x) {return x<-eps?-1:x>eps;}

//------------------------------------

int n;
LL x,y;

struct adjs
{
    int to,next;
}ad[maxn<<1];
int head[maxn],adcnt;
inline void add_edge(int a,int b)
{
    ad[adcnt].to=b; ad[adcnt].next=head[a];
    head[a]=adcnt++;
}

int dp[maxn][3];

void dfs(int u,int fa)
{
    dp[u][0]=dp[u][1]=dp[u][2]=1;
    for(int i=head[u];~i;i=ad[i].next)
    {
        int v=ad[i].to;
        if(v==fa) continue;
        dfs(v,u);
        int f1=min(dp[v][0],min(dp[v][1],dp[v][2]));
        int f2=min(dp[v][0],dp[v][1]);
        dp[u][2]=min(dp[u][2]+f1,dp[u][1]+f2-1);
        dp[u][1]=min(dp[u][1]+f1,dp[u][0]+f2-1);
        dp[u][0]=dp[u][0]+f1;
    }
}

int du[maxn];
inline void init()
{
    memset(du,0,sizeof(du));
    memset(head,-1,sizeof(head));
    adcnt=0;
}

void work()
{
    init();
    n=read(), x=read(), y=read(); //x you
    for(int i=1;i<n;i++)
    {
        int a=read(), b=read();
        add_edge(a,b); add_edge(b,a);
        du[a]++,du[b]++;
    }
    if(x==y)
    {
        printf("%I64d\n",(n-1)*x);
    }
    else if(x>y)
    {
        int cnt=0;
        for(int i=1;i<=n;i++) if(du[i]==1) cnt++;
        if(cnt>=n-1)
        {
            printf("%I64d\n",(n-2)*y+x);
        }
        else
        {
            printf("%I64d\n",(n-1)*y);
        }
    }
    else
    {
        dfs(1,0);
        int t=min(dp[1][0],min(dp[1][1],dp[1][2]))-1;
        printf("%I64d\n",t*y+(n-1-t)*x);
    }
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