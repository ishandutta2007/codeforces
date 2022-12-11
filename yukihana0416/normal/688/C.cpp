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
typedef pair<LL,LL> pLL;
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
const int maxm=(int) 1000000+15;

inline int sig(double x) {return x<-eps?-1:x>eps;}

//--------------start------------------

int n,m;
vi G[maxn];
vi ss[2];

int vis[maxn];


bool dfs(int u,int fa,int k)
{
    bool res=1;
    vis[u]=k;
    ss[k].pb(u);
    int sz=G[u].size();
    for(int i=0;i<sz;i++)
    {
        int v=G[u][i];
        if(v==fa) continue;
        if(vis[v]==k) return false;
        if(vis[v]==-1) res&=dfs(v,u,!k);
    }
    return res;
}

void work()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=0;i<m;i++)
        {
            int x,y; read(x), read(y);
            G[x].pb(y); G[y].pb(x);
        }
        memset(vis,-1,sizeof(vis));
        for(int i=0;i<2;i++) ss[i].clear();


        bool flag=1;
        for(int i=1;i<=n;i++) if(vis[i]==-1)
        {
            flag&=dfs(i,0,0);
        }

        if(flag==0)
        {
            puts("-1");
        }
        else
        {
            for(int j=0;j<2;j++)
            {
                int sz;
                sz=ss[j].size();
                printf("%d\n",sz);
                for(int i=0;i<sz;i++) printf("%d%c",ss[j][i], i==sz-1 ? '\n' : ' ' );
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