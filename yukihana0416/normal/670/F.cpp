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
typedef map<int,int> mii;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<LL,LL> pll;
typedef vector<int> vi;

template< typename T > inline void read(T &res)
{
    T x=0; bool f=0; char ch=getchar();
    while(ch<48 || ch>57) {if(ch=='-')f=!f; ch=getchar();}
    while(ch>=48 && ch<=57) {x=x*10+ch-48; ch=getchar();}
    res = f ? -x : x ;
}
char __stack[25],__top;
template< typename T > inline void write(T num)
{
    if(num)
    {
        if(num<0) putchar('-'), num=-num;
        __top=0;
        while(num) __stack[++__top]=num%10, num/=10;
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
const int maxn=(int) 1e5+20;
const int maxm=(int) 2e5+20;

inline int sig(double x) {return x<-eps?-1:x>eps;}
inline void fadd(LL &x,LL a) {x+=a; if(x>=MOD) x-=MOD;}

//--------------start------------------

int la,lb;
string a,b,ans;
int cnta[10],cntb[10];

int use[10],bp[10];
void gao2(int *use,int Btype,int st)
{
    string s;
    bool B;
    bool Buse;
    B=st&1;
    Buse=1;
    s="";
    for(int i=1;i<10;i++)
    {
        if(B==0)
        {
            if(Btype==i && Buse)
            {
                Buse=0;
                s+=b;
                break;
            }
        }
        if(use[i])
        {
            use[i]--;
            s+='0'+i;
            break;
        }
        if(B==1)
        {
            if(Btype==i && Buse)
            {
                Buse=0;
                s+=b;
                break;
            }
        }
    }
    B=st&2;
    for(int i=0;i<10;i++)
    {
        if(B==0)
        {
            if(Btype==i && Buse)
            {
                Buse=0;
                s+=b;
            }
        }
        while(use[i]--) s+='0'+i;
        if(B==1)
        {
            if(Btype==i && Buse)
            {
                Buse=0;
                s+=b;
            }
        }
    }
    Min(ans,s);
}

void gao(int Len)
{
    for(int i=0;i<10;i++) use[i]=cnta[i]-cntb[i];
    int t=Len;
    while(t) use[t%10]--, t/=10;
    for(int i=0;i<10;i++) bp[i]=use[i];
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<10;j++) use[j]=bp[j];
        gao2(use,b[0]-'0',i);
    }
}

void work()
{
    while(cin >>a >>b)
    {
        if(a=="01" || a=="10")
        {
            puts("0");
            continue;
        }

        memset(cnta,0,sizeof(cnta));
        memset(cntb,0,sizeof(cntb));

        la=a.size(), lb=b.size();
        for(int i=0;i<la;i++) cnta[a[i]-'0']++;
        for(int i=0;i<lb;i++) cntb[b[i]-'0']++;

        ans="";
        for(int i=0;i<la;i++) ans+='9';

        for(int i=1;i<la;i++)
        {
            int temp[10]={0};
            int j=i;
            while(j) temp[j%10]++, j/=10;

            int tot=0;
            for(int j=0;j<10;j++) tot+=cnta[j]-temp[j];
            bool ck=1;
            for(int j=0;j<10;j++) if(cnta[j]-temp[j]<cntb[j]) ck=0;
            if(ck && tot==i) gao(i);
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