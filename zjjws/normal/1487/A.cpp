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
inline void jh(int &x,int &y){if(x!=y)x^=y^=x^=y;return;}
inline void jh(LL &x,LL &y){if(x!=y)x^=y^=x^=y;return;}

const int N=3e5+3;
int n,m;
int a[N];
inline void work()
{
    n=rin();
    int maxl=1e9+7;
    int ans=0;
    for(int i=1;i<=n;i++)a[i]=rin(),maxl=min(maxl,a[i]);
    for(int i=1;i<=n;i++)ans+=(a[i]==maxl);
    printf("%d\n",n-ans);
    return;
}
int main()
{
    for(int T=rin();T;T--)work();
    return 0;
}

//vjudge 