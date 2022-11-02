#include <vector>
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
    if(bj)return -s;
    return s;
}

inline int min(int x,int y){return x<y?x:y;}
inline int max(int x,int y){return x>y?x:y;}
inline LL min(LL x,LL y){return x<y?x:y;}
inline LL max(LL x,LL y){return x>y?x:y;}
inline void jh(int &x,int &y){if(x!=y)x^=y^=x^=y;return;}
inline void jh(LL &x,LL &y){if(x!=y)x^=y^=x^=y;return;}

inline int Gcd(int x,int y){return (!y)?(x):(Gcd(y,x%y));}
inline int Lcm(int x,int y){return x/Gcd(x,y)*y;}

const int N=5e2+3;
int n,m;
int L=1;

int a[N][N];

inline void work()
{
    n=rin();m=rin();
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)a[i][j]=rin();
    for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){int x=a[i][j];if((i+j)&1)printf("%d ",L);else printf("%d ",L+x*x*x*x);}printf("\n");}
    return;
}
int main()
{
    for(int i=1;i<=16;i++)L=Lcm(L,i);
    work();
    return 0;
}