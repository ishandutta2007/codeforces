#pragma comment(linker,"/STACK:102400000,102400000")
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <climits>
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
#include <cassert>
using namespace std;

#define VT vector
#define LL long long
typedef unsigned LL ULL;
typedef unsigned uint;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<LL,LL> pLL;

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

LL gcd(LL a,LL b) {if(!b) return a; else return gcd(b,a%b);}

const double pi=(double) acos(-1.0);
const double eps=(double) 1e-8;
const int INF=(int) 0x3f3f3f3f;
const LL  LINF=(ULL)(-1) >> 2;
const int SINF=(uint) ~0U>>1;
const double DINF=(double) 1e50;
const int MOD=(int) 1e9+7;
const int maxn=(int) 5e3+20;
const int maxm=(int) 1e6+20;

ULL msg[60000];
int cnt;

void pre_work()
{
    cnt=0;
    ULL t;
    for(int i=0;i<64;i++)
    {
        t=0;
        for(int j=0;j<i;j++)
            t|=((ULL) 1) << j;
        for(int j=0;j<i-1;j++)
        {
            msg[cnt++]=t ^ (((ULL)1)<<j);
        }
    }
}


void work()
{
    pre_work();
    ULL a,b;
    a=read(), b=read();
    int ans=0;
    for(int i=0;i<cnt;i++)
    {
        if(a<=msg[i] && msg[i]<=b) ans++;
    }
    cout <<ans <<endl;
}


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