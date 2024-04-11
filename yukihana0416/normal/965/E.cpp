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
#include <bitset>
#include <vector>
using namespace std;

#define LL long long

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
    static bool fr_f; static char fr_ch;
    fr_f=0; x=0; fr_ch=getchar();
    while(fr_ch<'0' || fr_ch>'9') {if(fr_ch=='-') fr_f=1; fr_ch=getchar();}
    while(fr_ch>='0' && fr_ch<='9') {x=(x<<1)+(x<<3)+fr_ch-'0'; fr_ch=getchar();}
    if(fr_f) x=-x;
}

template< typename T > inline void Max(T &a, T b) {if(a<b) a=b;}
template< typename T > inline void Min(T &a, T b) {if(b<a) a=b;}
template< typename T > inline T Abs(T a) {if(a<0) return -a; else return a;}

const double pi   = acos(-1.0) ;
const int MOD     = (int)1e9+7 ;
const int INF     = (int)0x3f3f3f3f ;
const LL  LINF    = (LL)INF<<32|INF ;
const int SINF    = (uint)(-1)>>1 ;
const LL  SLINF   = (ULL)(-1)>>1 ;
const double DINF = 1e50 ;
const double eps  = 1e-8 ;
const int maxn    = (int) 2e5+20 ;
const int maxm    = (int) 25000+20 ;
const int maxk    = (int) 1000+20 ;

inline int sig(double x) {return x<-eps?-1:x>eps;}
inline LL fp(LL a,LL n,LL p) {LL res=1; for(;n;n>>=1,a=a*a%p) if(n&1) res=res*a%p; return res;}
template<typename T>inline T gcd(T a,T b) {for(T c;b;c=a%b,a=b,b=c); return a;}

//--------------------start--------------------

struct Node
{
    int dis,val;
    Node *l, *r;
    Node() {memset(this, 0, sizeof(Node));}
};

Node *Merge(Node *x, Node *y)
{
    if(!x) return y; if(!y) return x;

    if(x->val < y->val) swap(x,y);

    x->r = Merge(x->r, y);

    if(x->l == 0 || x->l->dis < x->r->dis) swap(x->l, x->r);

    if(x->r == 0) x->dis = 0; else x->dis = x->r->dis + 1;

    return x;
}

struct NodeT
{
    int cnt;
    NodeT *ch[26];
    NodeT() {memset(this,0,sizeof(NodeT));}
}Pool[maxn],*MPCNT;

int n;
char s[maxn];

void ins(NodeT *&o, char *p)
{
    if(!o)
    {
        o = new NodeT();
    }
    if(*p == 0)
    {
        o->cnt++;
        return ;
    }
    ins(o->ch[*p-'a'], p+1);
}

int dfs2(Node *o)
{
    if(!o) return 0;
    return dfs2(o->l) + dfs2(o->r) + o->val;
}

Node *dfs(NodeT *x, int dep)
{
    if(!x) return 0;

    Node *o, *p;
    o = 0;
    for(int i = 0; i < 26; i++)
    {
        if(x->ch[i]) o = Merge(o, dfs(x->ch[i], dep + 1));
    }
    if(x->cnt)
    {
        p = new Node();
        p->val = dep;
        o = Merge(o, p);
    }
    else if(dep)
    {
        p = o;
        o = Merge(o->l, o->r);
        p->l = p->r = 0;
        p->dis = 0;
        p->val = dep;
        o = Merge(o, p);
    }
    return o;
}



void work()
{
    read(n);
    NodeT *trie = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%s",s);
        ins(trie, s);
    }
    Node *heap = dfs(trie, 0);
    printf("%d\n", dfs2(heap));
}

//---------------------end---------------------

int main()
{
#ifdef yukihana0416
freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif // yukihana0416
    work();
    return 0;
}