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
const int maxn=(int) 1e5+20;
const int maxm=(int) 2e5+20;

inline int sig(double x) {return x<-eps?-1:x>eps;}
inline void fadd(LL &x,LL a) {x+=a; if(x>=MOD) x-=MOD;}

//--------------start------------------

int n,m;
pair<int,int> p[maxn];
struct adjs{int to,next,idx;}ad[maxn<<1];
int head[maxn],adcnt;
inline void adjs_init() {for(int i=1;i<=n;i++)head[i]=-1; adcnt=0;}
inline void add_edge(int a,int b,int c)
{
    ad[adcnt].to=b; ad[adcnt].next=head[a];
    ad[adcnt].idx=c;
    head[a]=adcnt++;
}
int vis[maxn];
int in[maxn],out[maxn];
inline Set(int idx,int from,int to)
{
    if(p[idx].first==from) vis[idx]=1;
    else vis[idx]=-1;
}
void dfs(int u)
{
    for(int i=head[u];~i;i=ad[i].next)
    {
        int v=ad[i].to, idx=ad[i].idx;
        if(vis[idx]) continue;
        if(in[u]>out[u])
        {
            Set(idx,u,v);
            out[u]++;
            in[v]++;
        }
        else
        {
            Set(idx,v,u);
            in[u]++;
            out[v]++;
        }
        dfs(v);
    }
}

int du[maxn];
vector<int> vec;

void work()
{
    int tc; read(tc);
    while(tc--)
    {
        read(n), read(m);
        for(int i=1;i<=n;i++) in[i]=out[i]=0;
        for(int i=1;i<=n;i++) du[i]=0;
        adjs_init();
        for(int i=0,x,y;i<m;i++)
        {
            vis[i]=0;
            read(x), read(y);
            add_edge(x,y,i);
            add_edge(y,x,i);
            p[i]=mk(x,y);
            du[x]++;
            du[y]++;
        }
        vec.clear();
        for(int i=1;i<=n;i++) if(du[i]&1) vec.push_back(i);
        int mm=m;
        for(int i=0;i<vec.size();i+=2)
        {
            add_edge(vec[i],vec[i+1],mm);
            add_edge(vec[i+1],vec[i],mm);
            p[mm]=mk(vec[i],vec[i+1]);
            mm++;
        }
        for(int i=0;i<mm;i++) vis[i]=0;

        for(int i=1;i<=n;i++) dfs(i);

        int ans=n-vec.size();
        printf("%d\n",ans);
        for(int i=0;i<m;i++)
        {
            if(vis[i]==-1) swap(p[i].first,p[i].second);
            printf("%d %d\n",p[i].first,p[i].second);
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