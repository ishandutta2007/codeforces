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

template< typename T > inline void read(T &res) {
    T x=0; bool f=0; char ch=getchar();
    while(ch<48 || ch>57) {if(ch=='-')f=!f; ch=getchar();}
    while(ch>=48 && ch<=57) {x=x*10+ch-48; ch=getchar();}
    if(f) res=-x; else res=x;
}
char __stack[25],__top;
template< typename T > inline void write(T num) {
    if(num) {
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
const int maxn=(int) 5e3+20;
const int maxm=(int) 2e5+20;

inline int sig(double x) {return x<-eps?-1:x>eps;}
inline void fadd(LL &x,LL a) {x+=a; if(x>=MOD) x-=MOD;}

//--------------start------------------

int n,m,T;
int dis[5002][5002];

struct adjs{int to,next,c;}ad[maxn];
int head[maxn],adcnt;
inline void adjs_init() {for(int i=1;i<=n;i++)head[i]=-1; adcnt=0;}
inline void add_edge(int a,int b,int c)
{
    ad[adcnt].to=b; ad[adcnt].next=head[a];
    ad[adcnt].c=c;
    head[a]=adcnt++;
}

int DP(int u,int d)
{
    if(dis[u][d]!=-1) return dis[u][d];
    if(d==0) return INF;
    int mn=INF;
    for(int i=head[u];~i;i=ad[i].next)
    {
        int v=ad[i].to;
        Min(mn,DP(v,d-1)+ad[i].c);
    }
    return dis[u][d]=mn;
}

vector<int> ans;

void dfs(int u,int d)
{
    if(u==1)
    {
        ans.clear();
        ans.push_back(u);
        return ;
    }
    for(int i=head[u];~i;i=ad[i].next)
    {
        int v=ad[i].to;
        if(DP(v,d-1)+ad[i].c==DP(u,d))
        {
            dfs(v,d-1);
            ans.push_back(u);
            break;
        }
    }
}

void work()
{
    while(~scanf("%d%d%d",&n,&m,&T))
    {
        for(int i=1;i<=n;i++)
            for(int j=0;j<=n;j++)
                dis[i][j]=-1;
        dis[1][0]=0;

        adjs_init();
        for(int i=0,x,y,z;i<m;i++)
        {
            read(x), read(y), read(z);
            add_edge(y,x,z);
        }

        int flag=0;
        for(int i=n;i;i--) if(DP(n,i)<=T)
        {
            dfs(n,i);
            flag=1;
            break;
        }
        if(flag)
        {
            printf("%d\n",ans.size());
            for(int i=0;i<ans.size();i++)
                printf("%d ",ans[i]);
            printf("\n");
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