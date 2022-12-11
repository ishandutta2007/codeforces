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

template< typename T > inline void read(T &res) {
    T x=0; bool f=0; char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-')f=!f; ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    res = f ? -x : x ;
}

template< typename T > inline void Max(T &a, T b) {if(a<b) a=b;}
template< typename T > inline void Min(T &a, T b) {if(b<a) a=b;}
template< typename T > inline T Abs(T a) {if(a<0) a=-a; return a;}

const double pi=(double) acos(-1.0);
const int MOD=(int) 1e9+7;
const int INF=(int) 0x3f3f3f3f;
const LL  LINF=(LL) INF<<32|INF;
const int SINF=(uint) ~0>>1;
const LL  SLINF=(ULL) (-1)>>1;
const double DINF=(double) 1e50;
const double eps=(double) 1e-8;
const int maxn=(int) 1e6+20;
const int maxm=(int) 5e5+15;

inline int sig(double x) {return x<-eps?-1:x>eps;}

//--------------start------------------

int n;
int A[35];
int ans;
bool Map[400][400];
bool vis[400][400][3][3][31];

void Next_dir(int dx,int dy,int &dx1,int &dy1,int &dx2,int &dy2)
{
    dx1=dx2=dx;
    dy1=dy2=dy;
    if(dx==0) dx1++, dx2--;
    else if(dy==0) dy1++, dy2--;
    else
    {
        if(dx==1) dx1--;
        else dx1++;
        if(dy==1) dy2--;
        else dy2++;
    }
}

void dfs(int dep,int x,int y,int dx,int dy)
{
    if(dep==n+1) return ;
    if(vis[x][y][dx+1][dy+1][dep]) return ;
    vis[x][y][dx+1][dy+1][dep]=1;
    int dx1,dy1,dx2,dy2;
    Next_dir(dx,dy,dx1,dy1,dx2,dy2);
    for(int i=0;i<A[dep];i++)
    {
        ans+=!Map[x][y];
        Map[x][y]=1;
        x+=dx; y+=dy;
    }
    x-=dx, y-=dy;
    dfs(dep+1,x+dx1,y+dy1,dx1,dy1);
    dfs(dep+1,x+dx2,y+dy2,dx2,dy2);
}

void work()
{
    read(n);
    for(int i=1;i<=n;i++) read(A[i]);

    ans=0;
    dfs(1,200,200,0,1);
    printf("%d\n",ans);
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