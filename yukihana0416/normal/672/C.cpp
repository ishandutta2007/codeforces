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

struct item
{
    double dis;
    int idx,type;
    item() {}
    item(double _d,int _i,int _t):dis(_d),idx(_i),type(_t) {}
    bool operator < (const item &t) const {return dis>t.dis;}
};
inline double Dis(double x,double y,double X,double Y)
{
    double cx=x-X, cy=y-Y;
    return sqrt(cx*cx+cy*cy);
}

int n;
double ax,ay,bx,by;
double tx,ty;

double dp[maxn][4];
double c[maxn][2];

void work()
{
    while(~scanf("%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&tx,&ty))
    {

        scanf("%d",&n);
        int p=0;
        double tot_dis=0.0;
        for(int i=1;i<=n;i++)
        {
            double x,y; scanf("%lf%lf",&x,&y);
            double td,d;
            d=Dis(x,y,tx,ty)*2.0;
            tot_dis+=d;
            td=Dis(ax,ay,x,y)+Dis(x,y,tx,ty);
            c[i][0]=td-d;
            td=Dis(bx,by,x,y)+Dis(x,y,tx,ty);
            c[i][1]=td-d;
        }

        dp[0][0]=0.0;
        dp[0][1]=0.0;
        dp[0][2]=0.0;
        dp[0][3]=DINF;
        for(int i=1;i<=n;i++)
        {
            dp[i][0]=dp[i-1][0];
            dp[i][1]=min(dp[i-1][1],dp[i-1][0]+c[i][0]);
            dp[i][2]=min(dp[i-1][2],dp[i-1][0]+c[i][1]);
            dp[i][3]=dp[i-1][3];
            Min(dp[i][3],dp[i-1][1]+c[i][1]);
            Min(dp[i][3],dp[i-1][2]+c[i][0]);
        }

        printf("%.12f\n",tot_dis+dp[n][3]);
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