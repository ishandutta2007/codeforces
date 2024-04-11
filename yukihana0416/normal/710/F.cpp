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
const int maxn=(int) 3e5+20;
const int maxm=(int) 10000+20;

inline int sig(double x) {return x<-eps?-1:x>eps;}
inline void fadd(LL &x,LL a) {x+=a; if(x>=MOD) x-=MOD;}

//--------------start------------------

int n;
char S[maxn];

int block_size;
const int alpha_size=26;
const int pool_size=(int)3e5+20;
struct AC_auto
{
    int tot;
    struct node
    {
        int last,f,val,cnt;
        int next[alpha_size],backup[alpha_size];
        inline void init() {memset(this,0,sizeof(node));}
    }T[pool_size];
    inline void init() {T[tot=0].init();}
    inline int Idx(char c) {return c-'a';}
    void ins(char *s,int val)
    {
        int now=0;
        for(;*s;s++)
        {
            int c=Idx(*s);
            if(!T[now].next[c]) T[T[now].next[c]=T[now].backup[c]=++tot].init();
            now=T[now].next[c];
        }
        T[now].val+=val;
    }

    inline void Reset()
    {
        for(int i=0;i<=tot;i++)
            for(int j=0;j<alpha_size;j++) T[i].next[j]=T[i].backup[j];
    }

    void get_fail()
    {
        queue<int> Q;
        for(int i=0;i<alpha_size;i++)
        {
            int u=T[0].next[i];
            if(u) {Q.push(u);}
        }
        while(!Q.empty())
        {
            int r=Q.front(); Q.pop();
            T[r].cnt=T[r].val+T[T[r].f].cnt;
            for(int i=0;i<alpha_size;i++)
            {
                int u=T[r].next[i];
                if(!u) {T[r].next[i]=T[T[r].f].next[i]; continue;}
                Q.push(u);
                int v=T[r].f;
                T[u].f=T[v].next[i];
                T[u].last = T[T[u].f].val ? T[u].f : T[T[u].f].last ;
            }
        }
    }

    LL query(char *s)
    {
        LL res=0;
        for(int now=0;*s;s++)
        {
            int c=Idx(*s);
            now=T[now].next[c];
            res+=T[now].cnt;
        }
        return res;
    }
}Big,Small;

void dfs(int x,int y)
{
    Big.T[y].val+=Small.T[x].val;
    for(int i=0;i<alpha_size;i++)
    {
        int u=Small.T[x].backup[i], v=Big.T[y].backup[i];
        if(!u) continue;
        if(!v) Big.T[v=Big.T[y].backup[i]=++Big.tot].init();
        dfs(u,v);
    }
}

inline void Merge()
{
    dfs(0,0);
    Big.Reset();
    Big.get_fail();
    Small.init();
}

void work()
{
    while(~scanf("%d",&n))
    {
        Big.init(); Small.init();
        block_size=(int) sqrt(pool_size*1.0);
//        cout <<"block size : " <<block_size <<endl;
        for(int i=0;i<n;i++)
        {
            int cmd; read(cmd);
            scanf("%s",S);
            if(cmd==3)
            {
                LL ans;
                ans=Big.query(S)+Small.query(S);
                printf("%I64d\n",ans);
                fflush(stdout);
            }
            else
            {
                int val = cmd==1 ? 1 : -1;
                Small.Reset();
                Small.ins(S,val);
                Small.get_fail();
                if(Small.tot>block_size) Merge();
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