#include <string>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
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

inline void work()
{
    int n=rin();
    int m=n/2020;
    if(n%2020<=m)puts("YES");
    else puts("NO");
    return;
}
int main()
{
    for(int T=rin();T;T--)work();
    return 0;
}