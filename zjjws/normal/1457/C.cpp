#include <stdio.h>
#define LL long long
using namespace std;
const int N=1e5+3;
inline LL min(LL x,LL y){return x<y?x:y;}
inline int gc(){char c=getchar();for(;c!='0'&&c!='1';c=getchar());return c-'0';}
inline LL rin()
{
    LL s=0;
    bool bj=false;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')bj=true,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)s=-s;
    return s;
}

int a[N];
LL f[N];
inline void work()
{
    int n=rin(),p=rin(),k=rin();
    for(int i=1;i<=n;i++)a[i]=gc();
    LL x=rin(),y=rin();
    LL ans=0x3f3f3f3f3f3f3f3f;
    for(int i=p;i<=n;i++)
    {
        f[i]=y*(i-p)+(a[i]?0:x);
        if(i-k>=p)f[i]=min(f[i],f[i-k]+(a[i]?0:x));
        if(i+k>n)ans=min(ans,f[i]);
    }
    printf("%lld\n",ans);
    return;
}

int main()
{
    int i,j;
    for(int T=rin();T;T--)work();
    return 0;
}