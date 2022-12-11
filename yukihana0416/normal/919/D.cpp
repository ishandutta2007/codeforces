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
const int    maxn = (int) 3e5+20 ;
const int    maxm = (int) 25000+20 ;
const int    maxk = (int) 1000+20 ;

inline int sig(double x) {return x<-eps?-1:x>eps;}
inline LL fp(LL a,LL n,LL p) {LL res=1; for(;n;n>>=1,a=a*a%p) if(n&1) res=res*a%p; return res;}
template<typename T>inline T gcd(T a,T b) {for(T c;b;c=a%b,a=b,b=c); return a;}

//--------------------start--------------------

int n,m;
string s;
vector<int> G[maxn];
int c[maxn];

int vis[maxn];

bool dfs(int u)
{
    vis[u]=2;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(vis[v]==1) continue;
        if(vis[v]==2 || dfs(v)) return 1;
    }
    vis[u]=1;
    return 0;
}

int dp[maxn];

int DP(int u,int k)
{
    if(dp[u]!=-1) return dp[u];
    int res=0;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        Max(res,DP(v,k));
    }
    return dp[u]=res+(c[u]==k);
}

int gao(int k)
{
    memset(dp+1,-1,sizeof(int)*n);

    int res=0;
    for(int i=1;i<=n;i++) Max(res,DP(i,k));
    return res;
}

void work()
{
    read(n), read(m);
    cin >>s;
    for(int i=1;i<=n;i++) c[i]=s[i-1]-'a';

    for(int i=0;i<m;i++)
    {
        int x,y; read(x), read(y);
        G[x].pb(y);
    }

    for(int i=1;i<=n;i++)
        if(!vis[i] && dfs(i))
        {
            puts("-1");
            return ;
        }

    int ans=0;
    for(int i=0;i<26;i++) Max(ans,gao(i));

    printf("%d\n",ans);

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