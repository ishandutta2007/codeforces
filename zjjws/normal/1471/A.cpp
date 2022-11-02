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
    int n=rin(),x=rin();
    LL sum=0;
    LL ans=0;
    for(int i=1;i<=n;i++)
    {
        int s=rin();
        sum+=s;
        ans+=(s-1)/x+1;
    }
    sum=(sum-1)/x+1;
    printf("%lld %lld\n",sum,ans);
    return;
}
int main()
{
    int i,j;
    for(int T=rin();T;T--)work();
    return 0;
}