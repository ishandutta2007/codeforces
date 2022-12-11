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
const int maxn=(int) 2e5+20;
const int maxm=(int) 5e5+15;

inline int sig(double x) {return x<-eps?-1:x>eps;}

//--------------start------------------

int n,m;
char str[maxn], Temp[]={'2','0','1','7','6'};


struct Node
{
    int a[6][6];
    inline void init() {memset(a,0x3f,sizeof(a));}
    inline void print()
    {
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<6;j++)
            {
                printf("%2d",a[i][j]>=INF ? -1 : a[i][j]);
            }
            printf("\n");
        }
    }
}T[maxn<<2];

inline Node Merge(const Node &L,const Node &R)
{
    Node res; res.init();
    for(int k=0;k<6;k++)
        for(int i=0;i<6;i++)
            for(int j=0;j<6;j++)
                Min(res.a[i][j],L.a[i][k]+R.a[k][j]);

    return res;
}

void build(int l,int r,int id)
{
    if(l==r)
    {
        T[id].init();
        for(int i=0;i<6;i++) T[id].a[i][i]=0;
        for(int i=0;i<4;i++) if(str[l]==Temp[i])
        {
            T[id].a[i][i]=1;
            T[id].a[i][i+1]=0;
        }
        if(str[l]=='6')
        {
            T[id].a[3][3]=1;
            T[id].a[4][4]=1;
            T[id].a[3][5]=0;
            T[id].a[4][5]=0;
        }
//        cout <<l <<"  : " <<endl;
//        T[id].print();
        return ;
    }
    int mid=MID(l,r);
    build(lson);
    build(rson);
    T[id]=Merge(T[ls],T[rs]);
//    cout <<l <<" " <<r <<endl;
//    T[id].print();
}

Node query(int L,int R,int l,int r,int id)
{
    if(L<=l && r<=R) return T[id];
    int mid=MID(l,r);
    if(R<=mid) return query(L,R,lson);
    if(mid<L)  return query(L,R,rson);
    return Merge(query(L,R,lson), query(L,R,rson));
}

void work()
{
    read(n), read(m);
    scanf("%s",str+1);
    build(1,n,1);
    Node Ans;
    int l,r,last;
    while(m--)
    {
        read(l), read(r);
        Ans=query(l,r,1,n,1);
        last=Ans.a[0][4];
        if(last>=INF) last=-1;
        printf("%d\n",last);
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