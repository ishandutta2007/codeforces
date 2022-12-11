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
#include <iomanip>
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
template< typename T >
inline void Swap(T &a,T &b) {T c=a; a=b; b=c;}

const double pi=(double) acos(-1.0);
const int MOD=(int) 1e9+7;
const int INF=(int) 0x3f3f3f3f;
const LL  LINF=(LL) INF<<32|INF;
const int SINF=(uint) ~0>>1;
const LL  SLINF=(ULL) (-1)>>1;
const double DINF=(double) 1e50;
const double eps=(double) 1e-8;
const int maxn=(int) 1e3+20;
const int maxm=(int) 1000000+15;

inline int sig(double x) {return x<-eps?-1:x>eps;}
inline void fadd(LL &x,LL a) {x+=a; if(x>=MOD) x-=MOD;}

//--------------start------------------

int n,m,q;
struct node
{
    node *L,*R,*U,*D;
    int val;
}A[maxn][maxn];

void work()
{
    while(~scanf("%d%d%d",&n,&m,&q))
    {
        for(int i=0;i<=n+1;i++)
            for(int j=0;j<=m+1;j++)
            {
                if(i) A[i][j].U=&A[i-1][j];
                if(j) A[i][j].L=&A[i][j-1];
                A[i][j].D=&A[i+1][j];
                A[i][j].R=&A[i][j+1];
            }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                read(A[i][j].val);

        for(int i=0;i<q;i++)
        {
            int x,y,X,Y,r,c;
            read(x), read(y), read(X), read(Y), read(r), read(c);
            node *p1,*p2;
            p1=p2=&A[0][0];
            while(x--) p1=p1->D; while(y--) p1=p1->R;
            while(X--) p2=p2->D; while(Y--) p2=p2->R;

//            cout <<p1->val <<" " <<p2->val <<endl;
            p1=p1->U; p2=p2->U;
            for(int i=0;i<r;i++)
            {
                p1=p1->D; p2=p2->D;
                Swap(p1->L->R,p2->L->R);
                Swap(p1->L,p2->L);
            }
            p1=p1->L; p2=p2->L;
            for(int i=0;i<c;i++)
            {
                p1=p1->R; p2=p2->R;
                Swap(p1->D->U,p2->D->U);
                Swap(p1->D,p2->D);
            }
            p1=p1->D; p2=p2->D;
            for(int i=0;i<r;i++)
            {
                p1=p1->U; p2=p2->U;
                Swap(p1->R->L,p2->R->L);
                Swap(p1->R,p2->R);
            }
            p1=p1->R; p2=p2->R;
            for(int i=0;i<c;i++)
            {
                p1=p1->L; p2=p2->L;
                Swap(p1->U->D,p2->U->D);
                Swap(p1->U,p2->U);
            }
        }

        for(int i=1;i<=n;i++)
        {
            node *p=&A[i][0];
            for(int j=0;j<m;j++)
            {
                p=p->R;
                printf("%d ",p->val);
            }
            putchar('\n');
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