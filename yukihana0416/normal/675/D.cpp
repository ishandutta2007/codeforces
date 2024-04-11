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
const int maxn=(int) 1e5+20;
const int maxm=(int) 2e5+20;

inline int sig(double x) {return x<-eps?-1:x>eps;}
inline void fadd(LL &x,LL a) {x+=a; if(x>=MOD) x-=MOD;}

//--------------start------------------

map<int,int> mp;
struct node
{
    int key,r;
    node *ch[2];
    inline int cmp(int x) {return x==key ? -1 : x>key;}
}*MPCNT,MP[maxn],*ROOT;
inline node *newnode()
{
    MPCNT->r=rand();
    MPCNT->ch[0]=MPCNT->ch[1]=0;
    return MPCNT++;
}

void ro(node *&o,int d)
{
    node *p=o->ch[!d]; o->ch[!d]=p->ch[d]; p->ch[d]=o; o=p;
}
int RES;
void query(node *o,int t,int val)
{
    if(!o) return ;
    if(t==0)
    {
        if(o->key<val) Max(RES,o->key);
        if(o->key<val) query(o->ch[1],t,val);
        else query(o->ch[0],t,val);
    }
    else
    {
        if(o->key>val) Min(RES,o->key);
        if(o->key>val) query(o->ch[0],t,val);
        else query(o->ch[1],t,val);
    }
}
void ins(node *&o,int val)
{
    if(!o)
    {
        o=newnode();
        o->key=val;
        return ;
    }
    int d=o->cmp(val);
    ins(o->ch[d],val);
    if(o->ch[d]->r > o->r) ro(o,!d);
}

void work()
{
    int n;
    while(~scanf("%d",&n))
    {
        mp.clear();
        MPCNT=MP; ROOT=0;
        int x; read(x); ins(ROOT,x); mp[x]=0;
        for(int i=1;i<n;i++)
        {
            read(x);
            int mn,mx;
            RES=-INF; query(ROOT,0,x);
            mn=RES;
            RES=INF; query(ROOT,1,x);
            mx=RES;
            if(mn==-INF)
            {
                int t=mp[mx];
                printf("%d ",mx);
                mp[x]=t+1;
            }
            else if(mx==INF)
            {
                int t=mp[mn];
                printf("%d ",mn);
                mp[x]=t+1;
            }
            else
            {
                int t=max(mp[mn],mp[mx]);
                mp[x]=t+1;
                if(mp[mn]>mp[mx]) printf("%d ",mn);
                else printf("%d ",mx);
            }
            ins(ROOT,x);
        }
        puts("");
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