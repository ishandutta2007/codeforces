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
    int w=rin(),h=rin(),n=rin();
    int s_1=1,s_2=1;
    for(;w%2==0;w/=2)s_1<<=1;
    for(;h%2==0;h/=2)s_2<<=1;
    if(s_1*s_2>=n)puts("YES");
    else puts("NO");
    return;
}
int main()
{
    int i,j;
    for(int T=rin();T;T--)work();
    return 0;
}