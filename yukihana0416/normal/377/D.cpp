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
typedef vector<int> vi;

inline LL read()
{
    LL x=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-')f=-f;ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1
#define ls id<<1
#define rs id<<1|1
#define MID(a,b) (((LL)(a)+(LL)(b))>>1)
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
const double eps=(double) 1e-10;
const int INF=(int) 0x3f3f3f3f;
const LL  LINF=(ULL)(-1) >> 2;
const int SINF=(uint) ~0U>>1;
const double DINF=(double) 1e50;
const int MOD=(int) 1e9+7;
const int maxn=(int) 3e5+15;
const int maxm=(int) 3000+15;

LL gcd(LL x,LL y) {LL t; while(y) t=x%y,x=y,y=t; return absx(x);}
inline int sig(double x) {return x<-eps?-1:x>eps;}

//--------------start------------------

int n,m;
vector<int> vec[2][maxn];

struct node
{
    int mx,flag;
}st[maxn<<2];

void build(int l,int r,int id)
{
    st[id].mx=st[id].flag=0;
    if(l==r) return ;
    int mid=MID(l,r);
    build(lson);
    build(rson);
}

inline void lazy(int id)
{
    int &v=st[id].flag;
    st[ls].flag+=v; st[ls].mx+=v;
    st[rs].flag+=v; st[rs].mx+=v;
    v=0;
}

void update(int v,int L,int R,int l,int r,int id)
{
    if(L<=l && r<=R)
    {
        st[id].flag+=v;
        st[id].mx+=v;
        return ;
    }
    if(st[id].flag) lazy(id);
    int mid=MID(l,r);
    if(L<=mid) update(v,L,R,lson);
    if(mid<R) update(v,L,R,rson);
    st[id].mx=maxt(st[ls].mx,st[rs].mx);
}

int query(int l,int r,int id)
{
    if(l==r) return l;
    if(st[id].flag) lazy(id);
    int mid=MID(l,r);
    if(st[id].mx==st[ls].mx) return query(lson);
    else return query(rson);
}

struct INPUT
{
    int l,r,v;
}in[maxn/3];

void work()
{
    n=read();
    m=0;
    for(int i=1;i<=n;i++)
    {
        in[i].l=read(), in[i].v=read(), in[i].r=read();
        vec[0][in[i].v].PB(i); vec[1][in[i].r+1].PB(i);
        Max(m,in[i].r);
    }
    m++;
    build(1,m,1);

    int ans_val=0, ans_l,ans_r;
    for(int i=1;i<=m;i++)
    {
        int s;
        s=vec[0][i].size();
        for(int j=0;j<s;j++)
        {
            int idx=vec[0][i][j];
            update(1,in[idx].l,in[idx].v,1,m,1);
        }
        s=vec[1][i].size();
        for(int j=0;j<s;j++)
        {
            int idx=vec[1][i][j];
            update(-1,in[idx].l,in[idx].v,1,m,1);
        }

        if(st[1].mx<=ans_val) continue;
        ans_val=st[1].mx;
        ans_l=query(1,m,1);
        ans_r=i;
    }

    printf("%d\n",ans_val);
    bool f=0;
    for(int i=1;i<=n;i++)
    {
        if(ans_l<=in[i].v && in[i].v<=ans_r && in[i].l<=ans_l && ans_r<=in[i].r)
        {
            if(f) putchar(' ');
            else f=1;
            printf("%d",i);
        }
    }putchar('\n');
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