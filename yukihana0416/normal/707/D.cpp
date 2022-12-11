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
//#define ls id<<1
//#define rs id<<1|1
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
const int maxn=(int) 1e5+20;
const int maxm=(int) 1000000+15;

inline int sig(double x) {return x<-eps?-1:x>eps;}
inline void fadd(LL &x,LL a) {x+=a; if(x>=MOD) x-=MOD;}

//--------------start------------------

int n,m,k;
int cnt[maxn*80],flag[maxn*80],ch[maxn*80][2],tot;
int rt[maxn];

inline void Copy(int x,int y)
{
    cnt[x]=cnt[y];
    flag[x]=flag[y];
    ch[x][0]=ch[y][0];
    ch[x][1]=ch[y][1];
}

inline void lazy(int l,int r,int &o)
{
    if(!flag[o]) return ;
    flag[o]=0;
    int ls=ch[o][0],rs=ch[o][1];
    ch[o][0]=++tot; ch[o][1]=++tot;
    Copy(ch[o][0],ls); Copy(ch[o][1],rs);
    flag[ch[o][0]]^=1;
    flag[ch[o][1]]^=1;
    int mid=MID(l,r);
    cnt[ch[o][0]]=(mid-l+1)-cnt[ch[o][0]];
    cnt[ch[o][1]]=(r-mid)-cnt[ch[o][1]];
}

int Set(int pos,int val,int l,int r,int id,int o)
{
    int res=++tot;
    Copy(res,o);
    if(l==r)
    {
        cnt[res]=val;
        return res;
    }
    lazy(l,r,res);
    int mid=MID(l,r);
    if(pos<=mid) ch[res][0]=Set(pos,val,lson,ch[res][0]);
    else ch[res][1]=Set(pos,val,rson,ch[res][1]);
    cnt[res]=cnt[ch[res][0]]+cnt[ch[res][1]];
    return res;
}

int update(int L,int R,int l,int r,int id,int o)
{
    int res=++tot;
    Copy(res,o);
    if(L<=l && r<=R)
    {
        flag[res]^=1;
        cnt[res]=(r-l+1)-cnt[res];
        return res;
    }
    lazy(l,r,res);
    int mid=MID(l,r);
    if(L<=mid) ch[res][0]=update(L,R,lson,ch[res][0]);
    if(mid<R) ch[res][1]=update(L,R,rson,ch[res][1]);
    cnt[res]=cnt[ch[res][0]]+cnt[ch[res][1]];
    return res;
}

void work()
{
    ch[0][0]=ch[0][1]=0;
    flag[0]=cnt[0]=0;
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        tot=0; rt[0]=0;
        int now=0;
        for(int i=0;i<k;i++)
        {
            int cmd; read(cmd);
            if(cmd==1)
            {
                int x,y; read(x), read(y);
                x--,y--;
                rt[now+1]=Set(x*m+y,1,0,n*m,1,rt[now]);
                now++;
            }
            else if(cmd==2)
            {
                int x,y; read(x), read(y);
                x--,y--;
                rt[now+1]=Set(x*m+y,0,0,n*m,1,rt[now]);
                now++;
            }
            else if(cmd==3)
            {
                int x; read(x);
                x--;
                rt[now+1]=update(x*m,(x+1)*m-1,0,n*m,1,rt[now]);
                now++;
            }
            else
            {
                int x; read(x);
                rt[now+1]=rt[x];
                now++;
            }
            printf("%d\n",cnt[rt[now]]);
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