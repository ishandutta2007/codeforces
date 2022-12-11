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
    while(fr_ch<'0' || '9'<fr_ch) {if(fr_ch=='-') fr_f=1; fr_ch=getchar();}
    while('0'<=fr_ch && fr_ch<='9') {x=(x<<1)+(x<<3)+fr_ch-'0'; fr_ch=getchar();}
    if(fr_f) x=-x;
}

template< typename T > inline void Max (T &a, T b) {if(a<b) a=b;}
template< typename T > inline void Min (T &a, T b) {if(b<a) a=b;}
template< typename T > inline void Swap(T &a, T &b) {T c=a;a=b;b=c;}
template< typename T > inline T Abs(T a) {if(a<0) return -a; else return a;}

const double   pi = acos(-1.0) ;
const int     MOD = (int)1e9+7 ;
const int     INF = (int)0x3f3f3f3f ;
const LL     LINF = (LL)INF<<32|INF ;
const int    SINF = (uint)(-1)>>1 ;
const LL    SLINF = (ULL)(-1)>>1 ;
const double DINF = 1e50 ;
const double  eps = 1e-5 ;
const int    maxn = (int) 2e5+20 ;
const int    maxm = (int) 1e6+20 ;
const int    maxk = (int) 1000+20 ;

inline int sig(double x) {return x<-eps?-1:x>eps;}
inline LL fp(LL a,LL n,LL p) {LL res=1; for(;n;n>>=1,a=a*a%p) if(n&1) res=res*a%p; return res;}
template<typename T>inline T gcd(T a,T b) {for(T c;b;c=a%b,a=b,b=c); return a;}

//--------------------start--------------------

int n;
int a[maxn];
vector<int> E[maxn];
int x[maxn], y[maxn];

LL cnt;
int fa[maxn], sz[maxn];
LL ans[maxn];

int find_fa(int x)
{
    if(x == fa[x]) return x;
    return fa[x] = find_fa(fa[x]);
}

void mer(int x, int y)
{
    x = find_fa(x);
    y = find_fa(y);

    if(x == y) return ;

    cnt += (LL) sz[x] * sz[y];
    fa[x] = y;
    sz[y] += sz[x];
}

void work()
{
    read(n);
    for(int i = 1; i <= n; i++) read(a[i]);
    for(int i = 1; i < n; i++)
    {
        read(x[i]);
        read(y[i]);
        E[gcd(a[x[i]], a[y[i]])].pb(i);
    }

    for(int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1;
    for(int i = 0; i < maxn; i++) ans[i] = 0;
    cnt = 0;

    for(int i = 1; i < maxn; i++)
    {
        for(int j = i; j < maxn; j += i)
        {
            for(int k = 0; k < E[j].size(); k++)
            {
                int p = E[j][k];
                mer(x[p], y[p]);
            }
        }
        ans[i] = cnt;

        for(int j = i; j < maxn; j += i)
        {
            for(int k = 0; k < E[j].size(); k++)
            {
                int p = E[j][k];
                fa[x[p]] = x[p];
                fa[y[p]] = y[p];
                sz[x[p]] = 1;
                sz[y[p]] = 1;
            }
        }
        cnt = 0;
    }

    for(int i = maxn - 1; i > 0; i--)
    {
        for(int j = i + i; j < maxn; j += i)
        {
            ans[i] -= ans[j];
        }
    }

    for(int i = 1; i <= n; i++) ans[a[i]]++;

    for(int i = 1; i < maxn; i++) if(ans[i])
        printf("%d %lld\n", i, ans[i]);
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