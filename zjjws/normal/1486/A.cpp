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
int n;
LL a[N];
inline void work()
{
    n=rin();
    LL sum=0;
    for(int i=1;i<=n;i++)a[i]=rin();
    for(int i=1;i<=n;i++)
    {
        if(a[i]<(i-1)){puts("NO");return;}
        a[i+1]+=(a[i]-(i-1));
    }
    puts("YES");
    return;
}
int main()
{
    for(int T=rin();T;T--)work();
    return 0;
}

//vjudge 