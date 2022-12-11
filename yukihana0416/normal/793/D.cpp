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

template< typename T > inline void read(T &x) {
    bool f=0; char ch=getchar(); x=0;
    while(ch<'0' || ch>'9') {if(ch=='-') f=1; ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    if(f) x=-x;
}

template< typename T > inline void Max(T &a, T b) {if(a<b) a=b;}
template< typename T > inline void Min(T &a, T b) {if(b<a) a=b;}
template< typename T > inline T Abs(T a) {if(a<0) return -a; else return a;}

const double pi=(double) acos(-1.0);
const int MOD=(int) 1e7+9;
const int INF=(int) 0x3f3f3f3f;
const LL  LINF=(LL) INF<<32|INF;
const int SINF=(uint) ~0>>1;
const LL  SLINF=(ULL) (-1)>>1;
const double DINF=(double) 1e50;
const double eps=(double) 1e-8;
const int maxn=(int) 2e5+10;
const int maxm=(int) 2e4+10;
const int maxk=(int) 5e2+10;

inline int sig(double x) {return x<-eps?-1:x>eps;}

//--------------start------------------

int n,m,k;
int dp[82][82][82][82];
int G[88][88];

queue< pair<pii,pii> > Q;
bool inq[82][82][82][82];
void spfa(int x,int y,int z,int q)
{
    while(!Q.empty()) Q.pop();
    Q.push(mk(mk(x,y),mk(z,q)));
    inq[x][y][z][q]=1;
    dp[x][y][z][q]=0;
    int nx,ny,nz,nq,val;
    while(!Q.empty())
    {
        nx=Q.front().fi.fi;
        ny=Q.front().fi.se;
        nz=Q.front().se.fi;
        nq=Q.front().se.se;
        Q.pop();
        inq[nx][ny][nz][nq]=0;

        if(nq==k) continue;

        for(int i=nx;i<=ny;i++) if(G[nz][i]!=-1)
        {
            val=dp[nx][ny][nz][nq]+G[nz][i];
            if(i<nz)
            {
                if(dp[nx][nz-1][i][nq+1]<=val) continue;
                dp[nx][nz-1][i][nq+1]=val;
                Q.push(mk(mk(nx,nz-1),mk(i,nq+1)));
                inq[nx][nz-1][i][nq+1]=1;
            }
            else
            {
                if(dp[nz+1][ny][i][nq+1]<=val) continue;
                dp[nz+1][ny][i][nq+1]=val;
                Q.push(mk(mk(nz+1,ny),mk(i,nq+1)));
                inq[nz+1][ny][i][nq+1]=1;
            }
        }
    }
}

void work()
{
    read(n), read(k);
    read(m);

    memset(G,0x3f,sizeof(G));
    for(int i=0;i<m;i++)
    {
        int x,y,z; read(x), read(y), read(z);
        Min(G[x][y],z);
    }

    memset(dp,0x3f,sizeof(dp));

    for(int i=1;i<=n;i++) spfa(1,n,i,0);

    int ans=INF;

    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            for(int q=i;q<=j;q++)
                Min(ans,dp[i][j][q][k-1]);

    if(ans>=INF) ans=-1;
    printf("%d\n",ans);
}

//--------------end--------------------

int main()
{
#ifdef yukihana0416
freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif // yukihana0416
    work();
    return 0;
}