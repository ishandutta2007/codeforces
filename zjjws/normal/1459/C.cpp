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
inline LL Gcd(LL a,LL b){return (!b)?(a):(Gcd(b,a%b));}
inline LL abs(LL x){return (x<0)?(-x):x;}

int n,m;
int main()
{
    int i,j;
    n=rin();m=rin();
    LL a=rin();
    LL s=0;
    LL last=a;
    for(i=2;i<=n;i++){LL now=rin();s=Gcd(abs(now-last),s);last=now;}
    for(i=1;i<=m;i++)printf("%lld ",Gcd(rin()+a,s));
    return 0;
}