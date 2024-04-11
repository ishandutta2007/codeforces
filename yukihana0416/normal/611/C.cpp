#pragma comment(linker,"/STACK:102400000,102400000")
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <climits>
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
#include <cassert>
using namespace std;

#define VT vector
#define LL long long
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

LL gcd(LL a,LL b) {if(!b) return a; else return gcd(b,a%b);}

const double pi=(double) acos(-1.0);
const double eps=(double) 1e-8;
const int INF=(int) 0x3f3f3f3f;
const LL  LINF=(ULL)(-1) >> 2;
const int SINF=(uint) ~0U>>1;
const double DINF=(double) 1e50;
const int MOD=(int) 1e9+7;
const int maxn=(int) 5e3+20;
const int maxm=(int) 1e6+20;

char s[605][605];

int n,m;
LL sum[605][605];
LL isum[605][605],jsum[605][605];

void work()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<=m+1;i++) s[0][i]='#'; s[0][m+2]=0;
    for(int i=1;i<=n;i++)
    {
        s[i][0]='#';
        scanf("%s",s[i]+1);
        s[i][m+1]='#';
        s[i][m+2]=0;
    }
    for(int i=0;i<=m+1;i++) s[n+1][i]='#'; s[n+1][m+2]=0;
//    for(int i=0;i<=n+1;i++)
//        printf("%s\n",s[i]);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int t=0;
            if(s[i][j]=='.')
            {
                if(s[i][j-1]=='.') t++;
                if(s[i-1][j]=='.') t++;
            }
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+t;
//            cout <<t <<" ";
            if(s[i][j]=='.' && s[i-1][j]=='.')
                isum[i][j]=isum[i][j-1]+1;
            else
                isum[i][j]=isum[i][j-1];

            if(s[i][j]=='.' && s[i][j-1]=='.')
                jsum[i][j]=jsum[i-1][j]+1;
            else
                jsum[i][j]=jsum[i-1][j];
        }
//        cout <<endl;
    }
//    cout <<endl;
//    for(int i=1;i<=n;i++)
//    {
//        for(int j=1;j<=m;j++)
//        {
//            cout <<sum[i][j] <<" ";
//        }
//        cout <<endl;
//    }
//
//    cout <<endl;
//    for(int i=1;i<=n;i++)
//    {
//        for(int j=1;j<=m;j++)
//        {
//            cout <<isum[i][j] <<" ";
//        }
//        cout <<endl;
//    }

    int q=read();
    while(q--)
    {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        LL ans=sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
//        cout <<"temp : " <<ans <<endl;
        ans-=isum[x1][y2]-isum[x1][y1-1];
        ans-=jsum[x2][y1]-jsum[x1-1][y1];
        printf("%d\n",ans);
    }
}

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