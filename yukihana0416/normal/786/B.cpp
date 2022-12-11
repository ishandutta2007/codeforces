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
typedef pair<LL,LL> pLL;

template< typename T > inline void read(T &x) {
    bool f=0; char ch=getchar(); x=0;
    while(ch<'0' || ch>'9') {if(ch=='-') f=1; ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    if(f) x=-x;
}

template< typename T > inline void Max(T &a, T b) {if(a<b) a=b;}
template< typename T > inline void Min(T &a, T b) {if(b<a) a=b;}
template< typename T > inline T Abs(T a) {if(a<0) return -a; else return a;}

const double pi=(double) acos(-1.0);
const int MOD=(int) 1e7+9;
const int INF=(int) 0x3f3f3f3f;
const LL  LINF=(LL) INF<<32|INF;
const int SINF=(uint) ~0>>1;
const LL  SLINF=(ULL) (-1)>>1;
const double DINF=(double) 1e50;
const double eps=(double) 1e-8;
const int maxn=(int) 1e5+10;
const int maxm=(int) 2e4+10;
const int maxk=(int) 5e2+10;

inline int sig(double x) {return x<-eps?-1:x>eps;}

//--------------start------------------

int node_cnt;

struct adjs {int to,next,c;}ad[maxn*30];
int head[maxn*3],adcnt;
inline void adjs_init() {for(int i=0;i<=node_cnt;i++) head[i]=-1; adcnt=0;}
inline void add_edge(int a,int b,int c)
{
    ad[adcnt].to=b; ad[adcnt].next=head[a]; ad[adcnt].c=c;
    head[a]=adcnt++;
}

#define ROOT 1,n,1
struct Segment_Tree
{
    int T[maxn<<2];
    void build(int l,int r,int id)
    {
        if(l==r) {T[id]=l; return ;}
        T[id]=++node_cnt;
        int mid=MID(l,r);
        build(lson);
        build(rson);
    }
    void update(int idx,int c,int type,int L,int R,int l,int r,int id)
    {
        if(L<=l && r<=R)
        {
            if(!type) add_edge(idx,T[id],c);
            else add_edge(T[id],idx,c);
            return ;
        }
        int mid=MID(l,r);
        if(L<=mid) update(idx,c,type,L,R,lson);
        if(mid<R)  update(idx,c,type,L,R,rson);
    }
    void Link(int type,int l,int r,int id)
    {
        if(l==r) return ;
        if(!type)
            add_edge(T[id],T[ls],0), add_edge(T[id],T[rs],0);
        else
            add_edge(T[ls],T[id],0), add_edge(T[rs],T[id],0);
        int mid=MID(l,r);
        Link(type,lson);
        Link(type,rson);
    }
}st[2];

bool inq[maxn*3];
LL dis[maxn*3];

void spfa(int st)
{
    for(int i=1;i<=node_cnt;i++) inq[i]=0, dis[i]=LINF;
    queue<int> Q;
    Q.push(st);
    inq[st]=1;
    dis[st]=0;

    while(!Q.empty())
    {
        int u=Q.front(); Q.pop(); inq[u]=0;
        for(int i=head[u];~i;i=ad[i].next)
        {
            int v=ad[i].to;
            if(dis[v]>dis[u]+ad[i].c)
            {
                dis[v]=dis[u]+ad[i].c;
                if(!inq[v])
                {
                    inq[v]=1;
                    Q.push(v);
                }
            }
        }
    }
}

void work()
{
    int n,q,s;
    read(n), read(q), read(s);
    node_cnt=n;

    for(int i=0;i<2;i++) st[i].build(ROOT);
    adjs_init();
    for(int i=0;i<2;i++) st[i].Link(i,ROOT);

    while(q--)
    {
        int t,v,u,w,l,r;
        read(t);
        if(t==1)
        {
            read(v), read(u), read(w);
            add_edge(v,u,w);
        }
        else
        {
            read(v), read(l), read(r), read(w);
            st[t-2].update(v,w,t-2,l,r,ROOT);
        }
    }

    spfa(s);

    for(int i=1;i<=n;i++) printf("%I64d%c",dis[i]==LINF ? -1 : dis[i],i==n ? '\n' : ' ');
}

//--------------end--------------------

int main()
{
#ifdef yukihana0416
freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif // yukihana0416
    work();
    return 0;
}