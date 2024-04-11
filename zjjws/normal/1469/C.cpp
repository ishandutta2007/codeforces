#include <stdio.h>
#define LL long long
using namespace std;
const int N=2e5+3;
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
inline LL max(LL x,LL y){return x>y?x:y;}
inline LL min(LL x,LL y){return x<y?x:y;}

LL h[N];
inline void work()
{
    int n=rin();
    LL k=rin();
    for(int i=1;i<=n;i++)h[i]=rin();
    LL l,r;
    l=r=h[1];
    bool if_true=true;
    for(int i=2;i<=n;i++)
    {
        LL l_,r_;
        l_=max(h[i],l+1-k);
        r_=min(h[i]+k-1,r-1+k);
        l=l_;r=r_;
        if(l>r||l-h[i]>=k)if_true=false;
        // printf("i:%d l:%lld r:%lld\n",i,l,r);
    }
    if(if_true&&l==h[n])puts("YES");else puts("NO");
    return;
}
int main()
{
    int i,j;
    for(int T=rin();T;T--)work();
    return 0;
}