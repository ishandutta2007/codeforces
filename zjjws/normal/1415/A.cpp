#include <stdio.h>
#define LL long long
using namespace std;
LL n,m,x,y;
inline LL max(LL x,LL y){return x>y?x:y;}
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
    n=rin();m=rin();x=rin();y=rin();
    LL ans=0;
    ans=max(max(x-1+y-1,x-1+(m-y)),max((n-x)+y-1,(n-x)+(m-y)));
    printf("%lld\n",ans);
    return ;
}
int main()
{
    int i,j;
    for(int T=rin();T;T--)work();
    return 0;
}