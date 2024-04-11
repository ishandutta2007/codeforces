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
const int maxn=(int) 4e2+20;
const int maxm=(int) 1e6+15;

inline int sig(double x) {return x<-eps?-1:x>eps;}
inline void fadd(LL &x,LL a) {x+=a; if(x>=MOD) x-=MOD;}

//--------------start------------------

int n,m;
vi G[maxn];
int dis[maxn][maxn];
int dd[maxn][maxn];

double mx_pro[maxn],pro[maxn];
bool vis[maxn];
vector<int> tar;

double get_next(int x,int d)
{
    memset(vis,0,sizeof(vis));
    memset(pro,0,sizeof(pro));

    tar.clear();
    for(int i=1;i<=n;i++)
    {
        if(dis[x][i]!=d) continue;
        int sz=G[i].size();
        for(int j=0;j<sz;j++)
        {
            int v=G[i][j];
            pro[v]+=1.0/(sz*n);
            if(!vis[v])
            {
                vis[v]=1;
                tar.pb(v);
            }
        }
    }

    double res=0.0;
    for(int i=1;i<=n;i++)
    {
        int sz=tar.size();
        for(int j=0;j<sz;j++)
        {
            int v=tar[j];
            Max(mx_pro[dis[i][v]],pro[v]);
        }
        double temp_sum=0.0;
        for(int j=0;j<sz;j++)
        {
            int v=tar[j];
            temp_sum+=mx_pro[dis[i][v]];
            mx_pro[dis[i][v]]=0.0;
        }
        Max(res,temp_sum);
    }

    return res;
}

void work()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(dis,0x3f,sizeof(dis));
        for(int i=1;i<=n;i++) dis[i][i]=0, G[i].clear();
        for(int i=0;i<m;i++)
        {
            int x,y; read(x), read(y);
            G[x].pb(y); G[y].pb(x);
            dis[x][y]=dis[y][x]=1;
        }

        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    Min(dis[i][j],dis[i][k]+dis[k][j]);


        memset(dd,0,sizeof(dd));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(dis[i][j]<=n)
                    dd[i][dis[i][j]]++;

        double ans=0.0;
        for(int i=1;i<=n;i++)
        {
            double Pros=0.0;
            for(int d=0;d<n;d++)
            {
                if(!dd[i][d]) continue;
                Pros+=max(1.0/(double)n,get_next(i,d));
            }
            Max(ans,Pros);
        }
        printf("%.12lf\n",ans);
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