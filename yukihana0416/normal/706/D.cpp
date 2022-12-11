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

const double pi=(double) acos(-1.0);
const int MOD=(int) 1e9+7;
const int INF=(int) 0x3f3f3f3f;
const LL  LINF=(LL) INF<<32|INF;
const int SINF=(uint) ~0>>1;
const LL  SLINF=(ULL) (-1)>>1;
const double DINF=(double) 1e50;
const double eps=(double) 1e-8;
const int maxn=(int) 2e5+20;
const int maxm=(int) 100000+15;

inline int sig(double x) {return x<-eps?-1:x>eps;}
inline void fadd(LL &x,LL a) {x+=a; if(x>=MOD) x-=MOD;}

//--------------start------------------

int n;
int tot,cnt[maxn*20],ch[maxn*20][2],rt;

void ins(int val,int num,int dep,int &o)
{
    if(o==0) o=++tot, ch[o][0]=ch[o][1]=0;
    cnt[o]+=val;
    if(dep==-1) return ;
    if((1<<dep)&num) ins(val,num,dep-1,ch[o][1]);
    else ins(val,num,dep-1,ch[o][0]);
}

void query(int num,int dep,int o,int &res)
{
    if(dep==-1) return ;
    bool bit=(1<<dep)&num;
    if(ch[o][!bit]!=0 && cnt[ch[o][!bit]]!=0)
    {
        res|=(1<<dep);
        query(num,dep-1,ch[o][!bit],res);
    }
    else
    {
        query(num,dep-1,ch[o][bit],res);
    }
}

void work()
{
    while(~scanf("%d",&n))
    {
        rt=0; tot=0;
        ins(1,0,30,rt);
        char cmd[3]; int x;
        for(int i=0;i<n;i++)
        {
            scanf("%s%d",cmd,&x);
            if(cmd[0]=='+')
            {
                ins(1,x,30,rt);
            }
            else if(cmd[0]=='-')
            {
                ins(-1,x,30,rt);
            }
            else
            {
                int ans=0;
                query(x,30,rt,ans);
                printf("%d\n",ans);
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