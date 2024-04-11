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

const double pi=(double) acos(-1.0);
const int MOD=(int) 1e9+7;
const int INF=(int) 0x3f3f3f3f;
const LL  LINF=(LL) INF<<32|INF;
const int SINF=(uint) ~0>>1;
const LL  SLINF=(ULL) (-1)>>1;
const double DINF=(double) 1e50;
const double eps=(double) 1e-8;
const int maxn=(int) 1e6+20;
const int maxm=(int) 2e6+15;

inline int sig(double x) {return x<-eps?-1:x>eps;}
inline void fadd(LL &x,LL a) {x+=a; if(x>=MOD) x-=MOD;}

//--------------start------------------

int vis[maxn],prime[maxn>>2];
int mul[maxn],tar[maxn];

int get_prime()
{
    int tot=0;
    for(int i=2;i<maxn;i++)
    {
        if(!vis[i]) prime[tot++]=i, vis[i]=i;
        for(int j=0;j<tot;j++)
        {
            if((LL)i*prime[j]>=maxn) break;
            vis[i*prime[j]]=prime[j];
            if(i%prime[j]==0) break;
        }
    }
}

void fac(int k,int *arr)
{
    int f=1,nf,cnt=0;
    while(k>1)
    {
        nf=vis[k];
        if(nf!=f) Max(arr[f],cnt), f=nf, cnt=0;
        cnt++;
        k/=nf;
    }
    Max(arr[f],cnt);
}

void work()
{
    get_prime();
//    for(int i=1;i<=50;i++) cout <<"i & vis[i] : " <<i <<" " <<vis[i] <<endl;
    int n,m;
    read(n), read(m);
    fac(m,tar);
    for(int i=0;i<n;i++)
    {
        int x; read(x);
        fac(x,mul);
    }

    for(int i=1;i<maxn;i++)
    {
        if(mul[i]<tar[i])
        {
            puts("No");
            return ;
        }
    }
    puts("Yes");
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