#include <stdio.h>
#define LL long long
using namespace std;
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

inline void work()
{
    int n=rin();
    LL sum=0;
    LL s=0;
    LL maxs=0;
    for(int i=1;i<=n;i++)
    {
        s+=rin();
        if(s>maxs)maxs=s;
    }
    sum+=maxs;
    n=rin();
    s=maxs=0;
    for(int i=1;i<=n;i++)
    {
        s+=rin();
        if(s>maxs)maxs=s;
    }
    sum+=maxs;
    printf("%lld\n",sum);
    return;
}
int main()
{
    int i,j;
    for(int T=rin();T;T--)work();
    return 0;
}