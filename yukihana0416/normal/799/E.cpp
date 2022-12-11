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
int a[maxn],t[maxn];
int b[4][maxn];

int cmp(const int ax,const int bx) { return a[ax]<a[bx]; }

bool gao(LL &res)
{
    if(k*2-m>b[3][0]) return 0;
    res=0;
    int p[4]={1,1,1,1};
    int cnt1=0, cnt2=0, cntm=0;
    for(int i=1;i<=k*2-m && i<=b[3][0] && i<=m;i++)
    {
        int x=b[3][p[3]];
        cnt1++; cnt2++; cntm++;
        res+=a[x];
        p[3]++;
    }

    while(cntm<m)
    {
        if(cnt1<k && cnt2<k)
        {
            int X1=-1, Y1=-1, X2=-1, Y2=-1;
            if(p[1]<=b[1][0]) X1=b[1][p[1]];
            if(p[2]<=b[2][0]) Y1=b[2][p[2]];
            if(p[3]<=b[3][0]) X2=b[3][p[3]++];
            for(int j=0;j<4;j++) if(p[j]<=b[j][0] && (Y2==-1 || a[Y2]>a[b[j][p[j]]])) Y2=b[j][p[j]];

            if((X1==-1 || Y1==-1) && (X2==-1 || Y2==-1)) return 0;

            if((X1!=-1 && Y1!=-1) && ((X2==-1 || Y2==-1) || a[X1]+a[Y1]<a[X2]+a[Y2]))
            {
                res+=a[X1]+a[Y1];
                cnt1++; cnt2++;
                cntm+=2;
                p[1]++; p[2]++;
                if(~X2) p[3]--;
            }
            else
            {
                res+=a[X2]+a[Y2];
                cnt1+=!!(t[X2]&1)+!!(t[Y2]&1);
                cnt2+=!!(t[X2]&2)+!!(t[Y2]&2);
                cntm+=2;
                for(int j=0;j<4;j++) if(p[j]<=b[j][0] && b[j][p[j]]==Y2) p[j]++;
            }
        }
        else if(cnt1<k)
        {
            int X1=-1, X2=-1;
            if(p[1]<=b[1][0]) X1=b[1][p[1]];
            if(p[3]<=b[3][0]) X2=b[3][p[3]];

            if(X1==-1 && X2==-1) return 0;

            if(X1!=-1 && (X2==-1 || a[X1]<a[X2]))
            {
                res+=a[X1];
                p[1]++;
                cnt1++;
                cntm++;
            }
            else
            {
                res+=a[X2];
                p[3]++;
                cnt1++;
                cntm++;
            }
        }
        else if(cnt2<k)
        {
            int X1=-1, X2=-1;
            if(p[2]<=b[2][0]) X1=b[2][p[2]];
            if(p[3]<=b[3][0]) X2=b[3][p[3]];

            if(X1==-1 && X2==-1) return 0;

            if(X1!=-1 && (X2==-1 || a[X1]<a[X2]))
            {
                res+=a[X1];
                p[2]++;
                cnt2++;
                cntm++;
            }
            else
            {
                res+=a[X2];
                p[3]++;
                cnt2++;
                cntm++;
            }
        }
        else
        {
            int x=-1;
            for(int j=0;j<4;j++) if(p[j]<=b[j][0] && (x==-1 || a[x]>a[b[j][p[j]]])) x=b[j][p[j]];

            if(x==-1) return 0;

            res+=a[x];
            cntm++;
            for(int j=0;j<4;j++) if(p[j]<=b[j][0] && x==b[j][p[j]]) p[j]++;
        }
    }

    return cnt1>=k && cnt2>=k;
}

void work()
{
    read(n), read(m), read(k);
    for(int i=1;i<=n;i++) read(a[i]), t[i]=0;

    int tt; read(tt);
    for(int i=1;i<=tt;i++)
    {
        int x; read(x);
        t[x]|=1;
    }
    read(tt);
    for(int i=1;i<=tt;i++)
    {
        int x; read(x);
        t[x]|=2;
    }

    for(int j=0;j<4;j++)
    {
        b[j][0]=0;
        for(int i=1;i<=n;i++)
            if(t[i]==j) b[j][++b[j][0]]=i;
        sort(b[j]+1,b[j]+1+b[j][0],cmp);

//        cout <<" j : " <<j <<endl;
//        for(int i=1;i<=b[j][0];i++) cout <<b[j][i] <<" "; cout <<endl;
    }


    LL ans;
    if(gao(ans)==0) puts("-1");
    else cout <<ans <<endl;
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