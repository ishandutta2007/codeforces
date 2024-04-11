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
#define mk(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define lowbit(x) ((x)&-(x))

typedef unsigned LL ULL;
typedef unsigned uint;
typedef pair<int,int> pii;
typedef vector<int> vi;

template< typename T > inline void read(T &x) {
    bool f=0; char ch=getchar(); x=0;
    while(ch<48 || 57<ch) {if(ch=='-')f=!f; ch=getchar();}
    while(47<ch && ch<58) {x=x*10+ch-48; ch=getchar();}
    if(f) x=-x;
}
char __stack[25],__top;
template< typename T > inline void write(T x) {
    if(x) {
        if(x<0) putchar('-'), x=-x;
        __top=0;
        while(x) __stack[++__top]=x%10, x/=10;
        while(__top) putchar(48+__stack[__top--]);
    }
    else putchar(48);
}

template< typename T > inline void Max(T &a, T b) {if(a<b) a=b;}
template< typename T > inline void Min(T &a, T b) {if(b<a) a=b;}
template< typename T > inline void Swap(T &a,T &b) {T c=a; a=b; b=c;}
template< typename T > inline T Abs(T a) {if(a<0) return -a; else return a;}

const double pi=(double) acos(-1.0);
const int MOD=(int) 1e9+7;
const int INF=(int) 0x3f3f3f3f;
const LL  LINF=(LL) INF<<32|INF;
const int SINF=(uint) ~0>>1;
const LL  SLINF=(ULL) (-1)>>1;
const double DINF=(double) 1e50;
const double eps=(double) 1e-8;
const int maxn=(int) 2e5+20;
const int maxm=(int) 2e5+20;

inline int sig(double x) {return x<-eps?-1:x>eps;}

//--------------start------------------

int n,m,k;
LL a[maxn];
priority_queue<pair<LL,int> > pq;
pair<LL,int> temp;


void work()
{
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        int mn_pos=1,f=0;
        for(int i=1;i<=n;i++)
        {
            read(a[i]);
            if(a[i]<0) f=!f;
            if(Abs(a[i])<Abs(a[mn_pos])) mn_pos=i;
        }
        while(!f && m)
        {
            if(a[mn_pos]>=0)
            {
                a[mn_pos]-=k;
                if(a[mn_pos]<0)
                {
                    f=1;
                    m--;
                    break;
                }
            }
            else
            {
                a[mn_pos]+=k;
                if(a[mn_pos]>=0)
                {
                    f=1;
                    m--;
                    break;
                }
            }
            m--;
        }

        if(m){
        while(!pq.empty()) pq.pop();
        for(int i=1;i<=n;i++)
        {
            temp.first=-Abs(a[i]);
            temp.second=i;
            pq.push(temp);
        }
        }

        while(m)
        {
            temp=pq.top(); pq.pop();
            if(a[temp.second]<0) a[temp.second]-=k;
            else a[temp.second]+=k;
            temp.first=-Abs(a[temp.second]);
            pq.push(temp);
            m--;
        }

        for(int i=1;i<=n;i++) write(a[i]),putchar(' ');
        putchar('\n');
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