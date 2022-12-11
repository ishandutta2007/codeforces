#include <bits/stdc++.h>
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
    x=0; bool f=0; char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-') f=1; ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    if(f) x=-x;
}

template< typename T > inline void Max(T &a, T b) {if(a<b) a=b;}
template< typename T > inline void Min(T &a, T b) {if(b<a) a=b;}
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
const int maxm=(int) 1e6+20;
const int maxk=(int) 5e2+20;

inline int sig(double x) {return x<-eps?-1:x>eps;}

//--------------start------------------

int n;
int a[maxn];
int cnt[maxm];

LL fp(LL a, LL n)
{
    LL res=1;
    while(n)
    {
        if(n&1) res=res*a%MOD;
        a=a*a%MOD; n>>=1;
    }
    return res;
}

void work()
{
    read(n);

    int maxv=0;
    for(int i=1;i<=n;i++)
    {
        int x; read(x);
        Max(maxv,x);
        for(LL j=1;j*j<=x;j++)
        {
            if(x%j) continue;
            cnt[j]++;
            if(x/j!=j) cnt[x/j]++;
        }

    }
    for(int i=2;i<=maxv;i++)
    {
//        cout <<cnt[i] <<endl;
        if(cnt[i]) cnt[i]=(fp(2,cnt[i]-1)*cnt[i])%MOD;
//        cout <<cnt[i] <<endl;
    }


    int ans=0;
    for(int i=maxv;i!=1;i--)
    {
        for(int j=i+i;j<=maxv;j+=i)
        {
            cnt[i]=(cnt[i]-cnt[j]);
            if(cnt[i]<0) cnt[i]+=MOD;
        }
//        cout <<"fi : " <<i <<" " <<cnt[i] <<endl;
        ans=(ans+(LL)cnt[i]*i)%MOD;
    }
    printf("%d\n",ans);
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