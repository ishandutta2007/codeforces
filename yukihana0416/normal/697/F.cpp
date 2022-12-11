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

const double pi=(double) acos(-1.0);
const int MOD=(int) 1e9+7;
const int INF=(int) 0x3f3f3f3f;
const LL  LINF=(LL) INF<<32|INF;
const int SINF=(uint) ~0>>1;
const LL  SLINF=(ULL) (-1)>>1;
const double DINF=(double) 1e50;
const double eps=(double) 1e-8;
const int maxn=(int) 1e5+20;
const int maxm=(int) 1e6+15;

inline int sig(double x) {return x<-eps?-1:x>eps;}
inline void fadd(LL &x,LL a) {x+=a; if(x>=MOD) x-=MOD;}

//--------------start------------------

struct mat
{
    int sz;
    LL a[205][205];
    inline void init(int _sz) {sz=_sz; for(int i=0;i<sz;i++) for(int j=0;j<sz;j++) a[i][j]=-INF;}
    inline void to_I(int _sz) {init(_sz); for(int i=0;i<sz;i++) a[i][i]=0;}
    mat operator * (const mat &t) const
    {
        mat res; res.to_I(sz);
        for(int k=0;k<sz;k++)
            for(int i=0;i<sz;i++)
                for(int j=0;j<sz;j++)
                    Max(res.a[i][j],a[i][k]+t.a[k][j]);
        return res;
    }
};

struct AC_auto
{
    struct node
    {
        int next[26],val,f,last,tot;
        inline void init() {memset(this,0,sizeof(node));}
    }T[205];
    int Tcnt;

    inline void clear() {T[Tcnt=0].init();}
    inline int idx(char c) {return c-'a';}

    void ins(char *s,int val)
    {
        int now=0,c;
        for(;*s;s++)
        {
            c=idx(*s);
            if(!T[now].next[c]) T[now].next[c]=++Tcnt, T[Tcnt].init();
            now=T[now].next[c];
        }
        T[now].val+=val;
    }

    void getf()
    {
        queue<int> Q;
        for(int i=0;i<26;i++) if(T[0].next[i]) Q.push(T[0].next[i]);

        while(!Q.empty())
        {
            int r=Q.front(); Q.pop();
            T[r].tot=T[r].val+T[T[r].f].tot;
            for(int i=0;i<26;i++)
            {
                int u=T[r].next[i];
                if(!u) {T[r].next[i]=T[T[r].f].next[i]; continue;}
                Q.push(u);

                int v=T[r].f;
                T[u].f=T[v].next[i];
                T[u].last = T[T[u].f].val ? T[u].f : T[T[u].f].last;
            }
        }
    }

    void print()
    {
        for(int i=0;i<=Tcnt;i++) cout <<i <<" " <<T[i].tot <<endl;
    }

    mat get_mat()
    {
        mat res; res.init(Tcnt+1);
        for(int i=0;i<=Tcnt;i++)
            for(int j=0;j<26;j++)
                res.a[i][T[i].next[j]]=T[T[i].next[j]].tot;
        return res;
    }
}ac;

int n;
LL l;

int vv[205];
char s[205];

mat fp(mat a,LL n)
{
    mat res; res.to_I(a.sz);
    while(n)
    {
        if(n&1) res=res*a;
        a=a*a; n>>=1;
    }
    return res;
}

void work()
{
    while(~scanf("%d%I64d",&n,&l))
    {
        ac.clear();
        for(int i=0;i<n;i++) read(vv[i]);
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            ac.ins(s,vv[i]);
        }

        ac.getf();
//        ac.print();
        mat tmp=ac.get_mat();
        tmp=fp(tmp,l);

        LL ans=0;
        for(int i=0;i<tmp.sz;i++) Max(ans,tmp.a[0][i]);

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