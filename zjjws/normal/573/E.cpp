#pragma Gcomcom optimize(2, "Ofast", "inline", "-fgcse", "-fgcse-lm", "-fipa-sra", "-ftree-pre", "-ftree-vrp", "-fpeephole2", "-ffast-math", "-fsched-spec", "unroll-loops", "-falign-jumps", "-falign-loops", "-falign-labels", "-fdevirtualize", "-fcaller-saves", "-fcrossjumping", "-fthread-jumps", "-funroll-loops")
#pragma Gcomcom target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include <cmath>
#include <stdio.h>
#include <algorithm>
#define LL long long
using namespace std;
struct Rin
{
    char c;
    static const int Rea=1e5+3;
    inline char gc()
    {
        static char rea[Rea];
        static char *head,*tail;
        return head==tail&&(tail=(head=rea)+fread(rea,1,Rea,stdin),head==tail)?EOF:*head++;
    }
    inline Rin&operator >>(int &x)
    {
        x=0;
        bool tag=false;
        for(c=gc();c>'9'||c<'0';c=gc())if(c=='-'){c=gc();tag=true;break;}
        for(;c>='0'&&c<='9';c=gc())x=(x<<1)+(x<<3)+(c^'0');
        if(tag)x=-x;return *this;
    }
}rin;

const int N=1e6+3;
int n,m;
LL b[N];
int c[N];
int v[N];
bool tag[N];
int lens,ks;
inline int sl(int x){return (x-1)*lens+1;}
inline int sr(int x){return (x==ks)?(n):(x*lens);}
inline bool myru_cutt(int x,int y){return v[x]==v[y]?b[x]>b[y]:v[x]<v[y];}
const int K=1e3+3;
struct gyq
{
    int dio;
    int num;
    int d[K];
    int nam[K];
    int tail,cutt;
    inline bool check(int x,int y,int z)
    {
        double t_1=b[x]-b[y],t_2=b[y]-b[z];t_1/=(v[y]-v[x]);t_2/=(v[z]-v[y]);
        return t_1>=t_2;
    }
    inline void tb()
    {
        int l=sl(num),r=sr(num);tail=0;
        for(int i=1,j;i<=cutt;i=j)
        {
            if(tag[nam[i]]){j=i+1;continue;}int st=i;
            for(j=i+1;j<=cutt&&v[nam[j]]==v[nam[i]];j++){if(!tag[nam[j]]&&b[nam[j]]>b[nam[st]])st=j;}
            for(;tail>1&&check(d[tail-1],d[tail],nam[st]);tail--);
            d[++tail]=nam[st];
        }
        return;
    }
    inline LL Val(int x,int a){return 1LL*v[x]*a+b[x];}
    inline LL check(int a)
    {
        if(!tail)return -0x3f3f3f3f3f3f3f3f;
        int l=2,r=tail,lst=1;
        for(;l<=r;)
        {
            int mid=l+r>>1;
            if(Val(d[mid],a)>Val(d[mid-1],a))lst=mid,l=mid+1;
            else r=mid-1;
        }
        dio=d[lst];
        return Val(d[lst],a);
    }
    inline void del()
    {
        if(!tail)return;
        int l=sl(num),r=sr(num);
        for(int i=l;i<dio;i++)b[i]+=v[dio];
        for(int i=dio+1;i<=r;i++)b[i]+=v[i];
        tag[dio]=true;tb();return;
    }
    inline void init(int num_)
    {
        num=num_;int l=sl(num),r=sr(num);cutt=0;
        for(int i=l;i<=r;i++)nam[++cutt]=i;
        sort(nam+1,nam+cutt+1,myru_cutt);tb();return;
    }
}T[K];
inline void init(){lens=sqrt(n);ks=n/lens;if(n%lens)ks++;for(int i=1;i<=ks;i++)T[i].init(i);return;}

int A[K];
LL B[K];
inline LL check()
{
    LL sum=0,maxl=-0x3f3f3f3f3f3f3f3f,nows;
    int dio=-1,a=0;
    for(int i=1;i<=ks;i++){sum+=B[i];a+=A[i];if((nows=(sum+T[i].check(a)))>maxl)maxl=nows,dio=i;}
    if(dio==-1)return -0x3f3f3f3f3f3f3f3f;
    A[dio+1]++;B[1]+=v[T[dio].dio];B[dio]-=v[T[dio].dio];
    T[dio].del();
    return maxl;
}
int main()
{
    rin>>n;
    LL ans=0,cutt=0,sum=0;
    for(int i=1;i<=n;i++)rin>>v[i];
    for(int i=1;i<=n;i++){if(v[i]>=0)ans+=(++cutt)*v[i],sum+=v[i];else b[++m]=sum-cutt*v[i],v[m]=v[i];}
    n=m;for(int i=1;i<=n;i++)b[i]=sum-b[i];if(!n){printf("%lld\n",ans);return 0;}
    init();A[1]=1;
    for(int i=1;i<=n;i++){LL nows=check();if(nows<=0)break;ans+=nows;}
    printf("%lld\n",ans);
    return 0;
}