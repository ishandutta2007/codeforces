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
const int maxn=(int) 1e5+20;
const int maxm=(int) 1e6+15;

inline int sig(double x) {return x<-eps?-1:x>eps;}
inline void fadd(LL &x,LL a) {x+=a; if(x>=MOD) x-=MOD;}

//--------------start------------------

int n;
char s[maxn];
int a[maxn];

inline int cg(char c)
{
    if('A'<=c && c<='Z') return c-'A';
    else return c-'a'+26;
}

int sum[maxn][52];
int temp[52];
int app[52];

void work()
{
    while(cin >>n)
    {
        memset(sum,0,sizeof(sum));
        scanf("%s",s+1);
        int ans=n;
        memset(app,0,sizeof(app));
        for(int i=1;i<=n;i++) a[i]=cg(s[i]), app[a[i]]=1;

        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<52;j++) sum[i][j]=sum[i-1][j];
            sum[i][a[i]]++;

            int l=1,r=i;
            while(l<=r)
            {
                int mid=MID(l,r);
                for(int j=0;j<52;j++) if(app[j]) temp[j]=sum[i][j]-sum[mid-1][j];
                int flag=1;
                for(int j=0;j<52;j++) if(app[j] && temp[j]==0) {flag=0; break;}
                if(flag)
                {
                    Min(ans,i-mid+1);
                    l=mid+1;
                }
                else r=mid-1;
            }
        }
        cout <<ans <<endl;
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