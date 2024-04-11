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
    bool f; char ch; f=0; x=0; ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-') f=1; ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    if(f) x=-x;
}

template< typename T > inline void Max(T &a, T b) {if(a<b) a=b;}
template< typename T > inline void Min(T &a, T b) {if(b<a) a=b;}
template< typename T > inline T Abs(T a) {if(a<0) return -a; else return a;}

const double pi=(double) acos(-1.0);
const int MOD=(int) 1e9+7;
const int INF=(int) 0x3f3f3f3f;
const LL  LINF=(LL) INF<<32|INF;
const int SINF=(uint) ~0>>1;
const LL  SLINF=(ULL) (-1)>>1;
const double DINF=(double) 1e50;
const double eps=(double) 1e-8;
const int maxn=(int) 200000+20;
const int maxm=(int) 1e5+20;
const int maxk=(int) 5e2+20;

inline int sig(double x) {return x<-eps?-1:x>eps;}

//--------------start------------------

struct Node
{

    Node *ch[2];
}POOL[maxn*30],*MPCNT,*ROOT;

inline void ins(Node *&o,int dep,int x)
{
    if(o==0)
    {
        o=MPCNT++;
        o->ch[0]=o->ch[1]=0;
    }
    if(dep==-1) return ;
    ins(o->ch[!!(x&(1<<dep))],dep-1,x);
}

LL ans;

int dfs2(Node *o,Node *u,int dep)
{
    if(o==0 || u==0) return INF;
    if(dep==-1) return 0;

    int res=INF;
    bool t = (o->ch[0] && u->ch[0]) | (o->ch[1] && u->ch[1]) ;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
        {
            if(t==0 || (t!=0 && i==j)) Min(res,dfs2(o->ch[i],u->ch[j],dep-1)|(i==j ? 0 : (1<<dep)));
        }
    return res;
}

void dfs(Node *o,int dep)
{
    if(o==0) return ;

    if(o->ch[0]!=0 && o->ch[1]!=0)
    {
        ans+=dfs2(o->ch[0],o->ch[1],dep-1)|(1<<dep);
    }

    if(o->ch[0]) dfs(o->ch[0],dep-1);
    if(o->ch[1]) dfs(o->ch[1],dep-1);

}

void work()
{
    int n;
    read(n);
    MPCNT=POOL;
    ROOT=0;
    for(int i=0;i<n;i++)
    {
        int x; read(x);
        ins(ROOT,30,x);
    }
    ans=0;
    dfs(ROOT,30);
    cout <<ans <<endl;
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