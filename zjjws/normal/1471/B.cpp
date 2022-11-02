#include <stdio.h>
#define LL long long
using namespace std;
const int N=1e5+3;
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

LL d[N];
LL cutt[N];
inline void work()
{
    LL n=rin(),x=rin();
    LL ans=0;
    for(int i=1;i<=n;i++)
    {
        d[i]=rin();cutt[i]=0;
        for(LL j=d[i];j%x==0;j/=x)cutt[i]++;
    }
    LL minl=0x3f3f3f3f,st=0;
    for(int i=1;i<=n;i++)if(cutt[i]<minl)minl=cutt[i],st=i;
    for(int i=1;i<st;i++)ans+=d[i]*(minl+2);
    for(int i=st;i<=n;i++)ans+=d[i]*(minl+1);
    printf("%lld\n",ans);
    return;
}
int main()
{
    int i,j;
    for(int T=rin();T;T--)work();
    return 0;
}