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


int n;
char s[1005][1005];
double d[]={(double)-INF,0.0,log10(2.0),log10(3.0)};
struct item
{
    double tot;
    int two,three;
    item() {}
    item(double _tot,int _two,int _three):tot(_tot),two(_two),three(_three) {}
    bool operator < (const item &t) const {return tot<t.tot;}
    item operator + (const item &t) const {return item(tot+t.tot,two+t.two,three+t.three);}
    item operator - (const item &t) const {return item(tot-t.tot,two-t.two,three-t.three);}
    inline void set(int x) { tot=d[x], two=x==2, three=x==3; }
}dp[8][1005][1005],mp[1005][1005],ans;

LL fp(LL x,LL n)
{
    LL res=1;
    while(n)
    {
        if(n&1) res=res*x%MOD;
        x=x*x%MOD; n>>=1;
    }
    return res;
}

void work()
{
    while(~scanf("%d",&n))
    {
        ans.set(0);
        memset(dp,0,sizeof(dp));
        memset(s,'0',sizeof(s));
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) mp[i][j].set(s[i][j]-'0');
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                dp[0][i][j]=dp[0][i-1][j]+mp[i][j];
                dp[1][i][j]=dp[1][i][j-1]+mp[i][j];
                dp[4][i][j]=dp[4][i-1][j-1]+mp[i][j];
                dp[5][i][j]=dp[5][i-1][j+1]+mp[i][j];
            }
        for(int i=n;i;i--)
            for(int j=n;j;j--)
            {
                dp[2][i][j]=dp[2][i+1][j]+mp[i][j];
                dp[3][i][j]=dp[3][i][j+1]+mp[i][j];
                dp[6][i][j]=dp[6][i+1][j+1]+mp[i][j];
                dp[7][i][j]=dp[7][i+1][j-1]+mp[i][j];
            }

        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(s[i][j]=='0') continue;
                int ed=n;
                Min(ed,i-1),Min(ed,n-i),Min(ed,j-1),Min(ed,n-j);
                int l,r;
                l=0,r=ed;
                item it[4];
                int res;
                while(l<=r)
                {
                    int mid=MID(l,r);
                    it[0]=dp[0][i+mid][j]-dp[0][i][j];
                    it[1]=dp[1][i][j+mid]-dp[1][i][j];
                    it[2]=dp[2][i-mid][j]-dp[2][i][j];
                    it[3]=dp[3][i][j-mid]-dp[3][i][j];

                    if(sig(it[0].tot)<0 || sig(it[1].tot)<0 || sig(it[2].tot)<0 || sig(it[3].tot)<0)
                    {
                        r=mid-1;
                    }
                    else
                    {
                        l=mid+1;
                        res=mid;
                    }
                }
                    it[0]=dp[0][i+res][j]-dp[0][i][j];
                    it[1]=dp[1][i][j+res]-dp[1][i][j];
                    it[2]=dp[2][i-res][j]-dp[2][i][j];
                    it[3]=dp[3][i][j-res]-dp[3][i][j];
                Max(ans,it[0]+it[1]+it[2]+it[3]+mp[i][j]);

                l=0,r=ed;
                while(l<=r)
                {
                    int mid=MID(l,r);
                    it[0]=dp[4][i+mid][j+mid]-dp[4][i][j];
                    it[1]=dp[5][i+mid][j-mid]-dp[5][i][j];
                    it[2]=dp[6][i-mid][j-mid]-dp[6][i][j];
                    it[3]=dp[7][i-mid][j+mid]-dp[7][i][j];

                    if(sig(it[0].tot)<0 || sig(it[1].tot)<0 || sig(it[2].tot)<0 || sig(it[3].tot)<0)
                    {
                        r=mid-1;
                    }
                    else
                    {
                        l=mid+1;
                        res=mid;
                    }
                }
                    it[0]=dp[4][i+res][j+res]-dp[4][i][j];
                    it[1]=dp[5][i+res][j-res]-dp[5][i][j];
                    it[2]=dp[6][i-res][j-res]-dp[6][i][j];
                    it[3]=dp[7][i-res][j+res]-dp[7][i][j];
                Max(ans,it[0]+it[1]+it[2]+it[3]+mp[i][j]);
            }
        int last=1;
        last=fp(2,ans.two)*fp(3,ans.three)%MOD;
        if(ans.tot<0) last=0;
        cout <<last <<endl;
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