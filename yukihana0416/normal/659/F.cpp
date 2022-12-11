#pragma comment(linker,"/STACK:102400000,102400000")
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <assert.h>
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

#define I64d_OJ

#ifdef I64d_OJ
#define LL __int64
#endif // I64d_OJ
#ifndef I64d_OJ
#define LL long long
#endif // I64d_OJ

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
#define MK(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define lowbit(x) ((x)&-(x))

typedef unsigned LL ULL;
typedef unsigned uint;
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
inline void swapt(T &a,T &b) {T c=a;a=b;b=c;}
template< typename T >
inline void Max(T &a, T b) {if(a<b) a=b;}
template< typename T >
inline void Min(T &a, T b) {if(b<a) a=b;}
template< typename T >
inline T maxt(T a,T b) {if(a<b) return b; else return a;}
template< typename T >
inline T mint(T a,T b) {if(a<b) return a; else return b;}

const double pi=(double) acos(-1.0);
const int MOD=(int) 1e9+7;
const int INF=(int) 0x3f3f3f3f;
const LL  LINF=(LL) 0x3f3f3f3f3f3f3f3f;
const int SINF=(uint) ~0U>>1;
const LL  SLINF=(ULL) (-1)>>1;
const double DINF=(double) 1e50;
const double eps=(double) 1e-8;
const int maxn=(int) 1e4+15;
const int maxm=(int) 124750+15;

LL gcd(LL x,LL y) {LL t; while(y) t=x%y,x=y,y=t; return absx(x);}
inline int sig(double x) {return x<-eps?-1:x>eps;}

//--------------start------------------

int n,m;
LL k;
int mp[1001][1001];
int fa[1000005];
int sz[1000005];
pii a[1000005];

int find_fa(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find_fa(fa[x]);
}

void Ui(int x,int y)
{
    int X=find_fa(x), Y=find_fa(y);
    if(X==Y) return ;
    if(sz[X]<sz[Y]) swap(X,Y);
    fa[Y]=X;
    sz[X]+=sz[Y];
}

bool vis[1001][1001];

int cmp(pii a,pii b)
{
    return a.fi>b.fi;
}

int dir[4][2]={
    {1,0},{-1,0},{0,1},{0,-1}
};

//LL can[1000005];

void BFS(int x,int y,int cnt,int num,int f)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            mp[i][j]=0;
    queue<pii> Q;
    cnt--;
    mp[x][y]=num;
    Q.push(MK(x,y));
    while(!Q.empty())
    {
        pii now=Q.front(); Q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=now.fi+dir[i][0], ny=now.se+dir[i][1];
            if(nx<0 || nx>=n || ny<0 || ny>=m || vis[nx][ny]==0 || mp[nx][ny]!=0) continue;
            if(cnt==0) return ;
            int ff=find_fa(nx*m+ny);
            if(ff!=f) continue;
            mp[nx][ny]=num;
            cnt--;
            Q.push(MK(nx,ny));
        }
    }
}

void work()
{
    read(n), read(m);
    read(k);
//    cout <<n <<" " <<m <<endl;
    for(int i=0;i<n*m;i++) fa[i]=i, sz[i]=1;
    memset(vis,0,sizeof(vis));

    int temp;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            read(temp);
            a[i*m+j]=MK(temp,i*m+j);
        }
    sort(a,a+n*m,cmp);

//    can[1]=k;
//    for(int i=2;i<=m*n;i++)
//    {
//        if(k%i==0) can[i]=k/i;
//        else can[i]=can[i-1];
//    }
//    for(int i=1;i<=n*m;i++) cout <<can[i] <<" "; cout <<endl;

    for(int i=0;i<n*m;i++)
    {
        int posx=a[i].se/m, posy=a[i].se%m;
        vis[posx][posy]=1;
//        cout <<a[i].fi <<" " <<posx <<" " <<posy <<endl;
        int f;
        for(int j=0;j<4;j++)
        {
            int nx=posx+dir[j][0], ny=posy+dir[j][1];
            if(nx<0 || nx>=n || ny<0 || ny>=m || vis[nx][ny]==0) continue;
            Ui(a[i].se,nx*m+ny);
        }
        f=find_fa(a[i].se);
        int ss=sz[f];
        if(k%a[i].fi==0 && sz[f]>=k/a[i].fi)
        {
//            cout <<a[i].fi <<" " <<can[ss] <<endl;
            int cnt=k/a[i].fi;
//            cout <<cnt <<endl;
            BFS(posx,posy,cnt,a[i].fi,f);
            puts("YES");
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(j) putchar(' ');
                    printf("%d",mp[i][j]);
                }
                putchar('\n');
            }
            return ;
        }
    }
    puts("NO");
}

//--------------end------------------

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