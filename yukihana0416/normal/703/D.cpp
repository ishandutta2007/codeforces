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
const int maxn=(int) 1e6+20;
const int maxm=(int) 3e4+15;

inline int sig(double x) {return x<-eps?-1:x>eps;}
inline void fadd(LL &x,LL a) {x+=a; if(x>=MOD) x-=MOD;}

//--------------start------------------

struct opt
{
    int l,r,id;
    bool operator < (const opt &t) const {return r<t.r;}
}op[maxn];
int ans[maxn];
int dp[maxn],a[maxn];
int n,m;
map<int,int> pre;

int T[maxn];

inline void add(int pos,int val)
{
    for(int i=pos;i<=n;i+=lowbit(i)) T[i]^=val;
}
inline int sum(int pos)
{
    int res=0;
    for(int i=pos;i;i-=lowbit(i)) res^=T[i];
    return res;
}

void work()
{
    while(~scanf("%d",&n))
    {
        pre.clear();
        dp[0]=0;
        for(int i=1;i<=n;i++) read(a[i]);
        for(int i=1;i<=n;i++) T[i]=0;

        read(m);
        for(int i=0;i<m;i++) read(op[i].l), read(op[i].r), op[i].id=i;
        sort(op,op+m);
        int temp,last=0;
        for(int i=1,j=0;i<=n;i++)
        {
            dp[i]=dp[i-1]^a[i];
            int pr=pre[a[i]];
            if(pr==0)
            {
                last^=a[i];
                pre[a[i]]=i;
                add(i,a[i]);
            }
            else
            {
                add(pr,a[i]);
                add(i,a[i]);
                pre[a[i]]=i;
            }
            while(j<m && op[j].r==i)
            {
                int L,R; L=op[j].l, R=op[j].r;
                temp=dp[R]^dp[L-1];
                ans[op[j].id]=temp^last^sum(L-1);
//                cout <<L <<" " <<R <<" " <<temp <<endl;
                j++;
            }
        }
        for(int i=0;i<m;i++) printf("%d\n",ans[i]);
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