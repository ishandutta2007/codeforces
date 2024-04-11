#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
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

const int N=3e5+3;

inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline LL max(LL x,LL y){return x>y?x:y;}
inline LL min(LL x,LL y){return x<y?x:y;}
inline void jh(int x,int y){if(x!=y)x^=y^=x^=y;return;}
inline void jh(LL x,LL y){if(x!=y)x^=y^=x^=y;return;}

int n;

LL k;
LL a[N];

inline LL Gcd(LL a,LL b){return (!b)?(a):(Gcd(b,a%b));}
inline void work()
{
    n=rin();k=rin();
    for(int i=1;i<=n;i++)a[i]=rin();sort(a+1,a+n+1);
    LL s=0;
    for(int i=2;i<=n;i++)s=Gcd(s,a[i]-a[1]);
    if((a[1]%s+s)%s==(k%s+s)%s)puts("YES");
    else puts("NO");
    return;
}
int main()
{
    int i,j;
    for(int T=rin();T;T--)work();
    return 0;
}