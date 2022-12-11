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
const double eps=(double) 1e-4;
const int maxn=(int) 1e5+10;
const int maxm=(int) 2e4+10;
const int maxk=(int) 5e2+10;

inline int sig(double x) {return x<-eps?-1:x>eps;}

//--------------start------------------

int n,m;
int vis[1005][1005],vis2[1005][1005],vis3[1005][1005];
char mp[1005][1005];

void gao(int x,int y,int kk,int vis[1005][1005],int vis2[1005][1005])
{
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) vis[i][j]=0;
    vis[x][y]=1;

    for(int k=0;k<kk;k++)
    {
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) vis2[i][j]=0;

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(vis[i][j])
                {
                    int t;
                    t=i;
                    while(t>=0 && mp[t][j]!='*')
                    {
                        vis2[t][j]=1;
                        t--;
                    }
                    t=i;
                    while(t<n && mp[t][j]!='*')
                    {
                        vis2[t][j]=1;
                        t++;
                    }
                    t=j;
                    while(t>=0 && mp[i][t]!='*')
                    {
                        vis2[i][t]=1;
                        t--;
                    }
                    t=j;
                    while(t<m && mp[i][t]!='*')
                    {
                        vis2[i][t]=1;
                        t++;
                    }

                }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                vis[i][j]=vis2[i][j];
    }
}

void work()
{
    read(n), read(m);
    for(int i=0;i<n;i++) scanf("%s",mp[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(mp[i][j]=='S')
                gao(i,j,2,vis,vis3);
            else if(mp[i][j]=='T')
                gao(i,j,1,vis2,vis3);

    bool ans=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            ans|=vis[i][j]&vis2[i][j];
    if(ans) puts("YES");
    else puts("NO");
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