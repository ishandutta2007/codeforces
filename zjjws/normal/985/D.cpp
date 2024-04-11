#include <stdio.h>
#define LL long long
using namespace std;
inline LL min(LL x,LL y){return x<y?x:y;}
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
int main()
{
    int i,j;
    LL n,h,P;
    n=rin();h=rin(),P=2e9;
    LL l=1,r=min(h,P);
    LL last=1;
    for(;l<=r;)
    {
        LL mid=(l+r)>>1;
        if((mid*(mid+1)>>1)<=n)last=mid,l=mid+1;
        else r=mid-1;
    }
    LL cpy=n;
    LL ans=last;n-=(last*(last+1)>>1);
    ans+=n/last;n%=last;
    if(n)ans++;
    n=cpy;
    
    LL sum;
    if(h<P&&((h+1)*h>>1)<n)
    {
        l=h+1,r=P;
        LL last=h+1;
        for(;l<=r;)
        {
            LL mid=(l+r)>>1;
            if(((mid+1)*mid>>1)+((h+mid-1)*(mid-h)>>1)<=n)last=mid,l=mid+1;
            else r=mid-1;
        }
        sum=last-h;n-=((h+last-1)*(last-h)>>1);
        sum+=last;n-=((last+1)*last>>1);
        sum+=n/last;n%=last;
        if(n)sum++;
        ans=min(ans,sum);
    }
    printf("%lld\n",ans);
    return 0;
}