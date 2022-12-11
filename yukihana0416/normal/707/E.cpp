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
const int maxn=(int) 2000+20;
const int maxm=(int) 1000000+15;

inline int sig(double x) {return x<-eps?-1:x>eps;}
inline void fadd(LL &x,LL a) {x+=a; if(x>=MOD) x-=MOD;}

//--------------start------------------

int n,m,k;
struct adjs{int to,v,next;}ad[maxn*maxn*2];
int head[maxn],adcnt;
inline void adjs_init() {memset(head,-1,sizeof(head));}
inline void add_edge(int a,int b,int v)
{
    ad[adcnt].to=b; ad[adcnt].next=head[a];
    ad[adcnt].v=v;
    head[a]=adcnt++;
}

LL T[maxn][maxn];
inline void add(int x,int y,LL val)
{
    for(int i=x;i<=n;i+=lowbit(i))
        for(int j=y;j<=m;j+=lowbit(j))
            T[i][j]+=val;
}
inline LL sum(int x,int y)
{
    LL res=0;
    for(int i=x;i;i-=lowbit(i))
        for(int j=y;j;j-=lowbit(j))
            res+=T[i][j];
    return res;
}

bool now[maxn],tag[maxn];

void work()
{
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        memset(now,0,sizeof(now));
        memset(tag,0,sizeof(tag));
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) T[i][j]=0;
        adjs_init();
        for(int i=1;i<=k;i++)
        {
            int t; read(t);
            for(int j=0;j<t;j++)
            {
                int x,y,v; read(x), read(y), read(v);
                add_edge(i,x*(m+1)+y,v);
                add(x,y,v);
            }
        }
        int Q; read(Q);
        char cmd[10];
        while(Q--)
        {
            scanf("%s",cmd);
            if(cmd[0]=='S')
            {
                int x; read(x);
                now[x]=!now[x];
            }
            else
            {
                for(int i=1;i<=k;i++)
                {
                    if(now[i]==tag[i]) continue;
                    tag[i]=now[i];
                    if(now[i]) for(int j=head[i];~j;j=ad[j].next)
                    {
                        add(ad[j].to/(m+1),ad[j].to%(m+1),-ad[j].v);
                    }
                    else for(int j=head[i];~j;j=ad[j].next)
                    {
                        add(ad[j].to/(m+1),ad[j].to%(m+1),ad[j].v);
                    }
                }
                int x1,y1,x2,y2;
                read(x1), read(y1), read(x2), read(y2);
                printf("%I64d\n",sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)+sum(x1-1,y1-1));
            }
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