#pragma comment(linker,"/STACK:102400000,102400000")
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <assert.h>
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
const double eps=(double) 1e-10;
const int INF=(int) 0x3f3f3f3f;
const LL  LINF=(ULL)(-1) >> 2;
const int SINF=(uint) ~0U>>1;
const double DINF=(double) 1e50;
const int MOD=(int) 1e9+7;
const int maxn=(int) 2e5+15;
const int maxm=(int) 3000+15;

LL gcd(LL x,LL y) {LL t; while(y) t=x%y,x=y,y=t; return absx(x);}
inline int sig(double x) {return x<-eps?-1:x>eps;}

//--------------start------------------

struct treap
{
    struct node
    {
        int r,key,size;
        node *ch[2];
        int cmp(int x)
        {
            return key==x ? -1 : x>key;
        }
    }mempool[maxn],*MPCNT,*rt;
    node *newnode()
    {
        MPCNT->r=rand();
        MPCNT->ch[0]=MPCNT->ch[1]=0;
        return MPCNT++;
    }

    void init()
    {
        MPCNT=mempool;
        rt=0;
    }
    void ro(node *&o,int d)
    {
        node *t=o->ch[!d];
        o->ch[!d]=t->ch[d];
        t->ch[d]=o;
        o=t;
    }

    void insert(node *&o,int val)
    {
        if(o==0)
        {
            o=newnode();
            o->key=val;
            o->size=1;
            return ;
        }
        int d=o->cmp(val);
        if(d==-1)
        {
            o->size++;
            return ;
        }
        insert(o->ch[d],val);
        if(o->ch[d]->r > o->r) ro(o,!d);
    }

    int query(node *o,int val)
    {
        if(o==0) return 0;
        int d=o->cmp(val);
        if(d==-1) return o->size;
        else return query(o->ch[d],val);
    }
}tx,ty;

struct treap2
{
    struct node
    {
        pii key;
        int r,size;
        node *ch[2];
        int cmp(pii x)
        {
            return key==x ? -1 : x>key;
        }
    }mempool[maxn],*MPCNT,*rt;
    node *newnode()
    {
        MPCNT->r=rand();
        MPCNT->ch[0]=MPCNT->ch[1]=0;
        return MPCNT++;
    }

    void init()
    {
        MPCNT=mempool;
        rt=0;
    }
    void ro(node *&o,int d)
    {
        node *t=o->ch[!d];
        o->ch[!d]=t->ch[d];
        t->ch[d]=o;
        o=t;
    }

    void insert(node *&o,pii val)
    {
        if(o==0)
        {
            o=newnode();
            o->key=val;
            o->size=1;
            return ;
        }
        int d=o->cmp(val);
        if(d==-1)
        {
            o->size++;
            return ;
        }
        insert(o->ch[d],val);
        if(o->ch[d]->r > o->r) ro(o,!d);
    }

    int query(node *o,pii val)
    {
        if(o==0) return 0;
        int d=o->cmp(val);
        if(d==-1) return o->size;
        else return query(o->ch[d],val);
    }
}tp;

void work()
{
    tx.init(); ty.init();
    tp.init();
    LL ans=0;
    int n=read();
    for(int i=0;i<n;i++)
    {
        int x=read(), y=read();

        ans+=tx.query(tx.rt,x);
        tx.insert(tx.rt,x);

        ans+=ty.query(ty.rt,y);
        ty.insert(ty.rt,y);

        pii pp=MK(x,y);

        ans-=tp.query(tp.rt,pp);
        tp.insert(tp.rt,pp);
    }
    cout <<ans <<endl;
}

//--------------end------------------

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