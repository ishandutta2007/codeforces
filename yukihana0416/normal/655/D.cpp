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


typedef unsigned LL ULL;
typedef unsigned uint;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<LL,LL> pLL;

inline LL read()
{
    LL x=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-')f=-f;ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

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
const int INF=(int) 0x3f3f3f3f;
const LL  LINF=(ULL)(-1) >> 2;
const int SINF=(uint) ~0U>>1;
const double DINF=(double) 1e50;
const int MOD=(int) 1e9+7;
const double eps=(double) 1e-8;
const int maxn=(int) 1e5+15;
const int maxm=(int) 254750+15;

LL gcd(LL x,LL y) {LL t; while(y) t=x%y,x=y,y=t; return absx(x);}
inline int sig(double x) {return x<-eps?-1:x>eps;}

//--------------start------------------


int n,m;
int du[maxn];
vector<int> G[maxn];

int nxt[maxn];
map<pii,int> mp;
void work()
{
    n=read(), m=read();
    for(int i=1;i<=m;i++)
    {
        int x=read(), y=read();
        G[x].PB(y);
        du[y]++;
        if(mp[MK(x,y)]==0) mp[MK(x,y)]=i;
    }
    bool ok=1;
    int cnt=0,top;
    for(int i=1;i<=n;i++)
    {
        if(du[i]==0)
        {
            top=i;
            cnt++;
        }
    }
    if(cnt!=1)
    {
        puts("-1");
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        cnt=0;
        nxt[i]=top;
        int nt;
        for(int j=0;j<G[top].size();j++)
        {
            int v=G[top][j];
//            cout <<top <<" " <<v<<endl;
            du[v]--;
//            cout <<du[v] <<endl;
            if(du[v]==0)
            {
                cnt++;
                nt=v;
            }
        }
        if(i<n && cnt!=1)
        {
            puts("-1");
            return ;
        }
        top=nt;
    }
    int ans=0;
//    for(int i=1;i<=n;i++) cout <<nxt[i] <<" ";
//    cout <<endl;
    for(int i=1;i<n;i++)
    {
        Max(ans,mp[MK(nxt[i],nxt[i+1])]);
    }
    cout <<ans <<endl;
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