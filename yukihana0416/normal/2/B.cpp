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
    static bool fr_f; static char fr_ch;
    fr_f=0; x=0; fr_ch=getchar();
    while(fr_ch<'0' || fr_ch>'9') {if(fr_ch=='-') fr_f=1; fr_ch=getchar();}
    while(fr_ch>='0' && fr_ch<='9') {x=(x<<1)+(x<<3)+fr_ch-'0'; fr_ch=getchar();}
    if(fr_f) x=-x;
}

template< typename T > inline void Max(T &a, T b) {if(a<b) a=b;}
template< typename T > inline void Min(T &a, T b) {if(b<a) a=b;}
template< typename T > inline T Abs(T a) {if(a<0) return -a; else return a;}

const double pi   =    acos(-1.0) ;
const int MOD     = (int)1e9+7 ;
const int INF     = (int)0x3f3f3f3f ;
const LL  LINF    = (LL)INF<<32|INF ;
const int SINF    = (uint)(-1)>>1 ;
const LL  SLINF   = (ULL)(-1)>>1 ;
const double DINF = 1e50 ;
const double eps  = 1e-8 ;
const int maxn    = (int) 3e5+20 ;
const int maxm    = (int) 25000+20 ;
const int maxk    = (int) 1000+20 ;

inline int sig(double x) {return x<-eps?-1:x>eps;}
inline LL fp(LL a,LL n,LL p) {LL res=1; for(;n;n>>=1,a=a*a%p) if(n&1) res=res*a%p; return res;}
template<typename T>inline T gcd(T a,T b) {for(T c;b;c=a%b,a=b,b=c); return a;}

//--------------------start--------------------

int n,ze;
int dp2[1005][1005],dp5[1005][1005];
char ro[2005];
int rc;


void work()
{
    read(n);
    ze=0;
    int zx,zy;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            int x, c2, c5; read(x);
            if(x==0)
            {
                c2=c5=1;
                ze=1;
                zx=i,zy=j;
            }
            else
            {
                c2=c5=0;
                int tmp=x;
                while(tmp%2==0)
                {
                    c2++;
                    tmp/=2;
                }
                tmp=x;
                while(tmp%5==0)
                {
                    c5++;
                    tmp/=5;
                }
            }

            dp2[i][j]=c2, dp5[i][j]=c5;
            if(i==1 && j==1) ;
            else if(i==1) dp2[i][j]+=dp2[i][j-1], dp5[i][j]+=dp5[i][j-1];
            else if(j==1) dp2[i][j]+=dp2[i-1][j], dp5[i][j]+=dp5[i-1][j];
            else dp2[i][j]+=min(dp2[i-1][j],dp2[i][j-1]), dp5[i][j]+=min(dp5[i-1][j],dp5[i][j-1]);
        }

    int ans;

    int tct=2*n-2;

    if(dp2[n][n]<dp5[n][n])
    {
        ans=dp2[n][n];
        int x=n,y=n;
        rc=0;
        while(1)
        {
            if((x==1 && y==1) || (tct==0)) break;
            else if(x==1) ro[rc++]='R', y--;
            else if(y==1) ro[rc++]='D', x--;
            else
            {
                if(dp2[x-1][y]<dp2[x][y-1]) ro[rc++]='D', x--;
                else ro[rc++]='R', y--;
            }
            tct--;
//            if(a[1][1]==933) cout <<x <<" " <<y <<endl;

            if(x<1 || y<1) while(1);
        }
        reverse(ro,ro+rc);
    }
    else
    {
        ans=dp5[n][n];
        int x=n,y=n;
        rc=0;
        while(1)
        {
            if((x==1 && y==1) || (tct==0)) break;
            else if(x==1) ro[rc++]='R', y--;
            else if(y==1) ro[rc++]='D', x--;
            else
            {
                if(dp5[x-1][y]<dp5[x][y-1]) ro[rc++]='D', x--;
                else ro[rc++]='R', y--;
            }
            tct--;
//            if(a[1][1]==933) cout <<x <<" " <<y <<endl;

            if(x<1 || y<1) while(1);
        }
        reverse(ro,ro+rc);
    }

    if(ans>1 && ze)
    {
        rc=0;
        for(int i=1;i<zx;i++) ro[rc++]='D';
        for(int i=1;i<n;i++) ro[rc++]='R';
        for(int i=zx;i<n;i++) ro[rc++]='D';
        ans=1;
    }
    ro[rc]=0;
    printf("%d\n%s\n",ans,ro);
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